
#pragma once

#include <string>

namespace mqtt {

class MqttStatus {
 public:
  enum ErrorCode {
    kOk = 0,
    kSerializerError = -1001,
    kParseError = -1002,
  };

  MqttStatus() : code_(kOk), message_("") {}
  MqttStatus(ErrorCode code, const std::string &message)
      : code_(code), message_(message) {}

  void SetCode(ErrorCode code) { code_ = code; }
  void SetMessage(const std::string &message) { message_ = message; }

    bool Ok() { return code_ == kOk;}
  std::string ToString() { return message_; }

 private:
  ErrorCode code_;
  std::string message_;
};
}  // namespace mqtt