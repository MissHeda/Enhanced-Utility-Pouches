#include "script_component.hpp"

// The pouches are kits of Enhanced First Aid Kits' framework: its registry (EFAK_Kits) gives every
// one its contents, capacity, settings, kit window and quick access - this addon only brings the
// pouches. The framework (efak_main, efak_core, efak_gui, efak_arsenal) comes along as unchanged
// copies of EFAK's own PBOs (tools/sync_framework.py), so the pouches run without EFAK; with EFAK
// loaded the game finds the same addons twice and uses one of them.
class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {"eup_UtilityPouch", "eup_AmmoPouch", "eup_AmmoBag", "eup_EngineerBag", "eup_CBRNBag"};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "eup_main",
            "efak_core",
            "efak_arsenal"
        };
        author = "Miss Heda";
        url = ECSTRING(main,URL);
        VERSION_CONFIG;
    };
};

#include "CfgEFAKKits.hpp"
#include "CfgWeapons.hpp"
#include "Cfg3DEN.hpp"

// What the framework is called in the CBA settings and keybinds while the pouches run on their own.
// With EFAK loaded, compat_efak gives it back EFAK's name.
class EFAK_Framework {
    settingsCategory = CBA_SETTINGS_EUP;
};

// ACE Arsenal's kits tab and button: the pouches, white like ACE's own buttons. On their own its
// texts speak of pouches; with EFAK's first aid kits loaded, of kits and pouches (compat_efak).
class EFAK_Arsenal {
    icon = QPATHTOF(ui\arsenal_icon.paa);
    buttonName = CSTRING(Arsenal_Button);
    tabTooltip = CSTRING(Arsenal_Tab);
    header = CSTRING(Arsenal_Tab);
    buttonContents = CSTRING(Arsenal_Contents);
    hintNoKits = CSTRING(Arsenal_HintNoKits);
    rowNoKits = CSTRING(Arsenal_RowNoKits);
    tabDisabledUnit = CSTRING(Arsenal_DisabledUnit);
};
