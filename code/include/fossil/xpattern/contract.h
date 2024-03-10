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
#ifndef FSCL_CONTRACT_H
#define FSCL_CONTRACT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>

// Define the contract type
typedef struct {
    bool (*pre_condition)();
    void (*post_condition)();
} ccontract;

// =================================================================
// create and erase
// =================================================================
/**
 * Create a contract with specified pre and post conditions.
 *
 * @param pre_condition  The precondition function.
 * @param post_condition The postcondition function.
 * @return               The created contract.
 */
ccontract* fscl_contract_create(bool (*pre_condition)(), void (*post_condition)());

// =================================================================
// Additional functions
// =================================================================

/**
 * Check the precondition of the contract.
 *
 * @param contract The contract to check.
 * @return         True if the precondition is met, false otherwise.
 */
bool fscl_contract_check_pre(ccontract* contract);

/**
 * Check the postcondition of the contract.
 *
 * @param contract The contract to check.
 * @return         True if the postcondition is met, false otherwise.
 */
bool fscl_contract_check_post(ccontract* contract);

/**
 * Assert a boolean condition, and if false, print an error message.
 *
 * @param condition The condition to assert.
 * @param message   The error message to print if the condition is false.
 * @return          True if the condition is true, false otherwise.
 */
bool fscl_contract_assert(bool condition, const char* message);

/**
 * Require that a pointer is not null.
 *
 * @param ptr        The pointer to check.
 * @param param_name The name of the parameter.
 * @return           True if the requirement is met, false otherwise.
 */
bool fscl_contract_require_not_null(const void* ptr, const char* param_name);

// Other require functions ...

/**
 * Require a custom condition to be true.
 *
 * @param custom_condition The custom condition function.
 * @param param_name       The name of the parameter.
 * @return                 True if the requirement is met, false otherwise.
 */
bool fscl_contract_require_custom_condition(bool (*custom_condition)(), const char* param_name);

#ifdef __cplusplus
}
#endif

#endif
