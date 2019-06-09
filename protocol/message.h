#pragma once

#include <string>
#include <cstring>

namespace mqtt {

enum class MessageType {
  kUnknown = 0,
  kConnect = 1,
  kConnack = 2,
  kPublish = 3,
  kPuback = 4,
  kPubrec = 5,
  kPubrel = 6,
  kPubcomp = 7,
  kSubscribe = 8,
  kSuback = 9,
  kUnsubscribe = 10,
  kUnsuback = 11,
  kPingreq = 12,
  kPingresp = 13,
  kDisconnect = 14,
};

enum RetainFlag { kRetailFlase = 0, kRetailTrue = 1, };

enum QosType {
    kQosUnknown = 0,
    kAtMostOnce = 1,
    kAtLeastOnce = 2,
    kExactlyOnce =3,
};

enum DupFlag {
    kDupFalse = 0,
    kDupTrue = 1,
};

typedef struct mqtt_topic_s {
  struct mqtt_topic_s* next;
  std::string name;
} mqtt_topic_t;

typedef struct mqtt_topicpair_s {
  struct mqtt_topicpair_s* next;
  std::string name;
  QosType qos;
} mqtt_topicpair_t;

#define MQTT_MESSAGE_COMMON_FIELDS \
  RetainFlag retain; \
  QosType qos; \
  DupFlag dup; \
  MessageType type; \
  uint32_t length;

  struct Common {
    MQTT_MESSAGE_COMMON_FIELDS
  } ;

  struct Connect {
    MQTT_MESSAGE_COMMON_FIELDS

    std::string protocol_name;
    uint8_t protocol_version;

    struct {
      char username_follows;
      char password_follows;
      char will_retain;
      char will_qos;
      char will;
      char clean_session;
    } flags;

    uint16_t keep_alive;

    std::string client_id;

    std::string will_topic;
    std::string will_message;

    std::string username;
    std::string password;
  } ;

  struct Connack{
    MQTT_MESSAGE_COMMON_FIELDS

    uint8_t _unused;
    uint8_t return_code;
  } ;

  struct Publish{
    MQTT_MESSAGE_COMMON_FIELDS

    std::string topic_name;
    uint16_t message_id;

    std::string content;
  } ;

  struct Puback{
    MQTT_MESSAGE_COMMON_FIELDS

    uint16_t message_id;
  } ;

  struct Pubrec{
    MQTT_MESSAGE_COMMON_FIELDS

    uint16_t message_id;
  } ;

  struct Pubrel{
    MQTT_MESSAGE_COMMON_FIELDS

    uint16_t message_id;
  } ;

  struct Pubcomp{
    MQTT_MESSAGE_COMMON_FIELDS

    uint16_t message_id;
  } ;

  struct Subscribe{
    MQTT_MESSAGE_COMMON_FIELDS

    uint16_t message_id;
    mqtt_topicpair_t* topics;
  } ;

  struct Suback{
    MQTT_MESSAGE_COMMON_FIELDS

    uint16_t message_id;
    mqtt_topicpair_t* topics;
  } ;

  struct Unsubscribe{
    MQTT_MESSAGE_COMMON_FIELDS

    uint16_t message_id;
    mqtt_topic_t* topics;
  } ;

  struct Unsuback{
    MQTT_MESSAGE_COMMON_FIELDS

    uint16_t message_id;
  } ;

  struct Pingreq{
    MQTT_MESSAGE_COMMON_FIELDS
  } ;

  struct Pingresp{
    MQTT_MESSAGE_COMMON_FIELDS
  } ;

  struct Disconnect{
    MQTT_MESSAGE_COMMON_FIELDS
  } ;

  struct MessageBody {
      Common common;
Connect connect;
Connack connack;
Publish publish;
Puback puback;
Pubrec pubrec;
Pubrel pubrel;
Pubcomp pubcomp;
Subscribe subscribe;
Suback suback;
Unsubscribe unsubscribe;
Unsuback unsuback;
Pingreq pingreq;
Pingresp pingresp;
      Disconnect disconnect;
  };

class Message {
 public:
  Message() : type_(MessageType::kUnknown), body_(new MessageBody) { 
      std::memset(body_, 0, sizeof(MessageBody));
  }
  ~Message() {
      if (!body_) {
          delete body_;
      }
  }
    std::string ToString();
 private:
    MessageType type_;
    MessageBody* body_;
};

}  // namespace mqtt
