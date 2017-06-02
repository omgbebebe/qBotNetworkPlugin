#ifndef QBOTNETWORKPLUGIN_H
#define QBOTNETWORKPLUGIN_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>

#include "../warzone2100/lib/qtplugins/qtpluginsinterface.h"

class QBotNetworkPlugin : public QObject, IPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "ru.3712.warzone.plugins.QBotNetworkPlugin" FILE "QBotNetworkPlugin.json")
    Q_INTERFACES(IPluginInterface)
public:
    QBotNetworkPlugin();
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
    void onUnitAttacked(UnitId) {}
    void onUnitDiscover(UnitId) {}
    void onUnitEvade(UnitId) {}
    void onUnitDestroy(UnitId) {}
    void onResearchComplete(UnitId) {}
    void onProductionComplete(UnitId) {}

signals:
    
public slots:
    void startServer();
private slots:
    void clientConnected();
    void clientDisconnected();
    void readFromSocket();

private:
    quint16 apiMagic;
    IHostInterface *iHost;
    QTcpServer *tcpServer;
    QTcpSocket *socket;
    QDataStream *in;
    QDataStream *out;
    quint16 blockSize;
    QMap<QString, quint8> cmds;
    void dbg(QString);
    QVariantMap parseJSON(QString json);
    QVariantMap toVariantMap(const Unit *u);
    void send(QByteArray *msg);
};

#endif // QBOTNETWORKPLUGIN_H
