add_library(HomeBrewedMathLib mysqrt.cxx)

# add the install targets
install (TARGETS HomeBrewedMathLib DESTINATION bin)
install (FILES MathFunctions.h DESTINATION include)                                                                         
