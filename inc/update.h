/**
 * @file
 *
 * @brief This file defines the state update function header.
 */

#ifndef UPDATE_H_
#define UPDATE_H_

#include <vector>

#include "round.h"
#include "state.h"

using namespace std;

void update_state(const Settings &settings, State &state, const Question &question, const Answer &answer);

#endif
