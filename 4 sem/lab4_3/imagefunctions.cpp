#include "imagefunctions.h"
#include <cmath>
using namespace ImageFunctions;


void ImageFunctions::setToBrightnessMap(QImage& img)
{
    uchar *px = img.bits();

    int h = img.height();
    int w = img.width();

    int pixelsQuo = h * w;

    int r, g, b;
    int brightness = 0;
    for (int i = 0; i < pixelsQuo; i++)
    {
        brightness = getY(px);


        *px = brightness;
        *++px = brightness;
        *++px = brightness;

        px += 2;
    }
}

const float Kr = 0.299;
const float Kb = 0.114;

int ImageFunctions::getY(const uchar* px)
{
    float r = *px;
    float g = *++px;
    float b = *++px;

    int res = Kr*(r) + (1-Kr-Kb)*g + Kb*b;

    /*if(res<0)
        res = 0;
    else if(res>255)
        res=255;*/

    return res;
}

int ImageFunctions::getU(int B, int Y)
{
    int res = B - Y;

    /*if(res<0)
        res = 0;
    else if(res>255)
        res=255;*/

    return res;
}

int ImageFunctions::getV(int R, int Y)
{
    int res = R - Y;

    /*if(res<0)
        res = 0;
    else if(res>255)
        res=255;*/

    return res;
}

int ImageFunctions::getR(int Y, int V)
{
    int res = Y + V;

    if(res < 0)
        res = 0;
    else if(res > 255)
        res = 255;

    return res;
}

int ImageFunctions::getG(int Y, float V, float U)
{
    int res = Y - (int)((Kr*V + Kb*U)/(1-Kb-Kr));

    if(res < 0)
        res = 0;
    else if(res > 255)
        res = 255;

    return res;
}

int ImageFunctions::getB(int Y, int U)
{
    int res = Y+U;

    if(res < 0)
        res = 0;
    else if(res > 255)
        res = 255;

    return res;
}

void ImageFunctions::setHistogramData(const QImage &img, unsigned long long(&histogramData)[256])
{
    const uchar *px = img.constBits();

    int h = img.height();
    int w = img.width();

    unsigned long long pixelsQuo = h * w;

    int r, g, b;
    int brightness = 0;
    for (unsigned long long i = 0; i < pixelsQuo; i++)
    {
        brightness = ImageFunctions::getY(px);
        histogramData[brightness]++;
        px += 2;
    }
}

void ImageFunctions::invertcolor(QImage& img)
{
    uchar *px = img.bits();

    int numofpix = img.height() * img.width();

    for (int i = 0; i < numofpix; i++)
    {
        *px = 255 - *px;
        px++;

        *px = 255 - *px;
        px++;

        *px = 255 - *px;

        px += 2;
    }
}

void ImageFunctions::set_color_threshold(QImage& img, int value, uchar color)
{
    uchar *px = img.bits();
    int numofpix = img.height() * img.width();
    int brightness = 0;
    for (int i = 0; i < numofpix; i++)
    {
        brightness = ImageFunctions::getY(px);
        if(brightness < value)
        {
            *px = color;
            px++;
            *px = color;
            px++;
            *px = color;
            px += 2;
        }
        else
        {
            px+= 4;
        }
    }

}

void ImageFunctions::set_log(QImage &img)
{
    uchar *px = img.bits();
    int r, g, b;
    double Y = 0, brightness = 0;
    int U = 0, V = 0;
    int numofpix = img.height() * img.width();
    for (int i = 0; i < numofpix; i++)
    {
        r = *px;
        ++px;
        b = *++px;

        px -= 2;

        Y = getY(px);

        U = getU(b, Y);

        V = getV(r, Y);

        brightness = (double)(getY(px) / 255.0);

        brightness = log10(1 + 9 * brightness) * 255;

        *px = getR(brightness, V);
        px++;
        *px = getG(brightness, V, U);
        px++;
        *px = getB(brightness, U);

        px += 2;
    }
}

void ImageFunctions::set_pow(QImage &img)
{
    uchar *px = img.bits();
    int r, g, b;
    double Y = 0, brightness = 0;
    int U = 0, V = 0;
    int numofpix = img.height() * img.width();
    for (int i = 0; i < numofpix; i++)
    {
        r = *px;
        ++px;
        b = *++px;

        px -= 2;

        Y = getY(px);

        U = getU(b, Y);

        V = getV(r, Y);

        brightness = (double)(Y / 255.0);
        brightness = pow(brightness, 0.2) * 255;

        *px = getR(brightness, V);
        px++;
        *px = getG(brightness, V, U);
        px++;
        *px = getB(brightness, U);

        px += 2;
    }
}

void ImageFunctions::set_piece(QImage &img)
{
    uchar *px = img.bits();
    int brightness = 0;
    int numofpix = img.height() * img.width();
    for (int i = 0; i < numofpix; i++)
    {
        brightness = getY(px);

        if  ((brightness > 32) && (brightness < 64))
        {
            *px += 50;
            *++px += 50;
            *++px += 50;
        }
        else if  ((brightness > 128) && (brightness < 150))
        {
            *px += 70;
            *++px += 70;
            *++px += 70;
        }
        else
        {
            px += 2;

        }

        px += 2;
    }
}


