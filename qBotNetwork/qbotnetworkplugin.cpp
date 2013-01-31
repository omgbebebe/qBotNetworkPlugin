#include <QtGui>
#include "qbotnetworkplugin.h"
#include "../common/qtpluginsinterface.h"

QString QBotNetworkPlugin::version()
{
    return "0.0.1";
}

QString QBotNetworkPlugin::name()
{
    return "BotNetwork interface";
}

Q_EXPORT_PLUGIN2(qbotnetworkplugin, QBotNetworkPlugin)
