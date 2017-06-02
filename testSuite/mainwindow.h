#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../warzone2100/lib/qtplugins/qtpluginsinterface.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public IHostInterface
{
    Q_OBJECT
    Q_INTERFACES(IHostInterface)

public:
    explicit MainWindow(QWidget *parent = 0);
    void dbg(QString msg);
    bool actionBuild(UnitId, int, int, int, UnitType) {return true;}
    bool actionAttack(UnitId, UnitId) {return true;}
    bool actionStop(UnitId) {return true;}

    QList<Unit> getUnits();
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    IPluginInterface *iPluginInterface;
    bool loadPlugin();

    QList<Unit> units;

public slots:
    void getPluginVersion();
};

#endif // MAINWINDOW_H
