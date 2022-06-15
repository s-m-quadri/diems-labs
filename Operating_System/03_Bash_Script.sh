#!/bin/sh

# Commands:
# MANUAL - man ...
# DIRECTORY - cd, pwd, ls, mkdir ...
# VARIABLE - echo, set, unset ...
# FILE DISPLAY - touch, cat, tac, nano, head, tail ...
# COPY/MOVE/REMOVE - cp, mv, rm, rmdir ...
# PERMISSIONS - chown, chgrp, chmod ...

# 1. Get the name
echo "What is your name?"
read Name
echo "--> Oh! so your name is $Name"

# 2. Get the age and calculate date of birth
echo "What is your age?"
read Age
if [ $Age -ge 5 ]
then
        echo "--> Hmm! Born in year $(expr 2022 - $Age) , isn't it?"
else
        echo "--> You're kid...!"
fi
