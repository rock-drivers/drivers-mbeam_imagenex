rock_library(mbeam_imagenex
    SOURCES Driver.cpp MBeamHandler.cpp 
    HEADERS Driver.hpp MBeamHandler.hpp Config.hpp MBeamRaw.hpp MBeamTypes.hpp
    DEPS_PKGCONFIG base-types iodrivers_base base-lib)

rock_executable(mbeam_imagenex_bin Main.cpp
    DEPS mbeam_imagenex)

