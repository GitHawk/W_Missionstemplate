class CO : SoldierClass {
    class Container : ContainerClass {
        O_Uniform
        O_Light_Vest
        O_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : KatibaC {};
        class handGun : O_Officer_Pistol {};
    };
    class Gear : O_NormalSoldier {
        O_EasyTrackPDA
        O_Officer_Helmet
        Rangefinder
        Team_Medium_Large_Radio
    };
    class Items : SmallMedicMaterial {};
};

class XO : CO {
    class Gear : Gear {
        O_EasyTrackLAPTOP
    };
};

class COLO : XO {
    class Gear : Gear {
        O_Cap_Helmet
    };
};

class MIO : COLO {
    class Gear : Gear {
        O_EasyTrackLAPTOP
    };
    class Items : Items {
        other[] = {"O_UavTerminal"};
    };
};

class JTAC : XO {
    class Container : Container {
        O_Medium_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : KatibaGL {
            optional[] = {
                {"1Rnd_SmokeRed_Grenade_shell",8}
            };
        };
        class handGun : O_Pistol {};
    };
    class Gear : Gear {
        GPS
        O_Soldier_Helmet
        O_Laserdesignator
    };
};

class RIFLEMAN : SoldierClass {
    class Container : ContainerClass {
        O_Uniform
        O_Standard_Vest
        O_Big_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Katiba {
            optional[] = {
                {"150Rnd_762x54_Box_Tracer", 2},
                {"1Rnd_HE_Grenade_shell", 8}
            };
        };
        class handGun : O_Pistol {};
    };
    class Gear : O_NormalSoldier {
        O_Soldier_Helmet
    };
    class Items : MoreMedicMaterial {};
};

class RIFLEMAN_AT : RIFLEMAN {
    class Container : Container {
        O_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Katiba {};
        class secondaryWeapon : RPG32 {};
    };
    class Items : BasicMedicMaterial {};
};

class ASSISTANT_RIFLEMAN_AT : RIFLEMAN_AT {
    class Container : Container {
        O_Medium_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Katiba {
            optional[] = {{"RPG32_F", 2}};
        };
    };
};

class AUTORIFLEMAN : RIFLEMAN {
    class Container : Container {
        O_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Zafir {};
    };
    class Items : SmallMedicMaterial {};
};

class EXPLOSIVE_SPECIALIST : RIFLEMAN {
    class Weapons : Weapons {
        class primaryWeapon : Katiba {
            magazinesMax = 8;
        };
    };
    class Items : ExplosiveMaterial {};
};

class COMBAT_ENGINEER : RIFLEMAN {
    class Weapons : Weapons {
        class primaryWeapon : Katiba {};
    };
    class Items : Items {
        other[] = {
            "ToolKit",
            "ACE_DefusalKit"
        };
    };
};

class COMBAT_MEDIC : RIFLEMAN {
    class Container : Container {
        O_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : KatibaC {};
    };
    class Items : CombatMedicMaterial {};
};

class MEDIC : COMBAT_MEDIC {
    class Container : Container {
        O_Big_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Sting {};
    }
    class Items : MedicMaterial {};
};

class MEDIC_TL : MEDIC {
    class Gear : O_NormalSoldier {
        O_EasyTrackPDA
        Team_Medium_Radio
    };
};

class DESIGNATED_MARKSMAN : AUTORIFLEMAN {
    class Weapons : Weapons {
        class primaryWeapon : Mk1 {};
        class handGun : O_Pistol {};
    };
    class Gear : Gear {
        Binocular
    };
};

class AT_SPECIALIST : DESIGNATED_MARKSMAN {
    class Container : Container {
        O_Medium_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Katiba {
            magazinesMax = 8;
        };
        class secondaryWeapon : O_TitanAT {};
    };
};

class ASSISTANT_AT : DESIGNATED_MARKSMAN {
    class Container : Container {
        O_Big_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Katiba {
            magazinesMax = 9;
            optional[] = {{"Titan_AT",2},"Titan_AP"};
        };
    };
};

