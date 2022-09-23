﻿#include <iostream> // консоль - cout

class Figura
{
private:
    unsigned int qtySide;           // число сторон фигуры

public:
    Figura() { qtySide = 0; }       // конструктор по умолчанию
    Figura(int n) { setData(n); }   // конструктор с параметрами

    bool setData(int n)
    {
        if (n <= 0) return false;
        qtySide = static_cast<unsigned int>(n);
        return true;
    }
    unsigned int getData() { return qtySide; }
};

class Triangle : public Figura
{
public:
    // конструктор по умолчанию запускает конструктор родителя с параметрами
    Triangle() : Figura(3) { ; }
};

class Quad : public Figura
{
public:
    // конструктор по умолчанию, вносит изменения в переменную qtySide через сеттер
    Quad() { setData(4); }
};

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");   // задаём русский текст
    system("chcp 1251");            // настраиваем кодировку консоли
    std::system("cls");

    std::cout << "Задача 1. Фигуры. Количество сторон\n"
              << "-----------------------------------\n\n";

    Figura fig;
    Triangle tri;
    Quad quad;

    std::cout << "Количество сторон:" << std::endl
              << "Фигура: " << fig.getData() << std::endl
              << "Треугольник: " << tri.getData() << std::endl
              << "Четырёхугольник: " << quad.getData() << std::endl;

    return 0;
}


/*
В этом задании вы построите первую простую иерархию классов для заданной предметной области.

Предметная область выглядит следующим образом: есть сущность фигура. Фигуры бывают двух типов:
треугольник и четырёхугольник. У фигуры есть количество сторон. Для неизвестной фигуры будем
считать это количество равным нулю. У треугольника три стороны, у четырёхугольника четыре стороны.
У любой фигуры мы хотим узнавать количество её сторон, но мы не должны быть способны изменить
количество сторон для заданной фигуры извне.

Задача: спроектировать и реализовать классы, описывающие предметную область. Продемонстрируйте их работу:
создайте по одному экземпляру каждого класса и выведите информацию о количестве его сторон на консоль.

Пример работы программы
Консоль
Количество сторон:
Фигура: 0
Треугольник: 3
Четырёхугольник: 4
*/