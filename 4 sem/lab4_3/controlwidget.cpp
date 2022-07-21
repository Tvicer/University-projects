#include "controlwidget.h"

ControlWidget::ControlWidget(ImageWidget *parent)
{
    sld = new QSlider(Qt::Horizontal, this);
    sld->setGeometry(0, 125, 150, 20);
    sld->setMinimum(0);
    sld->setMaximum(256);
    sld->setValue(128);

    btn_black = new QPushButton(this);
    btn_white = new QPushButton(this);

    btn_black->setText("Красить чёрным(по умолчанию)");
    btn_white->setText("Красить белым");

    btn_black->setGeometry(175, 25, 200, 75);
    btn_white->setGeometry(175, 175, 200, 75);
    connect(sld, SIGNAL(valueChanged(int)), parent, SLOT(setValue(int)));
    connect(btn_black, SIGNAL(clicked()), parent, SLOT(change_color_to_black()));
    connect(btn_white, SIGNAL(clicked()), parent, SLOT(change_color_to_white()));
}

