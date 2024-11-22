#!/bin/bash

set -x
km=$1

if [[ -z $km ]]; then
    km=jasonisgraham
fi

clear; qmk flash -c -kb zsa/voyager -km $km
