import numpy as np


def max_norm(mat):
    res = []
    for vec in mat:
        mid_res = 0
        for elem in vec:
            mid_res += abs(elem)
        res.append(mid_res)
    return max(res)


if __name__ == "__main__":
    size = 0
    matrix = []
    precision = 0.000001
    mat = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    arr_c = []
    ans = []

    try:
        file = open('matrix1.txt', 'r')
        size = int(file.readline())
        precision = float(file.readline())

        if size == 0:
            raise ValueError

        print("Size = " + str(size))

        if precision < 0:
            raise ValueError

        print("Precision = " + str(precision))

        for i in range(size):
            line = file.readline().split()
            if len(line) != size + 1:
                raise ValueError

            matrix.append([float(line[j]) for j in range(len(line) - 1)])
            arr_c.append(float(line[len(line) - 1]))

        file.close()
        mat = np.array(matrix)
        print('Your matrix:')
        print(mat)
        print('Your vector:')
        print(arr_c)

    except ValueError:
        print("Wrong value")
        exit(-1)

    el1 = mat[0][0]
    mat[0][0] -= el1
    mat[0][1] /= -el1
    mat[0][2] /= -el1
    arr_c[0] /= el1

    el2 = mat[1][1]
    mat[1][0] /= -el2
    mat[1][1] -= el2
    mat[1][2] /= -el2
    arr_c[1] /= el2

    el3 = mat[2][2]
    mat[2][0] /= -el3
    mat[2][1] /= -el3
    mat[2][2] -= el3
    arr_c[2] /= el3

    # print('Your matrix:\n')
    # print(mat)
    # print('Your vector:\n')
    # print(arr_c)

    betta_norm = 0
    cur_norm = 0
    norm = max_norm(mat)
    cur_norm = max_norm(mat)

    betta_norm = max(arr_c)

    num_of_iter = 0
    for i in range(len(arr_c)):
        ans.append(arr_c[i])

    buf = 0
    buf_ans = []
    for i in range(len(ans)):
        buf_ans.append(ans[i])
    cur_precision = 2

    forNormAns = []
    for i in range(len(ans)):
        forNormAns.append(0)

    if cur_norm < 1:
        while cur_precision > precision:
            for i in range(len(ans)):
                for j in range(len(ans)):
                    buf += mat[i][j] * buf_ans[j]
                buf += arr_c[i]
                ans[i] = buf
                buf = 0

            cur_norm *= norm
            cur_precision = (cur_norm / (1 - norm)) * abs(betta_norm)

            buf_ans = ans
            buf = 0
            num_of_iter += 1
    else:
        while (num_of_iter < 1000) and (cur_precision > precision):
            for i in range(len(ans)):
                for j in range(len(ans)):
                    buf += mat[i][j] * buf_ans[j]
                buf += arr_c[i]
                ans[i] = buf
                buf = 0

            for i in range(len(buf_ans)):
                forNormAns[i] = buf_ans[i] - ans[i]
            cur_precision = abs(max(forNormAns))
            buf_ans = ans
            buf = 0
            num_of_iter += 1

    print('')
    if cur_norm >= 1:
        print('Warning! The answer may not be available, because norm of matrix >= 1')

    print('Answer:')
    print(ans)
    print('Answer was reached in ' + str(num_of_iter) + ' iterations')
