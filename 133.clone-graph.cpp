/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
#include <unordered_map>

using namespace std;

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

        if (node == NULL) 
            return NULL;

        if (m.find(node->label) != m.end()) 
            return m[node->label];

        UndirectedGraphNode *ret = new UndirectedGraphNode(node->label);
        m[node->label] = ret;
        ret->neighbors.clear();
        for (int i = 0; i < node->neighbors.size(); i++)
            ret->neighbors.push_back(cloneGraph(node->neighbors[i]));
        return ret;
    }

    unordered_map<int, UndirectedGraphNode *> m;
};
