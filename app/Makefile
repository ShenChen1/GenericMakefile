#------------------------------------------------------------------------------
#              VARIABLES APPENDED TO BY INCLUDED MAKEFILE FRAGMENTS
#------------------------------------------------------------------------------

#vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
#                           GENERATED SETTINGS START                         v
#vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

# The following TYPE comment allows tools to identify the 'type' of target this 
# makefile is associated with. 
# TYPE: APP_MAKEFILE

# Define path to the application ELF. 
# It may be used by the makefile fragments so is defined before including them. 
# 
ELF := test.elf

# Paths to C, C++, and assembly source files.
C_SRCS := src/main.c
CXX_SRCS :=
ASM_SRCS :=

# Path to root of object file tree.
OBJ_ROOT_DIR := obj

# Options to control objdump.
CREATE_OBJDUMP := 1
OBJDUMP_INCLUDE_SOURCE := 1
OBJDUMP_FULL_CONTENTS := 1

# Options to enable/disable optional files.
CREATE_LINKER_MAP := 1

# Common arguments for ALT_CFLAGSs
APP_CFLAGS_DEFINED_SYMBOLS :=
APP_CFLAGS_UNDEFINED_SYMBOLS :=
APP_CFLAGS_OPTIMIZATION := -O0
APP_CFLAGS_DEBUG_LEVEL := -g
APP_CFLAGS_WARNINGS := -Wall
APP_CFLAGS_USER_FLAGS :=

APP_ASFLAGS_USER :=
APP_LDFLAGS_USER :=

# Linker options that have default values assigned later if not
# assigned here.
LINKER_SCRIPT :=
CRT0 :=
SYS_LIB :=

# List of application specific include directories, library directories and library names
APP_INCLUDE_DIRS := inc
APP_LIBRARY_DIRS := lib
APP_LIBRARY_NAMES := func

# Pre- and post- processor settings.
BUILD_PRE_PROCESS :=
BUILD_POST_PROCESS :=

#END GENERATED

#^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#                            GENERATED SETTINGS END                           ^
#^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


#------------------------------------------------------------------------------
#                           DEFAULT TARGET
#------------------------------------------------------------------------------

# Define the variable used to echo output if not already defined.
ifeq ($(ECHO),)
ECHO := echo
endif

# Put "all" rule before included makefile fragments because they may
# define rules and we don't want one of those to become the default rule.
.PHONY : all

all:
	@$(ECHO) [$(APP_NAME) build complete]

all : build_pre_process app build_post_process 


#------------------------------------------------------------------------------
#                 VARIABLES DEPENDENT ON GENERATED CONTENT
#------------------------------------------------------------------------------

# Define object file directory per build configuration
CONFIG_OBJ_DIR := $(OBJ_ROOT_DIR)

# Name of ELF application.
APP_NAME := $(basename $(ELF))

# Set to defaults if variables not already defined in settings.
ifeq ($(LINKER_SCRIPT),)
LINKER_SCRIPT := $(BSP_LINKER_SCRIPT)
endif
ifeq ($(CRT0),)
CRT0 := $(BSP_CRT0)
endif
ifeq ($(SYS_LIB),)
SYS_LIB := $(BSP_SYS_LIB)
endif

OBJDUMP_NAME := $(APP_NAME).objdump
OBJDUMP_FLAGS := --disassemble --syms --all-header
ifeq ($(OBJDUMP_INCLUDE_SOURCE),1)
OBJDUMP_FLAGS += --source
endif
ifeq ($(OBJDUMP_FULL_CONTENTS),1)
OBJDUMP_FLAGS += --full-contents
endif

# Create list of linker dependencies (*.a files).
APP_LDDEPS := $(LDDEPS)

