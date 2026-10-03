class CfgWeapons {
    class EFAK_KitBase;
    class CBA_MiscItem_ItemInfo;

    // Common base for every pouch: an EFAK kit, but not a medical item.
    class eup_PouchBase: EFAK_KitBase {
        author = "Miss Heda";
        scope = 0;
        scopeArsenal = 0;
        ACE_isMedicalItem = 0;
        EFAK_prototype = 1;
        EFAK_instanceId = 0;
    };

    // Masses are the room the packed pouch takes, about 40% of its default capacity like EFAK's
    // kits; EFAK_emptyWeight is what the empty pouch weighs (1 mass unit = 0.1 lb) and what goes in
    // adds its own.

    class eup_UtilityPouch: eup_PouchBase {
        model = QPATHTOF(data\utility_pouch.p3d);
        scope = 2;
        scopeArsenal = 2;
        displayName = CSTRING(UtilityPouch_Display);
        descriptionShort = CSTRING(UtilityPouch_Desc);
        picture = QPATHTOF(ui\UtilityPouch.paa);
        editorPreview = QPATHTOF(ui\UtilityPouch.paa);
        EFAK_emptyWeight = 3;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 12;
        };
    };

    class eup_AmmoPouch: eup_PouchBase {
        model = QPATHTOF(data\ammo_pouch.p3d);
        scope = 2;
        scopeArsenal = 2;
        displayName = CSTRING(AmmoPouch_Display);
        descriptionShort = CSTRING(AmmoPouch_Desc);
        picture = QPATHTOF(ui\AmmoPouch.paa);
        editorPreview = QPATHTOF(ui\AmmoPouch.paa);
        EFAK_emptyWeight = 3;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 20;
        };
    };

    class eup_AmmoBag: eup_PouchBase {
        model = QPATHTOF(data\ammo_bag.p3d);
        scope = 2;
        scopeArsenal = 2;
        displayName = CSTRING(AmmoBag_Display);
        descriptionShort = CSTRING(AmmoBag_Desc);
        picture = QPATHTOF(ui\AmmoBag.paa);
        editorPreview = QPATHTOF(ui\AmmoBag.paa);
        EFAK_emptyWeight = 12;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 95;
        };
    };

    class eup_EngineerBag: eup_PouchBase {
        model = QPATHTOF(data\engineer_bag.p3d);
        scope = 2;
        scopeArsenal = 2;
        displayName = CSTRING(EngineerBag_Display);
        descriptionShort = CSTRING(EngineerBag_Desc);
        picture = QPATHTOF(ui\EngineerBag.paa);
        editorPreview = QPATHTOF(ui\EngineerBag.paa);
        EFAK_emptyWeight = 15;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 80;
        };
    };

    class eup_CBRNBag: eup_PouchBase {
        model = QPATHTOF(data\cbrn_bag.p3d);
        scope = 2;
        scopeArsenal = 2;
        displayName = CSTRING(CBRNBag_Display);
        descriptionShort = CSTRING(CBRNBag_Desc);
        picture = QPATHTOF(ui\CBRNBag.paa);
        editorPreview = QPATHTOF(ui\CBRNBag.paa);
        EFAK_emptyWeight = 15;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 100;
        };
    };

    #include "CfgWeapons_instances.hpp"
};
