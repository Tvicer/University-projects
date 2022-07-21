#include "histogram.h"

Histogram::Histogram()
{
    hPen = QPen(Qt::black);
    borderPen = QPen(Qt::black);
    borderPen.setWidth(3);
    //this->resize(300 + borderPen.width()*2, 300 + borderPen.width()*2);
    this->resize(300, 300);
    //this->setFixedWidth(300 + borderPen.width()*2);
    //this->setFixedHeight(300 + borderPen.width()*2);

    Hmax = 0;
    memset(histogramData, 0, sizeof(*histogramData) * 256);
}


void Histogram::doHistogram(const QImage &img)
{
    ImageFunctions::setHistogramData(img, histogramData);

    setHmax();
    setPaintBuffer();
}

void Histogram::setHmax() // Cчитаем максимальную высоту корзины гистограммы
{
    Hmax = 0;
    for (int i = 0; i < 256; i++)
    {
        if (Hmax < histogramData[i])
            Hmax = histogramData[i];
    }
}

void Histogram::setPaintBuffer()
{
    picture = QPicture();
    painter.begin(&picture);
    painter.setPen(borderPen);
    int dw = ceil((float)borderPen.width() / 2);
    painter.drawRect(dw, dw, height()- 2*dw, width() - 2*dw);

    if(Hmax < 1)
    {
        painter.end();
        update(this->rect());
        return;
    }

    painter.setPen(hPen);
    int y = height() - 8*dw;
    int hh = y - 8*dw;
    unsigned long long h;

    for (int i = 0; i < 256; i++)
    {
        h = ((double)(histogramData[i] * hh)) / Hmax ;
        painter.drawLine(i + 25, y, i + 25, y - h);
    }

    painter.end();
    update(this->rect());
}

void Histogram::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    painter.begin(this);
    painter.drawPicture(0, 0, picture);
    painter.end();
}

void Histogram::HistogramEqualization(QImage &img)
{
    this->doHistogram(img);
    uchar *px = img.bits();

    int numofpix = img.height() * img.width();

    int r, g, b;
    int Y = 0, U = 0, V = 0;
    int new_Y = 0;
    int minCfd = cdf_min();
    unsigned long long cdf[256];

    cdf[0] = histogramData[0];

    for (int i = 1; i < 256; i++)
    {
        cdf[i] = cdf[i-1] + histogramData[i];
    }

    for (unsigned long long i = 0; i < numofpix; i++)
    {
        r = *px;
        ++px;
        b = *++px;

        px -= 2;

        Y = ImageFunctions::getY(px);

        U = ImageFunctions::getU(b, Y);

        V = ImageFunctions::getV(r, Y);

        new_Y = (float(cdf[Y] - minCfd)/(numofpix-1))*255;


        *px = ImageFunctions::getR(new_Y, V);
        px++;
        *px = ImageFunctions::getG(new_Y, V, U);
        px++;
        *px = ImageFunctions::getB(new_Y, U);

        px += 2;


    }
}

long long Histogram::cdf_min()
{
    long long min = 9999999999999999;
    for(int i = 0; i < 256; i++)
    {
        if ((histogramData[i] > 0) && (histogramData[i] < min))
        {
            min = histogramData[i];

        }
    }
    return min;
}



void Histogram::doDistribution(QImage &img)
{
    double expectation = 150, variance = 10;
    double m, d, E = 4, k_0 = 0.4, k_1 = 0.02, k_2 = 0.4;
    int newBrightness;

    unsigned long long h = img.height();
    unsigned long long w = img.width();

    uchar *px = img.bits();

    unsigned char** brightness;
    brightness = new unsigned char*[img.height()];
    initBrightness(brightness, h, w, px);

    int r, g, b;
    int Y = 0, U = 0, V = 0;

    //px += w * 4;
    for (unsigned long long i = 1; i < h-1; i++)
    {
        //px += 4;
        for (unsigned long long j = 1; j < w-1; j++)
        {
            r = *px;
            ++px;
            b = *++px;

            px -= 2;

            Y = ImageFunctions::getY(px);

            U = ImageFunctions::getU(b, Y);

            V = ImageFunctions::getV(r, Y);

            newVariableAndExpectation(m, d, i, j, brightness);


            if ((m <= k_0 * expectation) && (k_1 <= (d / variance)) && ((d / variance) <= k_2))
                newBrightness = brightness[i][j] * E;
            else
                newBrightness = brightness[i][j];

            *px = ImageFunctions::getR(newBrightness, V);
            px++;
            *px = ImageFunctions::getG(newBrightness, V, U);
            px++;
            *px = ImageFunctions::getB(newBrightness, U);

            px += 2;
        }
        px += 8;
    }

    for (unsigned long long i = 0; i < img.height(); i++)
        delete[] brightness[i];
    delete[] brightness;

}

void Histogram::initBrightness(unsigned char** brightness, unsigned long long h, unsigned long long w, uchar *px)
{
    int r, g, b;
    for (unsigned long long i = 0; i < h; i++)
    {
        brightness[i] = new unsigned char[w];
        for (unsigned long long j = 0; j < w; j++)
        {

            brightness[i][j] = ImageFunctions::getY(px);

            px += 4;
        }
    }
}

void Histogram::newVariableAndExpectation(double& expectation, double& variance, const unsigned long long& h, const unsigned long long& w, unsigned char** brightness)
{
    expectation = 0;
    variance = 0;

    QList <QPoint> coords = {QPoint(-1, -1), QPoint(-1, 0), QPoint(-1, 1), QPoint(0, -1), QPoint(0, 0), QPoint(0,1), QPoint(1,-1), QPoint(1,0), QPoint(1,1)};
    QMutableListIterator<QPoint> list_it(coords);

    while (list_it.hasNext())
    {
        expectation += brightness[h + list_it.peekNext().x()][w + list_it.peekNext().y()];
        list_it.next();
        list_it.remove();
    }

    expectation /= 9;
    coords << QPoint(-1, -1) << QPoint(-1, 0) << QPoint(-1, 1) << QPoint(0, -1) << QPoint(0, 0) << QPoint(0,1) << QPoint(1,-1) << QPoint(1,0) << QPoint(1,1);

    list_it.toFront();
    while (list_it.hasNext())
    {
        variance += pow(brightness[h + list_it.peekNext().x()][w + list_it.peekNext().y()] - expectation, 2);
        list_it.next();
        list_it.remove();
    }
    variance /= 9;
}
