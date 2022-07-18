#pragma once
#include <iostream>


class Compl
{
public:

	Compl(float rl = 0, float im = 0)
	{
		this->rl = rl;
		this->im = im;
	}

    void put_rl(float rl);
	void put_im(float im);
	float get_rl() const;
	float get_im() const;
	void prn() const;

	Compl add(Compl& num1) const;
	Compl subtract(Compl& num1) const;
	Compl multiply(Compl& num1) const;
	Compl divide(Compl& num1) const;

	Compl conj() const;
	float cmpl_abs() const;
	float arg() const;
	Compl cmpl_sqrt() const;


private:
	float rl = 0, im = 0;

};

