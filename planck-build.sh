#!/bin/bash

set -x
km=$1

if [[ -z $km ]]; then
    km=jasonisgraham-drop
fi


qmk flash -kb planck/rev6_drop -km $km
