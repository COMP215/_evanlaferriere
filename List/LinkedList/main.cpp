#include <iostream>
#include "LinkedList.h"
using namespace std;
class Node
{
    public:
        int num;
        Node* next;
        Node();
        Node(int num);
        Node(int num, Node* next);
};
Node::Node()
{
    //for buffer
}
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
    Node* buffer_ = new Node;
    Node* tail_ = buffer_;
        void add(int what);
        void add(int where, int what);
        void print();
};
void add::LinkedList(int what)
{
    tail_->next = new Node;
    tail_ = tail_->next;
    tail_->num = what;
}
void add::LinkedList(int where, int what)
{
    Node* foo = buffer_;
    for(int i = 0; i < where; i++)
    {
        foo = foo->next;
    }
    foo->num = what;
    if(tail_->next == foo)
    {
        tail_->next = new Node;
    }
}
void print::LinkedList()
{
    Node* printing_node = buffer_;
    while(printing_node != tail_)
}

int main()
{
    LinkedList Foo;
    int user_in = 1;
    while(1)
    {
        cout << "Input an int, or don't to end this."
        try
        {
            cin >> user_in;
        }
        catch
        {
            break;
        }
        Foo.add(user_in);
    }
    cout << "Would you like to print the list? Y/N"
    char response = "";
    cin >> response;
    if (response = 'Y')
    {
        Foo.print();
    }
}
