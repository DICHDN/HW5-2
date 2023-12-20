/*
Задача 2. Фигуры. Стороны и углы
В этом задании вы усложните иерархию классов для усложнённой предметной области.

У вас появляется информация о длине сторон и углах ваших фигур, а также несколько более конкретных фигур. Теперь в треугольнике вы должны хранить информацию о длине всех его трёх сторон (a, b, c) и значениях его трёх углов (A, B, C). В четырёхугольнике вы храните информацию о длине его четырёх сторон (a, b, c, d) и значениях его четырёх углов (A, B, C, D).

Также у вас появляются более конкретные фигуры:

прямоугольный треугольник (угол C всегда равен 90);
равнобедренный треугольник (стороны a и c равны, углы A и C равны);
равносторонний треугольник (все стороны равны, все углы равны 60);
прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
квадрат (все стороны равны, все углы равны 90);
параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
ромб (все стороны равны, углы A,C и B,D попарно равны).
Вы должны иметь возможность узнать у каждой фигуры длины её сторон и значения её углов, но извне вы не должны быть способны изменить длины сторон и углы.

Не должно быть возможности создать фигуры, не удовлетворяющие перечисленным условиям. Например, нельзя создать квадрат с разными углами. Геометрические соотношения проверять не нужно. Например, сумма углов в треугольнике может быть не равна 180.

Задача: спроектировать и реализовать классы, описывающие предметную область. Продемонстрируйте их работу: создайте по одному экземпляру каждой фигуры и выведите на экран информацию о длинах её сторон и величине её углов. Значения используйте произвольные.

Инициализацию длин сторон и величин углов нужно выполнить с помощью вызова базовых конструкторов.

Для вывода информации о фигуре создайте функцию print_info, которая будет принимать в качестве аргумента указатель на базовый класс фигуры.

Пример работы программы
Консоль
Треугольник:
Стороны: a=10 b=20 c=30
Углы: A=50 B=60 C=70

Прямоугольный треугольник:
Стороны: a=10 b=20 c=30
Углы: A=50 B=60 C=90

Равнобедренный треугольник:
Стороны: a=10 b=20 c=10
Углы: A=50 B=60 C=50

Равносторонний треугольник:
Стороны: a=30 b=30 c=30
Углы: A=60 B=60 C=60

Четырёхугольник:
Стороны: a=10 b=20 c=30 d=40
Углы: A=50 B=60 C=70 D=80

Прямоугольник:
Стороны: a=10 b=20 c=10 d=20
Углы: A=90 B=90 C=90 D=90

Квадрат:
Стороны: a=20 b=20 c=20 d=20
Углы: A=90 B=90 C=90 D=90

Параллелограмм:
Стороны: a=20 b=30 c=20 d=30
Углы: A=30 B=40 C=30 D=40

Ромб:
Стороны: a=30 b=30 c=30 d=30
Углы: A=30 B=40 C=30 D=40
*/


#include <iostream>
#include <windows.h>
#include <string>

class figura
{
protected:
    int field1;
    std::string name;
public:
    figura()
    {
        this->field1 = 0;
        this->name = "точка";
    }
    int get_sides_count()
    {
        return field1;
    }
    std::string get_name()
    {
        return name;
    }
    virtual void get_info()
    {
        std::cout << "Простая фигура с количеством сторн " << field1 << " - это " << name << std::endl;
    }
};
class triangle : public figura
{
protected:
    int a=10, b=20, c=30;
    int A=30, B=70, C=80;
public:
    triangle()
    {
        this->field1 = 3;
        this->name = "треугольник";
    }
    void get_info() override
    {
        std::cout << "Простая фигура с количеством сторн " << field1 << " - это " << name << std::endl;
        std::cout << "Стороны а=" << a << ", b=" << b << ", c=" << c << std::endl;
        std::cout << "Углы A=" << A << ", B=" << B << ", C=" << C << std::endl;
    }
};
class quadrilateral : public figura
{
protected:
    int a=10, b=20, c=30, d=40;
    int A=30, B=40, C=50, D=60;
public:
    quadrilateral()
    {
        this->field1 = 4;
        this->name = "четырехугольник";
    }
    void get_info() override
    {
        std::cout << "Простая фигура с количеством сторн " << field1 << " - это " << name << std::endl;
        std::cout << "Стороны а=" << a << ", b=" << b << ", c=" << c << ", d=" << d << std::endl;
        std::cout << "Углы A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << std::endl;
    }
};
class triangle90 : public triangle
{
public:
    triangle90()
    {
        this->field1 = 3;
        this->name = "прямоугольный треугольник";
        this->C = 90;
    }
};

class isosceles_triangle :public triangle
{
public:
    isosceles_triangle()
    {
        this->field1 = 3;
        this->name = "равнобедренный треугольник";
        this->c = a;
        this->C = A;
    }
};
class equilateral_triangle : public triangle
{
public:
    equilateral_triangle()
    {
        this->field1 = 3;
        this->name = "равносторонний треугольник";
        this->A = 60;
        this->c = a;
        this->b = a;
        this->C = A;
        this->B = A;
    }
};

class rectangle : public quadrilateral
{
public:
    rectangle()
    {
        this->name = "прямоугольник";
        this->c = a;
        this->d = b;
        this->A = 90;
        this->B = A;
        this->C = A;
        this->D = A;
    }
    
};
class square : public rectangle
{
public:
    square()
    {
        this->name = "квадрат";
        this->c = a;
        this->b = a;
        this->d = a;
        this->A = 90;
        this->B = A;
        this->C = A;
        this->D = A;
    }    
    
};
class parallelogram : public quadrilateral
{
public:
    parallelogram()
    {
        this->name = "параллелограмм";
        this->c = a;
        this->d = b;
        this->C = A;
        this->D = B;
    }
    
};
class rhomb : public parallelogram
{
public:
    rhomb()
    {
        this->name = "ромб";
        this->c = a;
        this->b = a;
        this->d = b;
        this->C = A;
        this->D = B;
    }
    
};

void print_info(figura* a)
{
        a->get_info();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    figura dot;
    triangle tri;
    quadrilateral quadro;
    triangle90 tri1;
    isosceles_triangle tri2;
    equilateral_triangle tri3;
    rectangle quadro1;
    square quadro2;
    parallelogram quadro3;
    rhomb quadro4;

    print_info(&tri);
    print_info(&tri1);
    print_info(&tri2);
    print_info(&tri3);
    print_info(&quadro);
    print_info(&quadro1);
    print_info(&quadro2);
    print_info(&quadro3);
    print_info(&quadro4);

    return 0;
}