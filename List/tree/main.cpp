#include <iostream>


using namespace std;
class Node
{
    public:
        int num_ = NULL;
        Node* left_ = NULL;
        Node* right_ = NULL;
        Node* root_ = NULL;
        Node(int data);
        Node(Node* left, Node* right);
        Node(int num, Node* left, Node* right);
};
Node::Node(int data)
{
    num_ = data;
}
Node::Node(Node* left, Node* right)
{
    this->left_ = left;
    this->right_ = right;
}
Node::Node(int num, Node* left, Node* right)
{
    this->num_ = num;
    this->left_ = left;
    this->right_ = right;
}
class Tree
{
    public:
        int hmr_data_ = 0;
        int total_ = 0;
        int* data_ = NULL;
        Node* buffer_ = new Node(32767);
        Tree(int passed_data[], int total);
        void Add(Node* sorting_node);
        void Print(Node* printing_node);
};
Tree::Tree(int* passed_data, int total)
{
    total_ = total;
    data_= passed_data;
    hmr_data_ = 0;
    buffer_->root_ = new Node(data_[hmr_data_]);
    buffer_->root_->root_ = buffer_;
    hmr_data_++;
    this->Add(buffer_->root_);
    this->Print(buffer_->root_);
}
void Tree::Print(Node* printing_node)
{
    if(printing_node->left_ != NULL)
        Print(printing_node->left_);
    cout << printing_node->num_ << ' ';
    if(printing_node->right_ != NULL)
        Print(printing_node->right_);
    return;
}
void Tree::Add(Node* sorting_node)
{
    if(hmr_data_ < total_)
    {
        if(sorting_node->num_ == NULL)
        {
            sorting_node->num_ = data_[hmr_data_];
            hmr_data_++;
            Add(sorting_node);
            return;
        }
        if(sorting_node->root_->num_ <= data_[hmr_data_])
        {
            Add(sorting_node->root_);
            return;
        }
        if(sorting_node->num_ < data_[hmr_data_])
        {
            sorting_node->right_ = new Node(NULL);
            sorting_node->right_->root_ = sorting_node;
            Add(sorting_node->right_);
            return;
        }
        if(sorting_node->num_ > data_[hmr_data_])
        {
            sorting_node->left_ = new Node(NULL);
            sorting_node->left_->root_ = sorting_node;
            Add(sorting_node->left_);
            return;
        }
    }
    return;
}
int main()
{
    int foo[8] = {17,34,9,16,10,1,74,20};
    Tree bar(foo, 8);
    return 0;
}
