code = files('lazy.c', 'observer.c', 'contract.c')

lib = static_library('fscl-xpattern-c',
    code,
    include_directories: dir)

fscl_xpattern_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)
