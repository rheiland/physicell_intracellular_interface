PROGRAM_NAME := simple

CC := g++
ifdef PHYSICELL_CPP 
	CC := $(PHYSICELL_CPP)
endif

ARCH := native 
#CFLAGS := -march=$(ARCH) -fomit-frame-pointer -fopenmp -m64 -std=c++11 -D LIBROADRUNNER 
CFLAGS := -march=$(ARCH) -fomit-frame-pointer -m64 -std=c++11 -D LIBROADRUNNER 


OSFLAG 	:=
ifeq ($(OS),Windows_NT)
	OSFLAG += -D WIN32
	OMP_LIB := 
	# LIBRR_DIR := C:\Users\heiland\libroadrunner\roadrunner-win64-vs14-cp35m
	# LIBRR_LIBS := C:\Users\heiland\libroadrunner\roadrunner-win64-vs14-cp35m/bin
	LIBRR_CFLAGS := -I${LIBRR_DIR}/include/rr/C
	CFLAGS := -march=$(ARCH) -fomit-frame-pointer -fopenmp -m64 -std=c++11 -D LIBROADRUNNER 
	ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
		OSFLAG += -D AMD64
	endif
	ifeq ($(PROCESSOR_ARCHITECTURE),x86)
		OSFLAG += -D IA32
	endif
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		OSFLAG += -D LINUX
		OMP_LIB :=
		# LIBRR_DIR := $(HOME)/libroadrunner/libroadrunner
		# LIBRR_CFLAGS := -I${LIBRR_DIR}/include/rr/C
		LIBRR_LIBS := ${LIBRR_DIR}/lib
		# CFLAGS := -march=$(ARCH) -g  -fomit-frame-pointer -fopenmp -m64 -std=c++11 -D LIBROADRUNNER 
		CFLAGS := -march=$(ARCH) -fomit-frame-pointer -m64 -std=c++11 -D LIBROADRUNNER 
	endif
	ifeq ($(UNAME_S),Darwin)
		# CC := clang++
		CC := g++
		OSFLAG += -D OSX
		LIBRR_DIR := $(HOME)/libroadrunner/roadrunner-osx-10.9-cp36m
		# LIBRR_CFLAGS := -I${LIBRR_DIR}/include/rr/C
		# LIBRR_LIBS := ${LIBRR_DIR}/lib
	endif
		UNAME_P := $(shell uname -p)
	ifeq ($(UNAME_P),x86_64)
		OSFLAG += -D AMD64
		LIBRR_DIR := $(HOME)/libroadrunner/libroadrunner
		# LIBRR_CFLAGS := -I${LIBRR_DIR}/include/rr/C
		# CFLAGS := -march=$(ARCH) -fomit-frame-pointer -fopenmp -m64 -std=c++11 -D LIBROADRUNNER 
		CFLAGS := -march=$(ARCH) -fomit-frame-pointer -fopenmp -m64 -std=c++11 -D LIBROADRUNNER 
	endif
		ifneq ($(filter %86,$(UNAME_P)),)
	OSFLAG += -D IA32
		endif
	ifneq ($(filter arm%,$(UNAME_P)),)
		OSFLAG += -D ARM
	endif
endif

COMPILE_COMMAND := $(CC) $(CFLAGS) $(LIBRR_CFLAGS) 

ALL_OBJECTS := Phenotype.o Molecular.o

all: main.cpp $(ALL_OBJECTS)
	@echo Your OS= $(OSFLAG)
	@echo LIBRR_CFLAGS= $(LIBRR_CFLAGS)
	@echo LIBRR_LIBS= $(LIBRR_LIBS)
	$(COMPILE_COMMAND) $(OMP_LIB) -o $(PROGRAM_NAME) $(ALL_OBJECTS) main.cpp 
	@echo
	@echo created $(PROGRAM_NAME)
	@echo

Phenotype.o: Phenotype.cpp
	$(COMPILE_COMMAND) -c Phenotype.cpp
Molecular.o: Molecular.cpp
	$(COMPILE_COMMAND) -c Molecular.cpp

clean:
	rm *.o