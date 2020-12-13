#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;

enum Specialty { ��, ��, ��, ��, Բ };
string strSpecialty[] = { "��", "��", "��", "��", "Բ" };
struct Student
{
	string prizv;
	Specialty specialty;
	short unsigned kurs;
	short unsigned physic;
	short unsigned math;
	short unsigned inform;
};
void Create(Student* s, const int N);
void Print(Student* s, const int N);
void Best(Student* s, const int N);
double LineSearch(Student* p, const int N);
void SaveToFile(Student* p, const int N, const char* filename);
void LoadFromFile(Student*& p, int& N, const char* filename);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "������ N: "; cin >> N;

	Student* s = new Student[N];
	Create(s, N);
	Print(s, N);
	Best(s, N);
	int found;
	char filename[100];
	double proc = LineSearch(s, N);
	cout << "������� ��������, �� ������� ������:" << endl;
	cout << proc << "%" << endl;
	return 0;
}
void Create(Student* s, const int N)
{
	int kurs, specialty{};
	for (int i = 0; i < N; i++)
	{
		cout << "�������" << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "�������"; getline(cin, s[i].prizv);
		cout << "����"; cin >> s[i].kurs;
		cout << "������ � ������"; cin >> s[i].physic;
		cout << "������ � ����������"; cin >> s[i].math;
		cout << " ������������ (0 - ��, 1 - ��, 2 - ��, 3 - ��, 4 - Բ): ";
		cin >> specialty;
		s[i].specialty = (Specialty)specialty;
	}
}
void Print(Student* s, const int N)
{
	cout << "===================================================================================="
		<< endl;
	cout << "| �   | �������  | ���� | ������������ |  Գ����  |  ����������  |  �����������  |"
		<< endl;
	cout << "-------------------------------------------------------------------------------------";
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].kurs << " "
			<< "| " << setw(8) << right << strSpecialty[s[i].specialty] << "    "
			<< "| " << setw(4) << right << s[i].physic << "  "
			<< "| " << setw(6) << right << s[i].math << "  "
			<< "| " << setw(4) << right << s[i].inform;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	}
	cout << "==================================================================================================================" << endl;
}
void Best(Student* s, const int N)
{
	cout << "������� c�������, � ����� ��������� ������ ���:" << endl;
	double best = 0;
	double tmp;
	for (int i = 0; i < N; i++)
	{
		tmp = (s[i].physic + s[i].math + s[i].inform) / 3;
	}
	if (tmp > best)
		best = tmp;
	for (int j = 0; j < N; j++)
		if (tmp == best)
			cout << setw(3) << right
			<< " " << s[j].prizv << endl;
}
double LineSearch(Student* p, const int N)
{
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		n++;
		if (p[i].physic == 5)
			if (p[i].math == 5)
				if (p[i].inform == 5)
				{
					k++;

				}
	}
	return 100.0 * k / n;
}
void SaveToFile(Student* p, const int N, const char* filename)
{
	ofstream fout(filename, ios::binary);
	fout.write((char*)&N, sizeof(N));
	for (int i = 0; i < N; i++)
		fout.write((char*)&p[i], sizeof(Student));
	fout.close();
}
void LoadFromFile(Student*& p, int& N, const char* filename)
{
	delete[] p;
	ifstream fin(filename, ios::binary);
	fin.read((char*)&N, sizeof(N));
	p = new Student[N];
	for (int i = 0; i < N; i++)
		fin.read((char*)&p[i], sizeof(Student));
	fin.close();
}
