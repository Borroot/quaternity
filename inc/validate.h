/**
 * @file
 *
 * @brief This file defines function headers for functions that can check if a
 * question or state is valid.
 */

#ifndef VALIDATE_H_
#define VALIDATE_H_

#include "round.h"
#include "settings.h"
#include "state.h"

bool *valid_question(const Settings &settings, const State &state, const Question &question);

#endif /* VALIDATE_H_ */
