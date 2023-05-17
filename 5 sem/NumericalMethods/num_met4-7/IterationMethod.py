from sympy import *


def func(x):
    return (x ** 3 / 15) + (x / 16) - (16 * 11)


def new_func(x):
    return (-15 * x / 16 + 15 * 16 * 11) ** (1.0 / 3)


def diff_func(x0):
    x = symbols('x')
    fx = diff((x ** 3 / 15) + (x / 16) - (16 * 11), x)
    return fx.evalf(subs={x: x0})


def new_diff_func(x0):
    x = symbols('x')
    fx = diff((-15 * x / 16 + 15 * 16 * 11) ** (1.0 / 3), x)
    return fx.evalf(subs={x: x0})


if __name__ == "__main__":
    iter_counter = 0
    precision = 0.00000001
    a = 0.0
    b = 1.0
    bn = 0
    bn2 = 0
    while func(a) * func(b) > 0:
        a += 0.5
        b += 0.5

    print("q = ", abs(new_diff_func(b)), '\n')  # q вывел

    if (a <= new_func(b)) and (new_func(b) <= b):  # проверка g(x) пренадлежит [a, b]
        while (abs(new_diff_func(b)) < 1) and ((abs(func(b)) > 0.00000001) and (((b - bn)**2) / (2*bn - b - bn2))):
            bn2 = bn
            bn = b
            b = new_func(b)
            print("b = " + str(b))
            print("q = ", abs(new_diff_func(b)))
            print(" ")

            iter_counter += 1

        print("Answer = " + str(b))
        print("Answer was reached in " + str(iter_counter) + " iterations")
    else:
        print("Error! g'(x) !e [a, b]")
