// Lab_9_3.cpp
// < Кузів Назар >
// Лабораторна робота № 9.3
// Опрацювання масиву структур
// Варіант 6

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <fstream>


using namespace std;



struct Tovar
{
	string name;
	int price;
	int kilk;
	string mass;

};


void Create(Tovar* p, const int N);
void Print(Tovar* p, const int N);
void SortByName(Tovar* p, const int N);
void SortByPrice(Tovar* p, const int N);
void SearchByName(Tovar* p, const int N, const string name);
void PrintSerchByName(Tovar tmp);
void SearchByPrise(Tovar* p, const int N);
void SaveToFile(Tovar* p, const int N, const char* filename);
void LoadFromFile(Tovar*& p, int& N, const char* filename);
void Remove(Tovar* p, int& N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	string name;
	char filename[100];
	cout << "Введіть кількість товарів N: "; cin >> N;

	Tovar* p = new Tovar[N];
	
	int menuItem;
	do {
		cout << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - сортування по назві товару" << endl;
		cout << " [4] - сортування за загальною вартістю товару" << endl;
		cout << " [5] - пошук товару по назві" << endl;
		cout << " [6] - пошук товару по діапазону вартості" << endl;
		cout << " [7] - запис даних у файл" << endl;
		cout << " [8] - зчитування даних із файлу" << endl;
		cout << " [9] - вилучити товар" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			SortByName(p, N);
			break;
		case 4:
			SortByPrice(p, N);
			break;
		case 5:
			cin.get(); 
			cin.sync();
			cout << " Назва тавару : "; getline(cin, name);
			cout << endl;
			SearchByName(p, N, name);
			break;
		case 6:
		
			SearchByPrise(p, N);
			break;
		case 7:
			cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
			cin.sync();

			cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
			SaveToFile(p, N, filename);
			break;
		case 8:
			cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
			cin.sync();
			cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
			LoadFromFile(p, N, filename);
			break;
		case 9:
			Remove(p, N);
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);

	return 0;

}

void Create(Tovar* p, const int N)
{

	for (int i = 0; i < N; i++)
	{
		cout << " № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
		cout << " Назва : "; getline(cin, p[i].name);
		cout << " Оиниця вмірювання :"; getline(cin, p[i].mass);
		cout << " Ціна: "; cin >> p[i].price;
		cout << " Кількість: "; cin >> p[i].kilk;
		cout << endl;

	
	}
}
void Print(Tovar* p, const int N)
{
	cout << "==================================================================================="
		<< endl;
	cout << "                          Список товарів" << endl;

	cout << "==================================================================================="
		<< endl;
	cout << "|  № |      Назва    |  Ціна за од. (грн) | Кількість | Оиниця вмірювання |"
		<< endl;
	cout << "-----------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(13) << right << p[i].name << " "
			<< "| " << setw(18) << right << p[i].price << " "
			<< "| " << setw(9) << right << p[i].kilk << " "
			<< "| " << setw(19) << right << p[i].mass << " |"<<endl;
		

	}
	cout << "==================================================================================="
		<< endl;
	cout << endl;
}
void SortByName(Tovar* p, const int N)
{
	Tovar tmp;
	int Do;

	cout << "Виберіть дію:" << endl << endl;
	cout << " [1] - від А до Я" << endl;
	cout << " [2] - від Я до А" << endl;
	cout << "Введіть значення: "; cin >> Do;
	switch (Do)
	{
	case 1:
		for (int i0 = 0; i0 < N - 1; i0++)
			for (int i1 = 0; i1 < N - i0 - 1; i1++)
				if (p[i1].name > p[i1 + 1].name)
				{
					tmp = p[i1];
					p[i1] = p[i1 + 1];
					p[i1 + 1] = tmp;
				}
		break;
	case 2:
		for (int i0 = 0; i0 < N - 1; i0++)
			for (int i1 = 0; i1 < N - i0 - 1; i1++)
				if (p[i1].name < p[i1 + 1].name)
				{
					tmp = p[i1];
					p[i1] = p[i1 + 1];
					p[i1 + 1] = tmp;
				}
		break;

	default:
		cout << "Ви ввели помилкове значення! "
			"Слід ввести число - номер вибраного пункту меню" << endl;
	}
}
void SortByPrice(Tovar* p, const int N)
{
	Tovar tmp;
	int Do;

	cout << "Виберіть дію:" << endl << endl;
	cout << " [1] - від Більшої до Меншої ціни" << endl;
	cout << " [2] - від Меншої до Більшої ціни" << endl;
	cout << "Введіть значення: "; cin >> Do;
	switch (Do)
	{
	case 1:
		for (int i0 = 0; i0 < N - 1; i0++)
			for (int i1 = 0; i1 < N - i0 - 1; i1++)
				if ((p[i1].price* p[i1].kilk) < (p[i1+1].price * p[i1+1].kilk))
				{
					tmp = p[i1];
					p[i1] = p[i1 + 1];
					p[i1 + 1] = tmp;
				}
		break;
	case 2:
		for (int i0 = 0; i0 < N - 1; i0++)
			for (int i1 = 0; i1 < N - i0 - 1; i1++)
				if ((p[i1].price * p[i1].kilk) > (p[i1 + 1].price * p[i1 + 1].kilk))
				{
					tmp = p[i1];
					p[i1] = p[i1 + 1];
					p[i1 + 1] = tmp;
				}
		break;

	default:
		cout << "Ви ввели помилкове значення! "
			"Слід ввести число - номер вибраного пункту меню" << endl;
	}
}


