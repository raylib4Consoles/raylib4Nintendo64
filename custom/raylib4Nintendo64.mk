# Override this to use a toolchain installed separately from libdragon
N64_GCCPREFIX ?= $(N64_INST)
N64_ROOTDIR = $(N64_INST)
N64_BINDIR = $(N64_ROOTDIR)/bin
N64_INCLUDEDIR = $(N64_ROOTDIR)/mips64-elf/include
N64_LIBDIR = $(N64_ROOTDIR)/mips64-elf/lib
N64_GCCPREFIX_TRIPLET = $(N64_GCCPREFIX)/bin/mips64-elf-


N64_CC = $(N64_GCCPREFIX_TRIPLET)gcc
N64_CXX = $(N64_GCCPREFIX_TRIPLET)g++
N64_AS = $(N64_GCCPREFIX_TRIPLET)as
N64_AR = $(N64_GCCPREFIX_TRIPLET)ar
N64_LD = $(N64_GCCPREFIX_TRIPLET)ld
N64_OBJCOPY = $(N64_GCCPREFIX_TRIPLET)objcopy
N64_OBJDUMP = $(N64_GCCPREFIX_TRIPLET)objdump
N64_SIZE = $(N64_GCCPREFIX_TRIPLET)size
N64_NM = $(N64_GCCPREFIX_TRIPLET)nm
N64_STRIP = $(N64_GCCPREFIX_TRIPLET)strip

N64_ED64ROMCONFIG = $(N64_BINDIR)/ed64romconfig
N64_MKDFS = $(N64_BINDIR)/mkdfs
N64_TOOL = $(N64_BINDIR)/n64tool
N64_SYM = $(N64_BINDIR)/n64sym
N64_ELFCOMPRESS = $(N64_BINDIR)/n64elfcompress
N64_AUDIOCONV = $(N64_BINDIR)/audioconv64
N64_MKSPRITE = $(N64_BINDIR)/mksprite
N64_MKFONT = $(N64_BINDIR)/mkfont
N64_MKMODEL = $(N64_BINDIR)/mkmodel
N64_DSO = $(N64_BINDIR)/n64dso
N64_DSOEXTERN = $(N64_BINDIR)/n64dso-extern
N64_DSOMSYM = $(N64_BINDIR)/n64dso-msym

N64_C_AND_CXX_FLAGS =  -march=vr4300 -mtune=vr4300 -I$(N64_INCLUDEDIR)
N64_C_AND_CXX_FLAGS += -falign-functions=32   # NOTE: if you change this, also change backtrace() in backtrace.c
N64_C_AND_CXX_FLAGS += -ffunction-sections -fdata-sections -g -ffile-prefix-map="$(CURDIR)"=
N64_C_AND_CXX_FLAGS += -ffast-math -ftrapping-math -fno-associative-math
#N64_C_AND_CXX_FLAGS += -DN64 -O2 -Wall -Werror -Wno-error=deprecated-declarations -fdiagnostics-color=always
N64_C_AND_CXX_FLAGS += -DN64 -O2 -Wall  -Wno-error=deprecated-declarations -fdiagnostics-color=always
N64_C_AND_CXX_FLAGS += -Wno-error=unused-variable -Wno-error=unused-but-set-variable -Wno-error=unused-function -Wno-error=unused-parameter -Wno-error=unused-but-set-parameter -Wno-error=unused-label -Wno-error=unused-local-typedefs -Wno-error=unused-const-variable
N64_CFLAGS = $(N64_C_AND_CXX_FLAGS) -std=gnu99
N64_CXXFLAGS = $(N64_C_AND_CXX_FLAGS)
N64_ASFLAGS = -mtune=vr4300 -march=vr4300 -Wa,--fatal-warnings -I$(N64_INCLUDEDIR)
N64_RSPASFLAGS = -march=mips1 -mabi=32 -Wa,--fatal-warnings -I$(N64_INCLUDEDIR)
N64_LDFLAGS = -g -L$(N64_LIBDIR) -ldragon -lm -ldragonsys -Tn64.ld --gc-sections --wrap __do_global_ctors
N64_DSOLDFLAGS = --emit-relocs --unresolved-symbols=ignore-all --nmagic -T$(N64_LIBDIR)/dso.ld
