#!/usr/bin/make -f
# Makefile for DISTRHO Plugins #
# ---------------------------- #
# Created by falkTX
#

# --------------------------------------------------------------
# Project name, used for binaries

NAME = uprising

# --------------------------------------------------------------
# Files to build

FILES_DSP = \
	UprisingPlugin.cpp \
	dsp/src/Test.cpp

#FILES_UI  = \
	InfoExampleUI.cpp

# --------------------------------------------------------------
# Do some magic

include ../../dpf/Makefile.plugins.mk

BASE_FLAGS += -I dsp

# --------------------------------------------------------------
# Enable all possible plugin types


#ifeq ($(HAVE_DGL),true)
ifeq ($(HAVE_JACK),true)
TARGETS += jack
endif
#endif

ifeq ($(HAVE_DGL),true)
TARGETS += lv2_sep
else
TARGETS += lv2_dsp
endif

TARGETS += vst

all: $(TARGETS)

# --------------------------------------------------------------
