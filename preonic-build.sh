#!/bin/bash

set -x
km=$1

if [[ -z $km ]]; then
    km=jasonisgraham
fi


qmk flash -kb preonic/rev3_drop -km $km
