// Helmets
// "H_Beret_Colonel", // auch mit _blk, _02 (EU),
// "H_MilCap_mcamo",
// "H_Watchcap_blk", // Beanie, auch mit _camo, _cbr, _camo, _khk, _sgg
// "H_HelmetCrew_B",
// "H_PilotHelmetHeli_B",
// "H_CrewHelmetHeli_B",
// "H_PilotHelmetFighter_B",
// "H_Cap_headphones",
// "H_HelmetB_light", // SOF, auch mit _black, _desert, _grass, _sand, _snakeskin
// "H_HelmetSpecB_blk" // Mit Mikrofon, auch mit _paint1, _paint2, _sand, _snakeskin
#define B_Soldier_Helmet \
helmet_pool[] = { \
    "H_HelmetB", \
    "H_HelmetB_desert", \
    "H_HelmetB_grass" \
};

#define O_Soldier_Helmet \
helmet_pool[] = { \
    "H_HelmetO_ocamo", \
    "H_HelmetSpecO_ocamo" \
};

#define I_Soldier_Helmet \
helmet_pool[] = { \
    "H_HelmetIA_camo", \
    "H_HelmetIA_net" \
};

#define B_Advanced_Helmet \
helmet_pool[] = { \
    "H_HelmetSpecB_paint1", \
    "H_HelmetSpecB_paint2", \
    "H_HelmetSpecB_sand", \
    "H_HelmetSpecB_snakeskin", \
    "H_HelmetB_light", \
    "H_HelmetB_light_desert", \
    "H_HelmetB_light_grass", \
    "H_HelmetB_light_sand", \
    "H_HelmetB_light_snakeskin" \
};

#define B_Sniper_Helmet \
helmet_pool[] = {"H_Cap_tan_specops_US", \
    "H_Bandanna_mcamo", \
    "H_Shemag_olive" \
};

#define O_Sniper_Helmet \
helmet_pool[] = {"H_Cap_brn_SPECOPS", \
    "H_Bandanna_khk", \
    "H_Shemag_khk" \
};

#define I_Sniper_Helmet \
helmet_pool[] = {"H_Cap_blk_Raven", \
    "H_Bandanna_gry", \
    "H_Shemag_olive" \
};

#define B_Crew_Helmet \
helmet_pool[] = {"H_HelmetCrew_B"};

#define O_Crew_Helmet \
helmet_pool[] = {"H_HelmetCrew_O"};

#define I_Crew_Helmet \
helmet_pool[] = {"H_HelmetCrew_I"};

#define B_Officer_Helmet \
helmet_pool[] = { \
    "H_Beret_blk", \
    "H_Beret_Colonel" \
};

#define O_Officer_Helmet \
helmet_pool[] = { \
    "H_Beret_blk", \
    "H_Beret_ocamo" \
};

#define I_Officer_Helmet \
helmet_pool[] = { \
    "H_Beret_blk", \
    "H_Beret_grn" \
};

#define B_Cap_Helmet \
helmet_pool[] = { \
    "H_MilCap_mcamo" \
};

#define O_Cap_Helmet \
helmet_pool[] = { \
    "H_MilCap_ocamo" \
};

#define I_Cap_Helmet \
helmet_pool[] = { \
    "H_MilCap_dgtl" \
};

#define B_Heli_Helmet \
helmet_pool[] = {"H_CrewHelmetHeli_B"};

#define O_Heli_Helmet \
helmet_pool[] = {"H_PilotHelmetFighter_O"};

#define I_Heli_Helmet \
helmet_pool[] = {"H_PilotHelmetHeli_I"};

#define B_Jet_Helmet \
helmet_pool[] = {"H_PilotHelmetFighter_B"};

#define O_Jet_Helmet \
helmet_pool[] = {"H_PilotHelmetFighter_O"};

#define I_Jet_Helmet \
helmet_pool[] = {"H_PilotHelmetFighter_I"};

#define B_Logistic_Helmet \
helmet_pool[] = {"H_Cap_headphones"};

