#include "stdafx.h"
#include "Converter.h"

struct danerzymskie {
	int wartosc;
	std::string rzymska;
	//char const* rzymska;
};
std::vector<danerzymskie>wektor
{
{ 1000, "M" },
{ 900, "CM" },
{ 500, "D" },
{ 400, "CD" },
{ 100, "C" },
{ 90, "XC" },
{ 50, "L" },
{ 40, "XL" },
{ 10, "X" },
{ 9, "IX" },
{ 5, "V" },
{ 4, "IV" },
{ 1, "I" },
{ 0, /*NULL*/ }
};

int Converter::Roman_To_Arabic(std::string string)
{

	int wynik = 0;
	auto sizestr = std::size(string);
	bool skip = false;

	for (int i = 0; i < sizestr; i++) {
		std::string test;
		std::string test1;
		test += string[i];
		test1 += string[i];
		if (i < sizestr - 1) {
			test += string[i + 1];
			for (int g = 0; g < size(wektor); g++) {
				if (wektor.at(g).rzymska == test) {
					wynik += wektor.at(g).wartosc;
					i++;
					skip = true;
				}
			}
			if (skip == false) {
				for (int h = 0; h < size(wektor); h++) {
					if (wektor.at(h).rzymska == test1) {
						wynik += wektor.at(h).wartosc;
					}
				}
			}
		}
		else {
			for (int u = 0; u < size(wektor); u++) {
				if (wektor.at(u).rzymska == test1) {
					wynik += wektor.at(u).wartosc;
				}
			}
		}
		skip = false;
	}


	return wynik;
}

std::string Converter::Arabic_To_Roman(int x)
{
	std::string result;
	int liczba = x;
	for (int i = 0; i < size(wektor); i++)
	{
		if (wektor.at(i).wartosc <= liczba) {
			result.append(wektor.at(i).rzymska);
			liczba -= wektor.at(i).wartosc;
			i--;
		}
		if (liczba == 0) {
			i = 2137;
		}
	}
	return result;
}
