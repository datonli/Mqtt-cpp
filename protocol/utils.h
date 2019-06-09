
#pragma once

#include "status.h"
#include "message.h"
#include <string>

namespace mqtt
{
   class MqttUtils {
       public :
        MqttStatus  MqttSerialize(const Message &mqtt_message, std::string *out);
   } ;
} // namespace mqtt