# Take lists and add required prefixes.
APP_INC_DIRS := $(addprefix -I, $(APP_INCLUDE_DIRS) $(INC_DIRS))
ASM_INC_PREFIX := -Wa,-I
APP_ASM_INC_DIRS := $(addprefix $(ASM_INC_PREFIX), $(APP_INCLUDE_DIRS) $(INC_DIRS))
APP_LIB_DIRS := $(addprefix -L, $(APP_LIBRARY_DIRS) $(LIB_DIRS))
APP_LIBS := $(addprefix -l, $(APP_LIBRARY_NAMES) $(LIBS))

# Arguments for the C preprocessor, C/C++ compiler, assembler, and linker.
APP_CFLAGS := $(APP_CFLAGS_DEFINED_SYMBOLS) \
              $(APP_CFLAGS_UNDEFINED_SYMBOLS) \
              $(APP_CFLAGS_OPTIMIZATION) \
              $(APP_CFLAGS_DEBUG_LEVEL) \
              $(APP_CFLAGS_WARNINGS) \
              $(APP_CFLAGS_USER_FLAGS) \
              $(ALT_CFLAGS) \
              $(CFLAGS)

# Arguments only for the C++ compiler.
APP_CXXFLAGS := $(CXXFLAGS)

# Arguments only for the C preprocessor.
# Prefix each include directory with -I.
APP_CPPFLAGS := $(APP_INC_DIRS) \
                $(CPPFLAGS)

# Arguments only for the assembler.
APP_ASFLAGS := $(APP_ASM_INC_DIRS) \
               $(APP_ASFLAGS_USER) \
               $(ASFLAGS)

# Arguments only for the linker.
APP_LDFLAGS := $(APP_LDFLAGS_USER)

ifneq ($(LINKER_SCRIPT),)
APP_LDFLAGS += -T'$(LINKER_SCRIPT)'
endif

# Arguments only for the ctr.o.
ifneq ($(CRT0),)
APP_LDFLAGS += $(CRT0)
endif

APP_LDFLAGS += \
           $(APP_LIB_DIRS) \
           $(LDFLAGS)

LINKER_MAP_NAME := $(APP_NAME).map
ifeq ($(CREATE_LINKER_MAP), 1)
APP_LDFLAGS += -Wl,-Map=$(LINKER_MAP_NAME)
endif

#------------------------------------------------------------------------------
#           MAKEFILE INCLUDES DEPENDENT ON GENERATED CONTENT
#------------------------------------------------------------------------------

# Create list of object files to be built using the list of source files.
# The source file hierarchy is preserved in the object tree.
# The supported file extensions are:
#
# .c            - for C files
# .cxx .cc .cpp - for C++ files
# .S .s         - for assembler files
#
# Handle source files specified by --src-dir & --src-rdir differently, to
# save some processing time in calling the adjust-path macro.

OBJ_LIST_C 		:= $(patsubst %.c,%.o,$(filter %.c,$(C_SRCS)))
OBJ_LIST_CPP	:= $(patsubst %.cpp,%.o,$(filter %.cpp,$(CXX_SRCS)))
OBJ_LIST_CXX 	:= $(patsubst %.cxx,%.o,$(filter %.cxx,$(CXX_SRCS)))
OBJ_LIST_CC 	:= $(patsubst %.cc,%.o,$(filter %.cc,$(CXX_SRCS)))
OBJ_LIST_S 		:= $(patsubst %.S,%.o,$(filter %.S,$(ASM_SRCS)))
OBJ_LIST_SS		:= $(patsubst %.s,%.o,$(filter %.s,$(ASM_SRCS)))

OBJ_LIST := $(sort $(OBJ_LIST_C) $(OBJ_LIST_CPP) $(OBJ_LIST_CXX) \
				$(OBJ_LIST_CC) $(OBJ_LIST_S) $(OBJ_LIST_SS))

