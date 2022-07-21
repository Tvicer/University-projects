#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

#include "imagefunctions.h"
#include "imagewidget.h"

class Infowidget : public QWidget
{
    Q_OBJECT
public:
    Infowidget();

private:
    QPushButton *btn_about_program, *btn_about_author;

public slots:
    void program_info();
    void author_info();

};

#endif // INFOWIDGET_H
