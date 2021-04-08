#! /bin/bash

# Error: Sub-process /usr/bin/dpkg returned an error code (1)
# Reason: Happens when a software installation failed and the installer(dpkg) becomes corrupted
# Possible repercussions: `sudo dpkg --configure -a` fails and dpkg warnings
# !IMPORTANT! : This package is not supposed to be run as a script even though its a .sh file

# SOLUTION

# 1. Remove the broken packages
sudo dpkg --configure -a 
sudo apt install -f # This will give packages which are broken/affecting the installer(dpkg)
sudo apt remove --purge ${package_name} # Here, ${package_name} are all the list of packages which are listed in the output of above command
sudo apt autoremove

# 2. Deal with the broken package's files 
sudo mv /var/lib/dpkg/info/*${package_name}* /tmp # Again, replace ${package_name} with the broken package. (Run the command multiple files for each package)
sudo apt update
sudo dpkg -i --force-overwrite /var/cache/apt/archives/${full_package_name} # Write the exact name of the package instead of ${full_package_name} and the the command multiple times
sudo apt update

# This should solve the problem. If error still persists feel free to contact me.
