/**
 * @file
 *
 * @brief This file defines maximum matching algorithm functions.
 */

#include <algorithm>
#include <vector>

#include "match.h"

/**
 * @brief Depth first search recursive function which returns true if a
 * matching for right node / `rnode` is possible.
 */
bool dfs(const Graph &graph, int rnode, std::vector<bool> &seen, std::vector<int> &match)
{
	for (size_t lnode = 0; lnode < graph.size(); lnode++) {
		if (graph[lnode][rnode] && !seen[lnode]) {
			seen[lnode] = true;
			if (match[lnode] < 0 || dfs(graph, match[lnode], seen, match)) {
				match[lnode] = rnode;
				return true;
			}
		}
	}
	return false;
}

/**
 * @brief Check if there exists a matching for _all_ cards.
 *
 * @see match_find
 */
bool match_exists(const Graph &graph)
{
	std::vector<int> match = match_find(graph);
	return std::find(match.begin(), match.end(), -1) == match.end();
}

/**
 * @brief Find a match of the given graph.
 *
 * @return A vector list with integers representing to which rnode the lnode at
 * the given index is connected, -1 indicates a connection to none.
 */
std::vector<int> match_find(const Graph &graph)
{
	std::vector<int> match(graph.size(), -1);  // FIXME Make match for left node, not for right.
	for (int rnode = 0; rnode < (int)graph.size(); rnode++) {
		std::vector<bool> seen(graph.size(), false);
		dfs(graph, rnode, seen, match);
	}
	return match;
}
