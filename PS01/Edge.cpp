#include "Edge.h"
#include <string>
Edge::Edge()
{
    Edge1_ = std::string("");
    Edge2_ = std::string("");
    weight = 0;
}
Edge::Edge(std::string anEdge, std::string edgy)
{
    Edge1_ = anEdge;
    Edge2_ = edgy;
}
Edge::Edge(std::string anEdge, std::string edgy, int weight)
{
    Edge1_ = anEdge;
    Edge2_ = edgy;
}