SDIR_OBJ_LIST_C		:= $(patsubst %.c,%.o,$(filter %.c,$(SDIR_C_SRCS)))
SDIR_OBJ_LIST_CPP	:= $(patsubst %.cpp,%.o,$(filter %.cpp,$(SDIR_CXX_SRCS)))
SDIR_OBJ_LIST_CXX 	:= $(patsubst %.cxx,%.o,$(filter %.cxx,$(SDIR_CXX_SRCS)))
SDIR_OBJ_LIST_CC 	:= $(patsubst %.cc,%.o,$(filter %.cc,$(SDIR_CXX_SRCS)))
SDIR_OBJ_LIST_S		:= $(patsubst %.S,%.o,$(filter %.S,$(SDIR_ASM_SRCS)))
SDIR_OBJ_LIST_SS	:= $(patsubst %.s,%.o,$(filter %.s,$(SDIR_ASM_SRCS)))

SDIR_OBJ_LIST := $(sort $(SDIR_OBJ_LIST_C) $(SDIR_OBJ_LIST_CPP) \
				$(SDIR_OBJ_LIST_CXX) $(SDIR_OBJ_LIST_CC) $(SDIR_OBJ_LIST_S) \
				$(SDIR_OBJ_LIST_SS))

# Relative-pathed objects that being with "../" are handled differently.
#
# Regular objects are created as 
#   $(CONFIG_OBJ_DIR)/<path>/<filename>.o
# where the path structure is maintained under the obj directory.  This
# applies for both absolute and relative paths; in the absolute path
# case this means the entire source path will be recreated under the obj
# directory.  This is done to allow two source files with the same name
# to be included as part of the project.
#
# Note: On Cygwin, the path recreated under the obj directory will be 
# the cygpath -u output path.
#
# Relative-path objects that begin with "../" cause problems under this 
# scheme, as $(CONFIG_OBJ_DIR)/../<rest of path>/ can potentially put the object
# files anywhere in the system, creating clutter and polluting the source tree.
# As such, their paths are flattened - the object file created will be 
# $(CONFIG_OBJ_DIR)/<filename>.o.  Due to this, two files specified with 
# "../" in the beginning cannot have the same name in the project.  VPATH 
# will be set for these sources to allow make to relocate the source file 
# via %.o rules.
#
# The following lines separate the object list into the flatten and regular
# lists, and then handles them as appropriate.

FLATTEN_OBJ_LIST := $(filter ../%,$(OBJ_LIST))
FLATTEN_APP_OBJS := $(addprefix $(CONFIG_OBJ_DIR)/,$(notdir $(FLATTEN_OBJ_LIST)))

REGULAR_OBJ_LIST 		:= $(filter-out $(FLATTEN_OBJ_LIST),$(OBJ_LIST))
REGULAR_OBJ_LIST_C 		:= $(filter $(OBJ_LIST_C),$(REGULAR_OBJ_LIST))
REGULAR_OBJ_LIST_CPP	:= $(filter $(OBJ_LIST_CPP),$(REGULAR_OBJ_LIST))
REGULAR_OBJ_LIST_CXX 	:= $(filter $(OBJ_LIST_CXX),$(REGULAR_OBJ_LIST))
REGULAR_OBJ_LIST_CC 	:= $(filter $(OBJ_LIST_CC),$(REGULAR_OBJ_LIST))
REGULAR_OBJ_LIST_S 		:= $(filter $(OBJ_LIST_S),$(REGULAR_OBJ_LIST))
REGULAR_OBJ_LIST_SS		:= $(filter $(OBJ_LIST_SS),$(REGULAR_OBJ_LIST))

FLATTEN_SDIR_OBJ_LIST := $(filter ../%,$(SDIR_OBJ_LIST))
FLATTEN_SDIR_APP_OBJS := $(addprefix $(CONFIG_OBJ_DIR)/,$(notdir $(FLATTEN_SDIR_OBJ_LIST)))

