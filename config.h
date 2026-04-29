#pragma once

#define OLED_TIMEOUT 60000
#define COMBO_COUNT 1

// Split sync — both OLEDs see full state (mods/layer/WPM/activity) from either half
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_WPM_ENABLE
#define SPLIT_ACTIVITY_ENABLE

// Délai entre register/unregister des tap_code → laisse l'OS voir les dead keys
#define TAP_CODE_DELAY 10
