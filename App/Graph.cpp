#pragma once
#include "Graph.h"


Graph::Graph() {

}

Graph::~Graph() {

}



// ����� ������� ���������� ��������� �����
void Graph::buildGraph() {

    std::vector<int> idList;                                                                                    // ������ ������� ����� ��������� id ���� �����
    int radius = 900 / 2 - 15;                                                                                  // ����������� ������ � ������ �������
    QPoint center(10 + 900 / 2, 10 + 900 / 2);                                                                  // ����� �������� �����
    Edge tmp = { 0, 0, 0 };

    srand(static_cast<unsigned>(time(0)));                                                                      //��������� ����������� �������� ��������� ���� ��� ������ � ����� ����
    setStartEdge(rand() % 100); 
    setEndEdge(rand() % 100);
    
    
    while (getVertexListLen() < 100) {                                                                          // ��������� 100 ����� � ���������� ������������ ������ �����
        int posX = rand() % 900 + 10;
        int posY = rand() % 900 + 10;
        QPoint newCircle(posX, posY);

                                                                                                                
        if (isPointInsideCircle(newCircle, center, radius) and !isOverlappingWithExistingCircles(newCircle)) {  // ��������: ��������� �� ���������� ���� ������ ����� ��� ���, � ��� �� ������������ �� ���� � ������ �����
            addVertex(posX, posY);
        }
    }

    for (int i = 0; i < 100; i++) {                                                                             // ��������� id ����� ����� ���������� � ������ 
        if (i != getStartEdge()) {
            idList.push_back(i);
        }
    }

    for (int current = getStartEdge(); idList.size() > 0;) {                                                    // ���������� ����� ����� ������ ������� �� ���������� (��������) � ��������� ���� (��������)
        int index = 0;                                                                                          // ���� �� ������ �������� ������ ���������� ������
                                                                                                                // ������ ���� ����� ���� ������� ������ ���. ����� ���������� ����� � ����, �� ������������ � current
        for (int i = 0; i < idList.size(); i++) {                                                               // � ��������� ����� ��������� ����� ��� � ��� ��������� �������

            if (idList.size() > 1 and idList[i] == getEndEdge()) {
                continue;
            }

            Edge check = {};
            check.first = current;
            check.second = idList[i];
            check.weight = calcDistance(current, idList[i]);

            if (tmp.weight == 0 or tmp.weight > check.weight) {
                tmp = check;
                index = i;
            }
        }

        idList.erase(idList.begin() + index);

        addEdge(tmp);

        current = tmp.second;
        tmp = {0, 0, 0};
    }

}

bool Graph::isPointInsideCircle(const QPoint& point, const QPoint& center, int radius) const {              // ��������� ��������� �� ���������� ������ �������� �����
    int deltaX = point.x() - center.x();
    int deltaY = point.y() - center.y();
    return (deltaX * deltaX + deltaY * deltaY) <= (radius * radius);
}

bool Graph::isOverlappingWithExistingCircles(const QPoint& newCircle) const {                               // ��������� ���� �� ����������� ��������� ���� � ������ �����
    int requiredDistance = 25;

    for (const auto& existingCircle : getVertexList()) {
        int deltaX = newCircle.x() - existingCircle.posX;
        int deltaY = newCircle.y() - existingCircle.posY;
        int distanceSquared = deltaX * deltaX + deltaY * deltaY;

        if (distanceSquared < (requiredDistance * requiredDistance)) {
            return true;
        }
    }

    return false;
}


void Graph::addVertex(int posX, int posY) {                                                             // ��������� (����������) ���� � ���������� ������������ � ������ �� ����� ������
    Vertex vertex = { vertexList.size() , posX, posY };
    vertexList.push_back(vertex);
}

void Graph::addEdge(int first, int second, double weight) {                                             // ��������� (����������) ����� � ������ �� ����� ������ (������ �����)
    Edge edge = { first, second, weight };
    edgeList.push_back(edge);
}

void Graph::addEdge(Edge edge) {                                                                        // ��������� (����������) ����� � ������ �� ����� ������ (����� ����� � ������������� ����������� ��� ��������)
    edgeList.push_back(edge);
}

double Graph::calcDistance(int first, int second) {                                                     // ������� ���������� ����� ����� ������ � ���������� ��� ����������
    Vertex  v1 = vertexList[first];
    Vertex  v2 = vertexList[second];
    return std::sqrt(std::pow(v2.posX - v1.posX, 2) + std::pow(v2.posY - v1.posY, 2));
}


std::vector<Vertex> Graph::getVertexList() const {                                                      // ������ ��� ������� � ������ �����
    return vertexList;
}

std::vector<Edge> Graph::getEdgeList() const {                                                          // ������ ��� ������ ����                                                         
    return edgeList;
}

Edge Graph::getEdge(int id) {                                                                           // ������ ��� ��������� ����������� ����� �� id
    return edgeList[id];
}

Vertex Graph::getVertex(int id) {                                                                       // ������ ��� ��������� ����������� ���� �� id
    return vertexList[id];
}

int Graph::getVertexListLen() {                                                                         // ���������� ����� ������� � ������
    return vertexList.size();
}

int Graph::getEdgeListLen() {                                                                           // ���������� ����� ������� � ������
    return edgeList.size();
}

int Graph::getStartEdge() const {                                                                       // ������ ��� ��������� ������ ���� �� �������� ����� ���������� �������
    return startEdge;
}

int Graph::getEndEdge() const {                                                                         // ������ ��� ��������� ������ ���� � �������� ����� ���������� �������
    return endEdge;
}

void Graph::setStartEdge(int id) {                                                                      // ������  ����� ���� �� �������� ����� ���������� �������
    if (id >= 0 or id < 100) { 
        startEdge = id; 
    }
}

void Graph::setEndEdge(int id) {                                                                        // ������  ����� ���� � �������� ����� ���������� �������
    if (id >= 0 or id < 100) {
        endEdge = id;
    }
}

bool Graph::isVisitedEdge(int id) {                                                                     // ��������� ������ ���������� ����� ( ������ � ������� �� ������������)

    for (const int& el : visitedEdgeList) {
        if (el == id) {
            return true;
        }
    }

    return false;
}

int Graph::getVisitedEdgeListLen() {                                                                    // �������� ����� ������� � id ���������� �����
    return visitedEdgeList.size();
}

void Graph::addEdgeToVisited(int id) {                                                                  // ��������� id ����������� ����
    if (id >= 0 or id < 100) {
        visitedEdgeList.push_back(id);
    }
}