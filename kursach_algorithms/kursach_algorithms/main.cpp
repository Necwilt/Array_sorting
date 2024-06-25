#include <iostream>
#include <fstream>
#include <cstring>
#include <Windows.h>
#include <stdlib.h>
#include <ctime>
#include <exception>
#include "Func.h"

using namespace std;

enum Menu1
{
	START1,
	sortRandom,
	dataStorage,
	EXIT1
};

enum Menu2
{
	START2,
	SelectionSort,
	BubbleSort,
	InsertionSort,
	EXIT2
};

enum Menu3
{
	START3,
	ArrayRandom,
	OrderedSequence,
	ReverseSequence,
	EXIT3
};

int getMenuItem1()
{
	int answer;
	do {
		cout << "\n�������� ���� �� ������� ����: " << endl
			<< sortRandom << " - ���������� ������ �������, ��������������� ��������� �������" << endl
			<< dataStorage << " - ����� ���������� �������������� ������" << endl
			<< EXIT1 << " - ����� �� ���������" << endl;
		cin >> answer;
	} while (answer <= START1 || answer > EXIT1);
	return answer;
}

int getMenuItem2()
{
	int answer;
	do {
		cout << "\n�������� ����� ���������� �������: " << endl
			<< SelectionSort << " - ���������� � ������� �������� ������" << endl
			<< BubbleSort << " - ���������� � ������� �������� ������" << endl
			<< InsertionSort << " - ���������� c ������� �������� ���������" << endl
			<< EXIT2 << " - ��������� � ������� ����" << endl;
		cin >> answer;
	} while (answer <= START2 || answer > EXIT2);
	return answer;

}

