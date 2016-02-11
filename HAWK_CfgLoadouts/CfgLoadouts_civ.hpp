class VIP : SoldierClass {
    class Container : ContainerClass {
        uniform_pool[] = {"LOP_U_CHR_Functionary_01"};
        vest_pool[] = {};
        backpack_pool[] = {};
    };
    class Weapons : Weapons {
        class primaryWeapon {
            weapon_pool[] = {};
            barrelAttachment_pool[] = {};
            magazine = "30Rnd_65x39_caseless_mag_Tracer";
            magazinesMax = 0;
            scopes[] = {};
        };
        class handGun : B_Officer_Pistol {};
    };
    class Gear : BasicGear {
        GPS
    };
    class Items {
        grenades[] = {
            {"SmokeShellGreen",2},
            {"SmokeShell",2},
            "ACE_EarPlugs"
        };
        medicMaterial[] = {};
    };
};
