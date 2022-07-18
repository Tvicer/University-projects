"""
Носов Александр М8О-111Б-20
Задание №1

Домик

Объявить класс окна, двери, корпуса и крыши.
Затем обявить класс домика хоббита, который будет принимать параметры его составляющих.

"""

from pyqtgraph.Qt import QtGui, QtCore
import pyqtgraph as pg
import sys


class HouseBase():  # Основание дома
    def __init__(self, a=10, x=0, y=0):
        self.a = a
        self.x = x
        self.y = y

        self.base = QtGui.QGraphicsRectItem(QtCore.QRectF(self.x, self.y, self.a, self.a))
        self.base.setPen(pg.mkPen(171, 171, 171, width=10))

    def draw(self, _view_box):
        self.base.setBrush(pg.mkBrush("w"))
        _view_box.addItem(self.base)


class RoofHouse():  # Крыша дома
    def __init__(self, base):
        self.a = base.a
        self.x = base.x
        self.y = base.y

        self.line = QtGui.QGraphicsLineItem(self.x, self.y + self.a, (self.x + self.a) / 2,
                                            self.a + (self.y + self.a) / 2)
        self.line.setPen(pg.mkPen(200, 100, 100, width=10))

        self.line2 = QtGui.QGraphicsLineItem(self.x + self.a, self.y + self.a, (self.x + self.a) / 2,
                                             self.a + (self.y + self.a) / 2)
        self.line2.setPen(pg.mkPen(200, 100, 100, width=10))

        self.line3 = QtGui.QGraphicsLineItem(self.x + self.a, self.y + self.a, self.x, self.y + self.a)
        self.line3.setPen(pg.mkPen(200, 100, 100, width=10))

    def draw(self, _view_box):
        _view_box.addItem(self.line)
        _view_box.addItem(self.line2)
        _view_box.addItem(self.line3)


class WindowHouse:  # Окно
    def __init__(self, base, dm=1):
        self.x = base.x
        self.y = base.y
        self.a = base.a
        self.dm = dm

        self.window = QtGui.QGraphicsEllipseItem(QtCore.QRectF((self.x + self.a) / 3 - dm / 2,
                                                               (self.y + self.a - dm) / 2, self.dm, self.dm))
        self.window.setPen(pg.mkPen(101, 67, 33, width=6))

        self.line = QtGui.QGraphicsLineItem((self.x + self.a) / 3 - dm / 2, (self.y + self.a) / 2,
                                            (self.x + self.a) / 3 + dm / 2,
                                            (self.y + self.a) / 2)
        self.line.setPen(pg.mkPen(101, 67, 33, width=6))

        self.line2 = QtGui.QGraphicsLineItem((self.x + self.a) / 3, (self.y + self.a - dm) / 2,
                                             (self.x + self.a) / 3, (self.y + self.a + dm) / 2)
        self.line2.setPen(pg.mkPen(101, 67, 33, width=6))

    def draw(self, _view_box):
        _view_box.addItem(self.window)
        _view_box.addItem(self.line)
        _view_box.addItem(self.line2)


class DoorHouse:  # Дверь
    def __init__(self, base):
        self.x = base.x
        self.y = base.y
        self.a = base.a

        self.door = QtGui.QGraphicsRectItem(
            QtCore.QRectF((self.x + self.a) / 1.5, self.y + 0.4, (self.x + self.a) / 3 - 0.4, (self.y + self.a) / 1.5))
        self.door.setPen(pg.mkPen(101, 67, 33, width=8))

        self.line = QtGui.QGraphicsLineItem((self.x + self.a) / 1.5, (self.y + self.a) / 2.5,
                                            (self.x + self.a) / 1.35, (self.y + self.a) / 2.5)
        self.line.setPen(pg.mkPen(101, 67, 33, width=7))

    def draw(self, _view_box):
        _view_box.addItem(self.door)
        _view_box.addItem(self.line)


class House:
    def __init__(self, vb1):
        self.vb = vb1

        self.base = HouseBase(a=10, x=0, y=0)
        self.roof = RoofHouse(base=self.base)
        self.window = WindowHouse(base=self.base, dm=4)
        self.door = DoorHouse(base=self.base)

    def build(self):
        self.base.draw(_view_box=self.vb)
        self.roof.draw(_view_box=self.vb)
        self.window.draw(_view_box=self.vb)
        self.door.draw(_view_box=self.vb)


def applicaton():
    app = QtGui.QApplication([])
    win = pg.PlotWidget()
    win.resize(1000, 600)
    vb = win.getViewBox()
    vb.setAspectLocked(1.0)

    hse = House(vb1=vb)
    hse.build()

    win.show()
    sys.exit(app.exec_())


if __name__ == "__main__":
    applicaton()
