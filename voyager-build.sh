#!/bin/bash

set -x
km=$1

if [[ -z $km ]]; then
    km=jasonisgraham
fi

clear; qmk --verbose flash  -c -kb zsa/voyager -km $km
