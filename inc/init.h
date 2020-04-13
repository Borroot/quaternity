/**
 * @file
 *
 * @brief This file defines an initialization function.
 */

#ifndef INIT_H
# define INIT_H

#include <vector>

#include "settings.h"
#include "state.h"

State init_state(const Settings &settings);

#endif
