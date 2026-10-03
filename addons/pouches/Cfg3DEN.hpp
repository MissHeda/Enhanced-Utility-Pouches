// What the pouches in a crate or vehicle hold, one field per pouch type in the framework's Eden
// attribute category, next to EFAK's own kits when it is loaded. The framework does the rest
// (efak_core_fnc_fillCrateKits): the property name tells it the pouch type, an empty field leaves
// the defaults.
#define CRATE_POUCH_ATTRIBUTE(pouch,name) \
    class efak_core_crate_##pouch { \
        displayName = CSTRING(3DEN_CrateContents_##name); \
        tooltip = "$STR_efak_core_3DEN_CrateContents_Tooltip"; \
        property = QUOTE(efak_core_crate_##pouch); \
        control = "EditMulti3"; \
        expression = "if (!is3DEN && {isServer} && {_value isNotEqualTo ''}) then {[_this,'%s',_value] call efak_core_fnc_fillCrateKits}"; \
        defaultValue = "''"; \
        typeName = "STRING"; \
        validate = "none"; \
        condition = "objectHasInventoryCargo"; \
    }

class Cfg3DEN {
    class Object {
        class AttributeCategories {
            // The framework's category, named for the pouches; with EFAK loaded for kits and
            // pouches (compat_efak).
            class efak_core_attributes {
                displayName = CSTRING(3DEN_Category);
                class Attributes {
                    class efak_core_kitContents {
                        tooltip = CSTRING(3DEN_KitContents_Tooltip);
                    };
                    CRATE_POUCH_ATTRIBUTE(eup_UtilityPouch,UtilityPouch);
                    CRATE_POUCH_ATTRIBUTE(eup_AmmoPouch,AmmoPouch);
                    CRATE_POUCH_ATTRIBUTE(eup_AmmoBag,AmmoBag);
                    CRATE_POUCH_ATTRIBUTE(eup_EngineerBag,EngineerBag);
                    CRATE_POUCH_ATTRIBUTE(eup_CBRNBag,CBRNBag);
                };
            };
        };
    };
};
