#include "qtplugins.h"
#include <QString>
#include <QDir>
#include <QPluginLoader>
#include "../framework/frame.h"

QtPluginsEngine *qtPlugins;

bool initPlugins()
{
    debug(LOG_SCRIPT, "initialize plugins");
    debug(LOG_INFO, "PE: initialize plugins");
    qtPlugins = new QtPluginsEngine();
    return true;
}

bool preparePlugins()
{
    debug(LOG_INFO, "PE: plugins preparations");
    debug(LOG_SCRIPT, "plugins preparations");
    return true;
}

bool shutdownPlugins()
{
    return true;
}

bool updatePlugins()
{
    return true;
}

QtPluginsEngine::QtPluginsEngine()
{
    loadPlugin();
    return;
}

QtPluginsEngine::~QtPluginsEngine()
{
    return;
}

bool QtPluginsEngine::loadPlugin()
{
    dbg("Trying load plugin");
    QDir pluginsDir("/home/scor/tmp/warzone-plugins/");
    pluginsDir.cd("plugins");
    const QString filter = "lib*.so";
    foreach (QString fileName, pluginsDir.entryList(QStringList() << filter, QDir::NoDotAndDotDot | QDir::Files)) {
        dbg(QString("found plugin: %1").arg(pluginsDir.absoluteFilePath(fileName)));
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin) {
            dbg("cast plugin pointer to IPluginInterface...");
            iPluginInterface = qobject_cast<IPluginInterface *>(plugin);
            if (iPluginInterface){
                dbg("OK");
                iPluginInterface->setHostInterface(qobject_cast<IHostInterface *>(this));
                iPluginInterface->onLoad();
                return true;
            }else{
                dbg("FAILED");
            }
        }else{
            dbg("plugin instancing failed");
            dbg(QString("err: %1").arg(pluginLoader.errorString()));
        }
    }
    return false;
}

void QtPluginsEngine::dbg(QString msg)
{
    debug(LOG_INFO, msg.toLatin1());
    return;
}

void QtPluginsEngine::getPluginVersion()
{
    return;
}
