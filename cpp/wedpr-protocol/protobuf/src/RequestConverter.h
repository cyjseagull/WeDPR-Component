/**
 *  Copyright (C) 2021 FISCO BCOS.
 *  SPDX-License-Identifier: Apache-2.0
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 * @file RequestConverter.h
 * @author: yujiechen
 * @date 2021-04-12
 */
#pragma once
#include "Service.pb.h"
#include "ppc-framework/protocol/INodeInfo.h"
#include "ppc-framework/protocol/Message.h"
#include "ppc-framework/protocol/Protocol.h"
#include <bcos-utilities/Common.h>
#include <bcos-utilities/Error.h>
#include <grpcpp/grpcpp.h>
#include <memory>

namespace ppc::protocol
{
inline MessageOptionalHeader::Ptr generateRouteInfo(
    MessageOptionalHeaderBuilder::Ptr const& routeInfoBuilder,
    ppc::proto::RouteInfo const& serializedRouteInfo)
{
    auto routeInfo = routeInfoBuilder->build();
    routeInfo->setComponentType(serializedRouteInfo.componenttype());
    routeInfo->setSrcNode(
        bcos::bytes(serializedRouteInfo.srcnode().begin(), serializedRouteInfo.srcnode().end()));
    routeInfo->setDstNode(
        bcos::bytes(serializedRouteInfo.dstnode().begin(), serializedRouteInfo.dstnode().end()));
    routeInfo->setDstInst(serializedRouteInfo.dstinst());
    routeInfo->setTopic(serializedRouteInfo.topic());
    return routeInfo;
}

inline void setRouteInfo(
    ppc::proto::RouteInfo* route_info, MessageOptionalHeader::Ptr const& routeInfo)
{
    // set the route information
    route_info->set_topic(routeInfo->topic());
    route_info->set_componenttype(routeInfo->componentType());
    *(route_info->mutable_srcnode()) =
        std::string((const char*)routeInfo->srcNode().data(), routeInfo->srcNode().size());
    *(route_info->mutable_dstnode()) =
        std::string((const char*)routeInfo->dstNode().data(), routeInfo->dstNode().size());
    *(route_info->mutable_dstinst()) = routeInfo->dstInst();
}

inline ppc::proto::SendedMessageRequest* generateRequest(std::string const& traceID,
    RouteType routeType, MessageOptionalHeader::Ptr const& routeInfo, bcos::bytes&& payload,
    long timeout)
{
    auto request = new ppc::proto::SendedMessageRequest();
    request->set_traceid(traceID);
    request->set_routetype(uint16_t(routeType));
    // set the route information
    setRouteInfo(request->mutable_routeinfo(), routeInfo);
    *request->mutable_payload() =
        std::move(std::string_view((const char*)payload.data(), payload.size()));
    request->set_timeout(timeout);
    return request;
}

inline ppc::proto::SelectRouteRequest* generateSelectRouteRequest(
    RouteType routeType, MessageOptionalHeader::Ptr const& routeInfo)
{
    auto request = new ppc::proto::SelectRouteRequest();
    request->set_routetype(uint16_t(routeType));
    // set the route information
    setRouteInfo(request->mutable_routeinfo(), routeInfo);
    return request;
}

inline ppc::proto::NodeInfo* toNodeInfoRequest(
    bcos::bytesConstRef const& nodeID, std::string const& topic)
{
    auto request = new ppc::proto::NodeInfo();
    *(request->mutable_nodeid()) = std::string_view((const char*)nodeID.data(), nodeID.size());
    request->set_topic(topic);
    return request;
}

inline void toNodeInfoRequest(ppc::proto::NodeInfo* request, INodeInfo::Ptr const& nodeInfo)
{
    if (!nodeInfo)
    {
        return;
    };
    *(request->mutable_nodeid()) =
        std::string_view((const char*)nodeInfo->nodeID().data(), nodeInfo->nodeID().size());
    request->set_endpoint(nodeInfo->endPoint());
    auto const& components = nodeInfo->components();
    for (auto const& component : components)
    {
        request->add_components(component);
    }
    request->set_meta(nodeInfo->meta());
}

inline void toRawNodeInfoList(
    ppc::proto::NodeInfoList* rawNodeInfoList, std::vector<INodeInfo::Ptr> const& nodeInfoList)
{
    for (auto const& it : nodeInfoList)
    {
        auto rawNodeInfo = rawNodeInfoList->add_nodelist();
        toNodeInfoRequest(rawNodeInfo, it);
    }
}

inline INodeInfo::Ptr toNodeInfo(
    INodeInfoFactory::Ptr const& nodeInfoFactory, ppc::proto::NodeInfo const& serializedNodeInfo)
{
    auto nodeInfo = nodeInfoFactory->build();
    nodeInfo->setNodeID(bcos::bytesConstRef(
        (bcos::byte*)serializedNodeInfo.nodeid().data(), serializedNodeInfo.nodeid().size()));
    nodeInfo->setEndPoint(serializedNodeInfo.endpoint());
    std::set<std::string> componentTypeList;
    for (int i = 0; i < serializedNodeInfo.components_size(); i++)
    {
        componentTypeList.insert(serializedNodeInfo.components(i));
    }
    nodeInfo->setComponents(componentTypeList);
    nodeInfo->setMeta(serializedNodeInfo.meta());
    return nodeInfo;
}

inline std::vector<INodeInfo::Ptr> toNodeInfoList(INodeInfoFactory::Ptr const& nodeInfoFactory,
    ppc::proto::NodeInfoList const& serializedNodeListInfo)
{
    std::vector<INodeInfo::Ptr> result;
    for (int i = 0; i < serializedNodeListInfo.nodelist_size(); i++)
    {
        result.emplace_back(toNodeInfo(nodeInfoFactory, serializedNodeListInfo.nodelist(i)));
    }
    return result;
}

inline bcos::Error::Ptr toError(grpc::Status const& status, ppc::proto::Error const& error)
{
    if (!status.ok())
    {
        return std::make_shared<bcos::Error>((int32_t)status.error_code(), status.error_message());
    }
    if (error.errorcode() == 0)
    {
        return nullptr;
    }
    return std::make_shared<bcos::Error>(error.errorcode(), error.errormessage());
}

inline void toSerializedError(ppc::proto::Error* serializedError, bcos::Error::Ptr error)
{
    if (!serializedError)
    {
        return;
    }
    if (!error)
    {
        serializedError->set_errorcode(PPCRetCode::SUCCESS);
        return;
    }
    serializedError->set_errorcode(error->errorCode());
    serializedError->set_errormessage(error->errorMessage());
}
};  // namespace ppc::protocol