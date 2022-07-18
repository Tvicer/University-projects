#pragma once
#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#define PI 3.1415926535
#include "Complex.h"

using namespace std;


void Compl::put_rl(float rl)
{
	this->rl = rl;
}

void Compl::put_im(float im)
{
	this->im = im;
}

float Compl::get_rl() const
{
	return this->rl;
}

float Compl::get_im() const
{
	return this->im;
}

void Compl::prn() const
{
	if (this->im < 0)
	{
		cout << this->get_rl() <<  this->get_im() << "*i" << endl;
	}
	else
	{
		cout << this->get_rl() << "+" << this->get_im() << "*i" << endl;
	}
}


Compl Compl::add(Compl &num1) const
{
	Compl ans;
	ans.put_rl(rl + num1.get_rl());
	ans.put_im(im + num1.get_im());
	return ans;
}

Compl Compl::subtract(Compl& num1) const
{
	Compl ans;
	ans.put_rl(rl - num1.get_rl());
	ans.put_im(im - num1.get_im());
	return ans;
}

Compl Compl::multiply(Compl& num1) const
{
	Compl ans;
	ans.put_rl(rl * num1.get_rl() - im * num1.get_im());
	ans.put_im(rl * num1.get_im() - im * num1.get_rl());
	return ans;
}

Compl Compl::divide(Compl& num1) const
{
	Compl ans;
	float c = 0;
	if (num1.get_rl() * num1.get_rl() + num1.get_im() * num1.get_im() == 0)
	{
		std::cout << "You can't divide to zero!";
		return ans;
	}
	else
	{
		ans.put_rl((rl * num1.get_rl() + (im * num1.get_im())) / (num1.get_rl() * num1.get_rl() + num1.get_im() * num1.get_im()));
		ans.put_im((num1.get_rl() * rl - num1.get_im() * rl) / (num1.get_rl() * num1.get_rl() + num1.get_im() * num1.get_im()));
	}
	return ans;
}

Compl Compl::conj() const
{
	Compl ans;
	ans.put_rl(this->rl);
	ans.put_im((-1) * this->im);
	return ans;
}

float Compl::cmpl_abs() const
{
	float ans;
	ans = sqrt((rl * rl) + (im * im));
	return ans;
}

float Compl::arg() const
{
	float ans;

	if (rl > 0)
	{
		ans = atan(im / rl);
	}
	else
	{
		if (im > 0)
		{
			ans = PI + atan(im / rl);
		}
		else
			ans = atan(im / rl) - PI;
	}
	return ans;
}

Compl Compl::cmpl_sqrt() const
{
	Compl ans;
	ans.put_rl(sqrt(abs(rl * cos(this->arg() / 2))));
	ans.put_im(sqrt(abs(rl * sin(this->arg() / 2))));
	return ans;
}