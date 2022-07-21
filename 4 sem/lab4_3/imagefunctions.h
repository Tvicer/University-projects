#ifndef IMAGEFUNCTIONS_H
#define IMAGEFUNCTIONS_H
#include<QImage>
#include<QDebug>


namespace ImageFunctions {
    void setToBrightnessMap(QImage &img);
    void setHistogramData(const QImage &img, unsigned long long(&histogramData)[256]);
    void invertcolor(QImage &img);
    void set_color_threshold(QImage &img, int value, uchar color);
    void set_log(QImage &img);
    void set_pow(QImage &img);
    void set_piece(QImage &img);

    int getY(const uchar* ptrRed);
    int getU(int Y, int B);
    int getV(int Y, int R);

    int getR(int Y, int V);
    int getG(int Y, float V, float U);
    int getB(int Y, int U);

}

#endif // IMAGEFUNCTIONS_H
