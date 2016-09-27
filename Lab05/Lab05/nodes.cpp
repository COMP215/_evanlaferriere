#include "node.h"
#include <vector>
Node::Node()
{
    edges_ = {};
}
Node::Node(name)
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
    cout << this->name_ << ':';
    for(int i = this->edges_.size(); i > 1; i--)
    {
        cout << ' ' << edges_[i].name_;
    }
    cout << ' ' << edges_[0].name;

}

