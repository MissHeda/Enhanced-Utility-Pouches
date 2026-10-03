#include "\x\cba\addons\main\script_macros_common.hpp"

// Enhanced First Aid Kits, the way it names its functions - the pouches run on its kit framework.
#define EFAK_PREFIX efak
#define EFAKFUNC(module,function)   TRIPLES(DOUBLES(EFAK_PREFIX,module),fnc,function)
#define QEFAKFUNC(module,function)  QUOTE(EFAKFUNC(module,function))
#define EFAKGVAR(module,var)        TRIPLES(EFAK_PREFIX,module,var)
#define QEFAKGVAR(module,var)       QUOTE(EFAKGVAR(module,var))

// CBA settings category every pouch setting lives under.
#define CBA_SETTINGS_EUP "Enhanced Utility Pouches"

// Size of the instance class pool of every pouch type, see tools/generate_instances.py.
#define EUP_INSTANCES_PER_POUCH 300
