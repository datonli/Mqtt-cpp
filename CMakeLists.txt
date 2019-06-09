cmake_minimum_required(VERSION 2.8)
project(mqtt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++11")
set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -ldl")
set(MQTT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(
	${MQTT_DIR}/protocol
)

set(ProtocolExample example/protocol_example.cpp)

add_executable(protocol_example ${ProtocolExample})