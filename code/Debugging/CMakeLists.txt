cmake_minimum_required (VERSION 3.16)

project (DebuggingExamples)

# add the executables
add_executable(badPowerAssign badPowerAssign.c)
add_executable(bugDebug bugDebug.c)
add_executable(gdbGoodPractice gdbGoodPractice.c)
add_executable(pointerGym pointerGym.c)
add_executable(sanitizeExample sanitizeExample.c)
add_executable(castingExample castingExample.c)

