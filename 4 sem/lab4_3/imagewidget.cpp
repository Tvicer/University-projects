#include "imagewidget.h"
#include "imagefunctions.h"

ImageWidget::ImageWidget(QWidget *parent) : QWidget(parent)
{

}

ImageWidget::ImageWidget(QImage& img)
{
    img_ptr = &img;
    copy_img = *img_ptr;
    ImageFunctions::set_color_threshold(*img_ptr, 128, cur_color);
    this->update();
}

void ImageWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    if (!img_ptr) return;

    painter.begin(this);
    //painter.drawImage(width() / 2 - 200, height() / 2 - 125, *img_ptr);
    painter.drawImage(0, 0, *img_ptr);
    painter.end();
}

void ImageWidget::set_image(QImage& img)
{
    img_ptr = &img;
}

void ImageWidget::set_BWimage(QImage& img)
{
    img_ptr = &img;
    ImageFunctions::setToBrightnessMap(img);
}

void ImageWidget::set_invert_image(QImage& img)
{
    img_ptr = &img;
    ImageFunctions::invertcolor(img);
}

void ImageWidget::setValue(int value)
{
    *img_ptr = copy_img;
    saved_value = value;
    ImageFunctions::set_color_threshold(*img_ptr, value, this->cur_color);
    this->update();
}

void ImageWidget::change_color_to_black()
{
    *img_ptr = copy_img;
    this->cur_color = 0;
    ImageFunctions::set_color_threshold(*img_ptr, saved_value, this->cur_color);
    this->update();
}

void ImageWidget::change_color_to_white()
{
    *img_ptr = copy_img;
    this->cur_color = 255;
    ImageFunctions::set_color_threshold(*img_ptr, saved_value, this->cur_color);
    this->update();
}

void ImageWidget::set_lightlog_image(QImage& img)
{
    img_ptr = &img;
    ImageFunctions::set_log(img);
}

void ImageWidget::set_lightpow_image(QImage& img)
{
    img_ptr = &img;
    ImageFunctions::set_pow(img);
}

void ImageWidget::set_lightpiece_image(QImage& img)
{
    img_ptr = &img;
    ImageFunctions::set_piece(img);
}
