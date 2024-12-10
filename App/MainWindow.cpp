#include "MainWindow.h"
#include <QPainter>
#include <QPaintEvent>



MainWindow::MainWindow(QWidget *parent)  : QMainWindow(parent) {
    ui.setupUi(this);
    this->setMinimumSize(920, 920);
    graph.buildGraph();
}

MainWindow::~MainWindow() {}

void MainWindow::paintEvent(QPaintEvent* event) {                                                   // Изменение поведения обработчика события
    QColor brushColor = Qt::blue;
    QPainter painter(this);
    painter.setBrush(Qt::blue);
    painter.drawEllipse(10, 10, 900, 900);

    painter.setPen(QPen(Qt::green, 1));                                                             // Отрисовывает рёбра между узлами
    for (const auto& edge: graph.getEdgeList()) {
        Vertex first = graph.getVertex(edge.first);
        Vertex second = graph.getVertex(edge.second);
        painter.drawLine(first.posX + 5, first.posY + 5, second.posX + 5, second.posY + 5);
    }


    painter.setPen(QPen(Qt::black, 1));
    for (const auto& pos : graph.getVertexList()) {                                                 // Отрисовывает узлы
        brushColor = Qt::blue;

        if(pos.id == graph.getStartEdge()) {
            brushColor = Qt::yellow;
        }

        if (pos.id == graph.getEndEdge()) {
            brushColor = Qt::red;
        }

        painter.setBrush(brushColor);
        painter.drawEllipse(pos.posX, pos.posY, 10, 10);
    }
}
