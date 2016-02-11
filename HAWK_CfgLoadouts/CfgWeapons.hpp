// "bipod_01_F_blk", // groß, auch mit _mtp, _snd
// "bipod_02_F_blk" // klein, auch mit _hex, _tan, _blk, _oli

// Scopes
class ACO : WeaponClass {
    scopes[] = {"optic_Aco"};
};

class HAMR : WeaponClass {
    scopes[] = {"optic_Hamr"};
};

class ARCO : WeaponClass {
    scopes[] = {"optic_Arco"};
};

class DMS : WeaponClass {
    scopes[] = {"optic_DMS"};
};

class SOS : WeaponClass {
    scopes[] = {"optic_SOS"};
};

class LRPS : WeaponClass {
    scopes[] = {"optic_LRPS"};
};

class Nightstalker : WeaponClass {
    scopes[] = {"optic_Nightstalker"};
};

class Holosight : WeaponClass {
    scopes[] = {"optic_Holosight"};
};

class Holosight_SMG : WeaponClass {
    scopes[] = {"optic_Holosight_smg"};
}

// Pistols
class B_Pistol : WeaponClass {
    weapon_pool[] = {"hgun_P07_F"};
    magazine = "16Rnd_9x21_Mag";
    magazinesMax = 2;
};

class O_Pistol : WeaponClass {
    weapon_pool[] = {"hgun_Rook40_F"};
    magazine = "16Rnd_9x21_Mag";
    magazinesMax = 2;
};

class I_Pistol : WeaponClass {
    weapon_pool[] = {"hgun_ACPC2_F"};
    magazine = "9Rnd_45ACP_Mag";
    magazinesMax = 2;
};

class B_Officer_Pistol : WeaponClass {
    weapon_pool[] = {"hgun_Pistol_heavy_01_F"};
    magazine = "11Rnd_45ACP_Mag";
    magazinesMax = 2;
};

class O_Officer_Pistol : WeaponClass {
    weapon_pool[] = {"hgun_Pistol_heavy_02_F"};
    magazine = "6Rnd_45ACP_Cylinder";
    magazinesMax = 4;
};

class I_Officer_Pistol : I_Pistol {};

// Machine pistols
class Vermin : Holosight_SMG {
    weapon_pool[] = {"SMG_01_F"};
    magazine = "30Rnd_45ACP_Mag_SMG_01_tracer_green";
    magazinesMax = 3;
};
class Sting : Holosight_SMG {
    weapon_pool[] = {"SMG_02_F"};
    magazine = "30Rnd_9x21_Mag";
    magazinesMax = 3;
};
class PDW2000 : Holosight_SMG {
    weapon_pool[] = {"hgun_PDW2000_F"};
    magazine = "30Rnd_9x21_Mag";
    magazinesMax = 3;
};

// Infantry rifles
class MX : HAMR {
    weapon_pool[] = {"arifle_MX_F", "arifle_MX_Black_F"};
    barrelAttachment_pool[] = {"acc_pointer_IR"};
    magazine = "30Rnd_65x39_caseless_mag_Tracer";
    magazinesMax = 12;
};

class MXGL : MX {
    weapon_pool[] = {"arifle_MX_GL_F", "arifle_MX_GL_Black_F"};
    magazinesMax = 9;
    optional[] = {
        {"1Rnd_HE_Grenade_shell",12},
        {"1Rnd_SmokeRed_Grenade_shell",8}
    };
};

class MXSW : MX {
    weapon_pool[] = {"arifle_MX_SW_F", "arifle_MX_SW_Black_F"};
    weaponRestingAttachment_pool[] = {"bipod_02_F_blk"};
    magazine = "100Rnd_65x39_caseless_mag_Tracer";
    magazinesMax = 10;
};

class MXC : Holosight {
    weapon_pool[] = {"arifle_MXC_F", "arifle_MXC_Black_F"};
    magazine = "30Rnd_65x39_caseless_mag_Tracer";
    magazinesMax = 8;
};

class Katiba : ARCO {
    weapon_pool[] = {"arifle_Katiba_F"};
    barrelAttachment_pool[] = {"acc_pointer_IR"};
    magazine = "30Rnd_65x39_caseless_green_mag_Tracer";
    magazinesMax = 12;
};

class KatibaGL : Katiba {
    weapon_pool[] = {"arifle_Katiba_GL_F"};
    magazinesMax = 9;
    optional[] = {
        {"1Rnd_HE_Grenade_shell",12},
        {"1Rnd_SmokeRed_Grenade_shell",8}
    };
};

class Zafir : ARCO {
    weapon_pool[] = {"LMG_Zafir_F"};
    magazine = "150Rnd_762x54_Box_Tracer";
    magazinesMax = 5;
};

class KatibaC : Holosight {
    weapon_pool[] = {"arifle_Katiba_C_F"};
    magazine = "30Rnd_65x39_caseless_green_mag_Tracer";
    magazinesMax = 8;
};

class Mk20 : HAMR {
    weapon_pool[] = {"arifle_Mk20_F"};
    barrelAttachment_pool[] = {"acc_pointer_IR"};
    magazine = "30Rnd_556x45_Stanag_Tracer_Yellow";
    magazinesMax = 12;
};

class Mk20GL : Mk20 {
    weapon_pool[] = {"arifle_Mk20_GL_F"};
    magazinesMax = 9;
    optional[] = {
        {"1Rnd_HE_Grenade_shell",12},
        {"1Rnd_SmokeRed_Grenade_shell",8}
    };
};

