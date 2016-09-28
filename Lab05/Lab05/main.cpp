#include <iostream>
#include <vector>
#include "graph.h"
using namespace std;

int main()
{
    Graph Foo;
    Node A ("Mike");
    Foo.Add(A);
    Node B ("Evan");
    vector<Node*> C;
    C.push_back(&B);
    Foo.AddVertex("Mike", C);
    C.pop_back();
    C.push_back(&A);
    Foo.Add(B);
    Foo.AddVertex("Evan", C);
    Foo.Printer();
    return 0;
}
