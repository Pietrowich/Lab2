#include <iostream>
#include <clocale>

using namespace std;

int random(int min, int max)
{
	int rnd;
	static const double fr = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fr * (max - min + 1) + min);
}

class MasWork
{
private:
	int *mas1 = new int[16];
	int *mas2 = new int[16];

public:
	MasWork(int m1_Length, int m2_Length)
	{
		int max = 0;
		int min = 0;
		int pos1 = 0, pos2 = 0;

		cout << "Неизмененные массивы\n\nМассив 1:" << endl;
		for(int i=0; i<m1_Length; i++) 
		{
			mas1[i] = random(-5, 5);
			if (max < mas1[i]) {
				max = mas1[i];
				pos1 = i;
			}
			cout << (mas1[i]) << " ";
		}

		cout << "\nМаксимальный элемент: " << max << endl;
		cout << "\nМассив 2:" << endl;

		for (int i = 0; i < m2_Length; i++)
		{
			mas2[i] = random(-5, 5);
			if (min > mas2[i]) {
				min = mas2[i];
				pos2 = i;
			}

			cout << (mas2[i]) << " ";
		}
		cout << "\nМинимальный элемент: " << min << endl;

		mas1[pos1] = min;
		mas2[pos2] = max;

		cout << "\n\n\nМассивы с замененными элементами\n\nМассив 1:" << endl;

		for (int i = 0; i < m1_Length; i++) 
		{
			cout << (mas1[i]) << " ";
		}

		cout << "\n\nМассив 2:" << endl;

		for (int i = 0; i < m2_Length; i++)
		{
			cout << (mas2[i]) << " ";
		}
		cout << "\n\n";
	}

	MasWork()
	{
		delete[] mas1;
		delete[] mas2;
	}
};

int main()
{
	setlocale(LC_CTYPE, "rus");

	int s1 = 0;
	int s2 = 0;

	cout << "Введите размер первого массива: " << endl;
	cin >> s1;

	cout << "\nВведите размер второго массива: " << endl;
	cin >> s2;
	system("cls");

	MasWork* mw1 = new MasWork(s1, s2);

	delete mw1;

	return 0;
}

