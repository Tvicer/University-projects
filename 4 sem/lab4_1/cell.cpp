#include "cell.h"

Cell::Cell() {}

Cell::Cell(int in_x, int in_y, char in_type)
{
    x = in_x;
    y = in_y;


    parent.setX(x);
    parent.setY(y);

    setPos(x * 80, y * 80);

    if(in_type == 'b')
    {
        type = BARRIER;
        color = QColor(0, 0, 0);
        block();
    }
    else if(in_type == 'f')
    {
        type = FOREST;
        distance = 20;
        color = QColor(0, 128, 0);
    }
    else if(in_type == 'w')
    {
        type = WATER;
        distance = 30;
        color = QColor(0, 0, 255);
    }
    else if(in_type == 'S')
    {
        type = START;
        color = QColor(0, 255, 0);
    }
    else if(in_type == 'F')
    {
        type = FINISH;
        color = QColor(255, 0, 255);
    }
    update();
}

void Cell::check()
{
    type = CHECK;
    color = QColor(128, 128, 128);
    arrow.load("D:\\Qt\\Projects\\lab3sem\\arrow.png");
    update();
}

QRectF Cell::boundingRect() const
{
    return QRectF(0, 0, 80, 80);
}

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setRenderHint(QPainter::TextAntialiasing, true);

    painter->setBrush(color);
    painter->setPen(QPen(Qt::black, 3));
    painter->drawRect(0,0, 80, 80);

    if ((type == Status::CLOSED_LIST) || (type == Status::CHECK))
    {
        painter->drawText(55, 60, QString::number(heur_approx));
        painter->drawText(15, 60, QString::number(len_to_start));
        painter->drawText(15, 10, QString::number(weight));

        painter->translate(40,40);

        if ((get_x() - parent.x()) < 0)
            painter->rotate((parent.y() - get_y())*45);
        else if ((get_x() - parent.x()) > 0)
            painter->rotate(180 - (parent.y() - get_y())*45);
        else
            painter->rotate((parent.y() - get_y())*90);

        painter->translate(-40,-40);
        painter->drawPixmap(30, 30, 20, 20, arrow, 0, 0, 142, 120);

    }
}
int Cell::get_x()
{
    return x;
}

int Cell::get_y()
{
    return y;
}

int Cell::get_weight()
{
    return weight;
}

int Cell::get_distance()
{
    return distance;
}

const QPoint &Cell::get_parent()
{
    return parent;
}

void Cell::set_heur_approx(int heur)
{
    heur_approx = heur;
}

void Cell::set_parent(Cell* pr)
{
    parent.setX(pr->get_x());
    parent.setY(pr->get_y());
}

void Cell::set_color(QColor color)
{
    this->color = color;
}

void Cell::block()
{
    visited = 2;
}

bool Cell::is_blocked()
{
    return visited == 2;
}

void Cell::visit()
{
    visited = 1;
}

bool Cell::is_visited()
{
    return visited == 1;
}

void Cell::count_weight()
{
    weight = heur_approx + len_to_start;
}

void Cell::close()
{
    color = QColor(255, 255, 0);
    type = CLOSED_LIST;
    update();
}

void Cell::set_len_to_start(int len)
{
    len_to_start = len;
}

int Cell::get_len_to_start()
{
    return len_to_start;
}
