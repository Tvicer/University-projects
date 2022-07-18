"""
Носов Александр М8О-111Б-20
Задание №3

Калькулятор

Генерировать клавиши от 0 до 9.
Выражения можно вводить с клавиатуры в самой строке или с кнопок калькулятора.
Использовать QGridLayout.

"""
from PyQt5.QtWidgets import QWidget, QApplication, QVBoxLayout, QGridLayout, QPushButton, QLabel, QLineEdit
from PyQt5 import QtCore, QtGui
import sys


class MainCalculator(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle('Awesome calculator')

        self.flag_z = True          # флаг для правильного вывода строки в QLabel
        self.buf_string = ""
        self.label = QLabel()
        self.label.setAlignment(QtCore.Qt.AlignRight)
        self.label.setFont(QtGui.QFont('Times', 10))
        self.input_field = QLineEdit()
        #self.mapper = None

        self.vbox = QVBoxLayout()
        self.setLayout(self.vbox)
        self.vbox.addWidget(self.label)
        self.vbox.addWidget(self.input_field)
        self.input_field.setAlignment(QtCore.Qt.AlignRight)
        grid = QGridLayout()
        self.__mapper = QtCore.QSignalMapper(self)

        for i in range(1, 10):
            btn = QPushButton(str(i))
            grid.addWidget(btn, (9 - i) // 3, (i - 1) % 3)
            btn.clicked.connect(self.__mapper.map)
            self.__mapper.setMapping(btn, i)

        btn = QPushButton("0")
        btn.clicked.connect(self.__mapper.map)
        self.__mapper.setMapping(btn, 0)
        self.__mapper.mapped['int'].connect(self.slot_button_clicked)
        grid.addWidget(btn, 3, 1)

        names = ["=", "+", "-", "*", "/", "C", "Del"]
        for i, name in enumerate(names, 3):
            btn = QPushButton(name)
            btn.clicked.connect(self.count_clicked)
            grid.addWidget(btn, i % 4, 2 + i // 4)

        self.vbox.addLayout(grid)

        self.show()

    def slot_button_clicked(self, num: int):
        if self.flag_z:
            self.input_field.setText(str(num))
            self.buf_string += str(num)
            self.flag_z = False
        else:
            self.input_field.setText(self.input_field.text() + str(num))
            self.buf_string += str(num)

    def count_clicked(self):
        button_text = self.sender().text()
        if button_text == "Del":
            self.input_field.setText('')
        elif button_text == "C":
            self.input_field.setText("0")
            self.buf_string = ""
            self.label.setText("")
        else:
            try:
                if button_text == "=":
                    self.label.setText(self.buf_string + " = ")
                    self.buf_string = str(eval(self.buf_string))
                    self.input_field.setText(self.buf_string)
                else:
                    self.buf_string = str(self.buf_string)
                    self.buf_string += button_text
                    self.label.setText(self.buf_string)
                    self.input_field.setText('')
                    self.flag_z = True

            except ZeroDivisionError:
                self.label.setText("You can't divide by zero!")
                self.input_field.setText("0")
                self.flag_z = True
                self.buf_string = ""

            except BaseException:
                self.label.setText("Wrong enter!")
                self.input_field.setText("0")
                self.flag_z = True
                self.buf_string = ""


if __name__ == '__main__':
    app = QApplication(sys.argv)
    win = MainCalculator()
    sys.exit(app.exec_())
