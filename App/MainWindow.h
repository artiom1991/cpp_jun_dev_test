#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_App.h"
#include "Graph.h"

class MainWindow : public QMainWindow {                                         // �������� ����������� ������ MainWindow �������������� �� QMainWindow
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    protected:
        void paintEvent(QPaintEvent* event) override;                           // ������ ����� PaintEvent ����������������

    private:
        Ui::AppClass ui;
        Graph graph;                                                            // ��������� � ������� ��������� ��� ����
};
