PROJECT(TestSuite)

cmake_minimum_required(VERSION 2.8)

FIND_PACKAGE(Qt4 REQUIRED)

SET(testsuite_SOURCES main.cpp mainwindow.cpp)
SET(testsuite_HEADERS mainwindow.h ../common/ihostinterface.h ../common/qtpluginsinterface.h)
SET(testsuite_FORMS mainwindow.ui)
QT4_WRAP_CPP(testsuite_HEADERS_MOC ${testsuite_HEADERS})
QT4_WRAP_UI(testsuite_FORMS_HEADERS ${testsuite_FORMS})

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

ADD_EXECUTABLE(testsuite ${testsuite_SOURCES} ${testsuite_HEADERS_MOC} ${testsuite_FORMS_HEADERS} )
TARGET_LINK_LIBRARIES(testsuite ${QT_LIBRARIES})
