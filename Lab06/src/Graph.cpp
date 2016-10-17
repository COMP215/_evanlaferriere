#include "Graph.h"
#include "Edge.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <random>
Graph::Graph()
{
    //ctor
    vector<Edge> All_Edges_ = {};
    vector<string*> All_Vertices_ = {};
}
void Graph::AddEdge(std::string anEdge, std::string edgy)
{
    All_Edges_.push_back(new Edge(anEdge, edgy));
}

void Graph::RemoveEdge(std::string anEdge, std::string edgy)
{
    for(int i = 0; i < All_Edges_.size(); i++)
    {
        if(All_Edges_[i].Edge1_==anEdge)
        {
            if(All_Edges_[i].Edge2_==edgy)
            {
                All_Edges_.erase(All_Edges_.begin()+i);
                return;
            }
        }
        if(All_Edges_[i].Edge1_==edgy)
        {
            if(All_Edges_[i].Edge2_=anEdge)
            {
                All_Edges_.erase(All_Edges_.begin+i);
                return;
            }
        }

    }
}

void Graph::AddVertex(std::string to_add)
{
    All_Vertices_.push_back(to_add);
}

void Graph::RemoveVertex(std::string to_remove)
{
    for(int i = 0; i < All_Vertices_.size(); i++)
    {
        if(All_Vertices_[i] == to_remove)
        {
            All_Vertices_.erase(All_Vertices_.begin()+i);
        }
    }
}
void Graph::GenNodes(int numNodes, int edgesEach, int wordWidth)
{
    srand(time(NULL));
    string randGen = "1234567890abcdefghijklmnopqrstuvwxyzABCEDFGHIJKLMNOPQRSTUVWXYZ"
    for(int i = 0; i < numNodes; i++)
    {
        string word = "";
        for(int j = 0; j < wordWidth; j++)
        {
            word+=randGen[rand()%62];
        }
        All_Vertices_.push_back(new string(word));
    }
    for(int i = 0; i < numNodes; i++)
    {
        for(int j = numEdges(All_Vertices_[i]); j < edgesEach; j++)
        {

        }
    }
}
int Graph::numEdges(string vertex)
{
    for(int i = 0; i < All_Vertices_.size(); i++)
    {

    }
}
