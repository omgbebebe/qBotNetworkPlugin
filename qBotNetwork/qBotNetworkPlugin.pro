TEMPLATE = lib
CONFIG   += plugin
QT       += network core
DESTDIR  = ../plugins
SOURCES  = qbotnetworkplugin.cpp
HEADERS  = qbotnetworkplugin.h \
           ../warzone2100/lib/qtplugins/qtpluginsinterface.h \
    qbotnetworkplugin.h
TARGET   = qbotnetwork
