#!/bin/bash

set -e
set -x
km=$1

if [[ -z $km ]]; then
    km=jasonisgraham-drop
fi

if [[ "lhs" = $km ]]; then
    km=jasonisgraham-lhs-mods
fi

# if [[ $km = "default" ]]; then
# qmk generate-autocorrect-data -kb planck/rev7 -km $km autocorrect.txt
# fi

qmk flash -kb planck/rev7 -km $km
#qmk flash -kb planck/rev6_drop -km $km
