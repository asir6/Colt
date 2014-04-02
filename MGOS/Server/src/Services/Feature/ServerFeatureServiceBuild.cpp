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

#include "FeatureOperation.cpp"
#include "FeatureOperationFactory.cpp"
#include "FeatureServiceHandler.cpp"
#include "OpAddSavePoint.cpp"
#include "OpApplySchema.cpp"
#include "OpCreateFeatureSource.cpp"
#include "OpDescribeSchema.cpp"
#include "OpDescribeSchemaAsXml.cpp"
#include "OpExecuteSqlNonQuery.cpp"
#include "OpExecuteSqlQuery.cpp"
#include "OpGetCapabilities.cpp"
#include "OpGetConnectionPropertyValues.cpp"
#include "OpGetFdoCacheInfo.cpp"
#include "OpGetFeatureProviders.cpp"
#include "OpGetSpatialContexts.cpp"
#include "OpReleaseSavePoint.cpp"
#include "OpRollbackSavePoint.cpp"
#include "OpSelectFeatures.cpp"
#include "OpSelectFeaturesSpatial.cpp"
#include "OpTestConnection.cpp"
#include "ServerCreateFeatureSource.cpp"
#include "OpTestFeatureSourceConnection.cpp"
#include "OpUpdateFeatures.cpp"
#include "ServerApplySchema.cpp"
#include "ServerDescribeSchema.cpp"
#include "ServerFeatureConnection.cpp"
#include "ServerFeatureService.cpp"
#include "ServerGetFeatureProviders.cpp"
#include "ServerGetProviderCapabilities.cpp"
#include "ServerSelectFeatures.cpp"
#include "OpCloseFeatureReader.cpp"
#include "OpGetFeatures.cpp"
#include "ServerFeatureReader.cpp"
#include "ServerFdoFeatureReader.cpp"
#include "ServerFeatureReaderPool.cpp"
#include "OpGetLongTransactions.cpp"
#include "ServerGetConnectionPropertyValues.cpp"
#include "ServerGetLongTransactions.cpp"
#include "ServerGetSpatialContexts.cpp"
#include "OpGetClassDefinition.cpp"
#include "OpGetClasses.cpp"
#include "OpGetSchemas.cpp"
#include "OpGetRaster.cpp"
#include "OpCloseSqlReader.cpp"
#include "OpGetSqlRows.cpp"
#include "ServerDataReaderPool.cpp"
#include "ServerFeatureUtil.cpp"
#include "ServerSqlCommand.cpp"
#include "ServerSqlDataReader.cpp"
#include "FeatureServiceCommand.cpp"
#include "FeatureDistribution.cpp"
#include "OpCloseDataReader.cpp"
#include "OpGetDataRows.cpp"
#include "SelectAggregateCommand.cpp"
#include "SelectCommand.cpp"
#include "ServerDataReader.cpp"
#include "ServerSqlDataReaderPool.cpp"
#include "FeatureNumericFunctions.cpp"
#include "FeatureStringFunctions.cpp"
#include "FeatureGeometricFunctions.cpp"
#include "FeatureManipulationCommand.cpp"
#include "ServerDeleteCommand.cpp"
#include "ServerInsertCommand.cpp"
#include "ServerUpdateCommand.cpp"
#include "ServerUpdateFeatures.cpp"
#include "OpSchemaToXml.cpp"
#include "OpXmlToSchema.cpp"
#include "ByteSourceRasterStreamImpl.cpp"
#include "OpGetIdentityProperties.cpp"
#include "OpDescribeWfsFeatureType.cpp"
#include "OpGetWfsFeature.cpp"
#include "FilterUtil.cpp"
#include "ServerGwsFeatureReader.cpp"
#include "GwsConnectionPool.cpp"
#include "OpEnumerateDataStores.cpp"
#include "OpGetSchemaMapping.cpp"
#include "ServerEnumerateDataStores.cpp"
#include "ServerGetSchemaMapping.cpp"
#include "OpSetLongTransaction.cpp"
#include "MgCSTrans.cpp"
#include "TransformCache.cpp"
#include "JoinFeatureReader.cpp"
#include "FdoReaderCollection.cpp"
#include "FdoFilterCollection.cpp"
#include "FdoFeatureReader.cpp"
#include "FdoForcedOneToOneFeatureReader.cpp"
#include "ServerFeatureTransactionPool.cpp"
#include "ServerFeatureTransaction.cpp"
#include "OpBeginTransaction.cpp"
#include "OpCommitTransaction.cpp"
#include "OpRollbackTransaction.cpp"
#include "OpUpdateFeaturesWithTransaction.cpp"
