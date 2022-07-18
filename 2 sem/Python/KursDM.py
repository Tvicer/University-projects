import sys

in_f = open(sys.argv[1], 'r')
matrix = []
copy_matrix = []
edge = []
c = 0
sz = int(in_f.readline())
for line in in_f:
    matrix.append(line.split(' '))
    copy_matrix.append(line.split(' '))
    for j, item in enumerate(matrix[c]):
        if item != '\n':
            matrix[c][j] = int(item)
            copy_matrix[c][j] = int(item)
    c += 1
    if c == sz:
        break

in_f.close()

for i in range(sz):
    for j in range(sz):
        if (matrix[i][j] != 0):
            matrix[j][i] = 0
            edge.append((matrix[i][j], i, j))


sorted_edge = sorted(edge, key=lambda x: x[0])
connected = set()   # список соединенных вершин
isolated = {}      # словарь списка изолированных групп вершин
skeleton = []      # список ребер остова

for r in sorted_edge:
    if r[1] not in connected or r[2] not in connected:  # проверка для исключения циклов в остове
        if r[1] not in connected and r[2] not in connected: # если обе вершины не соединены, то
            isolated[r[1]] = [r[1], r[2]]          # формируем в словаре ключ с номерами вершин
            isolated[r[2]] = isolated[r[1]]               # и связываем их с одним и тем же списком вершин
        else:
            if not isolated.get(r[1]):             # если в словаре нет первой вершины, то
                isolated[r[2]].append(r[1])        # добавляем в список первую вершину
                isolated[r[1]] = isolated[r[2]]           # и добавляем ключ с номером первой вершины
            else:
                isolated[r[1]].append(r[2])        # иначе, все то же самое делаем со второй вершиной
                isolated[r[2]] = isolated[r[1]]

        skeleton.append(r)             # добавляем ребро в остов
        connected.add(r[1])             # добавляем вершины в множество соединённых
        connected.add(r[2])

for r in sorted_edge:    # проходим по ребрам второй раз и объединяем разрозненные группы вершин
    if r[2] not in isolated[r[1]]:     # если вершины принадлежат разным группам, то объединяем
        skeleton.append(r)             # добавляем ребро в остов
        gr1 = isolated[r[1]]
        isolated[r[1]] += isolated[r[2]]      # объединем списки двух групп вершин
        isolated[r[2]] += gr1

print(skeleton)

out_f = open(sys.argv[1], 'w')
buf = str()
out_f.write(str(sz) + '\n')
for i in range(sz):
    for j in range(sz):
        out_f.write(str(copy_matrix[i][j]) + ' ')
    out_f.write('\n')
out_f.write("Colors_Edges:\n")

for i in range(sz):
    for j in range(sz):
        for one_edge in skeleton:
            if (one_edge[1] == i) and (one_edge[2] == j) and (copy_matrix[i][j] != 0):
                out_f.write(str(one_edge[1]) + ' ' + str(one_edge[2]) + ' ' + "Yellow\n")
            else:
                if (one_edge[1] == j) and (one_edge[2] == i) and (copy_matrix[j][i] != 0):
                    out_f.write(str(one_edge[2]) + ' ' + str(one_edge[1]) + ' ' + "Yellow\n")


out_f.close()
