/**
 * @file
 *
 * @brief This file defines maximum matching algorithm function headers.
 */

#ifndef MATCH_H_
#define MATCH_H_

#include <vector>

#include "graph.h"

std::vector<int> match_find(const Graph &graph);
bool match_exists(const Graph &graph);

#endif /* MATCH_H_ */
