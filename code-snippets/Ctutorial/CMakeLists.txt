cmake_minimum_required (VERSION 3.2)

project (CTutorial)

# add the executables
add_executable (helloWorld helloWorld.c)
add_executable (printStuffOut printStuffOut.c)
add_executable (swap swap.c)
add_executable (allocMemDyn allocMemDyn.c)
add_executable (pointerWildCard pointerWildCard.c)
add_executable (castingExample castingExample.c)
add_executable (simplePointerExample simplePointerExample.c)
add_executable (simpleMallocExample simpleMallocExample.c)
add_executable (simpleMallocExample2 simpleMallocExample2.c)
add_executable (pntrVSarray pntrVSarray.c)
add_executable (memmoveExample memmoveExample.c)
add_executable (structExample structExample.c)
add_executable (precedence precedence.c)
add_executable (pntrAliasing pntrAliasing.c)
add_executable (staticExample staticExample.c)
add_executable (sumGame sumGame.c)
add_executable (arrayVSpointer arrayVSpointer.c)
add_executable (typeArrayInt3 typeArrayInt3.c)
add_executable (pointerTrickery pointerTrickery.c)
add_executable (pointerFunc pointerFunc.c)

# keep an empty one, in case you want to test things quickly
add_executable (junk junk.c)



