//
//  binarysearchtree.hpp
//  demo
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//

#ifndef binarysearchtree_hpp
#define binarysearchtree_hpp

#include <stdio.h>
#include <string>

class BSTNode {
public:
    std::string data_;
    BSTNode* left_;
    BSTNode* right_;

public:
   BSTNode(std::string);
};


class BinarySearchTree {
    BSTNode* root_;

public:
    BinarySearchTree();
    bool Insert(std::string);
    bool Search(std::string);
    bool Delete(std::string);
};

#endif /* binarysearchtree_hpp */
