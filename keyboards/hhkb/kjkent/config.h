/*
Copyright 2020 Kan-Ru Chen <kanru@kanru.info>
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 8

/* matrix power saving */
#define MATRIX_POWER_SAVE_TIMEOUT_MS 10000
#define MATRIX_POWER_SAVE_TIMEOUT_L2_MS 1800000
#define MATRIX_POWER_SAVE_TIMEOUT_L3_MS 7200000

//#define UNICODE_KEY_LNX LCTL(LSFT(KC_U))
//#define UNICODE_KEY_WINC xxxxxxxxx
// For win run: reg add "HKCU\Control Panel\Input Method" -v EnableHexNumpad -t REG_SZ -d 1
// For linux, needs IBus, otherwise it'll ony work on GTK
//#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
//#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX, UNICODE_MODE_WINDOWS
//#define UNICODE_CYCLE_PERSIST false
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

///// Note: the options below are disabled automatically if CONSOLE_ENABLE = no
///         Uncommenting will result in redefined errors during build
/* disable debug print */
//#define NO_DEBUG
/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

//#define DEBUG_MATRIX_SCAN_RATE
