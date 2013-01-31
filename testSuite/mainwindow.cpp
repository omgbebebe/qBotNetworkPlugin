#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>

bool MainWindow::loadPlugin()
{
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
    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin) {
            qtPluginsInterface = qobject_cast<QtPluginsInterface *>(plugin);
            if (qtPluginsInterface)
                return true;
        }
    }

    return false;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
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
