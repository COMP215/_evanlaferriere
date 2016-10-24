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
void Graph::GenGraph(int numNodes, int edgesEach, int wordWidth)
{
    srand(time(NULL));
    std::string randGen = "1234567890abcdefghijklmnopqrstuvwxyzABCEDFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; i < numNodes; i++)
    {
        std::string word = "";
        for(int j = 0; j < wordWidth; j++)
        {
            do{
            word+=randGen[rand()%62];
            }while(FindVertex(word));
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
            }while(rando==i || FindEdge(*All_Vertices_[i], *All_Vertices_[rando]));
            AddEdge(*All_Vertices_[i], *All_Vertices_[rando], rand());
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
        else
        {
            if(All_Edges_[i].Edge2_ == vertex)
                counter++;
        }
    }
    return counter;
}
void Graph::ToGraphviz()
{
    std::cout << "Please name output file. Do not include the file extension. ";
    std::string outFileName;
    std::cin >> outFileName;
    outFileName += ".dot";
    std::ofstream outFile(outFileName);
    Graph check;
    outFile << "graph g {" << std::endl;
    for(int i = 0; i < All_Vertices_.size(); i++)
    {
        std::string subgraph = "";
        for(int k = 0; k < All_Edges_.size(); k++)
        {
            if(All_Edges_[k].Edge1_ == *All_Vertices_[i] && !check.FindEdge(All_Edges_[k].Edge2_, *All_Vertices_[i]))
            {
                subgraph += *All_Vertices_[i] + " -- " +  All_Edges_[k].Edge2_ + ';' + '\n';
                check.All_Edges_.push_back(All_Edges_[k]);
            }
            else
            {
                if(All_Edges_[k].Edge2_ == *All_Vertices_[i] && !check.FindEdge(All_Edges_[k].Edge1_, *All_Vertices_[i]))
                {
                    subgraph += *All_Vertices_[i] + " -- " + All_Edges_[k].Edge1_ + ';' + '\n';
                    check.All_Edges_.push_back(All_Edges_[k]);
                }
            }
        }
        outFile << subgraph;
    }
    outFile << '}';
}

void Graph::AddEdge(std::string source, std::string target, int weight)
{
    All_Edges_.push_back(Edge(source, target, weight));
}
bool Graph::FindVertex(std::string to_find)
{
    for(int i = 0; i < All_Vertices_.size(); i++)
    {
        if(*All_Vertices_[i] == to_find)
        {
            return true;
        }
    }
    return false;
}
bool Graph::FindEdge(std::string to_find1, std::string to_find2)
{
    for(int i = 0; i < All_Edges_.size(); i++)
    {
        if(All_Edges_[i].Edge1_ == to_find1 && All_Edges_[i].Edge2_ == to_find2)
            return true;
        if(All_Edges_[i].Edge1_ == to_find2 && All_Edges_[i].Edge2_ == to_find1)
            return true;
    }
}
Graph Graph::PrimMST()
{
    Graph Prim;
    Prim.AddVertex(*All_Vertices_[0]);
    std::vector<Edge> CanEdge;
    while(Prim.All_Vertices_.size() < All_Vertices_.size())
    {
        for(int i = 0; i < Prim.All_Vertices_.size(); i++)
        {
            for(int j = 0; j < All_Edges_.size(); j++)
            {
                if(All_Edges_[j].Edge1_ == *Prim.All_Vertices_[i])
                    CanEdge.push_back(All_Edges_[j]);
                if(All_Edges_[j].Edge2_ == *Prim.All_Vertices_[i])
                    CanEdge.push_back(All_Edges_[j]);
            }
        }
        int num = 0;
        for(int i = 0; i < CanEdge.size(); i++)
        {
            if(Prim.FindEdge(CanEdge[i].Edge1_, CanEdge[i].Edge2_))
                CanEdge.erase(CanEdge.begin()+i);
        }
        for(int i = 0; i < CanEdge.size(); i++)
        {
            if(CanEdge[i].weight < CanEdge[num].weight)
                num = i;
        }
        Prim.All_Edges_.push_back(CanEdge[num]);
        for(int i = 0; i < Prim.All_Edges_.size(); i++)
        {
            if(!Prim.FindVertex(Prim.All_Edges_[i].Edge1_))
                Prim.AddVertex(Prim.All_Edges_[i].Edge1_);
            else
            {
                if(!Prim.FindVertex(Prim.All_Edges_[i].Edge2_))
                    Prim.AddVertex(Prim.All_Edges_[i].Edge2_);
            }
        }
    }
    return Prim;
}
Graph Graph::KruskalMST()
{
    Graph Kruskal;
    int min_weight = 0;
    for(int i = 0; i < All_Edges_.size(); i++)
    {
        if(All_Edges_[i].weight < All_Edges_[0].weight)
        {
            Edge swapper = All_Edges_[i];
            All_Edges_.erase(All_Edges_.begin()+i);
            All_Edges_.insert(All_Edges_.begin(), swapper);
        }
    }
    for(int i = 0; i < All_Edges_.size(); i++)
    {
        if( !(Kruskal.All_Vertices_.size() < All_Vertices_.size()))
        {
            break;
        }
        if( !(Kruskal.FindVertex(All_Edges_[i].Edge1_)) && !(Kruskal.FindVertex(All_Edges_[i].Edge2_)) )
        {
            Kruskal.AddEdge(All_Edges_[i].Edge1_, All_Edges_[i].Edge2_);
            Kruskal.AddVertex(All_Edges_[i].Edge1_);
            Kruskal.AddVertex(All_Edges_[i].Edge2_);
        }
        if(Kruskal.FindVertex(All_Edges_[i].Edge1_)!= Kruskal.FindVertex(All_Edges_[i].Edge2_))
        {
            if(Kruskal.FindVertex(All_Edges_[i].Edge1_))
            {
                Kruskal.AddVertex(All_Edges_[i].Edge2_);
            }
            if(Kruskal.FindVertex(All_Edges_[i].Edge2_))
            {
                Kruskal.AddVertex(All_Edges_[i].Edge1_);
            }
            Kruskal.AddEdge(All_Edges_[i].Edge1_, All_Edges_[i].Edge2_);
        }
    }
    return Kruskal;
}

