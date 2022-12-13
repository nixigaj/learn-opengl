#!/usr/bin/env python
import os
import sys
from enum import Enum


class PatchType(Enum):
    APPLY = 0
    REVERSE = 1


def patch(apply):
    os.chdir(sys.path[0] + '/../../')
    if apply is PatchType.APPLY:
        os.system("python ext/patches/python-patch/patch.py "
                  "ext/patches/glfw-dev.patch")
    elif apply is PatchType.REVERSE:
        os.system("python ext/patches/python-patch/patch.py "
                  "ext/patches/glfw-dev-reverse.patch")


if len(sys.argv) > 1:
    if sys.argv[1] == '--apply':
        patch(PatchType.APPLY)
    elif sys.argv[1] == '--reverse':
        patch(PatchType.REVERSE)
    else:
        print("Error: no correct patch argument specified")

else:
    sel = ""
    while sel != "a" and sel != "r":
        sel = input("Apply or reverse patches? [a/r]: ")
    if sel == "a":
        patch(PatchType.APPLY)
    if sel == "r":
        patch(PatchType.REVERSE)
