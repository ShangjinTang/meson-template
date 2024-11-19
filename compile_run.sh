#!/usr/bin/env bash

set -e

rm -rf build &> /dev/null

conan install . --output-folder=build --build=missing

meson setup --native-file build/conan_meson_native.ini . build/debug --buildtype debug

cp build/debug/compile_commands.json .

meson compile -C build/debug

./build/debug/demo-d
