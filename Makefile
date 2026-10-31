CXX  := g++
CXXFLAGS  := -Wall -Wextra -Werror -std=c11
INCLUDES  := -Iinclude

DEBUG_FLAGS  := -g -O0
RELEASE_FLAGS  := -O2

BUILD ?= debug

ifeq ($(BUILD),release)
	CXXFLAGS += $(RELEASE_FLAGS)
else
	CXXFLAGS += $(DEBUG_FLAGS)
endif

SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:src/%.cpp=build/obj/%.o)
DEP := $(OBJ:.o=.d)

TARGET := bin/gcei

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p bin
	@echo Linking...
	@$(CXX) $(OBJ) -o $@
	@echo Compilation succesful. The files are in bin.

build/obj/%.o: src/%.cpp
	@mkdir -p build/obj
	@echo [ CXX ] $<
	@$(CXX) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

-include $(DEP)

clean:
	@rm -rf build bin
	@echo Build directory purged

