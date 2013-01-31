#ifndef IHOSTINTERFACE_H
#define IHOSTINTERFACE_H

#include <QString>

class IHostInterface
{
public:
    virtual ~IHostInterface() {}
    virtual void debug(QString msg) = 0;
};

Q_DECLARE_INTERFACE(IHostInterface,
                    "net.wz2100.Plugin.QtPluginsHostInterface/0.0.1")

#endif // IHOSTINTERFACE_H
