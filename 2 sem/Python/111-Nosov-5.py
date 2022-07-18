"""
Носов Александр М8О-111Б-20 Лаба №5 Фигуры

Рисование геометрических фигур на месте кликов
Обработка клавиш
Буфферизация
"""

from PyQt5 import QtWidgets, QtGui, QtCore
import sys


class RedFacedLabel(QtWidgets.QLabel):
    def __init__(self):
        super().__init__()

        self.m_ptPosition = None
        self.painter = QtGui.QPainter()

        self.pic = QtGui.QPicture()
        self.painter.begin(self.pic)  # работа с буфером.
        self.painter.save()
        self.setMouseTracking(True)

        self.graph_objects = []
        self.clicked_coordinates = None

        self.is_new_figure = False
        self.type_of_figure = "Ellipse"  # вид фигуры
        self.do_move = False  # флаг для передвижения фигуры
        self.last_added = ""  # Фигура, которая была добавленная последней

        self.massive_of_ellipse = []  # массив кругов
        self.massive_of_square = []  # массив квадратов
        self.massive_of_rect = []   # массив прямоугольников

        self.painter.setBrush(QtGui.QBrush(QtCore.Qt.white))
        self.painter.setPen(QtGui.QPen(QtCore.Qt.black))
        self.painter.restore()
        self.painter.end()

    def mousePressEvent(self, mev):
        if self.do_move is False:  # если в этот момент нет передвижения
            point_coords = mev.pos()

            if self.type_of_figure == "Square":
                self.massive_of_square.append((point_coords.x(), point_coords.y()))
                self.last_added = "Square"

            elif self.type_of_figure == "Ellipse":
                self.massive_of_ellipse.append((point_coords.x(), point_coords.y()))
                self.last_added = "Ellipse"

            elif self.type_of_figure == "Rect":
                self.massive_of_rect.append((point_coords.x(), point_coords.y()))
                self.last_added = "Rect"

            self.is_new_figure = True
            self.repaint()

    def mouseMoveEvent(self, mev):
        if self.do_move:  # если в этот момент нет передвижения
            if self.last_added == "Square" and len(self.massive_of_square):
                # передвигает последнюю добавленную фигуру (квадрат)
                self.massive_of_square.pop()
                self.massive_of_square.append((mev.x(), mev.y()))
                self.redraw_all_picture()

            elif self.last_added == "Ellipse" and len(self.massive_of_ellipse):
                # передвигает последнюю добавленную фигуру (круг)
                self.massive_of_ellipse.pop()
                self.massive_of_ellipse.append((mev.x(), mev.y()))
                self.redraw_all_picture()

            elif self.last_added == "Rect" and len(self.massive_of_rect):
                # передвигает последнюю добавленную фигуру (прямоугольник)
                self.massive_of_rect.pop()
                self.massive_of_rect.append((mev.x(), mev.y()))
                self.redraw_all_picture()

    def keyPressEvent(self, ev):
        if ev.key() == QtCore.Qt.Key_Space and self.do_move is False:
            # при нажатии на пробел, меняется тип фигуры
            if self.type_of_figure == "Square":
                self.type_of_figure = "Rect"

            elif self.type_of_figure == "Ellipse":
                self.type_of_figure = "Square"

            elif self.type_of_figure == "Rect":
                self.type_of_figure = "Ellipse"

        elif ev.key() == QtCore.Qt.Key_Shift:
            # Клавиша шивт начинает/останавливает передвижение объекта
            if self.do_move:
                self.do_move = False
            else:
                self.do_move = True

    def paintEvent(self, ev):
        super().paintEvent(ev)
        if self.is_new_figure:
            picture_buffer = QtGui.QPicture()
            self.painter.begin(picture_buffer)
            self.painter.drawPicture(0, 0, self.pic)
            self.painter.setBrush(QtGui.QBrush(QtCore.Qt.red))

            if self.type_of_figure == "Ellipse":  # рисует круг
                self.painter.drawEllipse(self.massive_of_ellipse[-1][0] - 30,
                                         self.massive_of_ellipse[-1][1] - 30, 60, 60)
            elif self.type_of_figure == "Rect":  # рисует прямоугольник
                self.painter.drawRect(self.massive_of_rect[-1][0] - 60,
                                      self.massive_of_rect[-1][1] - 30, 120, 60)
            elif self.type_of_figure == "Square":  # рисует квадрат
                self.painter.drawRect(self.massive_of_square[-1][0] - 30,
                                      self.massive_of_square[-1][1] - 30, 60, 60)

            self.painter.save()
            self.painter.end()
            self.is_new_figure = False
            self.pic = picture_buffer

        self.painter.begin(self)
        self.painter.drawPicture(0, 0, self.pic)
        self.painter.end()

    def redraw_all_picture(self):
        self.painter.begin(self.pic)
        self.painter.setBrush(QtGui.QBrush(QtCore.Qt.red))
        for x, y in self.massive_of_ellipse:  # перерисовывает круги
            self.painter.drawEllipse(x - 30, y - 30, 60, 60)

        for x, y in self.massive_of_rect:  # перерисовывает прямоугольники
            self.painter.drawRect(x - 60, y - 30, 120, 60)

        for x, y in self.massive_of_square:  # перерисовывает квадраты
            self.painter.drawRect(x - 30, y - 30, 60, 60)

        self.painter.end()
        self.repaint()


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    label = RedFacedLabel()
    label.showMaximized()
    sys.exit(app.exec_())