#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include "node.h"
class Graph
{
    std::vector<Node*> All_Nodes_ = {};
    public:
        void Add(Node to_add);
        void Add(Node to_add, std::vector<Node*> edges);
        void AddVertex(std::string name, std::vector<Node*> edges);
        void Printer();
        bool Find(std::string name);
        bool IsBipartite();
        void GenNodes(int numNodes, int edgesEach, int wordWidth);
};
#endif // GRAPH_H
