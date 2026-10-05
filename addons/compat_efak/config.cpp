#include "script_component.hpp"

// With Enhanced First Aid Kits loaded as well, the framework is EFAK's again: the general settings
// and keybinds under its name, and the arsenal tab and the Eden fields speak of kits and pouches.
// Without EFAK (no efak_kits) the game skips this addon.
class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "eup_pouches",
            "efak_kits"
        };
        skipWhenMissingDependencies = 1;
        author = "Miss Heda";
        url = ECSTRING(main,URL);
        VERSION_CONFIG;
    };
};

// EFAK's own value (CBA_SETTINGS_EFAK in its main addon).
class EFAK_Framework {
    settingsCategory = "Enhanced First Aid Kits";
    keybindCategory = "Enhanced First Aid Kits & Utility Pouches";
};

// The icon stays the pouches' (eup_pouches).
class EFAK_Arsenal {
    buttonName = CSTRING(Arsenal_Button);
    tabTooltip = CSTRING(Arsenal_Tab);
    header = CSTRING(Arsenal_Tab);
    buttonContents = CSTRING(Arsenal_Contents);
    hintNoKits = CSTRING(Arsenal_HintNoKits);
    rowNoKits = CSTRING(Arsenal_RowNoKits);
    tabDisabledUnit = CSTRING(Arsenal_DisabledUnit);
};

class Cfg3DEN {
    class Object {
        class AttributeCategories {
            class efak_core_attributes {
                displayName = CSTRING(3DEN_Category);
                class Attributes {
                    class efak_core_kitContents {
                        tooltip = CSTRING(3DEN_KitContents_Tooltip);
                    };
                };
            };
        };
    };
};
