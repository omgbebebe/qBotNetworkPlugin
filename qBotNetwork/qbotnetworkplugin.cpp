#include <QtGui>
#include "qbotnetworkplugin.h"
#include "../common/qtpluginsinterface.h"

QString QBotNetworkPlugin::version()
{
    iHost->debug("called version function");
    return "0.0.1";
}

QString QBotNetworkPlugin::name()
{
    iHost->debug("called name function");
    return "BotNetwork interface";
}

Q_EXPORT_PLUGIN2(qbotnetworkplugin, QBotNetworkPlugin)
