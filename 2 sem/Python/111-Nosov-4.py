"""
Носов Александр М8О-111Б-20 Лаба №4 Змейка
"""

from pyqtgraph.Qt import QtGui, QtCore, QtWidgets
import pyqtgraph as pg
import sys
import random


class Snake(QtWidgets.QWidget):
    def __init__(self, parent, _vb):
        super().__init__(parent=parent)

        self.vb = _vb
        self.was = -1  # для начала проверки передвижения
        self.body = []
        self.coord = [[0, 0], [1, 0], [2, 0], [3, 0], [4, 0]]

        for i in range(5):
            rectangle = QtGui.QGraphicsRectItem(QtCore.QRectF(0, 0, 1, 1))
            rectangle.setPen(pg.mkPen(255, 0, 0))
            rectangle.setBrush(pg.mkBrush(255, 0, 0))
            self.body.append(rectangle)
            self.vb.addItem(rectangle)

        self.draw()
        self.direction = None

    def draw(self):
        for rect, crd in zip(self.body, self.coord):
            rect.setPos(QtCore.QPointF(crd[0], crd[1]))

    def keyPressEvent(self, ev):
        if ev.key() == QtCore.Qt.Key_Right:
            if self.direction != "left":
                self.direction = "right"
                self.was += 1
                ev.accept()
            return
        elif ev.key() == QtCore.Qt.Key_Left:
            if self.direction != "right":
                self.direction = "left"
                self.was += 1
                ev.accept()
            return
        elif ev.key() == QtCore.Qt.Key_Down:
            if self.direction != "up":
                self.direction = "down"
                self.was += 1
                ev.accept()
            return
        elif ev.key() == QtCore.Qt.Key_Up:
            if self.direction != "down":
                self.direction = "up"
                self.was += 1
                ev.accept()
            return
        elif ev.key() == QtCore.Qt.Key_Space:
            ev.ignore()
            print("Pause")
            return
        ev.ignore()

    def move(self, fruit, timer):
        if self.direction is None:
            return

        if self.direction == "right":
            self.body[-1].moveBy(1, 0)
        elif self.direction == "up":
            self.body[-1].moveBy(0, 1)
        elif self.direction == "down":
            self.body[-1].moveBy(0, -1)
        elif self.direction == "left":
            self.body[-1].moveBy(-1, 0)

        self.look_alive(timer)  # проверка на врезание в себя

        self.coord.append([self.body[-1].pos().x(), self.body[-1].pos().y()])

        for crd in self.coord:  # проверка пересечения с фруктом
            if crd[0] == fruit.pos().x() and crd[1] == fruit.pos().y():
                print("Fruit")
                rectangle = QtGui.QGraphicsRectItem(QtCore.QRectF(0, 0, 1, 1))
                rectangle.setPen(pg.mkPen(255, 0, 0))
                rectangle.setBrush(pg.mkBrush(255, 0, 0))
                self.body.append(rectangle)
                self.vb.addItem(rectangle)
                fruit.draw(random.randint(-40, 40),
                           random.randint(-40, 40))  # новый фрукт
                self.draw()
                return
        self.coord = self.coord[1:]
        self.draw()

    def look_alive(self, timer):  # проверяет змейку на столкновение с собой
        for crd in self.coord:
            if self.was and self.body[-1].pos().x() == crd[0] and self.body[-1].pos().y() == crd[1]:
                print("Game over :(")
                timer.stop()
                return


class Fruit(QtGui.QGraphicsRectItem):  # класс фрукта
    def __init__(self, _vb):
        super().__init__(QtCore.QRectF(0, 0, 1, 1))
        self.setPen(pg.mkPen(255, 0, 0))
        self.setBrush(pg.mkBrush(255, 0, 0))
        _vb.addItem(self)
        self.draw()

    def draw(self, x=-20, y=-20):  # рисует фрукт
        self.setPos(x, y)


class Game(QtGui.QMainWindow):

    def __init__(self):
        super().__init__()

        self.setWindowTitle('Snake')
        self.show()
        self.resize(800, 600)
        self.gw = pg.PlotWidget()
        self.setCentralWidget(self.gw)
        self.vb = self.gw.getPlotItem().getViewBox()

        self.t = QtCore.QTimer()
        self.t.timeout.connect(self.update)
        self.t.start(50)

        self.field = QtGui.QGraphicsRectItem(QtCore.QRectF(-50, -50, 100, 100))
        self.field.setPen(pg.mkPen(255, 0, 0))
        self.field.setBrush(pg.mkBrush(27, 102, 34))

        self.vb.addItem(self.field)
        self.snake = Snake(parent=self, _vb=self.vb)
        self.snake.grabKeyboard()
        self.fruit = Fruit(_vb=self.vb)  # фрукт

    def update(self):
        self.snake.move(fruit=self.fruit, timer=self.t)
        position = self.snake.body[-1].pos()

        if not (50 > position.x() > -50
                and 50 > position.y() > -50):  # выход за границу
            print("Game over...")
            self.t.stop()

    def keyPressEvent(self, ev):
        if ev.key() == QtCore.Qt.Key_Space:
            print("Space in main window!")
            if self.t.isActive():
                self.t.stop()
            else:
                self.t.start(50)
            ev.accept()
            return
        ev.ignore()


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)

    game = Game()

    sys.exit(app.exec_())
