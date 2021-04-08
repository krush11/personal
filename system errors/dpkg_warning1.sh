#! /bin/bash

# Warning: dpkg: warning: files list file for package 'x' missing; assuming package has no files currently installed
# Reason: Happens when a software installation failed and the installer(dpkg) becomes corrupted

# SOLUTION
for package in $(sudo apt-get install catdoc 2>&1 | grep "warning: files list file for package '" | grep -Po "[^'\n ]+'" | grep -Po "[^']+");
do
  sudo apt-get -y install --reinstall "$package"
done
