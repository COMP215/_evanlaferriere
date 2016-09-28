#include "graph.h"
#include <iostream>
#include <vector>
#include <random>
using namespace std;
void Graph::Add(Node to_add)
{
    this->All_Nodes_.push_back(&to_add);
}
void Graph::Add(Node to_add, vector<Node*> edges)
{
    this->All_Nodes_.push_back(&to_add);
    for(int i = 0; i < edges.size(); i++)
    {
        All_Nodes_[All_Nodes_.size()-1]->Add(edges[i]);
    }
}
void Graph::AddVertex(string name, vector<Node*> edges)
{
    bool found = false;
    int counter = 0;
    for(;counter < All_Nodes_.size(); counter++)
    {
        if(All_Nodes_[counter]->name_ == name)
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        for(int i = 0; i < edges.size(); i++)
        {
            All_Nodes_[counter]->Add(edges[i]);
        }
    }
    if(!found)
    {
        std::cout << "Bad add" << endl;
    }
}
void Graph::Printer()
{
    for(int i = 0; i < All_Nodes_.size(); i++)
    {
        All_Nodes_[i]->PrintAdjList();
    }
}
bool Graph::Find(string name)
{
    bool found = false;
    for(int i = 0; i < All_Nodes_.size(); i++)
    {
        if(All_Nodes_[i]->name_ == name)
        {
            found = true;
            break;
        }
    }
    return found;
}
void Graph::GenNodes(int numNodes, int edgesEach, int wordWidth)
{
    if(edgesEach > (numNodes(numNodes-1) / 2))
    {
        std::cout << "Bad gen" << endl;
        return;
    }
    srand (time(NULL));
    const string randGen = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrtuvwxyz";
    for(int i = 0; i < numNodes; i++)
    {
        string word = "";
        for(int j=0; j < wordWidth; j++)
        {
            int t = rand();
            word = word + (randGen[t%randGen.length()]);
        }
        while(this->Find(word))
        {
            for(int j=0; j < wordWidth; j++)
            {
                int t = rand();
                word = word + (randGen[t%randGen.length()]);
            }
        }
        All_Nodes_.push_back(new Node(word));
    }
    for(int i = 0; i < All_Nodes_.size();i++)
    {
        for(int j = 0; j < edgesEach; j++)
        {
            All_Nodes_[i]->Add()
        }
    }
}
