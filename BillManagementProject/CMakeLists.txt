cmake_minimum_required(VERSION 3.17)
project(BillManagementProject)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(dist/json)
include_directories(include)
include_directories(include/json)

add_executable(BillManagementProject main.cpp
        dist/json/json-forwards.h
        dist/json/json.h
        dist/jsoncpp.cpp
        include/json/allocator.h
        include/json/assertions.h
        include/json/config.h
        include/json/forwards.h
        include/json/json.h
        include/json/json_features.h
        include/json/reader.h
        include/json/value.h
        include/json/version.h
        include/json/writer.h
        Creditor.cpp
        Creditor.h
        Login.cpp
        Login.h
        Notification.cpp
        Notification.h
        User.cpp
        User.h)
