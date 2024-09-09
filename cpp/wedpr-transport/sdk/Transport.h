/**
 *  Copyright (C) 2023 WeDPR.
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
 * @file Transport.h
 * @author: yujiechen
 * @date 2024-09-04
 */
#pragma once
#include "ppc-framework/front/IFront.h"
#include "ppc-framework/gateway/IGateway.h"
namespace ppc::sdk
{
class Transport
{
public:
    using Ptr = std::shared_ptr<Transport>;
    Transport() = default;
    virtual ~Transport() = default;

    virtual void start() { m_front->start(); }
    virtual void stop() { m_front->stop(); }

    virtual ppc::front::IFront::Ptr const& getFront() const { return m_front; }

    virtual ppc::gateway::IGateway::Ptr const& gateway() const { return m_gateway; }

protected:
    ppc::front::IFront::Ptr m_front;
    ppc::gateway::IGateway::Ptr m_gateway;
};
}  // namespace ppc::sdk