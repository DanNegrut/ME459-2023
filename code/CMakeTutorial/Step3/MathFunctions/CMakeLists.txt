add_library(HomeBrewedMathLib mysqrt.cxx)

install (TARGETS HomeBrewedMathLib DESTINATION bin)
install (FILES MathFunctions.h DESTINATION include)
