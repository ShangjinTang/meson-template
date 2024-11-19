project('meson-demo', 'cpp',
  default_options : [ 'cpp_std=c++20'])

# Note:
#   1. dependency_name is case sensitive; pkg-config `<dependency_name>.pc` must exists
#   2. do not use hyphen '-' in python; replace with underscore '_'
cli11 = dependency('CLI11', version: '2.4.2')
fmt = dependency('fmt', version: '11.0.2')
ms_gsl = dependency('ms-gsl', version: '4.1.0')
spdlog = dependency('spdlog', version: '1.15.0')

# Either use doctest or gtest. Do not use two test frameworks in one project.
doctest = dependency('doctest', version: '2.4.11')
# gtest = dependency('gtest', version: '1.15.0')

if get_option('buildtype').startswith('debug')
  executable('demo-d', 'main.cpp', dependencies: [cli11, fmt, ms_gsl, spdlog, doctest])
else
  executable('demo', 'main.cpp', dependencies: [cli11, fmt, ms_gsl, spdlog, doctest])
endif
