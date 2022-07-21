#ifndef CELL_H
#define CELL_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>

class Cell : public QGraphicsItem
{
public:
    Cell();
    Cell(int in_x, int in_y, char c);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    int get_x();
    int get_y();
    int get_weight();
    int get_distance();
    int get_len_to_start();
    const QPoint &get_parent();

    void set_type(int st);
    void set_heur_approx(int approx);
    void set_parent(Cell* pr);
    void set_color(QColor color);
    void set_len_to_start(int len);

    bool is_blocked();
    void block();
    void visit();
    bool is_visited();
    void check();
    void close();
    void count_weight();


    enum Status
    {
        WAY = 0,
        BARRIER = 1,
        FOREST = 2,
        WATER = 3,
        CLOSED_LIST = 4,
        CHECK = 5,
        START = 6,
        FINISH = 7
    };
private:
    int x = 0, y = 0;

    int type = WAY;

    int heur_approx = 0;

    int weight = 0;

    int distance = 10;

    int len_to_start = 0;

    int visited = 0;

    QColor color = QColor(255,255,255);

    QPoint parent;

    QPixmap arrow;

signals:

};



#endif // CELL_H
