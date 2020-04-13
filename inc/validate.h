#ifndef VALIDATE_H
# define VALIDATE_H

#include "round.h"
#include "settings.h"
#include "state.h"

bool valid_question(const Settings &settings, const State &state, const Question &question);
bool valid_answer(const Settings &settings, const State &state, const Question &question, const Answer &answer);
bool valid_state(const Settings &settings, const State &state);

#endif
