cmake_minimum_required (VERSION 3.2)

project (FinitePrecision)

# add the executables
add_executable (typeLength typeLength.cxx)

add_executable (powExample powExample.cxx)

add_executable (mat2DExample matrix2D-FinitePrec.cpp)

add_executable(wrapAround wrapAround.c)

add_executable(roundoffExmpl roundoffExmpl.c)

add_executable(typeLengthByte typeLengthByte.c)

add_executable(standSizes standSizes.c)

add_executable(int_as_float int_as_float.c)

add_executable(sinxOverx sinxOverx.c)