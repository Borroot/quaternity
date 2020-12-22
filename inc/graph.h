/**
 * @file
 *
 * @brief This file defines the graph type and a creation function header.
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

#include "settings.h"
#include "state.h"

/**
 * @brief A bipartite graph where true booleans represent edges between a left
 * node denoted as the row and a right node denoted as the column in the grid.
 */
typedef vector<vector<bool>> Graph;

bool  graph_possible(const State &state);
Graph graph_create(const Settings &settings, const State &state);

#endif /* GRAPH_H_ */
