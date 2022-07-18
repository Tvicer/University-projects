#include <iostream>
#include <string>
#include "Complex.h"
#include "funcks.h"

using namespace std;



void skip(char* a)
{
    if (*a == ' ')
        while (*a == ' ')
        {
            *a = getc(stdin);
        }
}



void take(Compl& num, char* cr, char* signerr, char* pos)
{
    char ch = 0;
    int i = 0;
    float c = 0;

    *cr = getc(stdin);
    skip(cr);
    if (*cr == '(')
    {
        *signerr += 1;
        *cr = getc(stdin);
        skip(cr);
    }

    while ((*cr >= '0') && (*cr <= '9'))
    {
        c = float(c * 10 + *cr - '0');
        *cr = getc(stdin);
        skip(cr);
        if ((*cr == '+') || (*cr == '-') || (*cr == '*') || (*cr == '/') || (*cr == '\n'))
        {
            ch = *cr;
        }
    }


    num.put_rl(c);

    c = 0;
    *cr = getc(stdin);
    skip(cr);
    if (*cr == 'i')
    {
        i++;
        *cr = getc(stdin);
        skip(cr);
        if (*cr == '*')
        {
            *cr = getc(stdin);
            skip(cr);
        }
        else if (!((*cr >= '0') && (*cr <= '9')))
        {
            cout << "Error!";
            exit (-1);
        }
    }



    while ((*cr >= '0') && (*cr <= '9'))
    {
        c = c * 10 + *cr - '0';
        *cr = getc(stdin);
        skip(cr);
        if (*cr == '*')
        {
            *cr = getc(stdin);
            skip(cr);
            if (*cr == 'i')
            {
                i++;
                *cr = getc(stdin);
                skip(cr);
                if (*cr == ')')
                {
                    *signerr -= 1;
                    *cr = getc(stdin);
                    skip(cr);
                }
            }
            else if (!((*cr == '+') || (*cr == '-') || (*cr == '*') || (*cr == '/') || (*cr == '\n')))
            {
                cout << "Error!";
                exit(-1);
            }
        }
        else if (*cr == 'i')
        {
            i++;
            *cr = getc(stdin);
            skip(cr);
            if (*cr == ')')
            {
                *signerr -= 1;
                *cr = getc(stdin);
                skip(cr);
            }
            if (!((*cr == '+') || (*cr == '-') || (*cr == '*') || (*cr == '/') || (*cr == '\n')))
            {
                cout << "Error!";
                exit(-1);
            }
        }
    }

    if (i != 1)
    {
        cout << "Error!";
        exit(-1);
    }

    if (ch == '-')
        c = -c;
    else if ((ch == '*') || (ch == '/'))
        exit(-1);

    num.put_im(c);
}



void author()
{
    cout << "Hi! This is lab 2 of Nosov Alexander M8O-111B-20\n";
}



int main()
{
	Compl num1, num2, ans;
    float ansv;
    char cr = 0, ch = 0, wrd[] = "      ", err = 0, pos = 0;
    int c = 0, i = 0;
    while (1)
    {
        cout << ">>";
        cr = getc(stdin);
        skip(&cr);
        if (cr != '(')
        {
            wrd[0] = cr;
            cin >> wrd[1];
            if (strcmp(wrd, "re    ") == 0)
            {
                take(num1, &cr, &err, &pos);
                cout << num1.get_rl() << endl;
            }
            else if (strcmp(wrd, "im    ") == 0)
            {
                take(num1, &cr, &err, &pos);
                cout << num1.get_im() << endl;
            }
            else
            {
                cin >> wrd[2];
                if (strcmp(wrd, "abs   ") == 0)
                {
                    take(num1, &cr, &err, &pos);
                    ansv = num1.cmpl_abs();
                    cout << ansv << endl;
                }
                else if (strcmp(wrd, "arg   ") == 0)
                {
                    take(num1, &cr, &err, &pos);
                    ansv = num1.arg();
                    cout << ansv << endl;
                }
                else
                {
                    cin >> wrd[3];
                    if (strcmp(wrd, "conj  ") == 0)
                    {
                        take(num1, &cr, &err, &pos);
                        ans = num1.conj();
                        ans.prn();

                    }
                    else if (strcmp(wrd, "sqrt  ") == 0)
                    {
                        take(num1, &cr, &err, &pos);
                        ans = num1.cmpl_sqrt();
                        ans.prn();
                    }
                    else if (strcmp(wrd, "quit  ") == 0)
                    {
                        cout << "Bye!";
                        return 0;
                    }
                    else
                    {
                        cin >> wrd[4] >> wrd[5];
                        if (strcmp(wrd, "author") == 0)
                            author();
                        else
                        {
                            cout << "Error!";
                            return -1;
                        }
                    }
                }
            }

        }
        else
        {
            take(num1, &cr, &err, &pos);
            ch = cr;
            take(num2, &cr, &err, &pos);
            if (ch == '+')
            {
                ans = num1.add(num2);
                ans.prn();
            }
            else if (ch == '-')
            {
                ans = num1.subtract(num2);
                ans.prn();
            }
            else if (ch == '*')
            {
                ans = num1.multiply(num2);
                ans.prn();
            }
            else if (ch == '/')
            {
                ans = num1.divide(num2);
                ans.prn();
            }
            else
            {
                cout << "Error!";
                return -1;
            }
        }
        
    }





	return 0;
}