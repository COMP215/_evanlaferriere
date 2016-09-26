#include <iostream>
#include <string>
#include <regex>
#include "LinkedList.h"

using namespace std;

Node::Node(string data)
{
    data_ = data;
}
Node::Node(string data, Node* next)
{
    data_ = data;
    next_ = next;
}

void LinkedList::Insert(string to_add)
{
    tail_->next_ = new Node(to_add);
    tail_ = tail_->next_;
}

void LinkedList::print()
{
    Node* printing_node = buffer_->next_;
    cout << "There were ";
    while(printing_node->next_ != tail_)
    {
        cout << printing_node->data_ << ", ";
        printing_node = printing_node->next_;
    }
    cout << "and " << printing_node->data_ << " in the list." << endl;
}

string LinkedList::Search(string data)
{
    Node* sorting_node = buffer_;
    while(sorting_node != tail_)
    {
        if (sorting_node->data_ == data)
            return sorting_node->data_;
    }
    return "Not found LL";
}

bool LinkedList::Delete(string data)
{
    Node* sorting_node = buffer_;
    if(Search(data)!="Not found LL")
    {
        while(sorting_node != tail_)
        {
            if (sorting_node->next_->data_ == data)
            {
                Node* to_die = sorting_node->next_;
                sorting_node->next_ = sorting_node->next_->next_;
                delete to_die;
                return true;
            }
        }
    }
    return false;
}
