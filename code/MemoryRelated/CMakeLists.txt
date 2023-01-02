cmake_minimum_required (VERSION 2.6)

project (MemoryIssues)

# add the executables
add_executable(pointerVirtMem pointerVirtMem.c)

add_subdirectory (MatrixRepresentation)
add_subdirectory (Malware)


