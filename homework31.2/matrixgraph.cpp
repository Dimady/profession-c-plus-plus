#include <iostream>
#include "matrixgraph.h"

MatrixGraph::MatrixGraph(){}

MatrixGraph::MatrixGraph(IGraph *_oth) {
    if (_oth->getType() == "Matrix") {
        std::cout << "Matrix in Matrix" <<std::endl;
    } else if(_oth->getType() == "List") {
        std::cout << "List in Matrix" <<std::endl;
    }
}

MatrixGraph::~MatrixGraph() {}

std::string MatrixGraph::getType() {return type;}

void MatrixGraph::AddEdge(int from, int to) {}

int MatrixGraph::VerticesCount() const {return 0;}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {}
