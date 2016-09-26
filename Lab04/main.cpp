//
//  main.cpp
//  classbst
//
//  Created by Tom Armstrong on 9/19/16.
//  Copyright © 2016 tarmstro. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "binarysearchtree.hpp"
#include "LinkedList.h"

using namespace std;

int main(int argc, const char * argv[]) {

    BinarySearchTree* words = new BinarySearchTree();
    LinkedList more_words;
    ifstream in_file("foowords.txt");
    string cargo = "";
    while(getline(in_file, cargo))
    {
        //cout << words->Insert(cargo) << endl;
        more_words.Insert(cargo);
    }
    ifstream search_file("words.txt");
    while(getline(search_file, cargo))
    {
        cout << words->Search(cargo) << endl;
        cout << more_words.Search(cargo);
    }

    return 0;
}
