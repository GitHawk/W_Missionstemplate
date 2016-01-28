// "V_Rangemaster_belt",
// "V_TacVest_blk",
// "V_BandollierB_rgr",
// "V_Chestrig_rgr", // auch mit _khk
// "V_PlateCarrierGL_rgr", // auch mit: _blk, _mtp, hat mehr Platz
// "V_PlateCarrierSpec_rgr" // light, auch mit: _blk, _mtp
// "V_PlateCarrier1_rgr",
// "V_PlateCarrier2_rgr" // Mehr Armor, Mehr gewicht als 1

// "B_Kitbag_mcamo", // auch mit _rgr
// "B_FieldPack_cbr", // Auch mit _blk
// "B_Carryall_oli", // auch mit _mcamo, _cbr
// "B_AssaultPack_rgr" // auch mit _blk, _mcamo
// Uniform
#define B_Uniform \
uniform_pool[] = { \
    "U_B_CombatUniform_mcam_vest", \
    "U_B_CombatUniform_mcam_tshirt", \
    "U_B_CombatUniform_mcam" \
};

#define O_Uniform \
uniform_pool[] = { \
    "U_O_CombatUniform_ocamo", \
    "U_O_SpecopsUniform_ocamo" \
};

#define I_Uniform \
uniform_pool[] = { \
    "U_I_CombatUniform", \
    "U_I_CombatUniform_shortsleeve", \
    "U_I_CombatUniform_tshirt" \
};

#define B_Urban_Uniform \
uniform_pool[] = { \
    "U_B_CTRG_1", \
    "U_B_CTRG_2", \
    "U_B_CTRG_3" \
};

#define O_Urban_Uniform \
uniform_pool[] = { \
    "U_O_CombatUniform_oucamo", \
    "U_O_SpecopsUniform_oucamo" \
};

#define I_Urban_Uniform \
uniform_pool[] = { \
    "U_I_CombatUniform", \
    "U_I_CombatUniform_shortsleeve", \
    "U_I_CombatUniform_tshirt" \
};

#define B_Sniper_Uniform \
uniform_pool[] = { \
    "U_B_FullGhillie_ard", \
    "U_B_FullGhillie_sard", \
    "U_B_FullGhillie_lsh" \
};

#define O_Sniper_Uniform \
uniform_pool[] = { \
    "U_O_FullGhillie_ard", \
    "U_O_FullGhillie_sard", \
    "U_O_FullGhillie_lsh" \
};

#define I_Sniper_Uniform \
uniform_pool[] = { \
    "U_I_FullGhillie_ard", \
    "U_I_FullGhillie_sard", \
    "U_I_FullGhillie_lsh" \
};

#define B_Jet_Uniform \
uniform_pool[] = {"U_B_PilotCoveralls"};

#define O_Jet_Uniform \
uniform_pool[] = {"U_O_PilotCoveralls"};

#define I_Jet_Uniform \
uniform_pool[] = {"U_I_PilotCoveralls"};

#define B_Heli_Uniform \
uniform_pool[] = {"U_B_HeliPilotCoveralls"};

#define O_Heli_Uniform \
uniform_pool[] = {"U_O_PilotCoveralls"};

#define I_Heli_Uniform \
uniform_pool[] = {"U_I_PilotCoveralls"};

#define B_Logistics_Uniform \
uniform_pool[] = {"U_I_G_Story_Protagonist_F"};

#define O_Logistics_Uniform \
uniform_pool[] = {"U_I_G_resistanceLeader_F"};

#define I_Logistics_Uniform \
uniform_pool[] = {"U_I_CombatUniform_tshirt"};

#define B_SpecOp_Uniform \
uniform_pool[] = {"U_B_survival_uniform"};

#define O_SpecOp_Uniform \
uniform_pool[] = {"U_O_SpecopsUniform_ocamo"};

#define I_SpecOp_Uniform \
uniform_pool[] = {"I_G_Soldier_TL_F"};

#define B_Diver_Uniform \
uniform_pool[] = {"U_B_Wetsuit"};

#define O_Diver_Uniform \
uniform_pool[] = {"U_O_Wetsuit"};

#define I_Diver_Uniform \
uniform_pool[] = {"U_I_Wetsuit"};

// Vests
#define B_Light_Vest \
vest_pool[] = {"V_PlateCarrier1_rgr"};

#define O_Light_Vest \
vest_pool[] = {"V_HarnessO_brn"};

#define I_Light_Vest \
vest_pool[] = {"V_PlateCarrierIA1_dgtl"};

