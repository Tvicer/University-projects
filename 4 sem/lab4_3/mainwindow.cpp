#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    load_image();
    draw();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load_image()
{
    //QString path = "D:\\Qt\\Projects\\lab4_3_1\\image\\cat.jpg"; // ТУТ НАДО ПОМЕНЯТЬ ПУТЬ
    QString path = QFileDialog::getOpenFileName();
    if (!image.load(path))
    {
        QString err_msg = QString("Ошибка открытия картинки");
        qDebug() << err_msg;
        QMessageBox::critical(this, "Ошибка", err_msg);
        exit(-1);
    }
    image = image.scaled(400, 300, Qt::KeepAspectRatio).convertToFormat(QImage::Format_RGBA8888_Premultiplied);
}

void MainWindow::draw()
{
    this->resize(1700, 1000);

    //hbox = new QHBoxLayout();
    gbox = new QGridLayout();
    this->centralWidget()->setLayout(gbox);

    img_widget = new ImageWidget();
    img_widget->set_image(image);

    gbox->addWidget(img_widget, 0, 0);

    BWimage = image;
    BWimg_widget = new ImageWidget();
    BWimg_widget->set_BWimage(BWimage);

    gbox->addWidget(BWimg_widget, 0, 2);

    histogram = new Histogram();
    histogram->doHistogram(image);

    gbox->addWidget(histogram, 1, 2);

    inv_image = image;
    img_invert_widget = new ImageWidget();
    img_invert_widget->set_invert_image(inv_image);

    gbox->addWidget(img_invert_widget, 0, 1);

    maxcol_image = image;
    img_maxcol_widget = new ImageWidget(maxcol_image);
    //img_maxcol_widget->set_maxcol_image(maxcol_image);

    gbox->addWidget(img_maxcol_widget, 1, 0);

    light_limit_control = new ControlWidget(img_maxcol_widget);

    gbox->addWidget(light_limit_control, 1, 1);

    light_log_image = image;
    img_lightlog_widget = new ImageWidget();
    img_lightlog_widget->set_lightlog_image(light_log_image);

    gbox->addWidget(img_lightlog_widget, 2, 0);

    light_pow_image = image;
    img_lightpow_widget = new ImageWidget();
    img_lightpow_widget->set_lightpow_image(light_pow_image);

    gbox->addWidget(img_lightpow_widget, 2, 1);

    light_piece_image = image;
    img_lightpiece_widget = new ImageWidget();
    img_lightpiece_widget->set_lightpiece_image(light_piece_image);

    gbox->addWidget(img_lightpiece_widget, 2, 2);

    eq_image = image;
    eq_histogram = new Histogram;
    eq_histogram->HistogramEqualization(eq_image);

    img_eq_widget = new ImageWidget();
    img_eq_widget->set_image(eq_image);
    gbox->addWidget(img_eq_widget, 0, 3);

    dist_image = image;
    dist_histogram = new Histogram;
    dist_histogram->doDistribution(dist_image);

    img_dist_widget = new ImageWidget();
    img_dist_widget->set_image(dist_image);
    gbox->addWidget(img_dist_widget, 2, 3);

    info_widget = new Infowidget();
    gbox->addWidget(info_widget, 1, 3);

}