REGULAR_SDIR_OBJ_LIST 		:= $(filter-out $(FLATTEN_SDIR_OBJ_LIST),$(SDIR_OBJ_LIST))
REGULAR_SDIR_OBJ_LIST_C 	:= $(filter $(SDIR_OBJ_LIST_C),$(REGULAR_SDIR_OBJ_LIST))
REGULAR_SDIR_OBJ_LIST_CPP	:= $(filter $(SDIR_OBJ_LIST_CPP),$(REGULAR_SDIR_OBJ_LIST))
REGULAR_SDIR_OBJ_LIST_CXX 	:= $(filter $(SDIR_OBJ_LIST_CXX),$(REGULAR_SDIR_OBJ_LIST))
REGULAR_SDIR_OBJ_LIST_CC 	:= $(filter $(SDIR_OBJ_LIST_CC),$(REGULAR_SDIR_OBJ_LIST))
REGULAR_SDIR_OBJ_LIST_S 	:= $(filter $(SDIR_OBJ_LIST_S),$(REGULAR_SDIR_OBJ_LIST))
REGULAR_SDIR_OBJ_LIST_SS	:= $(filter $(SDIR_OBJ_LIST_SS),$(REGULAR_SDIR_OBJ_LIST))

VPATH := $(sort $(dir $(FLATTEN_OBJ_LIST)) $(dir $(FLATTEN_SDIR_OBJ_LIST)))

APP_OBJS_C := $(addprefix $(CONFIG_OBJ_DIR)/,\
	$(REGULAR_SDIR_OBJ_LIST_C) \
	$(foreach s,$(REGULAR_OBJ_LIST_C),$s))

APP_OBJS_CPP := $(addprefix $(CONFIG_OBJ_DIR)/,\
	$(REGULAR_SDIR_OBJ_LIST_CPP) \
	$(foreach s,$(REGULAR_OBJ_LIST_CPP),$s))

APP_OBJS_CXX := $(addprefix $(CONFIG_OBJ_DIR)/,\
	$(REGULAR_SDIR_OBJ_LIST_CXX) \
	$(foreach s,$(REGULAR_OBJ_LIST_CXX),$s))

APP_OBJS_CC := $(addprefix $(CONFIG_OBJ_DIR)/,\
	$(REGULAR_SDIR_OBJ_LIST_CC) \
	$(foreach s,$(REGULAR_OBJ_LIST_CC),$s))

APP_OBJS_S := $(addprefix $(CONFIG_OBJ_DIR)/,\
	$(REGULAR_SDIR_OBJ_LIST_S) \
	$(foreach s,$(REGULAR_OBJ_LIST_S),$s))

APP_OBJS_SS := $(addprefix $(CONFIG_OBJ_DIR)/,\
	$(REGULAR_SDIR_OBJ_LIST_SS) \
	$(foreach s,$(REGULAR_OBJ_LIST_SS),$s))

APP_OBJS := $(APP_OBJS_C) $(APP_OBJS_CPP) $(APP_OBJS_CXX) $(APP_OBJS_CC) \
	$(APP_OBJS_S) $(APP_OBJS_SS) \
	$(FLATTEN_APP_OBJS) $(FLATTEN_SDIR_APP_OBJS)

# Add any extra user-provided object files.
APP_OBJS += $(OBJS)

# Create list of dependancy files for each object file.
APP_DEPS := $(APP_OBJS:.o=.d)

#------------------------------------------------------------------------------
#                           BUILD PRE/POST PROCESS
#------------------------------------------------------------------------------
build_pre_process :
	$(BUILD_PRE_PROCESS)

build_post_process :
	$(BUILD_POST_PROCESS)

.PHONY: build_pre_process build_post_process

#------------------------------------------------------------------------------
#                                 TOOLS
#------------------------------------------------------------------------------

#
# Set tool default variables if not already defined.
# If these are defined, they would typically be defined in an
# included makefile fragment.
#
ifeq ($(DEFAULT_CROSS_COMPILE),)
DEFAULT_CROSS_COMPILE :=
endif

ifeq ($(DEFAULT_RM),)
DEFAULT_RM := rm -f
endif

