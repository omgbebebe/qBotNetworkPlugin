#ifndef QBOTNETWORKPLUGIN_H
#define QBOTNETWORKPLUGIN_H

#include <QObject>
#include "../common/qtpluginsinterface.h"

class QBotNetworkPlugin : public QObject, QtPluginsInterface
{
    Q_OBJECT
    Q_INTERFACES(QtPluginsInterface)
public:
    QString version();
    QString name();
    
signals:
    
public slots:
    
};

#endif // QBOTNETWORKPLUGIN_H
