#include "graph.h"
#include <iostream>
#include <vector>
#include <random>
#include <time.h>
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
bool Graph::IsBipartite()
{
    return true;
}
void Graph::GenNodes(int numNodes, int edgesEach, int wordWidth)
{
    if(edgesEach > (numNodes*(numNodes-1) / 2))
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
        int j = All_Nodes_[i]->edges_.size();
        //cout << "Node " << All_Nodes_[i]->name_ << " has " << j << "edges rn."<< endl;
        for(; j < edgesEach; j++)
        {
            //All_Nodes_[i]->Add(All_Nodes_[rand()%All_Nodes_.size()]); adds just three random nodes
            Node* to_add = All_Nodes_[i];
            do{
                to_add = All_Nodes_[rand()%All_Nodes_.size()];
            }while(to_add->edges_.size() >= edgesEach);
            if (to_add == All_Nodes_[i])
                break;
            to_add->Add(All_Nodes_[i]);
            //cout << "Added " << to_add->name_ << endl;
            All_Nodes_[i]->Add(to_add);
        }

    }
}
