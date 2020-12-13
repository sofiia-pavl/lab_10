#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;
void CreateTXT(char* fname) 
{
	ofstream fout(fname); 
	char ch; 
	string s; 
	do
	{
		cin.get(); 
		cin.sync(); 
		cout << "enter line: "; getline(cin, s); 
		fout << s << endl; 
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}
void PrintTXT(char* fname) 
{
	ifstream fin(fname); 
	string s; 
	while (getline(fin, s)) 
	{
		cout << s << endl; 
	}
	cout << endl;
}
int main()
{
	char fname[100]; 
	int menuItem;

do {
	cout << endl << endl << endl;
	cout << "������� ��:" << endl << endl;
	cout << " [1] - �������� ����� � ���������" << endl;
	cout << " [2] - ���� ����� �� �����" << endl;
	cout << " [4] - ������� ������������� �����" << endl;
	cout << " [5] - ������� ����� ���������� �� ������� �� ��������" << endl;
	cout << " [7] - ����� ����� � ����" << endl;
	cout << " [8] - ���������� ����� �� �����" << endl << endl;
	cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
	cout << "������ ��������: "; cin >> menuItem;
	cout << endl << endl << endl;
	switch (menuItem)
	{
	case 1:
		CreateTXT(fname);
		break;
	case 2:
		PrintTXT(fname);
		break;
	case 4:
		//Sort(p, N);
		break;
	case 5:
		cin.get();
		cin.sync();

		//cout << " ����� ��������: "; cin >> shop;
		//cout << endl;
		//if ((found = BinSearch(p, N, shop)) != -1)
		//	cout << "�������� � ������� " << found + 1 << endl;
		//else
			cout << "�������� �� ��������" << endl;
		break;
	case 7:
		cin.get();
		cin.sync();

		cout << "������ ��'� �����: "; cin.getline(fname, 99);
		//SaveToFile(p, N, fname);
		break;
	case 8:
		cin.get();
		cin.sync();

		cout << "������ ��'� �����: "; cin.getline(fname, 99);
		//LoadFromFile(p, N, fname);
		break;
	case 0:
		break;
	default:
		cout << "�� ����� ��������� ��������! "
			"��� ������ ����� - ����� ��������� ������ ����" << endl;
	}
} while (menuItem != 0);
return 0;
}
