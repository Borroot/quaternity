/**
 * @file
 *
 * @brief This file defines maximum matching algorithm function headers.
 */

#ifndef MATCH_H_
#define MATCH_H_

#include <vector>

using namespace std;

/**
 * @brief A bipartite graph where true booleans represent edges between a left
 * node denoted as the row and a right node denoted as the column in the grid.
 */
typedef vector<vector<bool>> Graph;

bool match_exists(const Graph &graph);

#endif /* MATCH_H_ */
