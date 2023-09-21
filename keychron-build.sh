#!/bin/bash

set -x
km=$1

if [[ -z $km ]]; then
    km=jasonisgraham
fi

# clear;  make keychron/v6/v6_ansi_stm32l432:flash

# /home/jason/Projects/qmk_firmware/keyboards/zsa/voyager/keymaps/jasonisgraham/keymap.c
# qmk --verbose flash  -c -kb zsa/voyager -km $km

# /home/jason/Projects/qmk_firmware/keyboards/keychron/v6/ansi_encoder/keymaps/default/keymap.c

qmk --verbose flash  -c -kb keychron/v6/ansi_encoder -km default
