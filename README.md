# GEn (Game Engine)
A SDL wrapper/game engine that removes a lot of SDL's pains and makes it suitable for game dev!

# Dependencies

- `gcc`
- `SDL2`
- `SDL2_Image`
- `make`
- `ar` (This comes with MacOS Commandline Tools and is included in binutils on Linux)

## On Linux:
On Linux, you can install the dependencies with the included package managers. This is not an all inclusive list, so if you don't find your distro here, just Google it, but these are the most common distros.
### Debian and Derivatives:
`sudo apt install gcc libsdl2-dev libsdl2-image-dev make git binutils`

### Fedora and Derivatives:
`sudo dnf install gcc SDL2 SDL2-devel SDL2_Image make git binutils`

### Arch and Derivatives:
`sudo pacman -S gcc sdl2 sdl2-image make git binutils`

## On MacOS:
MacOS does not come with a package manager pre-installed, so users have 2 options: [Homebrew](https://brew.sh) or [Macports](https://macports.org).
Homebrew is recommended, but MacPorts is a suitable alternative.  
For both, you need Apple Command Line Development tools, which you can install with `xcode-select --install` and following the steps. This give you access to the clang compiler and other critical utilities pre-included with Linux systems that are necessary for the following steps
### Homebrew(Recommended):
Open Terminal, then paste this command:  
`/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`  
Give it necessary permissions, and follow the steps at the end. You may have to quit and reopen terminal for it to work.
Once Homebrew has been installed, type:  
`brew install sdl2 sdl2_image make git`
to install the dependencies

### MacPorts(Alternative)
Go to https://www.macports.org/install.php and download the appropriate .pkg for your OS version.  
After installation, type  
`sudo port install libsdl2 libsdl2_image make git`  
to install the dependencies.


## On Windows
Unlike Linux or MacOS, Windows is not Unix-like, which makes the use of other options necessary. The main option covered here will be WSL. Although Windows has its own C compiler, we recommend not to use it right now for reasons covered at the end of the section.

### WSL
WSL is a way to run Linux virtual machines natively from Windows. To install it, open Powershell and type `wsl --install`. The default distro is Ubuntu, so if you want that, then simply type that. However, if you want a different distro, type `wsl --list --online` to see a list of distros available. Then type `wsl --install -d (your choice of distro)`.  
After installation, you can press the Windows key and search up your distro name. It should be available as an app. Follow the setup instructions, and soon you should have a working Linux environment! Afterwards, follow the steps above for your chosen distro.

**Note on Cygwin:** Cygwin is a viable option for Windows users wanting a Unix-like environment. However, SDL2, which this project relies on, is broken and does not work there.

**Note on Visual Studio Compiler(MSVC):** Currently, there are a few GCC/Clang specific extensions in the code, and the Makefile is made for gcc. Official MSVC support will be provided in later releases, but right now, you should look to WSL.

# Quick Start
1. Clone the repo.
2. Navigate to `src`
3. Type `make`
4. The compiled static lib will be in the `lib` folder as `lib/libgen.a`, and the include file is `include/gen.h`.
# Docs
Well, there are none! There will be some later, but right now all the info you could need can be obtained by crawling the `includes`.
