#include "node.h"
#include <iostream>
#include <vector>
Node::Node()
{
    edges_ = {};
}
Node::Node(std::string name)
{
    edges_ = {};
    name_ = name;
}
void Node::Add(Node* to_add)
{
    this->edges_.push_back(to_add);
}

void Node::PrintAdjList()
{
    std::cout << name_ << ':';
    for(int i = edges_.size(); i > 1; i--)
    {
        std::cout << ' ' << edges_[i]->name_;
    }
    std::cout << ' ' << edges_[0]->name_ << std::endl;

}

