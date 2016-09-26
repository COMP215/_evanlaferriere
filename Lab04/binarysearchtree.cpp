//
//  binarysearchtree.cpp
//  demo
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//

#include "binarysearchtree.hpp"
#include <iostream>
#include <string>
using namespace std;

BSTNode::BSTNode(string data) {
    data_ = data;
    left_ = NULL;
    right_ = NULL;
}

BinarySearchTree::BinarySearchTree() {
    root_ = NULL;
}

bool BinarySearchTree::Insert(string data) {
    if (root_ == NULL) {
        // Empty tree, make a root
        root_ = new BSTNode(data);
        return true;
    } else {
        // Non-empty tree, find correct position for data
        BSTNode* curr = root_;
        while (curr != NULL) {
            if (data == curr->data_) {
                // Data already in tree, fail to insert
                return false;
            } else if (data < curr->data_) {
                // Lexicographically lesser, find location to the left
                if (curr->left_ == NULL) {
                    curr->left_ = new BSTNode(data);
                    return true;
                } else {
                    curr = curr->left_;
                }
            } else {
                // Lexicographically greater, find location to the right
                if (curr->right_ == NULL) {
                    curr->right_ = new BSTNode(data);
                    return true;
                } else {
                    curr = curr->right_;
                }
            }
        }
    }
    return false;
}
bool BinarySearchTree::Search(string data)
{
    BSTNode* sorting_node = root_;
    while(sorting_node->data_!=data)
    {
        if(sorting_node->data_ > data)
        {
            sorting_node = sorting_node->left_;
            if(sorting_node == NULL)
                return "Not found BST";
        }
        else
        {
            if(sorting_node->data_ < data)
            {
                sorting_node = sorting_node->right_;
                if(sorting_node == NULL)
                    return "Not found BST";
            }
        }
    }
    return sorting_node->data_;
}
bool BinarySearchTree::Delete(string data)
{
    BSTNode* sorting_node = root_;
    while(sorting_node->data_!=data)
    {
        if(sorting_node->data_ > data)
        {
            sorting_node = sorting_node->left_;
            if(sorting_node == NULL)
                return false;
        }
        else
        {
            if(sorting_node->data_ < data)
            {
                sorting_node = sorting_node->right_;
                if(sorting_node == NULL)
                    return false;
            }
        }
    }
    if (sorting_node->data_ == data)
    {

        return true;
    }
    return false;
}
void BinarySearchTree::InOrder()
{
    if(root_ != NULL)
       InOrder(root_);
}
void BinarySearchTree::InOrder(BSTNode* node)
{
    if(node->left_ != NULL)
    {
        InOrder(node->left_);
    }
    cout << node->data_ << endl;
    if(node->right_ != NULL)
    {
        InOrder(node->right_);
    }
}

