//#include <QtGui>
//#include <QtPlugin>
#include <QDataStream>
#include <QTcpSocket>
#include <QtScript/QScriptValue>
#include <QtScript/QScriptEngine>
#include <QMap>
#include "qbotnetworkplugin.h"
#include "../warzone2100/lib/qtplugins/qtpluginsinterface.h"
#include "json.h"

Q_PLUGIN_METADATA(IID PLUGINS_INTERFACE_VERSION)

#define MAX_BUFF_SIZE 1024
#define MAX_MSG_LENGTH 65535
#define API_VERSION "0.0.1"
#define API_MAGIC 0xDEAD

char* msg = new char[MAX_MSG_LENGTH];

void QBotNetworkPlugin::send(QByteArray *msg)
{
    if (!socket->isValid()){
        dbg("invalid socket");
        return;
    }
    (*out) << apiMagic;
    (*out) << (*msg);
}

QVariantMap QBotNetworkPlugin::parseJSON(QString json)
{
    //using namespace QtJson;
    bool ok;
    QVariantMap result = QtJson::parse(json, ok).toMap();

    if(!ok) {
        dbg("An error occurred during parsing");
    }
    return result;
}


QBotNetworkPlugin::QBotNetworkPlugin()
{
    cmds["getAllUnits"] = 1;
    cmds["getApiVersion"] = 2;
    apiMagic = 0xDEAD;
}

QVariantMap QBotNetworkPlugin::toVariantMap(const Unit *u)
{
    QVariantMap res;
    res["id"] = u->id;
    res["type"] = u->t;
    res["health"] = u->health;
    res["x"] = u->x;
    res["y"] = u->y;
    res["z"] = u->z;
    QVariantList eqs;
    foreach(int e, u->eqs){
        eqs << e;
    }

    res["eqs"] = eqs;
    return res;
}

void QBotNetworkPlugin::readFromSocket()
{
    //dbg(QString("reading message of %1 bytes length").arg(socket->bytesAvailable()));
    if (socket->bytesAvailable() < 2) // header not received
        return;

    quint16 magic;
    (*in) >> magic;
    if (magic != apiMagic){
        dbg(QString("wrong magic nimber: %1").arg(magic));
        socket->close();
        return;
    }

    //QString msg;
    (*in) >> msg;

    if (msg == NULL){
        dbg("empty message received");
        return;
    }

    //dbg(QString("received new message: %1").arg(msg));

    QVariantMap m = parseJSON(msg);
    QVariantMap res;
    QByteArray data;
    QVariantList newList;
    QList<Unit> units = iHost->getUnits();
    if(m.contains("cmd")){
        QString c = m["cmd"].toString();
        if (c == "getAllUnits"){
            //dbg("received getAllUnits command");
            foreach(const Unit u, units){
                newList << toVariantMap(&u);
            }

            res["units"] = newList;
            data = QtJson::serialize(res);
            send(&data);
        }
        else if (c == "getApiVersion"){
            //dbg("received getAPIVersion command");
            res["apiVersion"] = API_VERSION;
            data = QtJson::serialize(res);
//            QString res = v1.toString();
            //dbg(QString("reply with: %1").arg(res));
            send(&data);
        }
        else {
            dbg("unknown command");
        }
    } else{
        dbg("wrong message format. i want some commands");
        return;
    }

    /*
    if(value.property("arb_id").isNumber()) {
        QScriptValue out = value.property("arb_id").toInteger();
        qDebug() << out.toInteger();
    } else {
        qDebug()<<"Invalid response: " << m;
        // fatal error
    }
    */
}

void QBotNetworkPlugin::clientDisconnected()
{
    dbg("client disconnected");
    delete in;
    delete out;
}

void QBotNetworkPlugin::clientConnected()
{
    dbg("new incoming connection");
    socket = tcpServer->nextPendingConnection();
    if (!socket){
        dbg(QString("can't get socket description: %1").arg(tcpServer->errorString()));
    }
    dbg("connected");
    connect(socket, SIGNAL(readyRead()), this, SLOT(readFromSocket()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
//    in = new QDataStream(socket, QIODevice::ReadOnly);
    in = new QDataStream(socket);
    in->setVersion(QDataStream::Qt_5_0);
//    out = new QDataStream(socket, QIODevice::WriteOnly);
    out = new QDataStream(socket);
    out->setVersion(QDataStream::Qt_5_0);
}

void QBotNetworkPlugin::startServer()
{
    dbg("Starting network server");
    tcpServer = new QTcpServer(this);
    if (!tcpServer){
        dbg("FAILED");
    }
    QHostAddress hostadd("127.0.0.1");
    if (!tcpServer->listen(hostadd,5566)) {
        dbg(QString("Unable to start the server: %1.").arg(tcpServer->errorString()));
    }
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(clientConnected()));
    dbg("OK");
}

void QBotNetworkPlugin::onLoad()
{
    this->startServer();
}

QString QBotNetworkPlugin::version()
{
    dbg("called version function");
    dbg("getting all visible units");
    QList<Unit> units = iHost->getUnits();
    dbg(QString("recieved %1 units").arg(units.length()));
    for (int i = 0; i < units.length(); i++){
        Unit u = units.at(i);
        dbg(QString("unit (%1): pos=(%2, %3, %4)").arg(u.id).arg(u.x).arg(u.y).arg(u.z));
    }
    return "0.0.1";
}

void QBotNetworkPlugin::dbg(QString msg)
{
    iHost->dbg(msg);
}

QString QBotNetworkPlugin::name()
{
    dbg("called name function");
    return "BotNetwork interface";
}

//Q_EXPORT_PLUGIN2(qbotnetworkplugin, QBotNetworkPlugin)
