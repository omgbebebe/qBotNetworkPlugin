//#include <QtGui>
#include <QtPlugin>
#include "qbotnetworkplugin.h"
#include "../common/qtpluginsinterface.h"

void QBotNetworkPlugin::startServer()
{
    debug("Starting network server");
    tcpServer = new QTcpServer(this);
    if (!tcpServer){
        debug("FAILED");
    }
    debug("OK");
}

void QBotNetworkPlugin::onLoad()
{
    this->startServer();
}

QString QBotNetworkPlugin::version()
{
    debug("called version function");
    debug("getting all visible units");
    QList<Unit*> units = iHost->getUnits();
    debug(QString("recieved %1 units").arg(units.length()));
    for (int i = 0; i < units.length(); i++){
        Unit *u = units.at(i);
        debug(QString("unit (%1): pos=(%2, %3, %4)").arg(u->id).arg(u->x).arg(u->y).arg(u->z));
    }
    return "0.0.1";
}

void QBotNetworkPlugin::debug(QString msg)
{
    iHost->debug(msg);
}

QString QBotNetworkPlugin::name()
{
    debug("called name function");
    return "BotNetwork interface";
}

Q_EXPORT_PLUGIN2(qbotnetworkplugin, QBotNetworkPlugin)