int getMenuItem3()
{
	int answer;
	do {
		cout << "�������� ������ ������������ ��������� �������: " << endl
			<< ArrayRandom << " - ��������� ��������" << endl
			<< OrderedSequence << " - ������������� ������������������" << endl
			<< ReverseSequence << " - �������� ������������������" << endl
			<< EXIT3 << " - ��������� � ������� ����" << endl;
		cin >> answer;
	} while (answer <= START3 || answer > EXIT3);
	return answer;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));

	int answer;
	answer = getMenuItem1();

	do {

		switch (answer)
		{

		case sortRandom:
		{
			int range1, range2, N;
			char FileName[20];

			cout << "������� ������ �������: " << endl;
			bool retry = true;
			while (retry)
				try {
				retry = false;
				cin >> N;
				if (N < 0)
					throw range_error("������������� ������ �������");
			}
			catch (range_error) {
				cout << "������������ ��������. ������ ������� ������ ���� �������������" << endl;
				cout << "������� ������ �������: " << endl;
				retry = true;
			}
			cout << "������� �������� �������� ��������� �������: " << endl;
			cout << "�� " << endl;
			cin >> range1;
			cout << "�� " << endl;
			cin >> range2;

			int* randomNum = new int[N];
			for (int i = 0; i < N; i++)
				randomNum[i] = range1 + rand() % (range2 - range1 + 1);

			do {
				answer = getMenuItem2();

				Timer t;

				switch (answer)
				{
				case SelectionSort:
				{
					selectionSort(randomNum, N);

					cout << "\n����� ���������� � ������� ���������� �������� ������: " << t.elapsed() << '\n';

					break;
				}

				case BubbleSort:
				{
					bubbleSort(randomNum, N);

					cout << "\n����� ���������� � ������� ���������� �������� ������: " << t.elapsed() << '\n';

					break;
				}

				case InsertionSort:
					insertionSort(randomNum, N);

					cout << "\n����� ���������� � ������� ���������� �������� ���������: " << t.elapsed() << '\n';
				}
			} while (answer != EXIT2);

			answer = getMenuItem1();


			break;
		}

		case dataStorage:
		{
			int range1, range2, step, k;
			char FileName[20];
			ofstream fout(FileName);

			cout << "������� �������� �������� �������: " << endl;
			cout << "�� " << endl;
			bool retry = true;
			while (retry)
			try {
				retry = false;
				cin >> range1;
				if (range1 < 0)
					throw range_error("������������� ��������");
			}
			catch(range_error) {
				cout << "������������ ��������. �������� ������ ���� �������������" << endl;
				cout << "�� " << endl;
				retry = true;
			}
			cout << "�� " << endl;
			retry = true;
			while (retry)
				try {
				retry = false;
				cin >> range2;
				if (range2 < 0)
					throw range_error("������������� ��������");
			}
			catch (range_error) {
				cout << "������������ ��������. �������� ������ ���� �������������" << endl;
				cout << "�� " << endl;
				retry = true;
			}
			cout << "������� ��� ��������� �������� �������: " << endl;
			retry = true;
			while (retry)
				try {
				retry = false;
				cin >> step;
				if (step <= 0)
					throw range_error("������������� ��������");
			}
			catch (range_error) {
				cout << "������������ ��������. ��� ������ ���� �������������" << endl;
				cout << "������� ��� ��������� �������� �������: " << endl;
				retry = true;
			}
			cout << "������� ��� ����� ��� ������ ������: " << endl;
			cin >> FileName;

			fout.open(FileName, ios::out);

			do {
				answer = getMenuItem3();

				switch (answer)
				{

				case ArrayRandom:
				{
					fout << "\nC����� ������������ ��������� ������� - ��������� ��������:" << endl;
					k = range1;
					cout << "\n�������� ����� ���������� �������: " << endl;
					cout << "1 - ���������� � ������� �������� ������" << endl;
					cout << "2 - ���������� � ������� �������� ������" << endl;
					cout << "3 - ���������� c ������� �������� ���������" << endl;
					cin >> answer;
					if(range1 <= range2)
					while (k <= range2) {

						int* ArrayRandom = new int[k];

						for (int i = 0; i < k; i++) {
							ArrayRandom[i] = range1 + rand() % (range2 - range1 + 1);
						}

						Timer t;

						switch (answer)
						{
						case 1:
						{
							selectionSort(ArrayRandom, k);
							fout << "��� " << k << " ��������� ����� ���������� � ������� ���������� �������� ������: " << t.elapsed() << '\n';

							break;
						}

						case 2:
						{
							bubbleSort(ArrayRandom, k);
							fout << "��� " << k << " ��������� ����� ���������� � ������� ���������� �������� ������: " << t.elapsed() << '\n';

							break;
						}

						case 3:
						{
							insertionSort(ArrayRandom, k);
							fout << "��� " << k << " ��������� ����� ���������� � ������� ���������� �������� ���������: " << t.elapsed() << '\n';

							break;
						}


						}

						delete[] ArrayRandom;
						k = k + step;
					} else 
						if (range2 < range1)
							while (k >= range2) {
								int* ArrayRandom = new int[k];

								for (int i = 0; i < k; i++) {
									ArrayRandom[i] = range1 + rand() % (range2 - range1 + 1);
								}

								Timer t;

								switch (answer)
								{
								case 1:
								{
									selectionSort(ArrayRandom, k);
									fout << "��� " << k << " ��������� ����� ���������� � ������� ���������� �������� ������: " << t.elapsed() << '\n';

									break;
								}

								case 2:
								{
									bubbleSort(ArrayRandom, k);
									fout << "��� " << k << " ��������� ����� ���������� � ������� ���������� �������� ������: " << t.elapsed() << '\n';

									break;
								}

								case 3:
								{
									insertionSort(ArrayRandom, k);
									fout << "��� " << k << " ��������� ����� ���������� � ������� ���������� �������� ���������: " << t.elapsed() << '\n';

									break;
								}


								}

								delete[] ArrayRandom;
								k = k - step;
							}
					break;
				}

				case OrderedSequence:
				{
					fout << "\nC����� ������������ ��������� ������� - ������������� ������������������:" << endl;
					k = range1;
					cout << "\n�������� ����� ���������� �������: " << endl;
					cout << "1 - ���������� � ������� �������� ������" << endl;
					cout << "2 - ���������� � ������� �������� ������" << endl;
					cout << "3 - ���������� c ������� �������� ���������" << endl;
					cin >> answer;
					if (range1 <= range2)
					while (k <= range2) {

						int* ArrayRandom = new int[k];

						for (int i = 0; i < k; i++) {
							ArrayRandom[i] = i + 1;
						}

						Timer t;

						switch (answer)
						{
						case 1:
						{
							selectionSort(ArrayRandom, k);
							fout << "��� " << k << " ��������� ����� ���������� � ������� ���������� �������� ������: " << t.elapsed() << '\n';

							break;
						}

						case 2:
						{
							bubbleSort(ArrayRandom, k);
							fout << "��� " << k << " ��������� ����� ���������� � ������� ���������� �������� ������: " << t.elapsed() << '\n';

							break;
						}

						case 3:
						{
							insertionSort(ArrayRandom, k);
							fout << "��� " << k << " ��������� ����� ���������� � ������� ���������� �������� ���������: " << t.elapsed() << '\n';

							break;
						}

						}

						delete[] ArrayRandom;
						k = k + step;
					} else
						if (range2 < range1)
							while (k >= range2) {
								int* ArrayRandom = new int[k];

								for (int i = 0; i < k; i++) {
									ArrayRandom[i] = i + 1;
								}

								Timer t;

								switch (answer)
								{
								case 1:
								{
									selectionSort(ArrayRandom, k);
									fout << "��� " << k << " ��������� ����� ���������� � ������� ���������� �������� ������: " << t.elapsed() << '\n';

									break;
								}

								case 2:
								{
									bubbleSort(ArrayRandom, k);
									fout << "��� " << k << " ��������� ����� ���������� � ������� ���������� �������� ������: " << t.elapsed() << '\n';

									break;
								}

								case 3:
								{
									insertionSort(ArrayRandom, k);
									fout << "��� " << k << " ��������� ����� ���������� � ������� ���������� �������� ���������: " << t.elapsed() << '\n';

									break;
								}

								}

								delete[] ArrayRandom;
								k = k - step;
							}

					break;
				}

				case ReverseSequence:
				{
					fout << "\nC����� ������������ ��������� ������� - �������� ������������������:" << endl;
					k = range1;
					cout << "\n�������� ����� ���������� �������: " << endl;
					cout << "1 - ���������� � ������� �������� ������" << endl;
					cout << "2 - ���������� � ������� �������� ������" << endl;
					cout << "3 - ���������� c ������� �������� ���������" << endl;
					cin >> answer;
					if (range1 <= range2)
					while (k <= range2) {

						int* ArrayRandom = new int[k];

						for (int i = 0; i < k; i++) {
							ArrayRandom[i] = i + 1;
						}

						int temp;
						for (int i = 0; i < (k / 2); i++)
						{
							temp = ArrayRandom[k - i - 1];
							ArrayRandom[k - i - 1] = ArrayRandom[i];
							ArrayRandom[i] = temp;
						}

						Timer t;

						switch (answer)
						{
						case 1:
						{
							selectionSort(ArrayRandom, k);
							fout << "��� " << k << " ��������� ����� ���������� � ������� ���������� �������� ������: " << t.elapsed() << '\n';

							break;
						}

						case 2:
						{
							bubbleSort(ArrayRandom, k);
							fout << "��� " << k << " ��������� ����� ���������� � ������� ���������� �������� ������: " << t.elapsed() << '\n';

							break;
						}

						case 3:
						{
							insertionSort(ArrayRandom, k);
							fout << "��� " << k << " ��������� ����� ���������� � ������� ���������� �������� ���������: " << t.elapsed() << '\n';

							break;
						}

						}

						delete[] ArrayRandom;
						k = k + step;
					}
					else
						if (range2 < range1)
							while (k >= range2) {
								int* ArrayRandom = new int[k];

								for (int i = 0; i < k; i++) {
									ArrayRandom[i] = i + 1;
								}

								int temp;
								for (int i = 0; i < (k / 2); i++)
								{
									temp = ArrayRandom[k - i - 1];
									ArrayRandom[k - i - 1] = ArrayRandom[i];
									ArrayRandom[i] = temp;
								}

								Timer t;

								switch (answer)
								{
								case 1:
								{
									selectionSort(ArrayRandom, k);
									fout << "��� " << k << " ��������� ����� ���������� � ������� ���������� �������� ������: " << t.elapsed() << '\n';

									break;
								}

								case 2:
								{
									bubbleSort(ArrayRandom, k);
									fout << "��� " << k << " ��������� ����� ���������� � ������� ���������� �������� ������: " << t.elapsed() << '\n';

									break;
								}

								case 3:
								{
									insertionSort(ArrayRandom, k);
									fout << "��� " << k << " ��������� ����� ���������� � ������� ���������� �������� ���������: " << t.elapsed() << '\n';

									break;
								}

								}

								delete[] ArrayRandom;
								k = k - step;
							}
					break;

				}
				break;
				fout.close();

				}
			} while (answer != EXIT3);

			answer = getMenuItem1();
			break;

		}

		}

	} while (answer != EXIT1);
}