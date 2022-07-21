#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "cell.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_astar_clicked();

    void on_btn_dijkstra_clicked();



private:
    Ui::MainWindow *ui;

    QGraphicsScene scene;

    Cell* cells[8][10];

    void create_map();
    void delete_map();

    int heuristic(Cell* cell);
    void start_finish_line();

    void a_star();
    void Dijkstra();

    Cell* to_start;
    Cell* to_finish;
};
#endif // MAINWINDOW_H
