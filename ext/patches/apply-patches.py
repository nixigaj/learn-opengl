import os
import sys

os.chdir('../../')  # Root directory for repo
if sys.argv[1] == "--patch":
    os.system("git apply ext/patches/glfw-dev.patch")
elif sys.argv[1] == "--unpatch":
    os.system("git apply --reverse ext/patches/glfw-dev.patch")
else:
    print("Error: no patch parameter specified")
