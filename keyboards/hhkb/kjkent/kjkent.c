/* Copyright 2021 Kan-Ru Chen <kanru@kanru.info>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"

extern uint8_t power_save_level;

void keyboard_pre_init_kb(void) {
    keyboard_pre_init_user();

    // BT power up
    setPinOutput(D5);
    writePinLow(D5);

    // Row selectors
    setPinOutput(B0);
    setPinOutput(B1);
    setPinOutput(B2);

    // Col selectors
    setPinOutput(B3);
    setPinOutput(B4);
    setPinOutput(B5);

    // Key strobe
    setPinOutput(B6);
    writePinHigh(B6);

    // Key: input with pull-up
    setPinInputHigh(D7);

    // Unused pins on Pro2 ANSI
    // Input with pull up to save power
    setPinInputHigh(C6);
    setPinInputHigh(C7);

    //// LED pin configuration
    // F4 == LED 1
    // F1 == LED 2
    // F0 == LED 3
    setPinOutput(F4);
    setPinOutput(F1);
    setPinOutput(F0);
    writePinLow(F4);
    writePinLow(F1);
    writePinLow(F0);

    // Turn on switch PCB
    setPinOutput(D6);
    writePinLow(D6);

}

void suspend_power_down_kb(void) {
    suspend_power_down_user();

    if (power_save_level > 2) {
        // Disable UART TX to avoid current leakage
        UCSR1B &= ~_BV(TXEN1);
        // Power down BLE module
        writePinHigh(D5);
    }
}

void suspend_wakeup_init_kb(void) {
    suspend_wakeup_init_user();

    // Power up BLE module
    writePinLow(D5);
    // Enable UART TX
    UCSR1B |= _BV(TXEN1);

}

layer_state_t layer_state_set_kb(layer_state_t state) {
    state = layer_state_set_user(state);

    writePin(F4, IS_LAYER_ON_STATE(state, 1));
    writePin(F1, IS_LAYER_ON_STATE(state, 2));
    return state;
}
