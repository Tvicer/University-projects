def func(x):
    return (x / 16) ** 3 - x / 11 + 1 / 11


if __name__ == "__main__":
    iter_counter = 0
    arr = []
    arr_right = []
    arr_left = []
    precision = 0.00000001
    a = 0.0
    b = 1.0
    c = 0
    delta = abs(a - b)
    while func(a) * func(b) > 0:
        a += 0.5
        b += 0.5

    arr = [a, b]

    while delta > 2 * precision:
        c = (arr[0] + arr[1]) / 2
        arr_right = [arr[0], c]
        arr_left = [c, arr[1]]
        print("arr[0] = " + str(arr[0]) + "; arr[1] = " + str(arr[1]))
        print("arr_right[0] = " + str(arr_right[0]) + "; arr_right[1] = " + str(arr_right[1]))
        print("arr_left[0] = " + str(arr_left[0]) + "; arr_left[1] = " + str(arr_left[1]))
        print("delta = " + str(delta))
        print(" ")
        if func(arr_right[0]) * func(arr_right[1]) < 0:
            arr = [arr_right[0], arr_right[1]]
        else:
            arr = [arr_left[0], arr_left[1]]

        delta = abs(arr[0] - arr[1])
        iter_counter += 1

    print("Answer = " + str((arr[0] + arr[1]) / 2))
    print("Answer was reached in " + str(iter_counter) + " iterations")
