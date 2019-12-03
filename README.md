# cppDynamicArray

##NOTE## - use "make" from directory with makefile to compile project

"make" - compiles main.cpp into an object which are dumped into /build.
         myArray.cpp and main.cpp include the header myArray.h from /include.
         myArray.h includes myArray.cpp at the end due to extensive compilation issues regarding templates.
         the executable file "a.out" is dumped into the main directory with the makefile
"make clean" - removes all .o files from /build and removes a.out from /

"make backup" - creates a backup with /src /include /build makefile README.md