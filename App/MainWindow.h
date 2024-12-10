#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_App.h"
#include "Graph.h"

class MainWindow : public QMainWindow {                                         // Создание расширеного класса MainWindow наследованного от QMainWindow
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    protected:
        void paintEvent(QPaintEvent* event) override;                           // Делаем метод PaintEvent переопределяемым

    private:
        Ui::AppClass ui;
        Graph graph;                                                            // Добавляем в область видимости наш граф
};
