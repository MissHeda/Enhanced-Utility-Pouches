#!/usr/bin/env python3
"""Copies Enhanced First Aid Kits' kit framework into this mod, so the pouches run without EFAK.

The framework is EFAK's main, core, gui and arsenal addons - everything but its own kits (efak_kits),
its medical addon and its compats. They are copied as EFAK built them, PBO for PBO, with their
signatures and EFAK's key: with both mods loaded the game finds the same addons twice and uses one
of them, which only works while they are the same files. So after every EFAK release, release this
mod again with that release's framework.

Usage:
    python tools/sync_framework.py           # EFAK's .hemttout/release (signed) - before a release
    python tools/sync_framework.py --build   # EFAK's .hemttout/build - for hemtt launch

The copies land in addons/ and keys/ (both ignored by git), and .hemtt/project.toml takes them
into every build.
"""

import glob
import os
import shutil
import sys

FRAMEWORK = ["main", "core", "gui", "arsenal"]

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, ".."))
EFAK = os.path.normpath(os.path.join(ROOT, "..", "Enhanced-First-Aid-Kits"))


def main():
    source = os.path.join(EFAK, ".hemttout", "build" if "--build" in sys.argv else "release")
    addons = os.path.join(ROOT, "addons")
    keys = os.path.join(ROOT, "keys")

    for old in glob.glob(os.path.join(addons, "efak_*")) + glob.glob(os.path.join(keys, "efak_*")):
        if os.path.isfile(old):
            os.remove(old)

    for name in FRAMEWORK:
        pbo = os.path.join(source, "addons", "efak_%s.pbo" % name)
        if not os.path.isfile(pbo):
            sys.exit("missing %s - build or release EFAK first" % pbo)
        for path in [pbo] + glob.glob(pbo + ".*.bisign"):
            shutil.copy2(path, addons)
            print("addons/" + os.path.basename(path))

    os.makedirs(keys, exist_ok=True)
    for key in glob.glob(os.path.join(source, "keys", "efak_*.bikey")):
        shutil.copy2(key, keys)
        print("keys/" + os.path.basename(key))


if __name__ == "__main__":
    main()
