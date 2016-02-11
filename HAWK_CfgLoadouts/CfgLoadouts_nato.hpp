class CO : SoldierClass {
    class Container : ContainerClass {
        B_Uniform
        B_Light_Vest
        B_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : MXC {};
        class handGun : B_Officer_Pistol {};
    };
    class Gear : B_NormalSoldier {
		B_EasyTrackPDA
        B_Officer_Helmet
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
        B_Cap_Helmet
    };
};

class MIO : COLO {
    class Gear : Gear {
        B_EasyTrackLAPTOP
    };
    class Items : Items {
        other[] = {"B_UavTerminal"};
    };
};

class JTAC : XO {
    class Container : Container {
        O_Medium_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : MXGL {
            optional[] = {
                {"1Rnd_SmokeRed_Grenade_shell",8}
            };
        };
        class handGun : B_Pistol {};
    };
    class Gear : Gear {
		GPS
        B_Advanced_Helmet
        B_Laserdesignator
    };
};

class RIFLEMAN : SoldierClass {
    class Container : ContainerClass {
        B_Uniform
        B_Standard_Vest
        B_Big_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : MX {
            optional[] = {
                {"100Rnd_65x39_caseless_mag", 4},
                {"1Rnd_HE_Grenade_shell", 8}
            };
        };
        class handGun : B_Pistol {};
    };
    class Gear : B_NormalSoldier {
        B_Soldier_Helmet
    };
    class Items : MoreMedicMaterial {};
};

class RIFLEMAN_AT : RIFLEMAN {
    class Container : Container {
        B_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : MX {};
        class secondaryWeapon : PCML {};
    };
    class Items : BasicMedicMaterial {};
};

class ASSISTANT_RIFLEMAN_AT : RIFLEMAN_AT {
    // In ACE PCML is single use, so give assistant own launcher.
};

class AUTORIFLEMAN : RIFLEMAN {
    class Container : Container {
        B_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : MXSW {};
    };
    class Items : SmallMedicMaterial {};
};

class EXPLOSIVE_SPECIALIST : RIFLEMAN {
    class Weapons : Weapons {
        class primaryWeapon : MX {
            magazinesMax = 8;
        };
    };
    class Items : ExplosiveMaterial {};
};

class COMBAT_ENGINEER : RIFLEMAN {
    class Weapons : Weapons {
        class primaryWeapon : MX {};
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
        B_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : MXC {};
    };
    class Items : CombatMedicMaterial {};
};

class MEDIC : COMBAT_MEDIC {
    class Container : Container {
        B_Big_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Vermin {};
    }
    class Items : MedicMaterial {};
};

class MEDIC_TL : MEDIC {
    class Gear : B_NormalSoldier {
        B_EasyTrackPDA
        Team_Medium_Radio
    };
};

class DESIGNATED_MARKSMAN : AUTORIFLEMAN {
    class Weapons : Weapons {
        class primaryWeapon : ABR {};
        class handGun : B_Pistol {};
    };
    class Gear : Gear {
        Binocular
    };
};

class AT_SPECIALIST : DESIGNATED_MARKSMAN {
    class Container : Container {
        B_Medium_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : MX {
            magazinesMax = 8;
        };
        class secondaryWeapon : B_TitanAT {};
    };
};

class ASSISTANT_AT : DESIGNATED_MARKSMAN {
    class Container : Container {
        B_Big_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : MX {
            magazinesMax = 9;
            optional[] = {{"Titan_AT",2},"Titan_AP"};
        };
    };
};

class AA_SPECIALIST : AT_SPECIALIST {
    class Container : Container {
        B_Medium_Backpack
    };
    class Weapons : Weapons {
        class secondaryWeapon : B_TitanAA {};
    };
};

class ASSISTANT_AA : ASSISTANT_AT {
    class Items : Items {
        other[] = {{"Titan_AA", 2}};
    };
};

class MMG : AUTORIFLEMAN {
    class Container : Container {
        B_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : SPMG {};
    };
};

class ASSISTANT_MMG : AUTORIFLEMAN {
    class Container : Container {
        B_Medium_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : MX {
            magazinesMax = 8;
            optional[] = {{"130Rnd_338_Mag",4}};
        };
    };
    class Gear : Gear {
        Rangefinder
    };
};

class HMG : AUTORIFLEMAN {
    class Container : Container {
        B_HMG_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : MX {};
    };
    class Gear : Gear {
        binocular[] = {};
    };
};

class ASSISTANT_HMG : HMG {
    class Container : Container {
        B_Assistant_HMG_Backpack
    };
};

class GRENADIER : AUTORIFLEMAN {
    class Container : Container {
        B_Grenade_Vest
    };
    class Weapons : Weapons {
        class primaryWeapon : MXGL {};
    };
    class Items : BasicMedicMaterial {};
};

class JTAC_RFL : GRENADIER {
    class Container : Container {
        B_Medium_Backpack
    };
    class primaryWeapon : MXGL {
        optional[] = {
            {"1Rnd_SmokeRed_Grenade_shell", 8}
        };
    };
    class Gear : Gear {
        GPS
        B_Laserdesignator
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
        B_Medium_Backpack
    };
    class Weapons : Weapons {
        class handGun : B_Officer_Pistol {};
    };
    class Gear : Gear {
        Rangefinder
        B_EasyTrackPDA
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
        B_Medium_Backpack
    };
    class Gear : Gear {
        Rangefinder
		Team_Large_Radio
    };
};

