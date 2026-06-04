#include "../../include/core/sigslot.h"
#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
// Define a structure to represent a slot
struct _slot {
    void (*callback)(void *data);
    void *data;
};

// Define a structure to represent a signal
struct _signal {
    slot_t *slots;  // Use the typedef name `slot_t` instead of `Slot`
    size_t num_slots;
};

// Function to connect a slot to a signal
void connectSignal(signal_t *signal, void (*callback)(void *data), void *data) {
    // Resize the array of slots
    signal->num_slots++;
    signal->slots = realloc(signal->slots, signal->num_slots * sizeof(slot_t));

    // Check if realloc succeeded
    if (signal->slots == NULL) {
        perror("Error allocating memory for slots");
        exit(EXIT_FAILURE);  // Exit the program if memory allocation fails
    }

    // Add the new slot
    signal->slots[signal->num_slots - 1].callback = callback;
    signal->slots[signal->num_slots - 1].data = data;
}

// Function to emit a signal
void emitSignal(signal_t *signal) {
    // Call each slot's callback function
    for (size_t i = 0; i < signal->num_slots; i++) {
        signal->slots[i].callback(signal->slots[i].data);
    }
}
