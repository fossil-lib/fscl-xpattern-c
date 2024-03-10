/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#ifndef FSCL_OBSREVER_H
#define FSCL_OBSREVER_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdlib.h>

// Structure representing an observer
typedef struct {
    void (*update)(void* data); // Function pointer for the update method
} cobserver;

// Structure representing the subject to be observed
typedef struct {
    cobserver** observers; // Array of observers
    int numObservers;      // Number of observers
} csubject;

// =================================================================
// Create and Erase
// =================================================================

/**
 * Create a subject for observation.
 *
 * @param subject The subject to create.
 */
void fscl_observe_create(csubject* subject);

/**
 * Erase a subject and its observers.
 *
 * @param subject The subject to erase.
 */
void fscl_observe_erase(csubject* subject);

/**
 * Update all observers of the subject with the provided data.
 *
 * @param subject The subject whose observers need to be updated.
 * @param data    The data to update the observers.
 */
void fscl_observe_update_all(csubject* subject, void* data);

// =================================================================
// Additional Functions
// =================================================================

/**
 * Add an observer to the subject.
 *
 * @param subject  The subject to which the observer is added.
 * @param observer The observer to add.
 */
void fscl_observe_add_observer(csubject* subject, cobserver* observer);

/**
 * Remove an observer from the subject.
 *
 * @param subject  The subject from which the observer is removed.
 * @param observer The observer to remove.
 */
void fscl_observe_remove_observer(csubject* subject, cobserver* observer);

/**
 * Notify all observers of the subject with the provided data.
 *
 * @param subject The subject whose observers need to be notified.
 * @param data    The data to notify the observers.
 */
void fscl_observe_notify(csubject* subject, void* data);

/**
 * Erase all observers from the subject.
 *
 * @param subject The subject from which all observers are erased.
 */
void fscl_observe_erase_all(csubject* subject);

/**
 * Check if the subject has any observers.
 *
 * @param subject The subject to check for observers.
 * @return        1 if there are observers, 0 otherwise.
 */
int fscl_observe_has_observers(csubject* subject);

#ifdef __cplusplus
}
#endif

#endif
