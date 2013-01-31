#ifndef QTPLUGINSINTERFACE_H
#define QTPLUGINSINTERFACE_H

#include <QString>

class QtPluginsInterface
{
public:
    virtual ~QtPluginsInterface() {}
    virtual QString version() = 0;
    virtual QString name() = 0;
};

Q_DECLARE_INTERFACE(QtPluginsInterface,
                    "net.wz2100.Plugin.QtPluginsInterface/0.0.1")

#endif // QTPLUGINSINTERFACE_H
