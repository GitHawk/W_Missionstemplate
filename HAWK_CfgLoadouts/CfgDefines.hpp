class ContainerClass {
    uniform_pool[] = {};
    vest_pool[] = {};
    backpack_pool[] = {};
};

class GearClass {
    helmet_pool[] = {};
    goggle_pool[] = {};
    nightvision_pool[] = {};
    map_pool[] = {};
    gps_pool[] = {};
    compass_pool[] = {};
    clock_pool[] = {};
    radios[] = {};
    binocular[] = {};
};

class WeaponClass {
    weapon_pool[] = {};
    muzzleAttachment_pool[] = {};
    weaponRestingAttachment_pool[] = {};
    barrelAttachment_pool[] = {};
    scopes[] = {};
    optional[] = {};
    magazine = "";
    magazineTracer = "";
    magazinesMax = 0;
    magazinesTracerEvery = 3;
};

class ItemsClass {
    ace[] = {};
    grenades[] = {};
    medicMaterial[] = {};
    other[] = {};
    onApplyLoadout = "";
};

class SoldierClass {
    class Container : ContainerClass {};
    class Gear : GearClass {};
    class Weapons {
        class primaryWeapon : WeaponClass {};
        class secondaryWeapon : WeaponClass {};
        class handGun : WeaponClass {};
    };
    class Items : ItemsClass {};
    onApplyLoadout = "";
};
