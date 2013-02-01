#ifndef IHOSTINTERFACE_H
#define IHOSTINTERFACE_H

#include <QString>
#include <QList>
#include "../common/unitsdef.h"

class IHostInterface
{
public:
    virtual ~IHostInterface() {}
    virtual void debug(QString msg) = 0;

    virtual QList<Unit*> getUnits() = 0; // return all visible units
    // commands
    virtual bool actionBuild(UnitId unitId, int x, int y, int z, UnitType stType) = 0;
    virtual bool actionAttack(UnitId unitId, UnitId victimId) = 0;
    virtual bool actionStop(UnitId unitId) = 0;
};

Q_DECLARE_INTERFACE(IHostInterface,
                    "net.wz2100.Plugin.QtPluginsHostInterface/0.0.1")

#endif // IHOSTINTERFACE_H
