#define ACE_DefaultGear \
ace[] = { \
    "ace_earPlugs", \
    "ace_microDAGR" \
};


class BasicGrenades : ItemsClass {
    ACE_DefaultGear
    grenades[] = {
        {"HandGrenade",4},
        {"SmokeShellGreen",4},
        {"SmokeShell",4}
    };
};

class SmallGrenades : ItemsClass {
    ACE_DefaultGear
    grenades[] = {
        {"HandGrenade",2},
        {"SmokeShellGreen",2},
        {"SmokeShell",2}
    };
};

class B_SpecialGrenades : ItemsClass {
    ACE_DefaultGear
    grenades[] = {
        {"HandGrenade",2},
        {"SmokeShellGreen",2},
        {"SmokeShell",2},
        {"B_IR_Grenade",2}
    };
};

class O_SpecialGrenades : ItemsClass {
    ACE_DefaultGear
    grenades[] = {
        {"HandGrenade",2},
        {"SmokeShellGreen",2},
        {"SmokeShell",2},
        {"O_IR_Grenade",2}
    };
};

class I_SpecialGrenades : ItemsClass {
    ACE_DefaultGear
    grenades[] = {
        {"HandGrenade",2},
        {"SmokeShellGreen",2},
        {"SmokeShell",2},
        {"I_IR_Grenade",2}
    };
};

/*
    Medic Classnames - ACE:

    "ace_fieldDressing"
    "ace_packingBandage"
    "ace_elasticBandage"
    "ace_tourniquet"
    "ace_morphine"
    "ace_atropine"
    "ace_epinephrine"
    "ace_plasmaIV"
    "ace_plasmaIV_500"
    "ace_plasmaIV_250"
    "ace_salineIV"
    "ace_salineIV_500"
    "ace_salineIV_250"
    "ace_bloodIV"
    "ace_bloodIV_500"
    "ace_bloodIV_250"
    "ace_quikclot"
    "ace_personalAidKit"
    "ace_surgicalKit"
    "ace_bodyBag"
*/

class BasicMedicMaterial : BasicGrenades {
    medicMaterial[] = {
        {"ace_packingBandage",4},
        {"ace_elasticBandage",4},
        {"ace_fieldDressing",4},
        {"ace_morphine",2}
    };
};

class MoreMedicMaterial : BasicGrenades {
    medicMaterial[] = {
        {"ace_packingBandage",8},
        {"ace_elasticBandage",8},
        {"ace_fieldDressing",8},
        {"ace_morphine",2}
    };
};

class SmallMedicMaterial : SmallGrenades {
    medicMaterial[] = {
        {"ace_packingBandage",4},
        {"ace_elasticBandage",2},
        {"ace_fieldDressing",2},
        "ace_morphine"
    };
};

class ExplosiveMaterial : SmallMedicMaterial {
    other[] = {
        "MineDetector",
        "SatchelCharge_Remote_Mag",
        {"DemoCharge_Remote_Mag",2},
        {"APERSBoundingMine_Range_Mag",2},
        {"APERSTripMine_Wire_Mag",2}
    };
};

class CombatMedicMaterial : BasicGrenades {
    onApplyLoadout = "_obj setVariable ['ace_medical_medicClass', 1, true];";
    medicMaterial[] = {
        {"ace_surgicalKit",6},
        {"ace_fieldDressing",12},
        {"ace_packingBandage",12},
        {"ace_elasticBandage",12},
        {"ace_morphine",8},
        {"ace_epinephrine",4},
        {"ace_salineIV",6},
        {"ace_tourniquet",4}
    };
};

class MedicMaterial : SmallGrenades {
    onApplyLoadout = "_obj setVariable ['ace_medical_medicClass', 2, true];";
    medicMaterial[] = {
        {"ace_personalAidKit",12},
        {"ace_packingBandage",24},
        {"ace_fieldDressing",24},
        {"ace_elasticBandage",24},
        {"ace_tourniquet",6},
        {"ace_morphine",12},
        {"ace_epinephrine",4},
        {"ace_salineIV",4}
    };
};

class B_SOFMedicMaterial : B_SpecialGrenades {
    medicMaterial[] = {
        {"ace_packingBandage",4},
        {"ace_elasticBandage",2},
        {"ace_fieldDressing",2},
        {"ace_morphine",2}
    };
};

class O_SOFMedicMaterial : O_SpecialGrenades {
    medicMaterial[] = {
        {"ace_packingBandage",4},
        {"ace_elasticBandage",2},
        {"ace_fieldDressing",2},
        {"ace_morphine",2}
    };
};

class I_SOFMedicMaterial : I_SpecialGrenades {
    medicMaterial[] = {
        {"ace_packingBandage",4},
        {"ace_elasticBandage",2},
        {"ace_fieldDressing",2},
        {"ace_morphine",2}
    };
};

class B_SOFBigMedicMaterial : B_SpecialGrenades {
    onApplyLoadout = "_obj setVariable ['ace_medical_medicClass', 2, true];";
    medicMaterial[] = {
        {"ace_personalAidKit",4},
        {"ace_surgicalKit",2},
        {"ace_packingBandage",12},
        {"ace_fieldDressing",12},
        {"ace_elasticBandage",12},
        {"ace_tourniquet",6},
        {"ace_morphine",8},
        {"ace_epinephrine",2},
        {"ace_salineIV",4}
    };
};

class O_SOFBigMedicMaterial : O_SpecialGrenades {
    onApplyLoadout = "_obj setVariable ['ace_medical_medicClass', 2, true];";
    medicMaterial[] = {
        {"ace_personalAidKit",4},
        {"ace_surgicalKit",2},
        {"ace_packingBandage",12},
        {"ace_fieldDressing",12},
        {"ace_elasticBandage",12},
        {"ace_tourniquet",6},
        {"ace_morphine",8},
        {"ace_epinephrine",2},
        {"ace_salineIV",4}
    };
};

class I_SOFBigMedicMaterial : I_SpecialGrenades {
    onApplyLoadout = "_obj setVariable ['ace_medical_medicClass', 2, true];";
    medicMaterial[] = {
        {"ace_personalAidKit",4},
        {"ace_surgicalKit",2},
        {"ace_packingBandage",12},
        {"ace_fieldDressing",12},
        {"ace_elasticBandage",12},
        {"ace_tourniquet",6},
        {"ace_morphine",8},
        {"ace_epinephrine",2},
        {"ace_salineIV",4}
    };
};
