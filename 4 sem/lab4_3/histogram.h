#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QPicture>
#include <QImage>
#include <QDebug>

#include "imagefunctions.h"

class Histogram : public QWidget
{
    Q_OBJECT
public:
    Histogram();
    void doHistogram(const QImage& img);
    void paintEvent(QPaintEvent* event);
    void HistogramEqualization(QImage &img);
    void doDistribution(QImage &img);
    void initBrightness(unsigned char** brightness, unsigned long long h, unsigned long long w, uchar *px);
    void newVariableAndExpectation(double& expectation, double& variance, const unsigned long long& h, const unsigned long long& w, unsigned char** brightness);

private:
    unsigned long long histogramData[256];
    unsigned long long Hmax;
    QPainter painter;
    QPicture picture;
    QPen hPen, borderPen;

    void setHmax();
    void setPaintBuffer();

    unsigned long long cdf(int x);
    long long cdf_min();
};

#endif // HISTOGRAM_H
