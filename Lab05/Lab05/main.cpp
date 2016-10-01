#include <iostream>
#include <vector>
#include "graph.h"
using namespace std;

int main()
{
    Graph Foo;
    Foo.GenNodes(4,2,1);
    Foo.Printer();
    return 0;
}
