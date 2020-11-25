# tools

Homebrew

$ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

VSCode

$ brew cask install visual-studio-code

CMake

$ brew install cmake

Make

$ brew install make

pkg-config

$ brew install pkg-config


# vcpkg

https://github.com/microsoft/vcpkg

$ cd ~/ & mkdir prj & cd prj

$ git clone https://github.com/microsoft/vcpkg.git

$ cd vcpkg

$ git checkout tags/2020.07

$ ./bootstrap-vcpkg.sh

$ ./vcpkg install fmt

$ ./vcpkg install cryptopp


# environment

$ echo 'PATH="/usr/local/opt/make/libexec/gnubin:$PATH"' >> ~/.zshrc

$ echo 'export VCPKG_ROOT=$HOME/prj/vcpkg' >> ~/.zshrc

$ source ~/.zshrc


# build

$ source ~/.zshrc

$ cd ~/ & mkdir prj & cd prj

$ git clone https://github.com/ilshookim/scrypt.git

$ cd scrypt

$ mkdir build & cd build

$ cmake ..

$ make

$ ./scrypt


# editing

$ cd ~/ & mkdir prj & cd prj

$ cd scrypt

$ code .


