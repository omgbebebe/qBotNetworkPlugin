#PROJECT(TestSuite)

#cmake_minimum_required(VERSION 2.8)

#FIND_PACKAGE(Qt4 QtScript REQUIRED)

#SET(testsuite_SOURCES main.cpp mainwindow.cpp)
#SET(testsuite_HEADERS mainwindow.h ../common/ihostinterface.h ../common/qtpluginsinterface.h)
#SET(testsuite_FORMS mainwindow.ui)
#QT4_WRAP_CPP(testsuite_HEADERS_MOC ${testsuite_HEADERS})
#QT4_WRAP_UI(testsuite_FORMS_HEADERS ${testsuite_FORMS})

#INCLUDE(${QT_USE_FILE})
#ADD_DEFINITIONS(${QT_DEFINITIONS})
#INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

#ADD_EXECUTABLE(testsuite ${testsuite_SOURCES} ${testsuite_HEADERS_MOC} ${testsuite_FORMS_HEADERS} )
#TARGET_LINK_LIBRARIES(testsuite ${QT_LIBRARIES})

cmake_minimum_required(VERSION 2.8)

set(PROJECT TestSuite)
project(${PROJECT})

FIND_PACKAGE(Qt4 REQUIRED)

#SET (LIBRARY_OUTPUT_PATH ${QBotNetwork_BINARY_DIR}/plugins/)

list(APPEND HEADERS ${PROJECT_SOURCE_DIR}/../common/qtpluginsinterface.h ${PROJECT_SOURCE_DIR}/../common/ihostinterface.h)
list(APPEND Q_HEADERS ${PROJECT_SOURCE_DIR}/mainwindow.h )

#list(APPEND SOURCES ${PROJECT_SOURCE_DIR}/../../../../k095-common/zutils.cpp)
list(APPEND Q_SOURCES ${PROJECT_SOURCE_DIR}/main.cpp ${PROJECT_SOURCE_DIR}/mainwindow.cpp)
list(APPEND Q_FORMS ${PROJECT_SOURCE_DIR}/mainwindow.ui)

qt4_wrap_ui(Q_FORMS_HEADERS ${Q_FORMS})
qt4_wrap_cpp(MOC_SOURCES ${Q_HEADERS})
qt4_automoc(${Q_SOURCES})

find_package(Qt4 COMPONENTS QtGui QtCore QtNetwork QtScript REQUIRED)
include(${QT_USE_FILE})

include_directories(${PROJECT_SOURCE_DIR}/../commoni ${CMAKE_CURRENT_BINARY_DIR} )

link_directories(${CMAKE_CURRENT_BYNARY_DIR}/bin)

add_definitions(${QT_DEFINITIONS})
#add_definitions(-DQT_PLUGIN)
add_definitions(-DQT_NO_DEBUG)
#add_definitions(-DQT_SHARED)
#add_definitions(-DQT_DLL)

# output path
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCES_DIR}../../../bin/protocols)

ADD_EXECUTABLE(${PROJECT} ${MOC_SOURCES} ${Q_SOURCES} ${Q_HEADERS_MOC} ${Q_FORMS_HEADERS} )
target_link_libraries(${PROJECT} ${QT_LIBRARIES})
