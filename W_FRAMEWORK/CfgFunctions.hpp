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

//	W_Teleporter v1.1.0 by [W] Fett_Li
class W_Teleporter {
	tag = "FETT";
	class init {
		file = "W_FRAMEWORK\functions\dialogs";
		class W_RscTeleportInit {};
		class W_addTeleporter {};
	};
};

//	W_VD v1.0.0 by [W] Fett_Li
class W_VD {
	tag = "FETT";
	class init {
		file = "W_FRAMEWORK\functions\dialogs";
		class W_RscVDInit {};
	};
};
