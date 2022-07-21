#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include <QTime>
#include <fstream>
#include "cell.h"
#include <set>

using namespace std;




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setBackgroundBrush(QColor(255, 255, 255));

    scene.setSceneRect(0, 0, 800, 640);

    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    ui->graphicsView->setScene(&scene);

    create_map();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete_map();
}

void MainWindow::delete_map()
{
    int i, j;
    for (i = 0; i < 8; i++)
        for (j = 0; j < 10; j++)
        {
            if (cells[i][j])
                delete cells[i][j];
            cells[i][j] = nullptr;
        }
}

inline void delay(int sec)
{
    QEventLoop loop;
    QTimer t;
    t.connect(&t, &QTimer::timeout, &loop, &QEventLoop::quit);
    t.start(sec);
    loop.exec();
}

void MainWindow::create_map()
{
    std::ifstream map_file("D:\\Qt\\Projects\\lab3sem\\map.txt");
    char c;

    if (!map_file.is_open())
    {
        qDebug() << "Ошибка открытия файла!";
    }

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 10; j++)
        {
            c = map_file.get();

            while(c == '\n')
            {
                c = map_file.get();
            }

            cells[i][j] = new Cell(j, i, c);

            if (c == 'S')
                to_start = cells[i][j];
            else if (c == 'F')
                to_finish = cells[i][j];

            scene.addItem(cells[i][j]);
        }
}

int MainWindow::heuristic(Cell* cell)
{
    return (abs(cell->get_x() - to_finish->get_x()) + abs(cell->get_y() - to_finish->get_y()))*10;
}

bool compare(Cell* cell1, Cell* cell2)
{
    return cell1->get_weight() < cell2->get_weight();
}


void MainWindow::a_star()
{
    multiset<Cell*, decltype (compare)*> cells_set(compare);

    Cell* current_cell = to_start;

    while (current_cell != to_finish)
    {
        current_cell->block();
        if (!cells_set.empty())
            cells_set.erase(cells_set.begin());
        current_cell->set_color(QColor(255, 0, 0));
        current_cell->update();

        for (int i = current_cell->get_y() - 1; i <= current_cell->get_y() + 1; i++)
        {
            for(int j = current_cell->get_x() - 1; j <= current_cell->get_x() + 1; j++)
            {
                if ((i >= 0) && (j >= 0) && (i < 8) && (j < 10))
                {
                    if (!cells[i][j]->is_blocked())
                    {
                        delay(200);
                        if ((i == current_cell->get_y()) || (j == current_cell->get_x()))
                        {
                            if (!(cells[i][j]->is_visited() && (current_cell->get_len_to_start() + cells[i][j]->get_distance() > cells[i][j]->get_len_to_start())))
                            {
                                cells[i][j]->set_len_to_start(current_cell->get_len_to_start() + cells[i][j]->get_distance());

                                if (cells[i][j]->is_visited())
                                    cells_set.erase(cells[i][j]);

                                cells[i][j]->visit();
                                cells[i][j]->set_heur_approx(heuristic(cells[i][j]));
                                cells[i][j]->count_weight();
                                cells[i][j]->set_parent(current_cell);
                                cells[i][j]->check();
                                cells_set.insert(cells[i][j]);
                                cells[i][j]->update();
                            }

                        }
                        else
                        {
                            if (!(cells[i][j]->is_visited()) && (current_cell->get_len_to_start() + cells[i][j]->get_distance() > cells[i][j]->get_len_to_start()))
                            {
                                cells[i][j]->set_len_to_start((current_cell->get_len_to_start() + cells[i][j]->get_distance()*1.4));

                                if (cells[i][j]->is_visited())
                                    cells_set.erase(cells[i][j]);

                                cells[i][j]->visit();
                                cells[i][j]->set_heur_approx(heuristic(cells[i][j]));
                                cells[i][j]->count_weight();
                                cells[i][j]->set_parent(current_cell);
                                cells[i][j]->check();
                                cells_set.insert(cells[i][j]);
                                cells[i][j]->update();
                            }
                        }
                    }
                }
            }
        }
        current_cell->update();
        current_cell->close();
        current_cell = (*(cells_set.begin()));
        if (cells_set.empty())
            break;

    }
    start_finish_line();
}

