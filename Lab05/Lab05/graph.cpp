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
    cout << endl;
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
    bool inVar1 = false;
    bool inVar2 = false;
    int counter = 1;
    if(All_Nodes_.size() > 1)
    {
        vector<Node*> var1 = All_Nodes_[0]->edges_;
        vector<Node*> var2;
        for(; counter < All_Nodes_.size(); counter++)
        {
            for(int i = 0; i < var1.size(); i++)
            {
                if(All_Nodes_[counter]= var1[i])
                {
                    inVar1 = true;
                }
            }
            if(inVar1)
            {
                vector<Node*> var2 = All_Nodes_[counter]->edges_;
                break;
            }
        }
        if(var2.size() == 0)
        {
            return false;
        }
        for(int i = 1; i < All_Nodes_.size(); i++)
        {
            for(int j = 0; j < var1.size(); j++)
            {
                if(All_Nodes_[i]==var1[j])
                    inVar1 = true;
            }
            for(int j = 0; j < var2.size(); j++)
            {
                if(All_Nodes_[i]==var2[j])
                    inVar2 = true;
            }
            if(inVar1&&inVar2)
                return false;
        }
        return true;
    }
    return false;
}
void Graph::GenNodes(int numNodes, int edgesEach, int wordWidth)
{
    All_Nodes_.clear();
    if(edgesEach > (numNodes*(numNodes-1) / 2))
    {
        std::cout << "Bad data" << endl;
        return;
    }
    string randGen = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrtuvwxyz";
    srand (time(NULL));
    for(int i = 0; i < numNodes; i++)
    {
        string word = "";
        do{
            for(int j=0; j < wordWidth; j++)
            {
                int k = rand();
                word = word + randGen[k%randGen.length()];
            }
        }while(this->Find(word));
        All_Nodes_.push_back(new Node(word));
        //cout << "Made new node " << All_Nodes_.back()->name_ << endl;
    }
    int shuffleNodes[All_Nodes_.size()];
    for(int i = 0; i < All_Nodes_.size(); i++)
    {
        shuffleNodes[i] = rand()%All_Nodes_.size();
    }
    for(int i = 0; i < All_Nodes_.size(); i++)//For each node
    {
        //cout << endl << "Adding to " << All_Nodes_[i]->name_;
        for(int j = 0; j < All_Nodes_.size(); j++)//While the node doesn't have enough edges
        {
            //Get a random node
            //cout << " trying " << All_Nodes_[shuffleNodes[j]]->name_ << ' ';
            if(shuffleNodes[j] != i)//If it is not the same node
            {
                if(All_Nodes_[shuffleNodes[j]]->edges_.size() < edgesEach)
                {           //If it does not have enough sides either
                    bool check = true;
                    for(int k = 0; k < All_Nodes_[i]->edges_.size(); k++)
                    {
                        //For all the edges in the original node, if any of them are j, don't add them.
                        if(All_Nodes_[i]->edges_[k] == All_Nodes_[shuffleNodes[j]])
                            check = false;
                    }
                    if(check)
                    {
                        All_Nodes_[i]->Add(All_Nodes_[shuffleNodes[j]]);
                        //cout << " success." << endl;
                    }
                }
            }
        }
    }
    for(int i = 0; i < All_Nodes_.size(); i++)
    {
        if(All_Nodes_[i]->edges_.size() != edgesEach)
        {
            GenNodes(numNodes, edgesEach, wordWidth);
        }

    }
}
