#include "graph.h"
#include "Edge.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <random>
#include <fstream>
Graph::Graph()
{
    All_Edges_ = {};
    All_Vertices_ = {};
}
void Graph::AddEdge(std::string anEdge, std::string edgy)
{
    All_Edges_.push_back(Edge(anEdge, edgy));
}

void Graph::RemoveEdge(std::string anEdge, std::string edgy)
{
    for(int i = 0; i < All_Edges_.size(); i++)
    {
        if(All_Edges_[i].Edge1_ == anEdge)
        {
            if(All_Edges_[i].Edge2_ == edgy)
            {
                All_Edges_.erase(All_Edges_.begin()+i);
                return;
            }
        }
        if(All_Edges_[i].Edge1_ == edgy)
        {
            if(All_Edges_[i].Edge2_ == anEdge)
            {
                All_Edges_.erase(All_Edges_.begin()+i);
                return;
            }
        }

    }
}

void Graph::AddVertex(std::string to_add)
{
    All_Vertices_.push_back(&to_add);
}

void Graph::RemoveVertex(std::string to_remove)
{
    for(int i = 0; i < All_Vertices_.size(); i++)
    {
        if(!All_Vertices_[i]->compare(to_remove))
        {
            All_Vertices_.erase(All_Vertices_.begin()+i);
        }
    }
}
void Graph::GenNodes(int numNodes, int edgesEach, int wordWidth)
{
    srand(time(NULL));
    std::string randGen = "1234567890abcdefghijklmnopqrstuvwxyzABCEDFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; i < numNodes; i++)
    {
        std::string word = "";
        for(int j = 0; j < wordWidth; j++)
        {
            word+=randGen[rand()%62];
        }
        All_Vertices_.push_back(new std::string(word));
    }
    int rando;
    for(int i = 0; i < numNodes; i++)
    {
        for(int j = numEdges(*All_Vertices_[i]); j < edgesEach; j++)
        {
            do{
                rando = rand()%All_Vertices_.size();
            }while(rando==i);
            AddEdge(*All_Vertices_[i], *All_Vertices_[rando]);
        }
    }
}
int Graph::numEdges(std::string vertex)
{
    int counter = 0;
    for(int i = 0; i < All_Edges_.size(); i++)
    {
        if(All_Edges_[i].Edge1_ == vertex)
            counter++;
        if(All_Edges_[i].Edge2_ == vertex)
            counter++;
    }
    return counter;
}
void Graph::ToGraphviz()
{
    std::cout << "Please name output file. Do not include extension." << std::endl;
    std::string outFileName;
    std::cin >> outFileName;
    outFileName += ".dot";
    std::ofstream outFile(outFileName);
    for(int i = 0; i < All_Vertices_.size(); i++)
    {
        outFile << *All_Vertices_[i] << " ";
        if(numEdges(*All_Vertices_[i])>0)
        {
            std::string subgraph = "-- {";
            for(int j = 0; j < numEdges(*All_Vertices_[i]); j++)
            {
                for(int k = 0; k < All_Edges_.size(); k++)
                {
                    if(All_Edges_[k].Edge1_==*All_Vertices_[i])
                    {
                        subgraph += " " + All_Edges_[k].Edge1_;
                    }
                    else
                    {
                        if(All_Edges_[k].Edge2_==*All_Vertices_[i])
                        {
                        subgraph += " " + All_Edges_[k].Edge2_;
                        }
                    }
                }
            }
            subgraph += '}';
            outFile << subgraph;
        }
        outFile << std::endl;
    }
}
void Graph::AddEdge(std::string source, std::string target, int weight)
{
    All_Edges_.push_back(Edge(source, target));
    All_Edges_[All_Edges_.size()-1].weight = weight;
}
