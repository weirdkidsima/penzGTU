// circtor.cpp
// графические объекты "круг" и конструкторы
// для функций консольной графики
#include "msoftcon.h"

class circle
{
protected:
    int xCo, yCo;           // координаты центра
    int radius;             // радиус круга
    color fillcolor;        // цвет
    fstyle fillstyle;       // стиль заполнения

public:
    // конструктор
    circle(int x, int y, int r, color fc, fstyle fs) :
        xCo(x), yCo(y), radius(r), fillcolor(fc), fillstyle(fs)
    {
    }

    void draw()             // рисование круга
    {
        set_color(fillcolor);         // установка цвета
        set_fill_style(fillstyle);    // установка стиля заполнения
        draw_circle(xCo, yCo, radius); // вывод круга на экран
    }
};

int main()
{
    init_graphics();        // инициализация графики

    // создание кругов
    circle c1(0, 0, 10, cWHITE, O_FILL);
    circle c2(20, 20, 5, cBLACK, MEDIUM_FILL);
    circle c3(40, 40, 7, cMAGENTA, O_FILL);

    // рисование кругов
    c1.draw();
    c2.draw();
    c3.draw();

    set_cursor_pos(1, 25);  // левый нижний угол
    return 0;
}
