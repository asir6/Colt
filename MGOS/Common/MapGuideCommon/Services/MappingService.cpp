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

#include "MapGuideCommon.h"

//////////////////////////////////////////////////////////////////
/// <summary>
/// Default Constructor
/// </summary>
MgMappingService::MgMappingService() : MgService()
{
}

//////////////////////////////////////////////////////////////////
///TODO: Get rid of this stub once user info is passed to the server
MgByteReader* MgMappingService::GenerateMap(MgMap* map, CREFSTRING mapAgentUri, MgDwfVersion* dwfVersion)
{
    MG_TRY()

        throw new MgNotImplementedException(L"MgMappingService.GenerateMap", __LINE__, __WFILE__, NULL, L"", NULL);

    MG_CATCH_AND_THROW(L"MgMappingService.GenerateMap")

    return NULL;
}

/////////////////////////////////////////////////////////////////
/// <summary>
/// Get the class Id
/// </summary>
/// <returns>
/// The integer value
/// </returns>
INT32 MgMappingService::GetClassId()
{
    return m_cls_id;
}

//////////////////////////////////////////////////////////////////
/// <summary>
/// Dispose this object
/// </summary>
/// <returns>
/// Nothing
/// </returns>
void MgMappingService::Dispose()
{
    delete this;
}
