from sympy import *


def func(x):
    return (x ** 3 / 10) + (x / 16) + (16 * 11)


def diff_func(x0):
    x = symbols('x')
    fx = diff((x ** 3 / 10) + (x / 16) + (16 * 11), x)
    return fx.evalf(subs={x: x0})


if __name__ == "__main__":
    iter_counter = 0
    arr = []
    arr_right = []
    arr_left = []
    precision = 0.00000001
    a = 0
    an = 0
    delta = 1
    while func(a) * diff_func(diff_func(a)) > 0:
        a -= 0.5

    while (delta > precision) and (func(a) * diff_func(diff_func(a)) < 0):
        an = a
        a = a - (func(a) / diff_func(a))
        print("a = " + str(a))
        print("delta = " + str(delta))
        print(" ")

        delta = abs(an - a)
        iter_counter += 1

    print("Answer = " + str(a))
    print("Answer was reached in " + str(iter_counter) + " iterations")
