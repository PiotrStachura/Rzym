#include "stdafx.h"
#include "Calculator.h"

struct dane {
	std::string operacja;
	int wartosc;
};


int Calculator::Calculate_string(std::string string1)
{
	std::vector<dane>data;

	int koncowywynik = 0;

	char plus = '+';
	char minus = '-';
	char times = '*';
	char divided = '/';
	std::string copy;
	dane temp;
	dane temp1;

	for (int i = 0; i < size(string1); i++)
	{
		if (string1[i] != plus && string1[i] != minus && string1[i] != times && string1[i] != divided) {
			copy += string1[i];
		}
		else {
			temp.wartosc = Converter::Roman_To_Arabic(copy);
			data.push_back(temp);
			temp1.operacja = std::to_string(string1[i]);
			data.push_back(temp1);
			copy.clear();
			temp = {};
			temp1 = {};
		}
		if (i == size(string1) - 1) {
			temp.wartosc = Converter::Roman_To_Arabic(copy);
			data.push_back(temp);
		}
	}
	bool hasbendone = false; //calculation (division/multiplication) can be done only once and then again and again untill
	bool noneleft = false; //no more complex opertaions are left in the vector 
	do {
		for (int i = 1; i < size(data); i += 2) {
			if (data.at(i).operacja == "42" && hasbendone != true) { // mnozenie
				data.at(i - 1).wartosc = data.at(i - 1).wartosc*data.at(i + 1).wartosc;
				data.erase(data.begin() + i);
				data.erase(data.begin() + i);
				hasbendone=true;
				if (size(data) == 1) {
					i--; noneleft = true;
				}
			}
			if (i < size(data)) {
				if (data.at(i).operacja == "47" && hasbendone != true) { // dzielenie
					data.at(i - 1).wartosc = data.at(i - 1).wartosc / data.at(i + 1).wartosc;
					data.erase(data.begin() + i);
					data.erase(data.begin() + i);
					hasbendone = true;
				}
				if (size(data) == 1) {
					i--; noneleft = true;
				}
			}
		}
		hasbendone = false;
		for (int i = 1; i < size(data); i += 2) {
			if (data.at(i).operacja == "42" || data.at(i).operacja == "47") {
				noneleft = false;
				i = size(data)+1;
			}
			if (i==size(data)-2) {
				if (data.at(i).operacja != "42" || data.at(i).operacja != "47") {
					noneleft = true;
				}
			}
		}
	} while (noneleft != true);

	bool hasbendone2 = false; //again, in order to keep it simple all calculations happen once per iteration
	bool noneleft2 = false; //no adding or substracting is left, the code is finished
	do {
		for (int i = 1; i < size(data); i += 2) {
			if (data.at(i).operacja == "43" && hasbendone != true) { // dodawanie
				data.at(i - 1).wartosc = data.at(i - 1).wartosc+data.at(i + 1).wartosc;
				data.erase(data.begin() + i);
				data.erase(data.begin() + i);
				hasbendone = true;
				if (size(data) == 1) {
					i--; noneleft2 = true;
				}
			}
			if (i < size(data)) {
				if (data.at(i).operacja == "45" && hasbendone != true) { // odejmowanie
					data.at(i - 1).wartosc = data.at(i - 1).wartosc - data.at(i + 1).wartosc;
					data.erase(data.begin() + i);
					data.erase(data.begin() + i);
					hasbendone = true;
				}
				if (size(data) == 1) {
					i--; noneleft2 = true;
				}
			}
		}
		hasbendone = false;
		for (int i = 0; i < size(data); i++) {
			if (data.at(i).operacja == "43" || data.at(i).operacja == "45") {
				noneleft2 = false;
				i = size(data) + 1;
			}
			if (i == size(data) - 1) {
				if (data.at(i).operacja != "43" || data.at(i).operacja != "45") {
					noneleft2 = true;
				}
			}
		}
	} while (noneleft2 != true);
	return data.at(0).wartosc;
}
