#ifndef NODE_H
#define NODE_H
#include <vector>
class Node
{
    public:
        std::vector<Node*> edges_= {};
        std::string name_ = "";
        Node();
        Node(std::string name);
        void Add(Node* to_add);
        void PrintAdjList();
};
#endif
