#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QDebug>
#include "../common/qtpluginsinterface.h"

void MainWindow::debug(QString msg)
{
    qDebug() << msg;
}

bool MainWindow::loadPlugin()
{
    qDebug() << "try load plugin...";
    QDir pluginsDir(qApp->applicationDirPath());
#if defined(Q_OS_WIN)
    if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
        pluginsDir.cdUp();
#elif defined(Q_OS_MAC)
    if (pluginsDir.dirName() == "MacOS") {
        pluginsDir.cdUp();
        pluginsDir.cdUp();
        pluginsDir.cdUp();
    }
#endif
    pluginsDir.cd("plugins");
    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        qDebug() << "fund plugin: " << pluginsDir.absoluteFilePath(fileName);
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin) {
            qDebug() << "cast plugin pointer to QtPluginsInterface...";
            qtPluginsInterface = qobject_cast<QtPluginsInterface *>(plugin);
            if (qtPluginsInterface){
                qDebug() << "OK";
                qtPluginsInterface->setHostInterface(qobject_cast<IHostInterface *>(this));
//                qtPluginsInterface->setHostInterface((this));
                return true;
            }else{
                qDebug() << "FAILED";
            }
        }else{
            qDebug() << "plugin instancing failed";
            qDebug() << "err: " << pluginLoader.errorString();
        }
    }

    return false;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug() << "starting...";
    ui->setupUi(this);

    if (!loadPlugin()) {
        //QMessageBox::information(this, "Error", "Could not load the plugin");
        ui->lineEdit->setEnabled(false);
        ui->pushButton->setEnabled(false);
    }else{
        connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(getPluginVersion()));
    }
}

void MainWindow::getPluginVersion()
{
    QString text = qtPluginsInterface->version();
    ui->lineEdit->setText(text);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Q_EXPORT_PLUGIN2(mainwindow, IHostInterface)
