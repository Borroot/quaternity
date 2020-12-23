/**
 * @file
 *
 * @brief This file defines the state update function headers.
 */

#ifndef UPDATE_H_
#define UPDATE_H_

#include <vector>

#include "round.h"
#include "state.h"

void update_state(const Settings &settings, State &state, const Question &question, const Answer &answer);
void update_quartets(const Settings &settings, State &state);

#endif /* UPDATE */
