#pragma once

#define OLED_TIMEOUT 60000
#define COMBO_COUNT 1

// Home row mods — mirror ZMK hml/hmr (balanced flavor + opposite-hand trigger)
#define TAPPING_TERM 280
#define QUICK_TAP_TERM 175
#define PERMISSIVE_HOLD
#define CHORDAL_HOLD

// Split sync — both OLEDs see full state (mods/layer/WPM) from either half
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_WPM_ENABLE

// Délai entre register/unregister des tap_code → laisse l'OS voir les dead keys
#define TAP_CODE_DELAY 10
