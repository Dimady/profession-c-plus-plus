#pragma once
#include <string>
#include "igraph.h"
#include "listgraph.h"

class MatrixGraph : public IGraph {
private:
    std::string type = "Matrix";
    std::vector<std::vector<int>> grph;

public:
    MatrixGraph();

    MatrixGraph(IGraph *_oth);

    virtual ~MatrixGraph();

    std::string getType();

    void AddEdge(int from, int to); // Метод принимает вершины начала и конца ребра и добавляет ребро

    int VerticesCount() const; // Метод должен считать текущее количество вершин

    void GetNextVertices(int vertex, std::vector<int> &vertices) const; // Для конкретной вершины метод выводит в вектор “вершины”
                                                                                    // все вершины, в которые можно дойти по ребру из данной

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const; // Для конкретной вершины метод выводит в вектор “вершины”
                                                                                    // все вершины, из которых можно дойти по ребру в данную

};