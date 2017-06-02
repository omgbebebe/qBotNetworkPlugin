cmake_minimum_required(VERSION 2.8.8)

set(PROJECT QBotNetworkPlugin)
project(${PROJECT})

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Network REQUIRED)
find_package(Qt5Core REQUIRED)

get_target_property(QtCore_location Qt5::Core LOCATION)
get_target_property(QtCore_location Qt5::Network LOCATION)

#include_directories(${Qt5Core_INCLUDES})
#include_directories(${Qt5Network_INCLUDES})

list(APPEND HEADERS ${PROJECT_SOURCE_DIR}/../warzone2100/lib/qtplugins/qtpluginsinterface.h ${PROJECT_SOURCE_DIR}/../warzone2100/lib/qtplugins/ihostinterface.h)
list(APPEND Q_HEADERS ${PROJECT_SOURCE_DIR}/qbotnetworkplugin.h json.h)

list(APPEND Q_SOURCES ${PROJECT_SOURCE_DIR}/qbotnetworkplugin.cpp json.cpp)
add_library( ${PROJECT} SHARED ${HEDARS} ${SOURCES} ${Q_HEDARS} ${Q_SOURCES} ${MOC_SOURCES})
target_link_libraries(${PROJECT} ${QT_LIBRARIES})
qt5_use_modules(${PROJECT} Core Network)

#FIND_PACKAGE(Qt5 REQUIRED)

#list(APPEND HEADERS ${PROJECT_SOURCE_DIR}/../warzone2100/lib/qtplugins/qtpluginsinterface.h ${PROJECT_SOURCE_DIR}/../warzone2100/lib/qtplugins/ihostinterface.h)
#list(APPEND Q_HEADERS ${PROJECT_SOURCE_DIR}/qbotnetworkplugin.h json.h)

#list(APPEND Q_SOURCES ${PROJECT_SOURCE_DIR}/qbotnetworkplugin.cpp json.cpp)

#qt5_wrap_cpp(MOC_SOURCES ${Q_HEADERS})
#qt5_automoc(${Q_SOURCES})

#find_package(Qt5 COMPONENTS QtCore QtNetwork REQUIRED)
#include(${QT_USE_FILE})

#link_directories(${CMAKE_CURRENT_BYNARY_DIR}/lib)

add_definitions(${QT_DEFINITIONS})
add_definitions(-DQT_PLUGIN)
add_definitions(-DQT_NO_DEBUG)
add_definitions(-DQT_SHARED)
add_definitions(-DQT_DLL)

# output path
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCES_DIR}../../../bin/protocols)

#executable module of tmpled

