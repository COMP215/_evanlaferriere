#include <iostream>
#include <vector>
#include "graph.h"
using namespace std;

int main()
{
    Graph Foo;
    Foo.GenNodes(8,3,1);
    Foo.Printer();
    cout << "IsBipartite: " << Foo.IsBipartite();
    return 0;
}
