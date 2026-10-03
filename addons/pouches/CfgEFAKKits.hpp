// The pouches, registered as kits of Enhanced First Aid Kits (see its addons/core/CfgEFAKKits.hpp for
// every property). Not medical: they take anything (itemFilter 0) or only one kind of item
// (itemTypes), ACE treatments leave them alone (useInTreatments 0), and they have a menu and a
// settings category of their own.

#define POUCH_COMMON \
    instances = EUP_INSTANCES_PER_POUCH; \
    background = ""; \
    useInTreatments = 0; \
    group = "Pouches"; \
    settingsCategory = CBA_SETTINGS_EUP

class EFAK_Kits {
    // Anything that fits: chemlights, smokes, cable ties, a map, spare batteries.
    class EUP_UtilityPouch {
        item = "eup_UtilityPouch";
        shortName = CSTRING(UtilityPouch_Short);
        icon = QPATHTOF(ui\UtilityPouch.paa);
        iconContents = QPATHTOF(ui\UtilityPouch.paa);
        capacity = 30;
        defaultContents = "";
        itemFilter = 0;
        POUCH_COMMON;
    };

    // Magazines only - rifle and pistol magazines, grenades, flares.
    class EUP_AmmoPouch {
        item = "eup_AmmoPouch";
        shortName = CSTRING(AmmoPouch_Short);
        icon = QPATHTOF(ui\AmmoPouch.paa);
        iconContents = QPATHTOF(ui\AmmoPouch.paa);
        capacity = 50;
        defaultContents = "";
        itemFilter = 0;
        itemTypes[] = {"magazine"};
        POUCH_COMMON;
    };

    // The big one for magazines: belts, rockets and spare ammo for the team.
    class EUP_AmmoBag {
        item = "eup_AmmoBag";
        shortName = CSTRING(AmmoBag_Short);
        icon = QPATHTOF(ui\AmmoBag.paa);
        iconContents = QPATHTOF(ui\AmmoBag.paa);
        capacity = 240;
        defaultContents = "";
        itemFilter = 0;
        itemTypes[] = {"magazine"};
        // A bag rather than a pouch: the hard realism modes unload it into the backpack.
        bag = 1;
        POUCH_COMMON;
    };

    // Tools and things that go bang: toolkit, wire cutter, defusal kit, clacker, charges and mines
    // (the explosives are "secondary" magazines to ACE).
    class EUP_EngineerBag {
        item = "eup_EngineerBag";
        shortName = CSTRING(EngineerBag_Short);
        icon = QPATHTOF(ui\EngineerBag.paa);
        iconContents = QPATHTOF(ui\EngineerBag.paa);
        capacity = 200;
        defaultContents = "ToolKit 1 ACE_wirecutter 1 ACE_DefusalKit 1 ACE_Clacker 1";
        itemFilter = 0;
        itemTypes[] = {"item", "magazine/secondary"};
        bag = 1;
        POUCH_COMMON;
    };

    // CBRN gear and nothing else: the list below (itemFilter 2). Suits, masks and the breathing sets
    // (backpacks) are worn things, which only go into a container that names them (itemTypes).
    // Classes of mods that are not loaded are simply never met.
    class EUP_CBRNBag {
        item = "eup_CBRNBag";
        shortName = CSTRING(CBRNBag_Short);
        icon = QPATHTOF(ui\CBRNBag.paa);
        iconContents = QPATHTOF(ui\CBRNBag.paa);
        capacity = 250;
        defaultContents = "G_AirPurifyingRespirator_01_F 1 ChemicalDetector_01_watch_F 1";
        itemFilter = 2;
        itemTypes[] = {"item/uniform", "item/glasses", "item/goggles", "backpack"};
        whitelist = "B_SCBA_01_F, B_CombinationUnitRespirator_01_F, U_B_CBRN_Suit_01_MTP_F, U_B_CBRN_Suit_01_Tropic_F, U_B_CBRN_Suit_01_Wdl_F, U_I_CBRN_Suit_01_AAF_F, U_I_E_CBRN_Suit_01_EAF_F, U_C_CBRN_Suit_01_Blue_F, U_C_CBRN_Suit_01_White_F, G_AirPurifyingRespirator_01_F, G_AirPurifyingRespirator_01_nofilter_F, G_AirPurifyingRespirator_02_black_F, G_AirPurifyingRespirator_02_olive_F, G_AirPurifyingRespirator_02_sand_F, G_RegulatorMask_F, ChemicalDetector_01_watch_F, kat_mask_M50, kat_mask_M04, kat_gasmaskFilter, kat_sealant, kat_m8paper, kat_decon_kit, KAT_ChemicalDetector, ACM_GasMaskFilter, ACM_Autoinjector_ATNA";
        bag = 1;
        POUCH_COMMON;
    };
};

// Their own entry in the interaction menu, next to EFAK's first aid kits.
class EFAK_KitGroups {
    class Pouches {
        displayName = CSTRING(Action_Root);
        displayNameOther = CSTRING(Action_RootOther);
        icon = QPATHTOF(ui\UtilityPouch.paa);
    };
};
