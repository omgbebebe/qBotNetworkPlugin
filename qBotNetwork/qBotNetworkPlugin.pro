TEMPLATE = lib
CONFIG   += plugin
QT       += network
DESTDIR  = ../plugins
SOURCES  = qbotnetworkplugin.cpp
HEADERS  = qbotnetworkplugin.h \
           ../common/qtpluginsinterface.h \
    qbotnetworkplugin.h
TARGET   = qbotnetwork
