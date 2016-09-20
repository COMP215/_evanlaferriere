#include <iostream>
#include <string>
#include <regex>
#include "LinkedList.h"

using namespace std;
class Node
{
    public:
        int num;
        Node* next = NULL;
        Node();
        Node(int num);
        Node(int num, Node* next);
};

Node::Node(int num)
{
    this->num = num;
}
Node::Node(int num, Node* next)
{
    this->num = num;
    this->next = next;
}

class LinkedList
{
    public:
        Node* buffer_ = new Node(NULL);
        Node* tail_ = buffer_;
        void add(int to_add);
        void add(int where_to, int to_add);
        void print();
};
void LinkedList::add(int to_add)
{
    tail_->next = new Node(to_add);
    tail_ = tail_->next;
}
void LinkedList::add(int where_to, int to_add)
{
    Node* foo = buffer_;
    for(int i = 0; i < where_to; i++)
    {
        foo = foo->next;
    }
    foo->num = to_add;
    if(tail_->next == foo)
    {
        tail_ = foo;
    }
}
void LinkedList::print()
{
    Node* printing_node = buffer_->next;
    cout << "There were ";
    while(printing_node->next != tail_)
    {
        cout << printing_node->num << ", ";
        printing_node = printing_node->next;
    }
    cout << "and " << printing_node->num << " in the list." << endl;
}

int main()
{
    LinkedList Foo;
    int user_in = 1;
    while(1)
    {
        cout << "Input an int, or don't to end this. ";
        cin >> user_in;
        if (cin.fail())
            break;
        Foo.add(user_in);
    }
    Foo.print();
}