class AA_SPECIALIST : AT_SPECIALIST {
    class Container : Container {
        O_Medium_Backpack
    };
    class Weapons : Weapons {
        class secondaryWeapon : O_TitanAA {};
    };
};

class ASSISTANT_AA : ASSISTANT_AT {
    class Items : Items {
        other[] = {{"Titan_AA", 2}};
    };
};

class MMG : AUTORIFLEMAN {
    class Container : Container {
        O_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Navid {};
    };
};

class ASSISTANT_MMG : AUTORIFLEMAN {
    class Container : Container {
        O_Medium_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Katiba {
            magazinesMax = 8;
            optional[] = {{"150Rnd_93x64_Mag",4}};
        };
    };
    class Gear : Gear {
        Rangefinder
    };
};

class HMG : AUTORIFLEMAN {
    class Container : Container {
        O_HMG_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Katiba {};
    };
    class Gear : Gear {
        binocular[] = {};
    };
};

class ASSISTANT_HMG : HMG {
    class Container : Container {
        O_Assistant_HMG_Backpack
    };
};

class GRENADIER : AUTORIFLEMAN {
    class Container : Container {
        O_Grenade_Vest
    };
    class Weapons : Weapons {
        class primaryWeapon : KatibaGL {};
    };
    class Items : BasicMedicMaterial {};
};

class JTAC_RFL : GRENADIER {
    class Container : Container {
        O_Medium_Backpack
    };
    class primaryWeapon : KatibaGL {
        optional[] = {
            {"1Rnd_SmokeRed_Grenade_shell", 8}
        };
    };
    class Gear : Gear {
        GPS
        O_Laserdesignator
		Team_Large_Radio
    };
};

class FIRETEAMLEADER : GRENADIER {
    class Gear : Gear {
        Binocular
    };
};

class SQUADLEADER : GRENADIER {
    class Container : Container {
        O_Medium_Backpack
    };
    class Weapons : Weapons {
        class handGun : O_Officer_Pistol {};
    };
    class Gear : Gear {
        Rangefinder
        O_EasyTrackPDA
        Team_Medium_Radio
	};
};

class PLATOONLEADER : SQUADLEADER {
    class Gear : Gear {
        Team_Large_Radio
    };
};

class PLATOONSERGEANT : GRENADIER {
    class Container : Container {
        O_Medium_Backpack
    };
    class Gear : Gear {
        Rangefinder
		Team_Large_Radio
    };
};

class RECON_SCOUT : SoldierClass {
    class Container : ContainerClass {
        O_SpecOp_Uniform
        Tac_Vest
        O_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Katiba {
            barrelAttachment_pool[] = {"muzzle_snds_H"};
            scopes[] += {"optic_Nightstalker"};
            magazinesMax = 6;
        };
        class handGun : O_Pistol {
            barrelAttachment_pool[] = {"muzzle_snds_L"};
        };
    };
    class Gear : O_NormalSoldier {
        O_Beanie_Helmet
        Rangefinder
    };
    class Items : O_SOFMedicMaterial {};
};

class RECON_TL : RECON_SCOUT {
    class Container : Container {
        O_Small_Backpack
    };
    class Gear : Gear {
        O_EasyTrackPDA
        Team_Large_Radio
    };
};

class RECON_ENGINEER : RECON_SCOUT {
    class Container : Container {
        O_Big_Backpack
    };
    class Items : Items {
        other[] = {
            "ToolKit",
            "ACE_DefusalKit"
        };
    };
};

class RECON_MEDIC : RECON_SCOUT {
    class Container : Container {
        O_Big_Backpack
    };
    class Items : O_SOFBigMedicMaterial {};
};

class RECON_DM : RECON_SCOUT {
    class Weapons : Weapons {
        class primaryWeapon : Mk1 {};
    };
};

class RECON_UAV_OPERATOR : RECON_SCOUT {
    class Container : Container {
        O_UAV_Backpack
    };
    class Gear : Gear {
        O_UAV
    };
};

