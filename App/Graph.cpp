#pragma once
#include "Graph.h"


Graph::Graph() {

}

Graph::~Graph() {

}



// Медод который генерирует структуру графа
void Graph::buildGraph() {

    std::vector<int> idList;                                                                                    // вектор который будет содержать id всех узлов
    int radius = 900 / 2 - 15;                                                                                  // Уменьшенный радиус с учётом отступа
    QPoint center(10 + 900 / 2, 10 + 900 / 2);                                                                  // Центр главного круга
    Edge tmp = { 0, 0, 0 };

    srand(static_cast<unsigned>(time(0)));                                                                      //используя рэндомайзер задаются случайные узлы для начала и конце пути
    setStartEdge(rand() % 100); 
    setEndEdge(rand() % 100);
    
    
    while (getVertexListLen() < 100) {                                                                          // Генерация 100 узлов с случайными координатами внутри круга
        int posX = rand() % 900 + 10;
        int posY = rand() % 900 + 10;
        QPoint newCircle(posX, posY);

                                                                                                                
        if (isPointInsideCircle(newCircle, center, radius) and !isOverlappingWithExistingCircles(newCircle)) {  // Проверка: находятся ли координаты узла внутри круга или нет, а так же пересекается ли узел с другим узлом
            addVertex(posX, posY);
        }
    }

    for (int i = 0; i < 100; i++) {                                                                             // добавляет id узлов кроме стартового в вектор 
        if (i != getStartEdge()) {
            idList.push_back(i);
        }
    }

    for (int current = getStartEdge(); idList.size() > 0;) {                                                    // генерирует ребра между узлами начиная от стартового (зеленого) к конечному узлу (красному)
        int index = 0;                                                                                          // взят за основу алгоритм поиска ближайшего соседа
                                                                                                                // каждый узел может быть посещен только раз. После проведения ребра к узлу, он записывается в current
        for (int i = 0; i < idList.size(); i++) {                                                               // и следующее ребро создается между ним и его ближайшим соседом

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

bool Graph::isPointInsideCircle(const QPoint& point, const QPoint& center, int radius) const {              // Проверяет находятся ли координаты внутри главного круга
    int deltaX = point.x() - center.x();
    int deltaY = point.y() - center.y();
    return (deltaX * deltaX + deltaY * deltaY) <= (radius * radius);
}

bool Graph::isOverlappingWithExistingCircles(const QPoint& newCircle) const {                               // Проверяет есть ли пересечения координат узла с другим узлом
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


void Graph::addVertex(int posX, int posY) {                                                             // Добавляет (генерирует) узел с передаными координатами в вектор со всеми узлами
    Vertex vertex = { vertexList.size() , posX, posY };
    vertexList.push_back(vertex);
}

void Graph::addEdge(int first, int second, double weight) {                                             // Добавляет (генерирует) ребро в вектор со всеми рёбрами (старый метод)
    Edge edge = { first, second, weight };
    edgeList.push_back(edge);
}

void Graph::addEdge(Edge edge) {                                                                        // Добавляет (генерирует) ребро в вектор со всеми рёбрами (новый метод с перегружеными параметрами для удобства)
    edgeList.push_back(edge);
}

double Graph::calcDistance(int first, int second) {                                                     // Считает расстояние между двумя узлами и возвращает это расстояние
    Vertex  v1 = vertexList[first];
    Vertex  v2 = vertexList[second];
    return std::sqrt(std::pow(v2.posX - v1.posX, 2) + std::pow(v2.posY - v1.posY, 2));
}


std::vector<Vertex> Graph::getVertexList() const {                                                      // Геттер для доступа к списку Узлов
    return vertexList;
}

std::vector<Edge> Graph::getEdgeList() const {                                                          // Геттер для списка рёбер                                                         
    return edgeList;
}

Edge Graph::getEdge(int id) {                                                                           // Геттер для получения конкретного ребра по id
    return edgeList[id];
}

Vertex Graph::getVertex(int id) {                                                                       // Геттер для получения конкретного узла по id
    return vertexList[id];
}

int Graph::getVertexListLen() {                                                                         // Возвращает длину вектора с узлами
    return vertexList.size();
}

int Graph::getEdgeListLen() {                                                                           // Возвращает длину вектора с рёбрами
    return edgeList.size();
}

int Graph::getStartEdge() const {                                                                       // Геттер для получения номера узла от которого будет проводится маршрут
    return startEdge;
}

int Graph::getEndEdge() const {                                                                         // Геттер для получения номера узла к которому будет проводится маршрут
    return endEdge;
}

void Graph::setStartEdge(int id) {                                                                      // Задает  номер узла от которого будет проводится маршрут
    if (id >= 0 or id < 100) { 
        startEdge = id; 
    }
}

void Graph::setEndEdge(int id) {                                                                        // Задает  номер узла к которому будет проводится маршрут
    if (id >= 0 or id < 100) {
        endEdge = id;
    }
}

bool Graph::isVisitedEdge(int id) {                                                                     // Проверяет список посещенных узлов ( сейчас в проекте не используется)

    for (const int& el : visitedEdgeList) {
        if (el == id) {
            return true;
        }
    }

    return false;
}

int Graph::getVisitedEdgeListLen() {                                                                    // Получает длину вектора с id посещенных узлов
    return visitedEdgeList.size();
}

void Graph::addEdgeToVisited(int id) {                                                                  // Добавляет id посещенного узла
    if (id >= 0 or id < 100) {
        visitedEdgeList.push_back(id);
    }
}