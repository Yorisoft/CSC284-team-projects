# Install script for directory: C:/Users/Yelsin S/Documents/code/my-gh/CSC284-team-projects/BillManagementProject/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/Yelsin S/Documents/code/my-gh/CSC284-team-projects/BillManagementProject/include/out/install/x64-Debug (default)")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/json/allocator.h;/json/assertions.h;/json/config.h;/json/forwards.h;/json/json.h;/json/json_features.h;/json/reader.h;/json/value.h;/json/version.h;/json/writer.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/json" TYPE FILE FILES
    "C:/Users/Yelsin S/Documents/code/my-gh/CSC284-team-projects/BillManagementProject/include/json/allocator.h"
    "C:/Users/Yelsin S/Documents/code/my-gh/CSC284-team-projects/BillManagementProject/include/json/assertions.h"
    "C:/Users/Yelsin S/Documents/code/my-gh/CSC284-team-projects/BillManagementProject/include/json/config.h"
    "C:/Users/Yelsin S/Documents/code/my-gh/CSC284-team-projects/BillManagementProject/include/json/forwards.h"
    "C:/Users/Yelsin S/Documents/code/my-gh/CSC284-team-projects/BillManagementProject/include/json/json.h"
    "C:/Users/Yelsin S/Documents/code/my-gh/CSC284-team-projects/BillManagementProject/include/json/json_features.h"
    "C:/Users/Yelsin S/Documents/code/my-gh/CSC284-team-projects/BillManagementProject/include/json/reader.h"
    "C:/Users/Yelsin S/Documents/code/my-gh/CSC284-team-projects/BillManagementProject/include/json/value.h"
    "C:/Users/Yelsin S/Documents/code/my-gh/CSC284-team-projects/BillManagementProject/include/json/version.h"
    "C:/Users/Yelsin S/Documents/code/my-gh/CSC284-team-projects/BillManagementProject/include/json/writer.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/Yelsin S/Documents/code/my-gh/CSC284-team-projects/BillManagementProject/include/out/build/x64-Debug (default)/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