ifeq ($(DEFAULT_CP),)
DEFAULT_CP := cp -f
endif

ifeq ($(DEFAULT_MKDIR),)
DEFAULT_MKDIR := mkdir -p
endif

#
# Set tool variables to defaults if not already defined.
# If these are defined, they would typically be defined by a
# setting in the generated portion of this makefile.
#
ifeq ($(CROSS_COMPILE),)
CROSS_COMPILE := $(DEFAULT_CROSS_COMPILE)
endif

ifeq ($(origin CC),default)
CC := $(CROSS_COMPILE)gcc -xc
endif

ifeq ($(origin CXX),default)
CXX := $(CROSS_COMPILE)gcc -xc++
endif

ifeq ($(origin AS),default)
AS := $(CROSS_COMPILE)gcc
endif

ifeq ($(origin AR),default)
AR := $(CROSS_COMPILE)ar
endif

ifeq ($(origin LD),default)
LD := $(CROSS_COMPILE)g++
endif

ifeq ($(origin NM),default)
NM := $(CROSS_COMPILE)nm
endif

ifeq ($(origin RM),default)
RM := $(DEFAULT_RM)
endif

ifeq ($(origin CP),default)
CP := $(DEFAULT_CP)
endif

ifeq ($(OBJDUMP),)
OBJDUMP := $(CROSS_COMPILE)objdump
endif

ifeq ($(OBJCOPY),)
OBJCOPY := $(CROSS_COMPILE)objcopy
endif

ifeq ($(MKDIR),)
MKDIR := $(DEFAULT_MKDIR)
endif

#------------------------------------------------------------------------------
#                     PATTERN RULES TO BUILD OBJECTS
#------------------------------------------------------------------------------

define compile.c
@$(ECHO) Info: Compiling $< to $@
@$(MKDIR) $(@D)
$(CC) -MP -MMD -c $(APP_CPPFLAGS) $(APP_CFLAGS) -o $@ $<
$(CC_POST_PROCESS)
endef

define compile.cpp
@$(ECHO) Info: Compiling $< to $@
@$(MKDIR) $(@D)
$(CXX) -MP -MMD -c $(APP_CPPFLAGS) $(APP_CXXFLAGS) $(APP_CFLAGS) -o $@ $<
$(CXX_POST_PROCESS)
endef

# If assembling with the compiler, ensure "-Wa," is prepended to all APP_ASFLAGS
ifeq ($(AS),$(patsubst %as,%,$(AS)))
COMMA := ,
APP_ASFLAGS :=  $(filter-out $(APP_CFLAGS),$(addprefix -Wa$(COMMA),$(patsubst -Wa$(COMMA)%,%,$(APP_ASFLAGS))))
endif

define compile.s
@$(ECHO) Info: Assembling $< to $@
@$(MKDIR) $(@D)
$(AS) -MP -MMD -c $(APP_CPPFLAGS) $(APP_CFLAGS) $(APP_ASFLAGS) -o $@ $<
$(AS_POST_PROCESS)
endef

$(CONFIG_OBJ_DIR)/%.o: %.c
	$(compile.c)

$(CONFIG_OBJ_DIR)/%.o: %.cpp
	$(compile.cpp)

$(CONFIG_OBJ_DIR)/%.o: %.cc
	$(compile.cpp)

$(CONFIG_OBJ_DIR)/%.o: %.cxx
	$(compile.cpp)

$(CONFIG_OBJ_DIR)/%.o: %.S
	$(compile.s)

$(CONFIG_OBJ_DIR)/%.o: %.s
	$(compile.s)

#------------------------------------------------------------------------------
#                     PATTERN RULES TO INTERMEDIATE FILES
#------------------------------------------------------------------------------

$(CONFIG_OBJ_DIR)/%.s: %.c
	@$(ECHO) Info: Compiling $< to $@
	@$(MKDIR) $(@D)
	$(CC) -S $(APP_CPPFLAGS) $(APP_CFLAGS) -o $@ $<

