#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

class Node
{
    public:
        int num;
        Node* next = NULL;
        Node();
        Node(int num);
        Node(int num, Node* next);
};

class LinkedList
{
    public:
        Node* buffer_ = new Node(NULL);
        Node* tail_ = buffer_;
        void Insert(int to_add);
        void Insert(int where_to, int to_add);
        void print();
        bool Search(std::string data);
        bool Delete(std::string data);
};

#endif
