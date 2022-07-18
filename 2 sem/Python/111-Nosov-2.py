"""
Носов Александр М8О-111Б-20
Задание №2

Создать класс на основе QWidget.
Добавить в него горизонтальный менеджер размещения (QHBoxLayout).
В последний добавить два вертикальных менеджера размещения (QVBoxLayout).

"""

from PyQt5.QtWidgets import (QWidget, QPushButton, QHBoxLayout, QVBoxLayout, QApplication)
import sys


class Columns(QWidget):
    def __init__(self):
        super().__init__()
        self.count = 0
        self.flag = False
        self.setWindowTitle("3 Columns")
        self.setGeometry(760, 390, 400, 300)

        self.hbox = QHBoxLayout()
        self.vbox_l = QVBoxLayout()
        self.vbox_r = QVBoxLayout()

        self.hbox.addLayout(self.vbox_l)
        self.hbox.addLayout(self.vbox_r)
        self.setLayout(self.hbox)
        self.do_buttons()

    def do_buttons(self):
        self.btn_l = QPushButton("Добавить в левый")
        self.btn_r = QPushButton("Добавить в правый")
        self.btn_replace = QPushButton("Перемещение")
        self.btn_buf = QPushButton("")

        self.vbox_l.addWidget(self.btn_l)
        self.vbox_r.addWidget(self.btn_r)
        self.hbox.addWidget(self.btn_replace)

        self.btn_l.clicked.connect(self.left_click)
        self.btn_r.clicked.connect(self.right_click)
        self.btn_replace.clicked.connect(self.swap)

        self.show()

    def left_click(self):
        self.btn_buf = QPushButton(str(self.count))
        self.vbox_l.addWidget(self.btn_buf)
        self.flag = False
        self.count += 1

    def right_click(self):
        self.btn_buf = QPushButton(str(self.count))
        self.vbox_r.addWidget(self.btn_buf)
        self.flag = True
        self.count += 1

    def swap(self):
        if not self.flag:
            self.vbox_l.removeWidget(self.btn_buf)
            self.vbox_r.addWidget(self.btn_buf)
        elif self.flag:
            self.vbox_r.removeWidget(self.btn_buf)
            self.vbox_l.addWidget(self.btn_buf)


if __name__ == "__main__":
    app = QApplication(sys.argv)

    window = Columns()

    sys.exit(app.exec_())
