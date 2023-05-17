import numpy as np
import math


def check_precision(mtx):
    max_el = mtx[0][1]
    for i in range(len(mtx)):
        for j in range(i + 1, len(mtx[0])):
            max_el = max(max_el, mtx[i][j])
    return max_el


if __name__ == "__main__":
    size = 0
    matrix = []
    precision = 0.000001
    mat = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])

    try:
        file = open('matrix2.txt', 'r')
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
            if len(line) != size:
                raise ValueError

            matrix.append([float(line[j]) for j in range(len(line))])

        file.close()
        mat = np.array(matrix)
        print("Your matrix:")
        print(mat)

    except ValueError:
        print("Wrong value")
        exit(-1)

    epsilon = 0.00000000000001
    beg_mat = np.eye(size).dot(mat)

    status = True
    current_precision = 1
    container_for_rotate_mat = []
    while status:
        max_elem = mat[0][1]
        row, col = 0, 1
        for i in range(len(mat)):
            for j in range(i + 1, len(mat)):
                cur_elem = abs(mat[i][j])
                if cur_elem > max_elem:
                    max_elem = cur_elem
                    row, col = i, j

        if mat[row][row] - mat[col][col] == 0:
            phi = 0.7853981633974483
        else:
            phi = 0.5 * math.atan(2 * mat[row][col] / (mat[row][row] - mat[col][col]))

        cos = math.cos(phi)
        sin = math.sin(phi)
        H_rot_mat = np.eye(size)
        H_rot_mat[row][row] = cos
        H_rot_mat[row][col] = -sin
        H_rot_mat[col][row] = sin
        H_rot_mat[col][col] = cos
        container_for_rotate_mat.append(H_rot_mat)
        H_op_rot_mat = H_rot_mat.transpose()
        mat = H_op_rot_mat.dot(mat).dot(H_rot_mat)
        # print(mat)
        current_precision = check_precision(mat)
        if current_precision <= precision:
            # print(current_precision)
            status = False
    print(" ")
    print("Eigenvalues:")
    # for i in range(len(mat)):
    #    print("lambda" + str(i) + "=" + str(mat[i][i]) + " vector: [" + res[0][0])

    res = np.eye(size)
    for rot_mat in container_for_rotate_mat:
        res = res.dot(rot_mat)
        # print(res)
    # print("Eigenvectors:")
    # print(res)
    el1 = res[0][0]
    res[0][0] /= el1
    res[1][0] /= el1
    res[2][0] /= el1

    el2 = res[1][1]
    res[0][1] /= el2
    res[1][1] /= el2
    res[2][1] /= el2

    el3 = res[2][2]
    res[0][2] /= el3
    res[1][2] /= el3
    res[2][2] /= el3

    # print(res)

    for i in range(len(mat)):
        print("lambda" + str(i) + " = " + str(mat[i][i]) + "; Eigenvector: [" + str(res[0][i]) + " , " + str(res[1][i]) + " , " + str(res[2][i]) + "]")
