class CO : SoldierClass {
    class Container : ContainerClass {
        I_Uniform
        I_Light_Vest
        I_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Mk20C {};
        class handGun : I_Officer_Pistol {};
    };
    class Gear : I_NormalSoldier {
        I_EasyTrackPDA
        I_Officer_Helmet
        Rangefinder
        Team_Medium_Large_Radio
    };
    class Items : SmallMedicMaterial {};
};

class XO : CO {
    class Gear : Gear {
        I_EasyTrackLAPTOP
    };
};

class COLO : XO {
    class Gear : Gear {
        I_Cap_Helmet
    };
};

class MIO : COLO {
    class Gear : Gear {
        I_EasyTrackLAPTOP
    };
    class Items : Items {
        other[] = {"I_UavTerminal"};
    };
};

class JTAC : XO {
    class Container : Container {
        I_Medium_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Mk20GL {
            optional[] = {
                {"1Rnd_SmokeRed_Grenade_shell",8}
            };
        };
        class handGun : I_Pistol {};
    };
    class Gear : Gear {
        GPS
        I_Soldier_Helmet
        I_Laserdesignator
    };
};

class RIFLEMAN : SoldierClass {
    class Container : ContainerClass {
        I_Uniform
        I_Standard_Vest
        I_Big_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Mk20 {
            optional[] = {
                {"200Rnd_65x39_cased_Box_Tracer", 2},
                {"1Rnd_HE_Grenade_shell", 8}
            };
        };
        class handGun : I_Pistol {};
    };
    class Gear : I_NormalSoldier {
        I_Soldier_Helmet
    };
    class Items : MoreMedicMaterial {};
};

class RIFLEMAN_AT : RIFLEMAN {
    class Container : Container {
        I_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Mk20 {};
        class secondaryWeapon : PCML {};
    };
    class Items : BasicMedicMaterial {};
};

class ASSISTANT_RIFLEMAN_AT : RIFLEMAN_AT {
    // In ACE PCML is single use, so give assistant own launcher.
};

class AUTORIFLEMAN : RIFLEMAN {
    class Container : Container {
        I_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Mk200 {};
    };
    class Items : SmallMedicMaterial {};
};

class EXPLOSIVE_SPECIALIST : RIFLEMAN {
    class Weapons : Weapons {
        class primaryWeapon : Mk20 {
            magazinesMax = 8;
        };
    };
    class Items : ExplosiveMaterial {};
};

class COMBAT_ENGINEER : RIFLEMAN {
    class Weapons : Weapons {
        class primaryWeapon : Mk20 {};
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
        I_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Mk20C {};
    };
    class Items : CombatMedicMaterial {};
};

class MEDIC : COMBAT_MEDIC {
    class Container : Container {
        I_Big_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : PDW2000 {};
    }
    class Items : MedicMaterial {};
};

class MEDIC_TL : MEDIC {
    class Gear : I_NormalSoldier {
        I_EasyTrackPDA
        Team_Medium_Radio
    };
};

class DESIGNATED_MARKSMAN : AUTORIFLEMAN {
    class Weapons : Weapons {
        class primaryWeapon : Mk1 {};
        class handGun : I_Pistol {};
    };
    class Gear : Gear {
        Binocular
    };
};

class AT_SPECIALIST : DESIGNATED_MARKSMAN {
    class Container : Container {
        I_Medium_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Mk20 {
            magazinesMax = 8;
        };
        class secondaryWeapon : I_TitanAT {};
    };
};

class ASSISTANT_AT : DESIGNATED_MARKSMAN {
    class Container : Container {
        I_Big_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Mk20 {
            magazinesMax = 9;
            optional[] = {{"Titan_AT",2},"Titan_AP"};
        };
    };
};

class AA_SPECIALIST : AT_SPECIALIST {
    class Container : Container {
        I_Medium_Backpack
    };
    class Weapons : Weapons {
        class secondaryWeapon : I_TitanAA {};
    };
};

class ASSISTANT_AA : ASSISTANT_AT {
    class Items : Items {
        other[] = {{"Titan_AA", 2}};
    };
};

class MMG : AUTORIFLEMAN {
    class Container : Container {
        I_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : SPMG {};
    };
};

class ASSISTANT_MMG : AUTORIFLEMAN {
    class Container : Container {
        I_Medium_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Mk20 {
            magazinesMax = 8;
            optional[] = {{"130Rnd_338_Mag",5}};
        };
    };
    class Gear : Gear {
        Rangefinder
    };
};

class HMG : AUTORIFLEMAN {
    class Container : Container {
        I_HMG_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Mk20 {};
    };
    class Gear : Gear {
        binocular[] = {};
    };
};

class ASSISTANT_HMG : HMG {
    class Container : Container {
        I_Assistant_HMG_Backpack
    };
};

class GRENADIER : AUTORIFLEMAN {
    class Container : Container {
        I_Grenade_Vest
    };
    class Weapons : Weapons {
        class primaryWeapon : Mk20GL {};
    };
    class Items : BasicMedicMaterial {};
};

