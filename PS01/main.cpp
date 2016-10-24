#include <iostream>
#include <vector>
#include "graph.h"
using namespace std;

int main()
{
    Graph Foo;
    Foo.GenGraph(5,2,1);
    Foo.ToGraphviz();
    Graph FooKruskal = Foo.KruskalMST();
    FooKruskal.ToGraphviz();
    //FooPrim.ToGraphviz();
    return 0;
}
