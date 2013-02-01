//#include <QtGui>
#include <QtPlugin>
#include <QDataStream>
#include <QTcpSocket>
#include "qbotnetworkplugin.h"
#include "../common/qtpluginsinterface.h"

void QBotNetworkPlugin::readFromSocket()
{
    debug(QString("reading message of %1 bytes length").arg(socket->bytesAvailable()));
    if (socket->bytesAvailable() < 2) // header not received
        return;

    blockSize = 1;
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_0);
    if (blockSize == 0) {

        in >> blockSize;
    }

    if (socket->bytesAvailable() < blockSize)
        return;

    QString msg;
    in >> msg;
    debug(QString("received new message: %1").arg(msg));
//    blockSize = 0;
}

void QBotNetworkPlugin::clientConnected()
{
    debug("new incoming connection");
    blockSize = 0;
    socket = tcpServer->nextPendingConnection();
    if (!socket){
        debug(QString("can't get socket description: %1").arg(tcpServer->errorString()));
    }
    debug("connected");
    connect(socket, SIGNAL(readyRead()), this, SLOT(readFromSocket()));
}

void QBotNetworkPlugin::startServer()
{
    debug("Starting network server");
    tcpServer = new QTcpServer(this);
    if (!tcpServer){
        debug("FAILED");
    }
    QHostAddress hostadd("127.0.0.1");
    if (!tcpServer->listen(hostadd,5566)) {
        debug(QString("Unable to start the server: %1.").arg(tcpServer->errorString()));
    }
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(clientConnected()));
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
