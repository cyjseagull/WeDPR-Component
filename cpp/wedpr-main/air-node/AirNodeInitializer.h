/**
 *  Copyright (C) 2022 WeDPR.
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
 * @file AirNodeInitializer.h
 * @author: yujiechen
 * @date 2022-11-14
 */
#pragma once
#include "ppc-framework/front/IFront.h"
#include "ppc-framework/gateway/IGateway.h"
#include "wedpr-initializer/Common.h"
#include "wedpr-initializer/Initializer.h"
#include <bcos-utilities/BoostLogInitializer.h>
#include <memory>
namespace ppc::rpc
{
class Rpc;
}
namespace ppc::front
{
class LocalFrontBuilder;
}
namespace ppc::node
{
class AirNodeInitializer
{
public:
    using Ptr = std::shared_ptr<AirNodeInitializer>;
    AirNodeInitializer();
    virtual ~AirNodeInitializer() { stop(); }

    virtual void init(std::string const& _configPath);
    virtual void start();
    virtual void stop();

protected:
    virtual void initGateway(std::string const& _configPath);

private:
    bcos::BoostLogInitializer::Ptr m_logInitializer;
    ppc::initializer::Initializer::Ptr m_nodeInitializer;
    ppc::gateway::IGateway::Ptr m_gateway;
    std::shared_ptr<ppc::rpc::Rpc> m_rpc;
    std::shared_ptr<ppc::front::LocalFrontBuilder> m_frontBuilder;
};
}  // namespace ppc::node