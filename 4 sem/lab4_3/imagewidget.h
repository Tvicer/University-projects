#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPainter>

class ImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageWidget(QWidget *parent = nullptr);
    ImageWidget(QImage& img);
    void paintEvent(QPaintEvent* event);
    void set_image(QImage& img);
    void set_BWimage(QImage& img);
    void set_invert_image(QImage& img);
    void set_lightlog_image(QImage& img);
    void set_lightpow_image(QImage& img);
    void set_lightpiece_image(QImage& img);
    //void set_eq_image(QImage& img);

private:
    QImage* img_ptr = nullptr;
    QPainter painter;
    QImage copy_img;
    uchar cur_color = 0;
    int saved_value = 128;

public slots:
   void setValue(int value);
   void change_color_to_black();
   void change_color_to_white();
};

#endif // IMAGEWIDGET_H
