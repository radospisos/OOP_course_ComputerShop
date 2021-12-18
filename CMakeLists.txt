cmake_minimum_required(VERSION 3.17)
project(CompShop)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE cli_sources "src/cli/*.cpp")
file(GLOB_RECURSE cli_headers "src/cli/*.h")

file(GLOB_RECURSE core_sources "src/core/*.cpp")
file(GLOB_RECURSE core_headers "src/core/*.h")

file(GLOB main "main.cpp")

include_directories(src/core)
include_directories(src/cli)

######## BOOST ########

set(Boost_USE_STATIC_LIBS       ON)
set(Boost_USE_DEBUG_LIBS        OFF)
set(Boost_USE_RELEASE_LIBS      ON)
set(Boost_USE_MULTITHREADED     ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost 1.74.0 COMPONENTS date_time REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

######## PROTOBUF ########

message("proto in ${Protobuf_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR}")
find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

file(GLOB_RECURSE PROTO_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/proto/*.proto")
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SOURCES})
message("generated ${PROTO_SRCS} ${PROTO_HDRS}")

SET_SOURCE_FILES_PROPERTIES(${PROTO_SRCS} ${PROTO_HDRS} PROPERTIES GENERATED TRUE)

add_executable(CompShop ${main} ${cli_headers} ${cli_sources} ${core_sources} ${core_headers}
        ${PROTO_SRCS} ${PROTO_HDRS})

target_link_libraries(CompShop ${Boost_LIBRARIES} ${Protobuf_LIBRARIES})
