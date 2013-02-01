#ifndef QTPLUGINSINTERFACE_H
#define QTPLUGINSINTERFACE_H

#include <QString>
#include "../common/ihostinterface.h"
#include "../common/unitsdef.h"

class QtPluginsInterface
{
public:
    virtual ~QtPluginsInterface() {}
    virtual QString version() = 0;
    virtual QString name() = 0;
    virtual void setHostInterface(IHostInterface*) = 0;
    // events callback
    virtual void onLoad() = 0;

    virtual void onStart() = 0;
    virtual void onEnd(bool isWinner) = 0; // i'm win?
    virtual void onFrame() = 0;

    virtual void onUnitAttacked(Unit* pUnit) = 0; // check pUnit->lastAttacked for found aggressor
    virtual void onUnitDiscover(Unit* pUnit) = 0;
    virtual void onUnitEvade(Unit* pUnit) = 0;
    virtual void onUnitDestroy(Unit* pUnit) = 0;

    virtual void onResearchComplete(UnitId) = 0; // research facility id
    virtual void onProductionComplete(UnitId) = 0; // research facility id
};

Q_DECLARE_INTERFACE(QtPluginsInterface,
                    "net.wz2100.Plugin.QtPluginsInterface/0.0.1")

#endif // QTPLUGINSINTERFACE_H
