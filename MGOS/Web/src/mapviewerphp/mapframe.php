<?php

//
//  Copyright (C) 2004-2011 by Autodesk, Inc.
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of version 2.1 of the GNU Lesser
//  General Public License as published by the Free Software Foundation.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//

include 'common.php';
include 'constants.php';

$mapDefinition = "";
$locale = "";
$infoWidth = 0;
$showLegend = false;
$showProperties = false;
$sessionId = "";
$type = "";
$username = '';
$password = '';
$hlTgt = '';
$hlTgtName = '';
$showSlider = true;

GetRequestParameters();

SetLocalizedFilesPath(GetLocalizationPath());

if($type == "DWF")
{
    if($hlTgt == 1)
        $frameName = "taskPaneFrame";
    else if($hlTgt == 3)
        $frameName = $hlTgtName;
    else
        $frameName = "_BLANK";
    $mapRequest = GetRootVirtualFolder() . "/mapagent/mapagent.fcgi?OPERATION=GETMAP&VERSION=1.0&MAPDEFINITION=" . urlencode($mapDefinition) . "&DWFVERSION=6.01&EMAPVERSION=1.0&LOCALE=" . $locale . ($sessionId != ""? "&SESSION=" . $sessionId: "") . "&reload=true";
    $templ = Localize(file_get_contents("../viewerfiles/dwfmappane.templ"), $locale, GetClientOS());
    printf ($templ,
                $mapRequest,
                $infoWidth,
                $showLegend || $showProperties?"true":"false",
                $showLegend?"true":"false",
                $showProperties?"true":"false",
                $frameName);
}
else
{
    try
    {
        InitializeWebTier();

        // create the map instance and store it with the session
        //
        $userInfo = new MgUserInformation();
        $userInfo->SetMgSessionId($sessionId);
        $userInfo->SetClientIp(GetClientIp());
        $userInfo->SetClientAgent(GetClientAgent());

        $site = new MgSiteConnection();
        $site->Open($userInfo);

        $tileSrvc = $site->CreateService(MgServiceType::TileService);

        $tileSizeX = $tileSrvc->GetDefaultTileSizeX();
        $tileSizeY = $tileSrvc->GetDefaultTileSizeY();

        $resourceSrvc = $site->CreateService(MgServiceType::ResourceService);

        $map = new MgMap();
        $resId = new MgResourceIdentifier($mapDefinition);
        $mapName = $resId->GetName();
        $map->Create($resourceSrvc, $resId, $mapName);

        //create an empty selection object and store it in the session repository
        $sel = new MgSelection($map);
        $sel->Save($resourceSrvc, $mapName);

        //get the map extent and calculate the scale factor
        //
        $mapExtent = $map->GetMapExtent();
        $srs = $map->GetMapSRS();
        if($srs != "")
        {
            $csFactory = new MgCoordinateSystemFactory();
            $cs = $csFactory->Create($srs);
            $metersPerUnit = $cs->ConvertCoordinateSystemUnitsToMeters(1.0);
            $unitsType = $cs->GetUnits();
        }
        else
        {
            $metersPerUnit = 1.0;
            $unitsType = GetLocalizedString("DISTANCEMETERS", $locale);
        }

        $llExtent = $mapExtent->GetLowerLeftCoordinate();
        $urExtent = $mapExtent->GetUpperRightCoordinate();
        $bgColor = $map->GetBackgroundColor();
        if(strlen($bgColor) == 8)
            $bgColor = '#' . substr($bgColor, 2);
        else
            $bgColor = "white";

        $scaleCreationCode = "";
        $scales = array();
        for($i = 0; $i < $map->GetFiniteDisplayScaleCount(); $i ++)
            $scales[$i] = $map->GetFiniteDisplayScaleAt($i);
        sort($scales);
        for($i = 0; $i < count($scales); $i ++)
            $scaleCreationCode = $scaleCreationCode . "scales[" . $i . "]=" . str_replace(",", ".", $scales[$i]) . "; ";

        $mapStateId = new MgResourceIdentifier("Session:" . $sessionId . "//" . $mapName . "." . MgResourceType::Map);
        $map->Save($resourceSrvc, $mapStateId);
        $templ = Localize(file_get_contents("../viewerfiles/ajaxmappane.templ"), $locale, GetClientOS());
        $vpath = GetSurroundVirtualPath();
        printf ($templ,
                    $tileSizeX,
                    $tileSizeY,
                    GetRootVirtualFolder() . "/mapagent/mapagent.fcgi",
                    $mapName,
                    $mapDefinition,
                    $infoWidth,
                    $showLegend?"true":"false",
                    $showProperties?"true":"false",
                    $sessionId,
                    $llExtent->GetX(), $llExtent->GetY(), $urExtent->GetX(), $urExtent->GetY(),
                    $metersPerUnit,
                    $unitsType,
                    $bgColor,
                    $hlTgt, $hlTgtName,
                    $vpath . "setselection.php",
                    $showSlider? "true": "false",
                    $locale,
                    $vpath . "getselectedfeatures.php",
                    $scaleCreationCode,
                    $vpath . "ajaxviewerabout.php",
                    $vpath . "legendctrl.php",
                    urlencode($mapName),
                    $sessionId,
                    $locale,
                    $vpath . "propertyctrl.php",
                    $locale
                    );
    }
    catch(MgException $e)
    {
        $errorMsg = EscapeForHtml($e->GetDetails());
        echo $errorMsg;
    }
}

//load ajax template code and format it
function GetParameters($params)
{
    global $mapDefinition, $type;
    global $infoWidth, $showLegend, $showProperties, $sessionId;
    global $locale, $hlTgt, $hlTgtName, $showSlider;


    $sessionId = ValidateSessionId(GetParameter($params, 'SESSION'));
    $locale = ValidateLocaleString(GetParameter($params, 'LOCALE'));
    $hlTgt = ValidateHyperlinkTargetValue(GetParameter($params, 'HLTGT'));
    $hlTgtName = ValidateFrameName(GetParameter($params, 'HLTGTNAME'));
    $mapDefinition = ValidateResourceId(GetParameter($params, 'MAPDEFINITION'));
    $showLegend = (GetIntParameter($params, 'SHOWLEGEND') == 1);
    $showProperties = (GetIntParameter($params, 'SHOWPROP') == 1);
    $showSlider = (GetIntParameter($params, 'SHOWSLIDER') == 1);
    $infoWidth = GetIntParameter($params, 'INFOWIDTH');
    $type = GetParameter($params, 'TYPE');
}

function GetRequestParameters()
{
    if($_SERVER['REQUEST_METHOD'] == "POST")
        GetParameters($_POST);
    else
        GetParameters($_GET);
}

?>
