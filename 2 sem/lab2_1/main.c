#include <stdio.h>
#include "Stack.h"
#include <string.h>
//#include "StackList.h"
//#include "StackList.c"
#include "StackArray.h"
#include "StackArray.c"


void prn(PStack stack)
{
    union Data c;
    while (isEmpty(stack))
    {
        pop(stack, &c);
        printf("%d %d / ", c.number, c.operator);
    }
}



int count(PStack num, union Data num1, union Data num2, union Data opr)
{
    union Data dres;
    if (opr.operator == '+')
    {
        dres.number = num1.number + num2.number;
        push(num, dres);
        return 0;
    }
    else if (opr.operator == '-')
    {
        dres.number = num1.number - num2.number;
        push(num, dres);
        return 0;
    }
    else if (opr.operator == '*')
    {
        dres.number = num1.number * num2.number;
        push(num, dres);
        return 0;
    }
    else if (opr.operator == '/')
    {
        if (num2.number == 0)
            return 1;
        dres.number = num1.number / num2.number;
        push(num, dres);
        return 0;
    }
}



int prior(char c)
{
    if ((c == '+') || (c == '-'))
    {
        return 1;
    }
    else if ((c == '*') || (c == '/'))
    {
        return 2;
    }
    else
        return 0;
}



void author()
{
    printf("Hi! This is lab 1 of Nosov Alexander M8O-111B-20\n");
}


void check(char* a, char* signerr, int i)
{
    if (*a == ' ')
        while (*a == ' ')
        {
            *a = getc(stdin);
        }

    if (((*a == '+') || (*a == '-') || (*a == '*') || (*a == '/')) && (*signerr == 1))
    {
        printf("Error in #%d symbol", i + 1);
        exit(-1);
    }

    if ((*a == '+') || (*a == '-') || (*a == '*') || (*a == '/'))
        *signerr = 1;
    else
        *signerr = 0;
}



int main()
{
    Stack num;
    Stack op;
    char co = 0, cr = 0, buf = 0, cm = 0, flag = 0, st[5], signerr = 0;
    union Data dn, dc, dres, num1, num2, opr, dbuf;
    int c = 0, i = 0, s = 0;

    init(&num);
    init(&op);

    while (1)
    {
        c = 0, cr = 0, buf = 0, cm = 0, flag = 0;
        i = 0, s = 0;
        dn.number = 0, dc.number = 0, dres.number = 0, num1.number = 0, num2.number = 0, opr.number = 0, dbuf.number = 0;

        while (cr != '\n')
        {
            printf(">> ");
            if (flag == 0)
                cr = getc(stdin);
            else if (flag == 1)
            {
                cr = cm;
                flag = 0;
            }
            else if (flag == 2)
            {
                cr = co;
                flag = 0;
            }

            check(&cr, &signerr, i);
            i++;

            if (((cr >= 'A') && (cr <= 'Z')) || ((cr >= 'a') && (cr <= 'z')))
            {
                if (cr == 'a')
                {
                    gets(st);
                    if (!strcmp(st, "uthor"))
                    {
                        author();
                        continue;
                    }
                    else
                    {
                        printf("Error in command!");
                        return -1;
                    }
                }
                else if (cr == 'q')
                {
                    gets(st);
                    if (!strcmp(st, "uit"))
                    {
                        //free(num.top);
                        //free(op.top);
                        free(num.data);
                        exit(0);
                    }
                }
                else
                {
                    printf("Error in command!");
                    return -1;
                }
            }
            else if (((cr < '(') || (cr > '9')) && (cr != '\n'))
            {
                printf("Error in #%d symbol! Don't use letters!", i);
                return -1;
            }
          


            if (cr == '(')
            {
                cm = getc(stdin);
                check(&cm, &signerr, i);
                i++;
                if (cm == '-')
                {
                    cr = getc(stdin);
                    check(&cr, &signerr, i);
                    i++;
                    while ((cr >= '0') && (cr <= '9'))
                    {
                        c = c * 10 + cr - '0';
                        cr = getc(stdin);
                        check(&cr, &signerr, i);
                        i++;
                        if (cr == ')')
                        {
                            dn.number = -c;
                            push(&num, dn);
                            c = 0;
                            cr = getc(stdin);
                            check(&cr, &signerr, i);
                            i++;
                        }
                    }
                }
                else
                    flag = 1;
            }

            while ((cr >= '0') && (cr <= '9'))
            {
                c = c * 10 + cr - '0';
                cr = getc(stdin);
                check(&cr, &signerr, i);
                i++;
                if ((cr == '+') || (cr == '-') || (cr == '*') || (cr == '/') || (cr == '(') || (cr == ')') || (cr == '\n'))
                {
                    dn.number = c;
                    push(&num, dn);
                    c = 0;
                }
            }

            if ((cr == '+') || (cr == '-') || (cr == '*') || (cr == '/') || (cr == '(') || (cr == ')'))
            {
                if (isEmpty(&op))
                {
                    top(&op, &dbuf);
                    buf = dbuf.operator;
                }

                if (!isEmpty(&op))
                {
                    dc.number = cr;
                    push(&op, dc);
                    if (cr == '(')
                        s++;
                }
                else if (((prior(cr) > prior(buf)) || (cr == '(') || (buf == '(')) && (cr != ')'))
                {
                    dc.number = cr;
                    push(&op, dc);
                    if (cr == '(')
                        s++;
                }
                else if ((prior(cr) <= prior(buf)) && (cr != ')'))
                {
                    while ((prior(cr) <= prior(buf)) && ((num.topIndex != 0) && (num.topIndex != -1)))  
                        //(num.top->next != NULL))
                    {
                        pop(&num, &num2);
                        pop(&num, &num1);
                        pop(&op, &opr);
                        count(&num, num1, num2, opr);
                        if (isEmpty(&op))
                        {
                            top(&op, &dbuf);
                            buf = dbuf.operator;
                        }
                    }

                    if ((prior(cr) > prior(buf)) || (cr == '(') || (buf == '(') || (!isEmpty(&op)))
                    {
                        dc.number = cr;
                        push(&op, dc);
                        if (cr == '(')
                            s++;
                    }
                }
                else if (cr == ')')
                {
                    if (s == 0)
                    {
                        printf("Error in brackets!!!");
                        return -1;
                    }
                    s--;
                    while (buf != '(')
                    {
                        pop(&num, &num2);
                        pop(&num, &num1);
                        pop(&op, &opr);
                        if (count(&num, num1, num2, opr))
                        {
                            printf("You can't divide by zero!!! Check symbol #%d", i);
                            return -1;
                        }

                        if (isEmpty(&op))
                        {
                            top(&op, &dbuf);
                            buf = dbuf.operator;
                        }
                    }
                    clear_top(&op);
                }
            }
        }

        while ((num.topIndex != 0) && (num.topIndex != -1))
            //(num.top->next != NULL)
        {
            pop(&num, &num2);
            pop(&num, &num1);
            pop(&op, &opr);

            if (count(&num, num1, num2, opr))
            {
                printf("You can't divide by zero!!! Check symbol #%d", i);
                return -1;
            }
        }
        if (s != 0)
        {
            printf("Error in brackets!!!");
            return -1;
        }
        pop(&num, &num1);
        printf("ans = %d\n", num1.number);
    }
    return 0;
}
