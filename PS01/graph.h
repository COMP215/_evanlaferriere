#ifndef GRAPH_H
#define GRAPH_H
#include "Edge.h"
#include <string>
#include <vector>
class Graph
{
    public:
    Graph();
    void AddEdge(std::string anEdge, std::string edgy); //Add edges to graph between the two vertexes 'anEdge' and 'edgy'
    void RemoveEdge(std::string anEdge, std::string edgy); //Remove an edge between two vertexes
    void AddVertex(std::string to_add); //Adds vertex 'to_add' to the graph
    void RemoveVertex(std::string to_remove); //Removes vertex 'to_remove' from the graph
    void ToGraphviz();
    void AddEdge(std::string source, std::string target, int weight);
    Graph PrimMST();
    Graph KruskalMST();

    bool FindVertex(std::string to_find);
    bool FindEdge(std::string to_find1, std::string to_find2);
    void GenGraph(int numNodes, int edgesEach, int wordWidth); //Generates a new graph
    int numEdges(std::string vertex); //Returns number of edges that vertex "string" has
    private:
        std::vector<Edge> All_Edges_ = {};
        std::vector<std::string*> All_Vertices_ = {};
};
#endif
