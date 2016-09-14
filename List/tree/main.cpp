#include <iostream>

using namespace std;
class Node
{
    public:
        int num;
        Node* left = NULL;
        Node* right = NULL;
        Node* root = NULL;
        Node();
        Node(Node* left, Node* right);
        Node(int num, Node* left, Node* right);
};
Node::Node(Node* left, Node* right)
{
    this->left = left;
    this->right = right;
}
Node::Node(int num, Node* left, Node* right)
{
    this->num = num;
    this->left = left;
    this->right = right;
}
class Tree
{
    int hmr_data_ = 0;
    int* data_ = new int[hmr_data_];
    Node* buffer_ = new Node(int* );
    Tree(int* passed_data, int num_ints);
};
Tree::Tree(int* passed_data, int num_ints)
{
    hmr_data_=num_ints;
    data_= passed_data;
    int num = 1;
    buffer_->left = new Node(data_[0])
    Node* sorting_node = buffer_;
    while(num < hmr_data_)
    {
        if
    }
}
int main()
{
    int foo[5] = {1,2,3,4,5};
    Tree bar(foo, 5);


}