class Mk200 : ARCO {
    weapon_pool[] = {"LMG_Mk200_F", "LMG_Mk200_BI_F"};
    weaponRestingAttachment_pool[] = {"bipod_02_F_blk"};
    magazine = "200Rnd_65x39_cased_Box_Tracer";
    magazinesMax = 5;
};

class Mk20C : Holosight {
    weapon_pool[] = {"arifle_Mk20C_F"};
    magazine = "30Rnd_556x45_Stanag_Tracer_Yellow";
    magazinesMax = 8;
};

class B_SDAR : WeaponClass {
    weapon_pool[] = {"arifle_SDAR_F"};
    magazine = "30Rnd_556x45_Stanag_Tracer_Red";
    magazinesMax = 4;
    optional[] = {
        {"20Rnd_556x45_UW_mag",2}
    };
};
class O_SDAR : B_SDAR {
    magazine = "30Rnd_556x45_Stanag_Tracer_Green";
};
class I_SDAR : B_SDAR {
    magazine = "30Rnd_556x45_Stanag_Tracer_Yellow";
};

// Designated marksman rifles
class MXM : MX {
    weapon_pool[] = {"arifle_MXM_F", "arifle_MXM_Black_F"};
    scopes[] = {"optic_DMS"};
    weaponRestingAttachment_pool[] = {"bipod_01_F_snd"};
    barrelAttachment_pool[] = {"acc_pointer_IR"};
    muzzleAttachment_pool[] = {"muzzle_snds_H"};
};

class ABR : DMS {
    weapon_pool[] = {"srifle_EBR_F"};
    weaponRestingAttachment_pool[] = {"bipod_02_F_blk"};
    barrelAttachment_pool[] = {"acc_pointer_IR"};
    magazine = "20Rnd_762x51_Mag";
    magazinesMax = 12;
};

class Mk1 : ABR {
    weapon_pool[] = {"srifle_DMR_03_F","srifle_DMR_03_multicam_F","srifle_DMR_03_khaki_F","srifle_DMR_03_tan_F"};
    muzzleAttachment_pool[] = {"muzzle_snds_B"};
    magazine = "20Rnd_762x51_Mag";
};

class Rahim : DMS {
    weapon_pool[] = {"srifle_DMR_01_F"};
    weaponRestingAttachment_pool[] = {"bipod_02_F_blk"};
    muzzleAttachment_pool[] = {"muzzle_snds_B"};
    magazine = "10Rnd_762x54_Mag";
    magazinesMax = 15;
};

// Sniper rifle
class GM6 : LRPS {
    weapon_pool[] = {"srifle_GM6_F", "srifle_GM6_camo_F"};
    weaponRestingAttachment_pool[] = {};
    barrelAttachment_pool[] = {};
    magazine = "5Rnd_127x108_Mag";
    magazinesMax = 5;
    optional[] = {"5Rnd_127x108_APDS_Mag"};
};

class LRR : LRPS {
    weapon_pool[] = {"srifle_LRR_F", "srifle_LRR_camo_F"};
    weaponRestingAttachment_pool[] = {};
    barrelAttachment_pool[] = {};
    magazine = "7Rnd_408_Mag";
    magazinesMax = 7;
};

// Medium machine guns
class SPMG : HAMR {
    weapon_pool[] = {"MMG_02_camo_F", "MMG_02_black_F", "MMG_02_sand_F"};
    weaponRestingAttachment_pool[] = {"bipod_01_F_mtp"};
    barrelAttachment_pool[] = {"acc_pointer_IR"};
    magazine = "130Rnd_338_Mag";
    magazinesMax = 4;
};

class Navid : ARCO {
    weapon_pool[] = {"MMG_01_hex_F", "MMG_01_tan_F"};
    weaponRestingAttachment_pool[] = {"bipod_02_F_hex"};
    barrelAttachment_pool[] = {"acc_pointer_IR"};
    magazine = "150Rnd_93x64_Mag";
    magazinesMax = 4;
};

// AT
class PCML : WeaponClass {
    weapon_pool[] = {"launch_NLAW_F"};
    magazine = "NLAW_F";
    magazinesMax = 0;
};

class RPG32 : WeaponClass {
    weapon_pool[] = {"launch_RPG32_F"};
    magazine = "RPG32_F";
    magazinesMax = 1;
    optional[] = {"RPG32_HE_F"};
};

class B_TitanAT : WeaponClass {
    weapon_pool[] = {"launch_B_Titan_short_F"};
    magazine = "Titan_AT";
    magazinesMax = 1;
    optional[] = {"Titan_AP"};
};

class O_TitanAT : B_TitanAT {
    weapon_pool[] = {"launch_O_Titan_short_F"};
};

class I_TitanAT : B_TitanAT {
    weapon_pool[] = {"launch_I_Titan_short_F"};
};

// AA
class B_TitanAA : WeaponClass {
    weapon_pool[] = {"launch_B_Titan_F"};
    magazine = "Titan_AA";
    magazinesMax = 1;
};

class O_TitanAA : B_TitanAA {
    weapon_pool[] = {"launch_B_Titan_F"};
};

class I_TitanAA : B_TitanAA {
    weapon_pool[] = {"launch_I_Titan_F"};
};
