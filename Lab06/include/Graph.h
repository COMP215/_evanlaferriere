#ifndef GRAPH_H
#define GRAPH_H
#include "Edge.h"
#include <vector>
#include <string>
class Graph
{
    public:
        Graph();
        void AddVertex(std::string to_add);
        void RemoveVertex(std::string to_remove);
        void AddEdge(std::string anEdge, std::string edgy);
        void RemoveEdge(std::string anEdge, std::string edgy);
        void GenNodes(int numNodes, int edgesEach, int wordWidth);
        int numEdges(string vertex);
        std::string ToGraphViz();
    private:
        std::vector<Edge> All_Edges_;
        std::vector<std::string*> All_Vertices_;
};

#endif // GRAPH_H
