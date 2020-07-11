/**
 * @file
 *
 * @brief This file defines an initialization function header.
 */

#ifndef INIT_H_
#define INIT_H_

#include <vector>

#include "settings.h"
#include "state.h"

State init_state(const Settings &settings);

#endif
