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
 * @file Front.h
 * @author: shawnhe
 * @date 2022-10-20
 */

#pragma once
#include "FrontImpl.h"
#include "ppc-framework/front/FrontInterface.h"
#include "ppc-framework/protocol/PPCMessageFace.h"

namespace ppc::front
{
class Front : public FrontInterface, public std::enable_shared_from_this<Front>
{
public:
    using Ptr = std::shared_ptr<Front>;
    Front(FrontImpl::Ptr front) : m_front(std::move(front)) {}
    ~Front() override {}

    /**
     * @brief: send message to other party by gateway
     * @param _agencyID: agency ID of receiver
     * @param _message: ppc message data
     * @param _callback: callback called when the message sent successfully
     * @param _respCallback: callback called when receive the response from peer
     * @return void
     */
    void asyncSendMessage(const std::string& _agencyID, front::PPCMessageFace::Ptr _message,
        uint32_t _timeout, ErrorCallbackFunc _callback, CallbackFunc _respCallback) override;

    // send response when receiving message from given agencyID
    void asyncSendResponse(const std::string& _agencyID, std::string const& _uuid,
        front::PPCMessageFace::Ptr _message, ErrorCallbackFunc _callback) override;

    /**
     * @brief notice task info to gateway
     * @param _taskInfo the latest task information
     */
    bcos::Error::Ptr notifyTaskInfo(std::string const& taskID) override;

    // erase the task-info when task finished
    bcos::Error::Ptr eraseTaskInfo(std::string const& _taskID) override;

    // get the agencyList from the gateway
    void asyncGetAgencyList(GetAgencyListCallback _callback) override;

    // register message handler for algorithm
    void registerMessageHandler(uint8_t _taskType, uint8_t _algorithmType,
        std::function<void(front::PPCMessageFace::Ptr)> _handler)
    {
        uint16_t type = ((uint16_t)_taskType << 8) | _algorithmType;
        auto self = weak_from_this();
        m_front->registerTopicHandler(
            std::to_string(type), [self, _handler](ppc::protocol::Message::Ptr msg) {
                auto front = self.lock();
                if (!front)
                {
                    return;
                }
                if (msg == nullptr)
                {
                    _handler(nullptr);
                    return;
                }
                _handler(front->m_messageFactory->buildPPCMessage(msg));
            });
    }

private:
    FrontImpl::Ptr m_front;
    ppc::front::PPCMessageFaceFactory::Ptr m_messageFactory;
};
}  // namespace ppc::front