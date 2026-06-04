#ifndef FOUNDATIONS_CORE_SIGSLOT_H_
#define FOUNDATIONS_CORE_SIGSLOT_H_

// Define the structures for signal and slot
typedef struct _signal signal_t;
typedef struct _slot slot_t;

// Function prototypes

/**
 * Connects a slot to a signal.
 *
 * @param signal   Pointer to the signal structure.
 * @param callback Pointer to the callback function.
 * @param data     Pointer to the data to be passed to the callback function.
 */
void connectSignal(signal_t *signal, void (*callback)(void *data), void *data);

/**
 * Emits a signal, calling all connected slots.
 *
 * @param signal Pointer to the signal structure.
 */
void emitSignal(signal_t *signal);

#endif
