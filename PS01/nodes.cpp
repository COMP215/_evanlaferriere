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
    to_add->edges_.push_back(this);
}

void Node::PrintAdjList()
{
    std::cout << name_ << ':';
    for(int i = 0; i+1 < edges_.size(); i++)
    {
        std::cout << ' ' << edges_[i]->name_;
    }
    std::cout << ' ' << edges_[edges_.size()-1]->name_ << std::endl;

}

