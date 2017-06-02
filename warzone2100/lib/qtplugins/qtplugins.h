#ifndef QTPLUGINS_H
#define QTPLUGINS_H

#include <QObject>
#include <QList>
#include <QString>

#define PLUGINS_INTERFACE_VERSION "net.wz2100.Plugins.IPluginInterface/0.0.2"
#define IHOST_INTERFACE_VERSION "net.wz2100.Plugins.IHostInterface/0.0.2"

class QtPluginsEngine;
extern QtPluginsEngine* qtPlugins;

bool initPlugins();
bool preparePlugins();
bool shutdownPlugins();
bool updatePlugins();


class IHostInterface
{
public:
    virtual ~IHostInterface() {}
    virtual void dbg(QString msg) = 0;
};

Q_DECLARE_INTERFACE(IHostInterface, IHOST_INTERFACE_VERSION);

class IPluginInterface
{
public:
    virtual ~IPluginInterface() {}
    virtual QString version() = 0;
    virtual void setHostInterface(IHostInterface*) = 0;

    // events callback
    virtual void onLoad() = 0;

    virtual void onStart() = 0;
    virtual void onEnd(bool isWinner) = 0; // i'm win?
    virtual void onFrame() = 0;
};

Q_DECLARE_INTERFACE(IPluginInterface, PLUGINS_INTERFACE_VERSION);

class QtPluginsEngine : public QObject, public IHostInterface
{
    Q_OBJECT
    Q_INTERFACES(IHostInterface)

public:
    QtPluginsEngine();
    ~QtPluginsEngine();
    void dbg(QString msg);

private:
    IPluginInterface *iPluginInterface;
    bool loadPlugin();

public slots:
    void getPluginVersion();
};
#endif // QTPLUGINS_H
