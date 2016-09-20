#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

class Node
{
    public:
        std::string data_;
        Node* next_ = NULL;
        Node();
        Node(std::string data);
        Node(std::string data, Node* next);
};

class LinkedList
{
    public:
        Node* buffer_ = new Node(NULL);
        Node* tail_ = buffer_;
        void Insert(std::string to_add);
        void Insert(int where_to, std::string to_add);
        void print();
        bool Search(std::string data);
        bool Delete(std::string data);
};

#endif
