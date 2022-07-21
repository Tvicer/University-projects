#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>
#include <QSlider>
#include <QPushButton>

#include "imagefunctions.h"
#include "imagewidget.h"

class ControlWidget : public QWidget
{
    Q_OBJECT
public:
    ControlWidget(ImageWidget *parent = nullptr);

private:
    QSlider *sld;
    QPushButton *btn_black, *btn_white;
};

#endif // CONTROLWIDGET_H