class UAVOPERATOR : RIFLEMAN {
    class Container : Container {
        O_Standard_Vest
        O_UAV_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : KatibaC {
            magazinesMax = 6;
        };
        class handGun : O_Pistol {};
    };
    class Gear : Gear {
        O_UAV
    };
    class Items : SmallMedicMaterial {};
};

class SNIPER : SoldierClass {
    class Container : ContainerClass {
        O_Sniper_Uniform
        O_SOF_Vest
    };
    class Weapons : Weapons {
        class primaryWeapon : GM6 {
            scopes[] += {"optic_Nightstalker"};
        };
        class handGun : O_Pistol {
            barrelAttachment_pool[] = {"muzzle_snds_L"};
        };
    };
    class Gear : O_NormalSoldier {
        O_Sniper_Helmet
    };
    class Items : O_SOFMedicMaterial {};
};

class SPOTTER : SNIPER {
    class Container : Container {
        O_Medium_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Mk1 {
            scopes[] += {"optic_Nightstalker"};
            magazinesMax = 8;
            optional[] = {
                {"5Rnd_127x108_Mag", 5},
                {"5Rnd_127x108_APDS_Mag", 2}
            };
        };
    };
    class Gear : Gear {
        O_EasyTrackPDA
        O_Laserdesignator
        Team_Large_Radio
        other[] = {
            "ACE_ATragMX",
            "ACE_Kestrel4500"
        };
    };
};

class CREW : SoldierClass {
    class Container : ContainerClass {
        O_Uniform
        Tac_Vest
    };
    class Gear : O_NormalSoldier {
        O_Crew_Helmet
    };
    class Weapons : Weapons {
        class primaryWeapon : Sting {};
        class handGun : O_Pistol {};
    };
    class Items : O_SOFMedicMaterial {};
};

class COMMANDER : CREW {
    class Container : Container {
        O_Small_Backpack
    };
    class Weapons : Weapons {
        class handGun : O_Officer_Pistol {};
    };
    class Gear : Gear {
        O_EasyTrackPDA
        Team_Large_Radio
    };
};

class HELICREW : CREW {
    class Container : Container {
        O_Heli_Uniform
        O_Small_Backpack
    };
    class Gear : Gear {
        O_Heli_Helmet
        Team_Large_Radio
    };
};

class HELIPILOT : COMMANDER {
    class Container : Container {
        O_Heli_Uniform
    };
    class Gear : Gear {
        O_Heli_Helmet
    };
};

class JETPILOT : HELIPILOT {
    class Container : ContainerClass {
        O_Jet_Uniform
        O_Bandolier_Vest
        Parachute_Backpack
    };
    class Gear : Gear {
        O_Jet_Helmet
    };
};

class LOGISTICS : SoldierClass {
    class Container : ContainerClass {
        O_Logistics_Uniform
        Belt_Vest
        O_Small_Backpack
    };
	class Weapons : Weapons {
        class primaryWeapon : Sting {};
        class handGun : O_Pistol {};
    };
    class Gear : O_NormalSoldier {
        O_Logistic_Helmet
        O_EasyTrackPDA
        Team_Large_Radio
    };
   class Items : SmallMedicMaterial {
         other[] = {
             "I_UavTerminal",
             "ToolKit"
         };
    };
    onApplyLoadout = "_obj setVariable ['ace_IsEngineer', 1, true];";
};

class LOGISTICS_TL : LOGISTICS {
    class Weapons : Weapons {
        class handGun : O_Officer_Pistol {};
    };
    class Gear : Gear {
        O_Cap_Helmet
    };
};

class DIVER : SoldierClass {
    class Container : ContainerClass {
        O_Diver_Uniform
        O_Diver_Vest
        Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : O_SDAR {};
        class handGun : O_Pistol {
            barrelAttachment_pool[] = {"muzzle_snds_L"};
        };
    };
    class Gear : O_NormalSoldier {
        helmet_pool[] = {};
        O_Diver_Goggle
        O_Laserdesignator
    };
    class Items : O_SOFMedicMaterial {};
};
