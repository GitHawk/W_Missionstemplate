#define MicroDAGR \
other[] = {"ACE_microDAGR"};

class BasicGrenades : ItemsClass {
    grenades[] = {
        {"HandGrenade",4},
        {"SmokeShellGreen",4},
        {"SmokeShell",4},
        "ACE_EarPlugs"
    };
};

class SmallGrenades : ItemsClass {
    grenades[] = {
        {"HandGrenade",2},
        {"SmokeShellGreen",2},
        {"SmokeShell",2},
        "ACE_EarPlugs"
    };
};

class B_SpecialGrenades : ItemsClass {
    grenades[] = {
        {"HandGrenade",2},
        {"SmokeShellGreen",2},
        {"SmokeShell",2},
        {"B_IR_Grenade",2},
        "ACE_EarPlugs"
    };
};

class O_SpecialGrenades : ItemsClass {
    grenades[] = {
        {"HandGrenade",2},
        {"SmokeShellGreen",2},
        {"SmokeShell",2},
        {"O_IR_Grenade",2},
        "ACE_EarPlugs"
    };
};

class I_SpecialGrenades : ItemsClass {
    grenades[] = {
        {"HandGrenade",2},
        {"SmokeShellGreen",2},
        {"SmokeShell",2},
        {"I_IR_Grenade",2},
        "ACE_EarPlugs"
    };
};

/*

    Medic Classnames - ACE:

    "ACE_fieldDressing"
    "ACE_packingBandage"
    "ACE_elasticBandage"
    "ACE_tourniquet"
    "ACE_morphine"
    "ACE_atropine"
    "ACE_epinephrine"
    "ACE_plasmaIV"
    "ACE_plasmaIV_500"
    "ACE_plasmaIV_250"
    "ACE_salineIV"
    "ACE_salineIV_500"
    "ACE_salineIV_250"
    "ACE_bloodIV"
    "ACE_bloodIV_500"
    "ACE_bloodIV_250"
    "ACE_quikclot"
    "ACE_personalAidKit"
    "ACE_surgicalKit"
    "ACE_bodyBag"

    // Basejumper
    #ifdef BASEJUMPER
        #include "Medical\CfgMedicalBasejumper.hpp"
    #endif
    #ifdef BASEJUMPER_LAND
        #include "Medical\CfgMedicalBasejumper.hpp"
    #endif

    // MilSim
    #ifdef MILSIM
        #include "Medical\CfgMedicalMilSim.hpp"
    #endif

    // Running man
    #ifdef RUNNINGMAN
        #include "Medical\CfgMedicalRunningMan.hpp"
    #endif

    // Rücksetzungpunkt, sollte kein Medicsystem definiert sein
    #ifndef MILSIM
        #ifndef BASEJUMPER
            #ifndef BASEJUMPER_LAND
                #ifndef RUNNINGMAN
                    class BasicMedicMaterial : BasicGrenades {};

                    class SmallMedicMaterial : SmallGrenades {};

                    class CombatMedicMaterial : BasicGrenades {};

                    class MedicMaterial : SmallGrenades {};

                    class SOFMedicMaterial : SpecialGrenades {};

                    class PilotMedicMaterial : SpecialGrenadesSmall {};
                #endif
            #endif
        #endif
    #endif

*/

class BasicMedicMaterial : BasicGrenades {
    MicroDAGR
    medicMaterial[] = {
        {"ace_packingBandage",4},
        {"ace_elasticBandage",4},
        {"ace_fieldDressing",4},
        {"ace_morphine",2},
        {"ace_epinephrine",2}
    };
};

class MoreMedicMaterial : BasicGrenades {
    MicroDAGR
    medicMaterial[] = {
        {"ace_packingBandage",8},
        {"ace_elasticBandage",8},
        {"ace_fieldDressing",8},
        {"ace_morphine",2},
        {"ace_epinephrine",2}
    };
};

class SmallMedicMaterial : SmallGrenades {
    MicroDAGR
    medicMaterial[] = {
        {"ace_packingBandage",4},
        {"ace_elasticBandage",2},
        {"ace_fieldDressing",2},
        "ace_morphine",
        "ace_epinephrine"
    };
};

class ExplosiveMaterial : SmallMedicMaterial {
    other[] = {
        "ACE_microDAGR",
        "ACE_EarPlugs",
        "MineDetector",
        "SatchelCharge_Remote_Mag",
        {"DemoCharge_Remote_Mag",2},
        {"APERSBoundingMine_Range_Mag",2},
        {"APERSTripMine_Wire_Mag",2}
    };
};

class CombatMedicMaterial : BasicGrenades {
    MicroDAGR
    medicMaterial[] = {
        "ace_surgicalKit",
        {"ace_fieldDressing",12},
        {"ace_packingBandage",12},
        {"ace_elasticBandage",12},
        {"ace_morphine",8},
        {"ace_epinephrine",8},
        {"ace_salineIV",4},
        {"ace_tourniquet",4}
    };
};

class MedicMaterial : SmallGrenades {
    MicroDAGR
    medicMaterial[] = {
        "ace_personalAidKit",
        "ace_surgicalKit",
        {"ace_packingBandage",24},
        {"ace_fieldDressing",24},
        {"ace_elasticBandage",24},
        {"ace_tourniquet",6},
        {"ace_morphine",12},
        {"ace_epinephrine",12},
        {"ace_salineIV",8},
        {"ace_bloodIV",8}
    };
};

class B_SOFMedicMaterial : B_SpecialGrenades {
    MicroDAGR
    medicMaterial[] = {
        {"ace_packingBandage",4},
        {"ace_elasticBandage",2},
        {"ace_fieldDressing",2},
        {"ace_morphine",2},
        {"ace_epinephrine",2}
    };
};

class O_SOFMedicMaterial : O_SpecialGrenades {
    MicroDAGR
    medicMaterial[] = {
        {"ace_packingBandage",4},
        {"ace_elasticBandage",2},
        {"ace_fieldDressing",2},
        {"ace_morphine",2},
        {"ace_epinephrine",2}
    };
};

class O_SOFBigMedicMaterial : O_SpecialGrenades {
    MicroDAGR
    medicMaterial[] = {
        "ace_personalAidKit",
        "ace_surgicalKit",
        {"ace_packingBandage",12},
        {"ace_fieldDressing",12},
        {"ace_elasticBandage",12},
        {"ace_tourniquet",6},
        {"ace_morphine",8},
        {"ace_epinephrine",8},
        {"ace_salineIV",4},
        {"ace_bloodIV",4}
    };
};

class I_SOFMedicMaterial : I_SpecialGrenades {
    MicroDAGR
    medicMaterial[] = {
        {"ace_packingBandage",4},
        {"ace_elasticBandage",2},
        {"ace_fieldDressing",2},
        {"ace_morphine",2},
        {"ace_epinephrine",2}
    };
};
