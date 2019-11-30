cmake_minimum_required(VERSION 3.5)

project(KavenegarLib LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CPP_SOURCE
    *.cpp *hpp
)

file(GLOB_RECURSE SRCS ${CPP_SOURCE})

add_library(KavenegarLib STATIC
  ${SRCS}
)

INCLUDE_DIRECTORIES(/lib/curl/7.67.0/include/)
LINK_DIRECTORIES(/lib/curl/7.67.0/lib/)
INCLUDE_DIRECTORIES(/lib/rapidjson-master/include/) #RapidJson is header only!
