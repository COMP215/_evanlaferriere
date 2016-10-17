#ifndef EDGE_H
#define EDGE_H
#include <string>

class Edge
{
    public:
        Edge();
        std::string Edge1_;
        std::string Edge2_;
        int weight = 0;
        Edge(std::string anEdge, std::string edgy);
    private:
};

#endif // EDGE_H
