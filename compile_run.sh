#!/usr/bin/env bash

set -e

COLOR_RESET=$(tput sgr0)
COLOR_HIGHLIGHT=$(tput bold)$(tput setaf 6)

function print_seperate_line() {
    echo
    echo "${COLOR_HIGHLIGHT}======================================================================"
    echo "$1${COLOR_RESET}"
    echo
}

print_seperate_line "Meson: build"
meson compile -C build/debug

print_seperate_line "Running demo"
./build/debug/demo-d