class RECON_SCOUT : SoldierClass {
    class Container : ContainerClass {
        B_SpecOp_Uniform
        Tac_Vest
        B_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : MX {
            barrelAttachment_pool[] = {"muzzle_snds_H"};
            scopes[] += {"optic_Nightstalker"};
            magazinesMax = 6;
        };
        class handGun : B_Pistol {
            barrelAttachment_pool[] = {"muzzle_snds_L"};
        };
    };
    class Gear : B_NormalSoldier {
        B_Beanie_Helmet
        Rangefinder
    };
    class Items : B_SOFMedicMaterial {};
};

class RECON_TL : RECON_SCOUT {
    class Container : Container {
        B_Small_Backpack
    };
    class Gear : Gear {
        B_EasyTrackPDA
        Team_Large_Radio
    };
};

class RECON_ENGINEER : RECON_SCOUT {
    class Container : Container {
        B_Big_Backpack
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
        B_Big_Backpack
    };
    class Items : B_SOFBigMedicMaterial {};
};

class RECON_DM : RECON_SCOUT {
    class Weapons : Weapons {
        class primaryWeapon : ABR {};
    };
};

class RECON_UAV_OPERATOR : RECON_SCOUT {
    class Container : Container {
        B_UAV_Backpack
    };
    class Gear : Gear {
        B_UAV
    };
};

class UAVOPERATOR : RIFLEMAN {
    class Container : Container {
        vest_pool[] = {"V_PlateCarrierSpec_rgr"};
        B_UAV_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : MXC {
            magazinesMax = 6;
        };
        class handGun : B_Pistol {};
    };
    class Gear : Gear {
        B_UAV
    };
    class Items : SmallMedicMaterial {};
};

class SNIPER : SoldierClass {
    class Container : ContainerClass {
        B_Sniper_Uniform
        B_SOF_Vest
    };
    class Weapons : Weapons {
        class primaryWeapon : LRR {
            scopes[] += {"optic_Nightstalker"};
        };
        class handGun : B_Pistol {
            barrelAttachment_pool[] = {"muzzle_snds_L"};
        };
    };
    class Gear : B_NormalSoldier {
        B_Sniper_Helmet
    };
    class Items : B_SOFMedicMaterial {};
};

class SPOTTER : SNIPER {
    class Container : Container {
        B_Medium_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : ABR {
            scopes[] += {"optic_Nightstalker"};
            magazinesMax = 8;
            optional[] = {{"7Rnd_408_Mag", 7}};
        };
    };
    class Gear : Gear {
        B_EasyTrackPDA
		B_Laserdesignator
        Team_Large_Radio
        other[] = {
            "ACE_ATragMX",
            "ACE_Kestrel4500"
        };
    };
};

class CREW : SoldierClass {
    class Container : ContainerClass {
        B_Uniform
        Tac_Vest
    };
    class Gear : B_NormalSoldier {
        B_Crew_Helmet
    };
    class Weapons : Weapons {
        class primaryWeapon : Vermin {};
        class handGun : B_Pistol {};
    };
    class Items : B_SOFMedicMaterial {};
};

class COMMANDER : CREW {
    class Container : Container {
        B_Small_Backpack
    };
    class Weapons : Weapons {
        class handGun : B_Officer_Pistol {};
    };
    class Gear : Gear {
        B_EasyTrackPDA
        Team_Large_Radio
    };
};

class HELICREW : CREW {
    class Container : Container {
        B_Heli_Uniform
        B_Small_Backpack
    };
    class Gear : Gear {
        B_Heli_Helmet
        Team_Large_Radio
    };
};

class HELIPILOT : COMMANDER {
    class Container : Container {
        B_Heli_Uniform
    };
    class Gear : Gear {
        B_Heli_Helmet
    };
};

class JETPILOT : HELIPILOT {
    class Container : ContainerClass {
        B_Jet_Uniform
        B_Bandolier_Vest
        Parachute_Backpack
    };
    class Gear : Gear {
        B_Jet_Helmet
    };
};

class LOGISTICS : SoldierClass {
    class Container : ContainerClass {
        B_Logistics_Uniform
        Belt_Vest
        B_Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : Vermin {};
        class handGun : B_Pistol {};
    };
    class Gear : B_NormalSoldier {
        B_Logistic_Helmet
        B_EasyTrackPDA
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
        class handGun : B_Officer_Pistol {};
    };
    class Gear : Gear {
        B_Cap_Helmet
    };
};

class DIVER : SoldierClass {
    class Container : ContainerClass {
        B_Diver_Uniform
        B_Diver_Vest
        Small_Backpack
    };
    class Weapons : Weapons {
        class primaryWeapon : B_SDAR {};
        class handGun : B_Pistol {
            barrelAttachment_pool[] = {"muzzle_snds_L"};
        };
    };
    class Gear : B_NormalSoldier {
        helmet_pool[] = {};
        B_Diver_Goggle
        B_Laserdesignator
    };
    class Items : B_SOFMedicMaterial {};
};
