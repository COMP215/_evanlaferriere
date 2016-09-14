#include <iostream>

using namespace std;
class Node
{
    public:
        int num;
        Node* left = NULL;
        Node* right = NULL;
        Node* root = NULL;
        Node(int data);
        Node(Node* left, Node* right);
        Node(int num, Node* left, Node* right);
};
Node::Node(int data)
{
    num = data;
}
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
    public:
        int hmr_data_ = 0;
        int* data_ = new int[hmr_data_];
        Node* buffer_ = new Node(NULL);
        Tree(int* passed_data);
        void Print(Node* printing_node);
        Node* Print_This();
};
Tree::Tree(int* passed_data)
{
    hmr_data_= sizeof(passed_data)/sizeof(hmr_data_);
    data_= passed_data;
    int num = 1;
    buffer_->root = new Node(data_[0]);
    Node* sorting_node = buffer_->root;
    while(num < hmr_data_)
    {
        if(sorting_node->num < data_[num])
        {
            sorting_node->right = new Node(data_[num]);
            num++;
            sorting_node = sorting_node->right;
        }
        if(sorting_node->num > data_[num])
        {
            sorting_node->left = new Node(data_[num]);
            num++;
            sorting_node = sorting_node->left;
        }
        while(sorting_node->root->num > data_[num])
        {
            sorting_node = sorting_node->root;
        }
    }
}
void Tree::Print(Node* printing_node)
{
    if(printing_node->left == NULL && printing_node->right == NULL)
    {
        cout << "if'd" << endl;
        return;
    }
    Print(printing_node->left);
    cout << printing_node->num;
    Print(printing_node->right);
}
Node* Tree::Print_This()
{
    return buffer_->root;
}

int main()
{
    int foo[8] = {17,34,9,16,10,1,74,20};
    Tree bar(foo);
    bar.Print(bar.Print_This());
}
