cmake_minimum_required(VERSION 2.8)

set(PROJECT QBotNetworkPlugin)
project(${PROJECT})

FIND_PACKAGE(Qt4 REQUIRED)

#SET (LIBRARY_OUTPUT_PATH ${QBotNetwork_BINARY_DIR}/plugins/)

list(APPEND HEADERS ${PROJECT_SOURCE_DIR}/../common/qtpluginsinterface.h ${PROJECT_SOURCE_DIR}/../common/ihostinterface.h)
list(APPEND Q_HEADERS ${PROJECT_SOURCE_DIR}/qbotnetworkplugin.h)

#list(APPEND SOURCES ${PROJECT_SOURCE_DIR}/../../../../k095-common/zutils.cpp)
list(APPEND Q_SOURCES ${PROJECT_SOURCE_DIR}/qbotnetworkplugin.cpp)

qt4_wrap_cpp(MOC_SOURCES ${Q_HEADERS})
qt4_automoc(${Q_SOURCES})

find_package(Qt4 COMPONENTS QtCore QtNetwork REQUIRED)
include(${QT_USE_FILE})

#add_definitions(-DQT_NO_CAST_FROM_ASCII -DQT_NO_CAST_TO_ASCII)

include_directories(${PROJECT_SOURCE_DIR}/../common)
#include_directories(${PROJECT_SOURCE_DIR}/../../kernel)

link_directories(${CMAKE_CURRENT_BYNARY_DIR}/lib)

add_definitions(${QT_DEFINITIONS})
add_definitions(-DQT_PLUGIN)
add_definitions(-DQT_NO_DEBUG)
add_definitions(-DQT_SHARED)
add_definitions(-DQT_DLL)

# output path
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCES_DIR}../../../bin/protocols)

#executable module of tmpled
add_library( ${PROJECT} SHARED ${HEDARS} ${SOURCES} ${Q_HEDARS} ${Q_SOURCES} ${MOC_SOURCES})
#target_link_libraries(${PROJECT} ${QT_LIBRARIES} "k095_kernel")
target_link_libraries(${PROJECT} ${QT_LIBRARIES})