#define O_Urban_Light_Vest \
vest_pool[] = {"V_PlateCarrierL_CTRG"};

#define B_Standard_Vest \
vest_pool[] = { \
    "V_PlateCarrier2_rgr", \
    "V_PlateCarrierSpec_rgr" \
};

#define O_Standard_Vest \
vest_pool[] = {"V_HarnessO_brn"};

#define I_Standard_Vest \
vest_pool[] = {"V_PlateCarrierIA2_dgtl"};

#define O_Urban_Standard_Vest \
vest_pool[] = {"V_PlateCarrierH_CTRG"};

#define B_Grenade_Vest \
vest_pool[] = {"V_PlateCarrierGL_rgr"};

#define O_Grenade_Vest \
vest_pool[] = {"V_HarnessOGL_brn"};

#define I_Grenade_Vest \
vest_pool[] = {"V_PlateCarrierIAGL_dgtl"};

#define B_SOF_Vest \
vest_pool[] = {"V_Chestrig_rgr"};

#define O_SOF_Vest \
vest_pool[] = {"V_Chestrig_khk"};

#define I_SOF_Vest \
vest_pool[] = {"V_Chestrig_oli"};

#define Tac_Vest \
vest_pool[] = {"V_TacVest_blk"};

#define Belt_Vest \
vest_pool[] = {"V_Rangemaster_belt"};

#define B_Bandolier_Vest \
vest_pool[] = { \
    "V_BandollierB_rgr", \
    "V_BandollierB_blk" \
};

#define O_Bandolier_Vest \
vest_pool[] = { \
    "V_BandollierB_khk", \
    "V_BandollierB_blk" \
};

#define I_Bandolier_Vest \
vest_pool[] = { \
    "V_BandollierB_khk", \
    "V_BandollierB_oli" \
};

#define B_Diver_Vest \
vest_pool[] = {"V_RebreatherB"};

#define O_Diver_Vest \
vest_pool[] = {"V_RebreatherIR"};

#define I_Diver_Vest \
vest_pool[] = {"V_RebreatherIA"};

// Backpacks
#define Small_Backpack \
backpack_pool[] = {"B_AssaultPack_blk"};

#define B_Small_Backpack \
backpack_pool[] = { \
    "B_AssaultPack_rgr", \
    "B_AssaultPack_mcamo" \
};

#define O_Small_Backpack \
backpack_pool[] = { \
    "B_AssaultPack_cbr", \
    "B_AssaultPack_ocamo" \
};

#define I_Small_Backpack \
backpack_pool[] = { \
    "B_AssaultPack_rgr", \
    "B_AssaultPack_dgtl" \
};

#define B_Medium_Backpack \
backpack_pool[] = { \
    "B_Kitbag_mcamo", \
    "B_Kitbag_rgr" \
};

#define O_Medium_Backpack \
backpack_pool[] = {"B_Kitbag_cbr"};

#define I_Medium_Backpack \
backpack_pool[] = {"B_Kitbag_rgr"};

#define B_Big_Backpack \
backpack_pool[] = { \
    "B_Carryall_oli", \
    "B_Carryall_mcamo" \
};

#define O_Big_Backpack \
backpack_pool[] = { \
    "B_Carryall_cbr", \
    "B_Carryall_ocamo" \
};

#define I_Big_Backpack \
backpack_pool[] = { \
    "B_Carryall_cbr", \
    "B_Carryall_oli" \
};

#define Parachute_Backpack \
backpack_pool[] = {"B_Parachute"};

#define B_UAV_Backpack \
backpack_pool[] = {"B_UAV_01_backpack_F"};

#define O_UAV_Backpack \
backpack_pool[] = {"O_UAV_01_backpack_F"};

#define I_UAV_Backpack \
backpack_pool[] = {"I_UAV_01_backpack_F"};

#define B_HMG_Backpack \
backpack_pool[] = {"B_HMG_01_weapon_F"};

#define O_HMG_Backpack \
backpack_pool[] = {"O_HMG_01_weapon_F"};

#define I_HMG_Backpack \
backpack_pool[] = {"I_HMG_01_weapon_F"};

#define B_Assistant_HMG_Backpack \
backpack_pool[] = {"B_HMG_01_support_F"};

#define O_Assistant_HMG_Backpack \
backpack_pool[] = {"O_HMG_01_support_F"};

#define I_Assistant_HMG_Backpack \
backpack_pool[] = {"I_HMG_01_support_F"};