void MainWindow::start_finish_line()
{
    Cell* current_cell = to_finish;
    to_start->set_color(QColor(0, 255, 0));
    to_finish->set_color(QColor(255, 0, 255));
    to_start->update();
    to_finish->update();
    QGraphicsLineItem* line;
    while (current_cell != to_start)
    {
        line = new QGraphicsLineItem();
        line->setPen(QPen(Qt::red, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        scene.addItem(line);
        line->setLine(current_cell->get_x() * 80 + 40, current_cell->get_y() * 80 + 40, current_cell->get_parent().x()* 80 + 40, current_cell->get_parent().y() * 80 + 40);
        current_cell = cells[current_cell->get_parent().y()][current_cell->get_parent().x()];
    }
}

bool compare2(Cell* obj1, Cell* obj2)
{
    return obj1->get_len_to_start() < obj2->get_len_to_start();
}

void MainWindow::Dijkstra()
{
    Cell* current_cell = to_start;
    multiset<Cell*, decltype (compare2)*> cells_set(compare2);

    while (1)
    {
        current_cell->block();
        delay(200);

        for (int i = current_cell->get_y() - 1; i <= current_cell->get_y() + 1; i++)
        {
            for(int j = current_cell->get_x() - 1; j <= current_cell->get_x() + 1; j++)
            {
                if ((i >= 0) && (j >= 0) && (i < 8) && (j < 10))
                {
                    if (!(cells[i][j]->is_blocked() || cells[i][j]->is_visited()))
                    {
                        //delay(200);
                        if ((i == current_cell->get_y()) || (j == current_cell->get_x()))
                        {
                            if (!(cells[i][j]->is_visited() && (current_cell->get_len_to_start() + cells[i][j]->get_distance() > cells[i][j]->get_len_to_start())))
                            {
                                delay(200);
                                cells[i][j]->set_len_to_start(current_cell->get_len_to_start() + cells[i][j]->get_distance());

                                if (cells[i][j]->is_visited())
                                    cells_set.erase(cells[i][j]);

                                cells[i][j]->visit();
                                cells[i][j]->check();
                                cells[i][j]->set_parent(current_cell);
                                cells_set.insert(cells[i][j]);
                                cells[i][j]->update();
                            }

                        }
                        else
                        {
                            if (!(cells[i][j]->is_visited()) && (current_cell->get_len_to_start() + cells[i][j]->get_distance() > cells[i][j]->get_len_to_start()))
                            {
                                delay(200);
                                cells[i][j]->set_len_to_start((current_cell->get_len_to_start() + cells[i][j]->get_distance()*1.4));

                                if (cells[i][j]->is_visited())
                                    cells_set.erase(cells[i][j]);

                                cells[i][j]->visit();
                                cells[i][j]->check();
                                cells[i][j]->set_parent(current_cell);
                                cells_set.insert(cells[i][j]);
                                cells[i][j]->update();
                            }
                        }
                    }
                }
            }
        }
        current_cell->update();
        current_cell->close();
        if (cells_set.empty() || current_cell == to_finish)
            break;
        current_cell = (*(cells_set.begin()));
        cells_set.erase(cells_set.begin());
    }
    start_finish_line();
}


void MainWindow::on_btn_astar_clicked()
{
    ui->btn_astar->setEnabled(false);
    ui->btn_dijkstra->setEnabled(false);
    create_map();
    a_star();
    ui->btn_astar->setEnabled(true);
    ui->btn_dijkstra->setEnabled(true);
}


void MainWindow::on_btn_dijkstra_clicked()
{
    ui->btn_astar->setEnabled(false);
    ui->btn_dijkstra->setEnabled(false);
    create_map();
    Dijkstra();
    ui->btn_astar->setEnabled(true);
    ui->btn_dijkstra->setEnabled(true);
}

