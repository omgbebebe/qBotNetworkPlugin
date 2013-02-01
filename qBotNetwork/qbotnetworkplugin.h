#ifndef QBOTNETWORKPLUGIN_H
#define QBOTNETWORKPLUGIN_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

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

    // pluginLoader events
    void onLoad();
    // game events
    void onStart() {}
    void onEnd(bool) {}
    void onFrame() {}
    void onUnitAttacked(Unit*) {}
    void onUnitDiscover(Unit*) {}
    void onUnitEvade(Unit*) {}
    void onUnitDestroy(Unit*) {}
    void onResearchComplete(UnitId) {}
    void onProductionComplete(UnitId) {}

signals:
    
public slots:
    void startServer();
private slots:
    void clientConnected();
    void readFromSocket();

private:
    IHostInterface *iHost;
    QTcpServer *tcpServer;
    QTcpSocket *socket;
    quint16 blockSize;
    void debug(QString);
};

#endif // QBOTNETWORKPLUGIN_H