#define O_Logistic_Helmet \
helmet_pool[] = {"H_Cap_headphones"};

#define I_Logistic_Helmet \
helmet_pool[] = {"H_Cap_headphones"};

#define B_Beanie_Helmet \
helmet_pool[] = { \
    "H_Watchcap_blk", \
    "H_Watchcap_camo" \
};

#define O_Beanie_Helmet \
helmet_pool[] = { \
    "H_Watchcap_blk", \
    "H_Watchcap_cbrk" \
};

#define I_Beanie_Helmet \
helmet_pool[] = { \
    "H_Watchcap_blk", \
    "H_Watchcap_sgg" \
};

// Items
#define Binocular \
binocular[] = {"Binocular"};

#define Rangefinder \
binocular[] = {"Rangefinder"};

#define B_Laserdesignator \
binocular[] = {"Laserdesignator", "Laserbatteries"};

#define O_Laserdesignator \
binocular[] = {"Laserdesignator_02", "Laserbatteries"};

#define I_Laserdesignator \
binocular[] = {"Laserdesignator_03", "Laserbatteries"};

#define NOGPS \
gps_pool[] = {};

#define GPS \
gps_pool[] = {"ItemGPS"};

#define B_EasyTrackPDA \
gps_pool[] = {"b_EasyTrack_PDA"};

#define O_EasyTrackPDA \
gps_pool[] = {"o_EasyTrack_PDA"};

#define I_EasyTrackPDA \
gps_pool[] = {"i_EasyTrack_PDA"};

#define B_EasyTrackLAPTOP \
gps_pool[] = {"b_EasyTrack_Tablet"};

#define O_EasyTrackLAPTOP \
gps_pool[] = {"o_EasyTrack_Tablet"};

#define I_EasyTrackLAPTOP \
gps_pool[] = {"i_EasyTrack_Tablet"};

#define B_UAV \
gps_pool[] = {"B_UavTerminal"};

#define O_UAV \
gps_pool[] = {"O_UavTerminal"};

#define I_UAV \
gps_pool[] = {"I_UavTerminal"};

#define B_Diver_Goggle \
goggle_pool[] = {"G_B_Diving"};

#define O_Diver_Goggle \
goggle_pool[] = {"G_O_Diving"};

#define I_Diver_Goggle \
goggle_pool[] = {"G_I_Diving"};

#define Team_Radio \
radios[] = {"ACRE_PRC343"};

#define Team_Medium_Radio \
radios[] = {"ACRE_PRC343", "ACRE_PRC152"};

#define Team_Large_Radio \
radios[] = {"ACRE_PRC343", "ACRE_PRC117F"};

#define Team_Medium_Large_Radio \
radios[] = {"ACRE_PRC343", "ACRE_PRC152", "ACRE_PRC117F"};

#define Team_Large_Large_Radio \
radios[] = {"ACRE_PRC343", "ACRE_PRC117F", "ACRE_PRC117F"};

class BasicGear : GearClass {
    helmet_pool[] = {};
    goggle_pool[] = {};
    nightvision_pool[] = {};
    gps_pool[] = {};
    compass_pool[] = {"ItemCompass"};
    clock_pool[] = {"ItemWatch"};
    map_pool[] = {"ItemMap"};
    binocular[] = {};
    Team_Radio
};

class B_BasicGearNVG : BasicGear {
    nightvision_pool[] = {"NVGoggles"};
};

class O_BasicGearNVG : BasicGear {
    nightvision_pool[] = {"NVGoggles_OPFOR"};
};

class I_BasicGearNVG : BasicGear {
    nightvision_pool[] = {"NVGoggles_INDEP"};
};

class B_NormalSoldier : B_BasicGearNVG {
    B_Soldier_Helmet
};

class O_NormalSoldier : O_BasicGearNVG {
    O_Soldier_Helmet
};

class I_NormalSoldier : I_BasicGearNVG {
    O_Soldier_Helmet
};