$(CONFIG_OBJ_DIR)/%.s: %.cpp
	@$(ECHO) Info: Compiling $< to $@
	@$(MKDIR) $(@D)
	$(CXX) -S $(APP_CPPFLAGS) $(APP_CXXFLAGS) $(APP_CFLAGS) -o $@ $<

$(CONFIG_OBJ_DIR)/%.s: %.cc
	@$(ECHO) Info: Compiling $< to $@
	@$(MKDIR) $(@D)
	$(CXX) -S $(APP_CPPFLAGS) $(APP_CXXFLAGS) $(APP_CFLAGS) -o $@ $<

$(CONFIG_OBJ_DIR)/%.s: %.cxx
	@$(ECHO) Info: Compiling $< to $@
	@$(MKDIR) $(@D)
	$(CXX) -S $(APP_CPPFLAGS) $(APP_CXXFLAGS) $(APP_CFLAGS) -o $@ $<

$(CONFIG_OBJ_DIR)/%.i: %.c
	@$(ECHO) Info: Compiling $< to $@
	@$(MKDIR) $(@D)
	$(CC) -E $(APP_CPPFLAGS) $(APP_CFLAGS) -o $@ $<

$(CONFIG_OBJ_DIR)/%.i: %.cpp
	@$(ECHO) Info: Compiling $< to $@
	@$(MKDIR) $(@D)
	$(CXX) -E $(APP_CPPFLAGS) $(APP_CXXFLAGS) $(APP_CFLAGS) -o $@ $<

$(CONFIG_OBJ_DIR)/%.i: %.cc
	@$(ECHO) Info: Compiling $< to $@
	@$(MKDIR) $(@D)
	$(CXX) -E $(APP_CPPFLAGS) $(APP_CXXFLAGS) $(APP_CFLAGS) -o $@ $<

$(CONFIG_OBJ_DIR)/%.i: %.cxx
	@$(ECHO) Info: Compiling $< to $@
	@$(MKDIR) $(@D)
	$(CXX) -E $(APP_CPPFLAGS) $(APP_CXXFLAGS) $(APP_CFLAGS) -o $@ $<

#------------------------------------------------------------------------------
#                        TARGET RULES
#------------------------------------------------------------------------------

.PHONY : help
help :
	@$(ECHO) "Summary of Makefile targets"
	@$(ECHO) "  Build targets:"
	@$(ECHO) "    all (default)     - Application"
	@$(ECHO) "    clean             - Application"

# Handy rule to skip making libraries and just make application.
.PHONY : app
app : $(ELF)

ifeq ($(CREATE_OBJDUMP), 1)
app : $(OBJDUMP_NAME)
endif

# Clean just the application.
.PHONY : clean
clean :
	@$(RM) -r $(ELF) $(OBJDUMP_NAME) $(LINKER_MAP_NAME) $(OBJ_ROOT_DIR)
	@$(ECHO) [$(APP_NAME) clean complete]

# Include the dependency files unless the make goal is performing a clean
# of the application.
-include $(APP_DEPS)

# Delete the target of a rule if it has changed and its commands exit 
# with a nonzero exit status.
.DELETE_ON_ERROR:

#------------------------------------------------------------------------------
#                         ELF TARGET RULE
#------------------------------------------------------------------------------
# Rule for constructing the executable elf file.
$(ELF) : $(APP_OBJS) $(LINKER_SCRIPT) $(APP_LDDEPS)
	@$(ECHO) Info: Linking $@
	$(LD) $(APP_LDFLAGS) $(APP_CFLAGS) -o $@ $(filter-out $(CRT0),$(APP_OBJS)) $(APP_LIBS)

$(OBJDUMP_NAME) : $(ELF)
	@$(ECHO) Info: Creating $@
	$(OBJDUMP) $(OBJDUMP_FLAGS) $< >$@
