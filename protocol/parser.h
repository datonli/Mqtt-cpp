
#pragma once

#include "status.h"
namespace mqtt
{
    enum class ParserState {
        kUnknown = 0,
        kInitial = 1,
        kRemainingLength = 2,
        kVariableHeader = 3,
        kConnect = 4,
        kConnectProtocolName = 5,
        kConnectProtocolVersion = 6,
        kConnectFlags = 7,
        kConnectKeepAlive = 8,
        kConnectClientIdentifier = 9,
        kConnectWillTopic = 10,
        kConnectWillMessage = 11,
        kConnectUsername = 12,
        kConnectPassword = 13,
        kConnack = 14,
        kPublish = 15,
        kPublishTopicName = 16,
        kPublishMessageId = 17, 
        kPuback  = 18,
        kPubrel = 19,
        kPubcomp = 20,
    };
class Parser {
public:
    Parser() : state_(ParserState::kUnknown) {}
    ~Parser() {}

private:
    ParserState state_;
};
} // namespace name
