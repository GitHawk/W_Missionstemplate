class ace_refuel_rate {
	typeName = "SCALAR";
	value = 6;
	force = 1;
};
class ace_repair_engineerSetting_Repair {
	typeName = "SCALAR";
	value = 1;
	force = 1;
	//values[] = {"ace_repair_engineerSetting_anyone", "ace_repair_engineerSetting_EngineerOnly", "ace_repair_engineerSetting_RepairSpecialistOnly"};
};
class ace_repair_engineerSetting_Wheel {
	typeName = "SCALAR";
	value = 0;
	force = 1;
	//values[] = {"ace_repair_engineerSetting_anyone", "ace_repair_engineerSetting_EngineerOnly", "ace_repair_engineerSetting_RepairSpecialistOnly"};
	//category = "ace_OptionsMenu_CategoryLogistics";
};
class ace_repair_repairDamageThreshold {
	typeName = "SCALAR";
	value = 0.6;
	force = 1;
	//category = "ace_OptionsMenu_CategoryLogistics";
};
class ace_repair_repairDamageThreshold_Engineer {
	typeName = "SCALAR";
	value = 0.0;
	force = 1;
	//category = "ace_OptionsMenu_CategoryLogistics";
};
class ace_repair_consumeItem_ToolKit {
	typeName = "SCALAR";
	value = 0;
	force = 1;
	//values[] = {"ace_common_No", "ace_common_Yes"};
};
class ace_repair_fullRepairLocation {
	typeName = "SCALAR";
	value = 3;
	force = 1;
	//values[] = {"ace_repair_useAnywhere", "ace_repair_repairVehicleOnly", "ace_repair_repairFacilityOnly", "ace_repair_vehicleAndFacility", "ace_common_Disabled"};
};
class ace_repair_engineerSetting_fullRepair {
	typeName = "SCALAR";
	value = 1;
	force = 1;
	//values[] = {"ace_repair_engineerSetting_anyone", "ace_repair_engineerSetting_EngineerOnly", "ace_repair_engineerSetting_RepairSpecialistOnly"};
};
class ace_repair_addSpareParts {
	typeName = "BOOL";
	value = 1;
	force = 1;
};
class ace_repair_wheelRepairRequiredItems {
	typeName = "SCALAR";
	value = 0;
	force = 1;
	//values[] = {"None", "ToolKit"};
	//_values[] = {{}, {"ToolKit"}};
};