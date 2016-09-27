#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include "node.h"
class Graph
{
    vector<Node*> All_Nodes_ = {};
    public:
        void Add(Node to_add);
        void Add(Node to_add, vector<Node*> edges);
        void AddVertex(std::string name, vector<Node*> edges);
        void Printer();
};
#endif // GRAPH_H
