#ifndef EDGE_H
#define EDGE_H
#include <string>

class Edge
{
    public:
        Edge();
        std::string Edge1_;
        std::string Edge2_;
        int weight;
        Edge(std::string anEdge, std::string edgy);
        Edge(std::string anEdge, std::string edgy, int weight);
    private:
};

#endif // EDGE_H
