#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../common/qtpluginsinterface.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public IHostInterface
{
    Q_OBJECT
    Q_INTERFACES(IHostInterface)

public:
    explicit MainWindow(QWidget *parent = 0);
    void debug(QString msg);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QtPluginsInterface *qtPluginsInterface;
    bool loadPlugin();

public slots:
    void getPluginVersion();
};

#endif // MAINWINDOW_H
