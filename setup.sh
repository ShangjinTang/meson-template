#!/usr/bin/env bash

set -e

COLOR_RESET=$(tput sgr0)
COLOR_HIGHLIGHT=$(tput bold)$(tput setaf 6)

if ! command -v ninja &> /dev/null || ! command -v meson &> /dev/null || ! command -v conan &> /dev/null; then
    echo "One or more of ('ninja', 'conan', 'meson') not avaiable"
    echo "To install:"
    echo "    python3 -m pip install pipx"
    echo "    pipx ensurepath"
    echo "    pipx install ninja meson conan"
    exit 1
fi

if ! [[ -f ~/.conan2/profiles/default ]]; then
    conan profile detect --force
fi

function print_seperate_line() {
    echo
    echo "${COLOR_HIGHLIGHT}======================================================================"
    echo "$1${COLOR_RESET}"
    echo
}

rm -rf build &> /dev/null

print_seperate_line "Cleaning"
rm -rf build compile_commands.json &> /dev/null

print_seperate_line "Meson: setup"
meson setup build
cp build/compile_commands.json .
