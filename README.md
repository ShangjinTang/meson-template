# C++ Meson Template

This repository aims to represent a template for C++ [Meson](https://mesonbuild.com/) projects with external dependencies management using [Conan](https://conan.io/).

## Introduction

- Link useful libraries for every subdirectory without manually installing first, including:
  - common libraries:
    - `cli11`
    - `fmt`
    - `spdlog`
    - `ms-gsl`
  - test libraries:
    - `doctest`

## Resources

- Meson:
  - Official: [Quickstart Guide](https://mesonbuild.com/Quick-guide.html)
- Conan:
  - Official: [conan.io](https://conan.io/)

## Requirements

- [`Meson`](https://mesonbuild.com/) >= 1.6.0
- [`Conan`](https://conan.io) >= 2.0.5

## How to build from command line

The project requires built using `conan` and `ninja` with `pipx`:

```bash
python3 -m pip install pipx &&
    pipx ensurepath &&
    pipx install ninja meson conan

./compile_run.sh
```
