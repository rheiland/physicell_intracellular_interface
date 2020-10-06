# physicell_intracellular_interface

We want to provide intracellular models in individual cells for PhysiCell. A significant challenge is that there are multiple types of intracellular models (and software packages), e.g., boolean (MaBoSS), flux balance analysis (FBA; COIN-OR Clp), or ODEs via SBML (libRoadrunner). How can PhysiCell best handle these different intracellular models and additional software libraries?

This will be a significant change in how PhysiCell has maintained a self-contained code base. Now we will be interfacing with multiple libraries. It may cause us to re-examine some of our basic practices up until now. For example, we may want to adopt CMake to build PhysiCell when we depend on multiple libraries. Time will tell. But for now, we will continue to use a single Makefile that can (hopefully) work on any operating system. Another significant change is that we will not be building everything from source. To make it easier for users, we will want to provide OS-dependent binary libraries which can be linked into a final executable.

The initial purpose of this repo is to 1) collect together some of the background material from collaborators, and 2) provide some very basic examples demonstrating the basic approach that might be used to build the desired models.

For example, in the `simplest` directory, we demo how to do conditional compilation:
```
~/git/physicell_intracellular_interface/simplest$ make
g++ -march=native  -fomit-frame-pointer -m64 -std=c++11 -D LIBROADRUNNER    -c Phenotype.cpp
g++ -march=native  -fomit-frame-pointer -m64 -std=c++11 -D LIBROADRUNNER    -c Molecular.cpp
Your OS= -D OSX -D IA32
LIBRR_CFLAGS=
LIBRR_LIBS=
g++ -march=native  -fomit-frame-pointer -m64 -std=c++11 -D LIBROADRUNNER     -o simple Phenotype.o Molecular.o main.cpp 

created simple
```
