#include "infowidget.h"
#include <QMessageBox>

Infowidget::Infowidget()
{
    btn_about_program = new QPushButton(this);
    btn_about_author = new QPushButton(this);

    btn_about_program->setText("О программе");
    btn_about_author->setText("Об авторе");

    btn_about_program->setGeometry(100, 25, 200, 75);
    btn_about_author->setGeometry(100, 175, 200, 75);
    connect(btn_about_program, SIGNAL(clicked()), this, SLOT(program_info()));
    connect(btn_about_author, SIGNAL(clicked()), this, SLOT(author_info()));
}

void Infowidget::program_info()
{
    QMessageBox::information(this, "О программе", "<h4>1 строка:</h4>"
"<p>1 картинка - оригинал изображения</p>"
"<p>2 картинка - негатив изображение</p>"
"<p>3 картинка - яркостная карта изображения</p>"
"<p>4 картинка - эквализированное по гистограмме изображение</p>"
"<h4>2 строка:</h4>"
"<p>1 картинка, цвета ниже порога на которой закрашиваются цветом, выбранным в модуле справа</p>"
"<p>2 - модуль управления 1 картинкой</p>"
"<p>3 картинка - гистограмма яркостной карты(которая над ней)</p>"
"<p>4 - информационный модуль</p>"
"<h4>3 строка:</h4>"
"<p>1 картинка получена путём логорифмического преобразования яркости</p>"
"<p>2 картинка получена путём экспоненциального преобразования яркости</p>"
"<p>3 картинка получена путём кусочно-линейного преобразования яркости</p>"
"<p>4 картинка получена путём приведения гистограммы изображения к нормальному распределению с заданным математическим ожиданием и дисперсией</p>");

}

void Infowidget::author_info()
{
    QMessageBox::information(this, "Об авторе", "Программа сделана студентом группы М8О-211Б-20 Носовым Александром");
}
