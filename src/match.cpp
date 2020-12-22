/**
 * @file
 *
 * @brief This file defines maximum matching algorithm functions.
 */

#include <vector>

#include "match.h"

/**
 * @brief Depth first search recursive function which returns true if a
 * matching for (left) node `lnode` is possible.
 */
bool dfs(const Graph &graph, int lnode, vector<bool> &seen, vector<int> &match)
{
	for (size_t rnode = 0; rnode < graph.size(); rnode++) {
		if (graph[lnode][rnode] && !seen[rnode]) {
			seen[rnode] = true;
			if (match[rnode] < 0 || dfs(graph, match[rnode], seen, match)) {
				match[rnode] = lnode;
				return true;
			}
		}
	}
	return false;
}

/**
 * @brief Check if there exists a matching for _all_ cards.
 */
bool match_exists(const Graph &graph)
{
	vector<int> match(graph.size(), -1);
	for (size_t lnode = 0; lnode < graph.size(); lnode++) {
		vector<bool> seen(graph.size(), false);
		if (!dfs(graph, lnode, seen, match))
			return false;
	}
	return true;
}
