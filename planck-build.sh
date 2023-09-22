#!/bin/bash

set -x
km=$1

if [[ -z $km ]]; then
    km=jasonisgraham-drop
elif [[ $km -eq "lhs" ]]; then
    km=jasonisgraham-lhs-mods
fi


qmk flash -kb planck/rev7 -km $km
#qmk flash -kb planck/rev6_drop -km $km
