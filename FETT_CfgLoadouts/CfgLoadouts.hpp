#include "CfgDefines.hpp"
#include "CfgContainers.hpp"
#include "CfgGear.hpp"
#include "CfgItems.hpp"
#include "CfgWeapons.hpp"

class CfgLoadouts {
    class BLU_F {
        #include "CfgLoadouts_nato_hawk.hpp"
    };
    class OPF_F {
        #include "CfgLoadouts_csat_hawk.hpp"
    };
    class IND_F {
        #include "CfgLoadouts_aaf_hawk.hpp"
    };
    class CIV_F {
        #include "CfgLoadouts_civ_hawk.hpp"
    };
};
