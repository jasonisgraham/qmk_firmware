#!/bin/bash

set -x
km=$1

if [[ -z $km ]]; then
    km=jasonisgraham
fi


qmk flash -c -kb keebio/levinson/rev3 -km $km -e CONVERT_TO=elite_pi
