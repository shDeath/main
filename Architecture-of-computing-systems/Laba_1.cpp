﻿#include <iostream> // подключаем библиотеку с функциями ввода-вывода (printf, system)
using namespace std;
int main() // обычный код на C++
{
	setlocale(LC_ALL, "RU");
	cout << R"(Лабараторная №1. Вариант: 4   Y = a+b-c-d                           
Выполнил Ахмедов Шамиль студент 2 курса группы ДИНРБ-21/1
	)" <<endl;
	int a=9; // объявляем переменную a и кладем туда значение 9
	int b=3; // объявляем переменную b и кладем туда значение 3
	int c=6; // объявляем переменную c и кладем туда значение 6
	int d=3; // объявляем переменную d и кладем туда значение 3
	int y; // объявляем переменную y, но не инициализируем ее

	// далее идет ассемблерная вставка -------------------------------------------
	__asm 
		{ // начало ассемблерной вставки
			mov eax,a // загружаем значение переменной a в регистр EAX
			add eax,b // складываем a с b, записывая результат в EAX
			mov ecx,c // загружаем значение переменной a в регистр ECX
			mov edx,d // загружаем значение переменной a в регистр EDX
			sub eax,ecx // eax = eax - ecx
			sub eax,edx // eax = eax - edx
			mov y,eax  // загружаем значение EAX в переменную y
		}// конец ассемблерной вставки ------------------------------------------ 
	 
	 // далее следует снова обычный код на C++
	 // выводим содержимое y на экран с помощью Сишной функции printf
	cout << "Assembler: \n";
	printf("a + b - c - d = %d + %d - %d - %d = %d\n", a, b, c,d,y);
	// Вычисление на C++ для проверки правильности кода на Ассемблере
	y = a + b - c - d;
	cout << "\nProverka na c++\n";
	printf("a  b - c - d = %d + %d - %d - %d = %d\n", a, b, c, d, y);
	system("pause");
	return 0;
}