class JTAC_RFL : GRENADIER {
    class Container : Container {
        I_Medium_Backpack
    };
    class primaryWeapon : Mk20GL {
        optional[] = {
            {"1Rnd_SmokeRed_Grenade_shell", 8}
        };
    };
    class Gear : Gear {
        GPS
        I_Laserdesignator
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
        I_Medium_Backpack
    };
    class Weapons : Weapons {
        class handGun : I_Officer_Pistol {};
    };
    class Gear : Gear {
        Rangefinder
        I_EasyTrackPDA
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
        I_Medium_Backpack
    };
    class Gear : Gear {
        Rangefinder
		Team_Large_Radio
    };
};

class RECON_SCOUT : SoldierClass {
    class Container : ContainerClass {
        I_SpecOp_Uniform
        Tac_Vest
        I_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Mk20 {
            barrelAttachment_pool[] = {"muzzle_snds_H"};
            scopes[] += {"optic_Nightstalker"};
            magazinesMax = 6;
        };
        class handGun : I_Pistol {
            barrelAttachment_pool[] = {"muzzle_snds_L"};
        };
    };
    class Gear : I_NormalSoldier {
        I_Beanie_Helmet
        Rangefinder
    };
    class Items : I_SOFMedicMaterial {};
};

class RECON_TL : RECON_SCOUT {
    class Container : Container {
        I_Small_Backpack
    };
    class Gear : Gear {
        I_EasyTrackPDA
        Team_Large_Radio
    };
};

class RECON_ENGINEER : RECON_SCOUT {
    class Container : Container {
        I_Big_Backpack
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
        I_Big_Backpack
    };
    class Items : I_SOFBigMedicMaterial {};
};

class RECON_DM : RECON_SCOUT {
    class Weapons : Weapons {
        class primaryWeapon : Mk1 {};
    };
};

class RECON_UAV_OPERATOR : RECON_SCOUT {
    class Container : Container {
        I_UAV_Backpack
    };
    class Gear : Gear {
        I_UAV
    };
};

class UAVOPERATOR : RIFLEMAN {
    class Container : Container {
        I_Standard_Vest
        I_UAV_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Mk20C {
            magazinesMax = 6;
        };
        class handGun : I_Pistol {};
    };
    class Gear : Gear {
        I_UAV
    };
    class Items : SmallMedicMaterial {};
};

class SNIPER : SoldierClass {
    class Container : ContainerClass {
        I_Sniper_Uniform
        I_SOF_Vest
    };
    class Weapons : Weapons {
        class primaryWeapon : GM6 {
            scopes[] += {"optic_Nightstalker"};
        };
        class handGun : I_Pistol {
            barrelAttachment_pool[] = {"muzzle_snds_L"};
        };
    };
    class Gear : I_NormalSoldier {
        I_Sniper_Helmet
    };
    class Items : I_SOFMedicMaterial {};
};

class SPOTTER : SNIPER {
    class Container : Container {
        I_Medium_Backpack
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
        I_EasyTrackPDA
		I_Laserdesignator
        Team_Large_Radio
        other[] = {
            "ACE_ATragMX",
            "ACE_Kestrel4500"
        };
    };
};

class CREW : SoldierClass {
    class Container : ContainerClass {
        I_Uniform
        Tac_Vest
    };
    class Gear : I_NormalSoldier {
        I_Crew_Helmet
    };
    class Weapons : Weapons {
        class primaryWeapon : PDW2000 {};
        class handGun : I_Pistol {};
    };
    class Items : I_SOFMedicMaterial {};
};

class COMMANDER : CREW {
    class Container : Container {
        I_Small_Backpack
    };
    class Weapons : Weapons {
        class handGun : I_Officer_Pistol {};
    };
    class Gear : Gear {
        I_EasyTrackPDA
        Team_Large_Radio
    };
};

class HELICREW : CREW {
    class Container : Container {
        I_Heli_Uniform
        I_Small_Backpack
    };
    class Gear : Gear {
        I_Heli_Helmet
        Team_Large_Radio
    };
};

class HELIPILOT : COMMANDER {
    class Container : Container {
        I_Heli_Uniform
    };
    class Gear : Gear {
        I_Heli_Helmet
    };
};

class JETPILOT : HELIPILOT {
    class Container : ContainerClass {
        I_Jet_Uniform
        I_Bandolier_Vest
        Parachute_Backpack
    };
    class Gear : Gear {
        I_Jet_Helmet
    };
};

class LOGISTICS : SoldierClass {
    class Container : ContainerClass {
        I_Logistics_Uniform
        Belt_Vest
        I_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : PDW2000 {};
        class handGun : I_Pistol {};
    };
    class Gear : I_NormalSoldier {
        I_Logistic_Helmet
        I_EasyTrackPDA
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
        class handGun : I_Officer_Pistol {};
    };
    class Gear : Gear {
        I_Cap_Helmet
    };
};

class DIVER : SoldierClass {
    class Container : ContainerClass {
        I_Diver_Uniform
        I_Diver_Vest
        Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : I_SDAR {};
        class handGun : I_Pistol {
            barrelAttachment_pool[] = {"muzzle_snds_L"};
        };
    };
    class Gear : I_NormalSoldier {
        helmet_pool[] = {};
        I_Diver_Goggle
        I_Laserdesignator
    };
    class Items : I_SOFMedicMaterial {};
};
