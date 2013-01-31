#ifndef QTPLUGINSINTERFACE_H
#define QTPLUGINSINTERFACE_H

#include <QString>
#include "../common/ihostinterface.h"

//#include "../common/ihostinterface.h"

/*
class IHostInterface
{
public:
    virtual void debug(QString msg);
};

Q_DECLARE_INTERFACE(IHostInterface,
                    "net.wz2100.Plugin.QtPluginsHostInterface/0.0.1")
*/

class QtPluginsInterface
{
public:
    virtual ~QtPluginsInterface() {}
    virtual QString version() = 0;
    virtual QString name() = 0;
    virtual void setHostInterface(IHostInterface*);
};

Q_DECLARE_INTERFACE(QtPluginsInterface,
                    "net.wz2100.Plugin.QtPluginsInterface/0.0.1")

#endif // QTPLUGINSINTERFACE_H
