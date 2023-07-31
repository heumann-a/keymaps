

# Keyboard specific defines
NKRO_ENABLE = yes  
EXTRAKEY_ENABLE = yes       # Audio control and System control
WPM_ENABLE = yes
TAP_DANCE_ENABLE = no		# Enable Tab Dance for Tap-Hold features
CONSOLE_ENABLE = no
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
AUDIO_ENABLE = no           # Audio output on port C6
MIDI_ENABLE = no            # MIDI controls

OCEAN_DREAM_ENABLE = yes
LUNA_ENABLE = yes

ifeq ($(strip $(OLED_ENABLE)), yes)

  ifdef OCEAN_DREAM_ENABLE
    ifeq ($(strip $(OCEAN_DREAM_ENABLE)), yes)
      SRC += ocean_dream.c
      OPT_DEFS += -DOCEAN_DREAM_ENABLE
    endif
  endif
  ifndef OCEAN_DREAM_ENABLE
    SRC += ocean_dream.c
    OPT_DEFS += -DOCEAN_DREAM_ENABLE
  endif


  ifdef LUNA_ENABLE
    ifeq ($(strip $(LUNA_ENABLE)), yes)
      SRC += luna.c
      OPT_DEFS += -DLUNA_ENABLE
    endif
  endif
  ifndef LUNA_ENABLE
    SRC += luna.c
    OPT_DEFS += -DLUNA_ENABLE
  endif
  
endif