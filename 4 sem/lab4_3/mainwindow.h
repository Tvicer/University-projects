#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QLayout>

#include "imagewidget.h"
#include "histogram.h"
#include "controlwidget.h"
#include "infowidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QImage image, BWimage, inv_image, maxcol_image, light_log_image, light_pow_image, light_piece_image, eq_image, dist_image;
    ImageWidget *img_widget, *BWimg_widget, *img_invert_widget, *img_maxcol_widget, *img_lightlog_widget, *img_lightpow_widget, *img_lightpiece_widget, *img_eq_widget, *img_dist_widget;
    Histogram *histogram, *eq_histogram, *dist_histogram;
    QGridLayout *gbox;

    ControlWidget *light_limit_control;
    Infowidget *info_widget;


    void load_image();
    void draw();
    void make_image();
};
#endif // MAINWINDOW_H
