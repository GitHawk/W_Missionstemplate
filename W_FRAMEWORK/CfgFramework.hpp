class CfgFramework {
	#include "packages\acre\CfgFramework.hpp"
	#include "packages\dlcCheck\CfgFramework.hpp"
	#include "packages\FETT_vd\CfgFramework.hpp"
	#include "packages\friendlyfire\CfgFramework.hpp"
	#include "packages\loadouts\CfgFramework.hpp"
	#include "packages\nomap\CfgFramework.hpp"

	class noFFPunishment {
		code = "W_no_ff_punishment = true;";
		client = 1;
		server = 1;
		preinit = 1;
	};
};
