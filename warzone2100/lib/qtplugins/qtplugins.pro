TEMPLATE   = lib

CONFIG    += plugin
QT        += network
DESTDIR    = build

SOURCES    = qtplugins.cpp \
             qtpluginsengine.cpp

HEADERS    = qtpluginsengine.h \
             qtplugins.h \
             qtpluginsinterface.h \
             qtpluginsunitsdefs.h

TARGET     = qtplugins
