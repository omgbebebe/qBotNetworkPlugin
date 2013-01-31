#ifndef QBOTNETWORKPLUGIN_H
#define QBOTNETWORKPLUGIN_H

#include <QObject>
#include "../common/qtpluginsinterface.h"
#include "../common/ihostinterface.h"

class QBotNetworkPlugin : public QObject, QtPluginsInterface
{
    Q_OBJECT
    Q_INTERFACES(QtPluginsInterface)
public:
//    QBotNetworkPlugin(IHostInterface *host) : iHost (host) {}
    QString version();
    QString name();
    void setHostInterface(IHostInterface *host) {iHost = host;}
    
signals:
    
public slots:
private:
    IHostInterface *iHost;
};

#endif // QBOTNETWORKPLUGIN_H
