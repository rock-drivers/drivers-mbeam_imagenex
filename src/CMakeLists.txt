rock_library(mbeam_imagenex
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(mbeam_imagenex_bin Main.cpp
    DEPS mbeam_imagenex)

