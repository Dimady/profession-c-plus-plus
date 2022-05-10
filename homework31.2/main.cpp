#include <iostream>
#include "igraph.h"
#include "listgraph.h"
#include "matrixgraph.h"

using std::cout;
using std::endl;

int main() {
    ListGraph lst(new ListGraph);
    ListGraph lst1(new MatrixGraph);
    MatrixGraph mtrx(new ListGraph);
    MatrixGraph mtrx1(new MatrixGraph);
    return 0;
}
