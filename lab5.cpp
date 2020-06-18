#include <string>

#include <iostream>

#include <fstream>

#include <sstream>

#include <algorithm>

using namespace std;

struct smth {

	float s = 0;

	string nazvanie = " ";

	string ves = " ";

	int kalorii = 0;

};

bool cmpByNazvanie(const smth& r1, const smth& r2)

{

	return r1.nazvanie < r2.nazvanie;

}

int main()

{

	setlocale(LC_ALL, "rus");

	string x;

	smth s;

	ifstream file;
	file.open("C:\\Users\\Gacevich\\Desktop\\file.txt");

	int len(0);

	if (file.is_open()) {

		while (!file.eof()) {

			string s;

			getline(file, s);

			len++;

		}

	}

	smth* arr = new smth[len];

	file.seekg(0, ios_base::beg);

	for (size_t i = 0; i < len; i++)

	{

		getline(file, x);

		istringstream iss(x);

		iss >> s.s >> s.nazvanie >> s.ves >> s.kalorii;

		arr[i] = s;

	}

	cout << "Информация о всех видах сладостей: \n" << endl;

	for (size_t n = 0; n < len; n++)

	{

		cout << "Срок : " << arr[n].s << " "

			<< "Название : " << arr[n].nazvanie << " "

			<< "Вес : " << arr[n].ves << " "

			<< "Калории : " << arr[n].kalorii << endl;

	}

	cout << "\nСколько бисквитных пирожных осталось на складе :\n" << endl;

	for (size_t n = 0; n < len; n++)

	{
	
		if (arr[n].ves != "0" && arr[n].nazvanie == "Biskvit")

		{

			cout << "Вес : " << arr[n].ves << endl;

		}

	}

	cout << "\nИнформация о сладостях, килограмм которых не превышает 400 Ккал:\n" << endl;

	sort(arr, arr + len, cmpByNazvanie);

	for (size_t n = 0; n < len; n++)

	{

		if ((arr[n].kalorii)*10 < 400)

		{

			cout << "Срок : " << arr[n].s << " "

				<< "Название : " << arr[n].nazvanie << " "

				<< "Вес : " << arr[n].ves << " "

				<< "Калории : " << arr[n].kalorii << endl;

		}

	}

	file.close();

}