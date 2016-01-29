// framwork in general
class W_Framework {
	tag = "FETT";
	class functions {
		file = "W_FRAMEWORK\functions\framework";
		class w_clientInit {};
		class w_dlcMissing {};
		class w_killMessage {};
		class w_postInit { postInit = 1; };
		class w_serverInit {};
		class w_setHC {};
		class w_setVariables {};
	};
};

#include "core\CfgFunctions.hpp"
#include "FETT_teleporter\CfgFunctions.hpp"
#include "FETT_vd\CfgFunctions.hpp"
#include "loadouts\CfgFunctions.hpp"
#include "dlcCheck\CfgFunctions.hpp"
