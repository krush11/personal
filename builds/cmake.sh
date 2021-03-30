#! /bin/bash

export version=3.19
export build=3
mkdir ~/temp
cd ~/temp
# Download cmake source
wget https://cmake.org/files/v$version/cmake-$version.$build.tar.gz
tar -xzvf cmake-$version.$build.tar.gz
cd cmake-$version.$build/

# Initiate build
./bootstrap

# Build cmake and install
make -j$(nproc)
sudo make install

# Remove downloaded source
cd ~
rm -rf temp

# Copy latest cmake to binaries
cp /usr/local/bin/cmake /usr/bin/cmake
cmake --version
