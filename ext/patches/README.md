Some experimental library patches that can be applied before build.
They currently include:

* Fix for Wayland cursor size
* Change Wayland window decoration color to a nice green

Before build run:
    
    python apply-patches.py --apply

After build run:

    python apply-patches.py --reverse

Or provide no argument for interactive mode:

    python apply-patches.py
