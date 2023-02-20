#!/bin/zsh

clang-format -style=file:../dotfiles/clang-format.yml -i include/**/*.hpp gtests/**/*.cpp examples/**/*.cpp