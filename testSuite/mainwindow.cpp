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
    pluginsDir.cdUp();
    pluginsDir.cd("plugins");
    const QString filter = "lib*.so";
    foreach (QString fileName, pluginsDir.entryList(QStringList() << filter, QDir::NoDotAndDotDot | QDir::Files)) {
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
                qtPluginsInterface->onLoad();
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

    // fill list of units
    Unit *u1 = new Unit;
    u1->id = 1;
    u1->x = 10;
    u1->y = 11;
    u1->z = 0;
    u1->health = 100;
    u1->lastAttacked = -1;
    u1->t = DR_CONSTRUCT;
//    QList<Equipment> eqs;
    u1->eqs.append(BODY_VIPER);
    u1->eqs.append(PROP_WHEELED);
    u1->eqs.append(EQ_TRUCK);

    Unit *u2 = new Unit;
    u2->id = 3;
    u2->x = 20;
    u2->y = 21;
    u2->z = 0;
    u2->health = 100;
    u2->lastAttacked = -1;
    u2->t = DR_CONSTRUCT;
    u2->eqs.append(BODY_VIPER);
    u2->eqs.append(PROP_WHEELED);
    u2->eqs.append(EQ_TRUCK);

    units.append(u1);
    units.append(u2);
}

QList<Unit*> MainWindow::getUnits()
{
    return units;
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
