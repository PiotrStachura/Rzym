// Rzym.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Rzym.h"
#include <vector>
#include <cstring>
#include <algorithm>

int main()
{
	std::cout << "Witamy, prosze wpisac kalulacje jaka ma byc wykonana w jednej lini(za dzielenie przyjmuje znak /, za mnozenie *)"<<"\n";
	std::string one;
	std::cin >> one;
	int x = Calculator::Calculate_string(one);
	std::cout << "Wynik w formacie arabskim:"<<"\n";
	std::cout << x << "\n";
	std::cout << "Wynik w formacie rzymskim:" << "\n";
	std::cout << Converter::Arabic_To_Roman(x) << "\n";
    return 0;
}


