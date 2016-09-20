#include <iostream>
#include <string>
#include <regex>

using namespace std;
class Node
{
    public:
        string data_;
        Node* next_ = NULL;
        Node();
        Node(string data);
        Node(string data, Node* next);
};

Node::Node(string data)
{
    data_ = data;
}
Node::Node(string data, Node* next)
{
    data_ = data;
    next_ = next;
}

class LinkedList
{
    public:
        Node* buffer_ = new Node(NULL);
        Node* tail_ = buffer_;
        void print();
        void Insert(string to_add);
        bool Search(string);
        bool Delete(string);
};
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

bool LinkedList::Search(string data)
{
    Node* sorting_node = buffer_;
    while(sorting_node != tail_)
    {
        if (sorting_node->data_ == data)
            return true;
    }
    return false;
}

bool LinkedList::Delete(string data)
{
    Node* sorting_node = buffer_;
    if(Search(data))
    {
        while(sorting_node != tail_)
        {
            if (sorting_node->next_->data_ == data)
            {
                //something
            }
        }
    }
    return false;
}