void SearchByName(Tovar* p, const int N, const string name)
{
	int Left = 0, Right = N - 1, c;
	Tovar tmp;
	int i = 0;
	do {
		c = (Left + Right) / 2;
		if (p[c].name == name)
		{
			tmp.name = p[c].name;
			tmp.price = p[c].price;
			tmp.kilk = p[c].kilk;
			tmp.mass = p[c].mass;
			PrintSerchByName(tmp);
			i++;
			break;
		}
			

		if ((p[c].name < name))
		{
			Left = c + 1;
		}
		else
		{
			Right = c - 1;
		}

	} while (Left <= Right);

	if (i == 0)
	{
		cout << "Такого товару немає"<< endl;
	}
}
void PrintSerchByName(Tovar tmp)
{
	cout << "======================================================================="
		<< endl;
	cout << "                          Шуканий товар" << endl;

	cout << "======================================================================="
		<< endl;
	cout << "|      Назва    |  Ціна за од. (грн) | Кількість | Оиниця вмірювання  |"
		<< endl;
	cout << "-----------------------------------------------------------------------"
		<< endl;
	
	
		cout << "| " << setw(13) << right << tmp.name << " "
			<< "| " << setw(18) << right << tmp.price << " "
			<< "| " << setw(9) << right << tmp.kilk << " "
			<< "| " << setw(19) << right << tmp.mass << " |" << endl;


	
	cout << "========================================================================="
		<< endl;
	cout << endl;
}
void SearchByPrise(Tovar* p, const int N)
{
	
	int  j = 0;
	Tovar* tmp = new Tovar[N];
	int from, to;
	
	cout << "Введіть діапазон вартості: " << endl;
	cout << "Від: "; cin >> from;
	cout << "До: "; cin >> to;

	if (from < to)
	{
		for(int c =0 ; c < N; c++)
		{
			if ((p[c].price * p[c].kilk) >= from && (p[c].price * p[c].kilk)<=to)
			{
				tmp[j].name = p[c].name;
				tmp[j].price = p[c].price;
				tmp[j].kilk = p[c].kilk;
				tmp[j].mass = p[c].mass;

				++j;
				
			}
		} 

		if (j == 0)
			cout << "Такого товару немає)" << endl;
		else
		{
			Print(tmp, j);
		}
			

	}
	else
		cout << "Ви неаравильно ввели діапазон!!!" << endl;

	
}
void Remove(Tovar* p, int& N)
{
	int K = N-1;    
	string name;
	cin.get();
	cin.sync();
	cout << " введіть назва тавару, який хочете вилучити : "; getline(cin, name);

	Tovar* t = new Tovar[K];                    
	int j = 0;     

	for (int i = 0; i < N; i++)          
		if (name == p[i].name)
		{
			t[j+1].name = p[i].name;
			t[j+1].price = p[i].price;
			t[j+1].kilk = p[i].kilk;
			t[j+1].mass = p[i].mass;
		}
			

	delete[] p;                            
	p = t;                             
	N = K;                                   
}

void SaveToFile(Tovar* p, const int N, const char* filename)
{
	ofstream fout(filename, ios::binary); // відкрили бінарний файл запису
	
	fout.write((char*)&N, sizeof(N)); // записали кількість елементів
	
	for (int i = 0; i < N; i++)
		fout.write((char*)&p[i], sizeof(Tovar)); // записали елементи масиву
	
	fout.close(); // закрили файл
}
void LoadFromFile(Tovar*& p, int& N, const char* filename)
{
	delete[] p; // знищили попередні дані

	ifstream fin(filename, ios::binary); // відкрили бінарний файл зчитування

	fin.read((char*)&N, sizeof(N)); // прочитали кількість елементів

	p = new Tovar[N]; // створили динамічний масив

	for (int i = 0; i < N; i++)
		fin.read((char*)&p[i], sizeof(Tovar)); // прочитали елементи масиву

	fin.close(); // закрили файл
}
