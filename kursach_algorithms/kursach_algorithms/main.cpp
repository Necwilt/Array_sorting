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
		cout << "\nВыберете один из пунктов меню: " << endl
			<< sortRandom << " - Сортировка одного массива, сформированного случайным образом" << endl
			<< dataStorage << " - режим накопления статистических данных" << endl
			<< EXIT1 << " - Выйти из программы" << endl;
		cin >> answer;
	} while (answer <= START1 || answer > EXIT1);
	return answer;
}

int getMenuItem2()
{
	int answer;
	do {
		cout << "\nВыберите метод сортировки массива: " << endl
			<< SelectionSort << " - Сортировка с помощью простого выбора" << endl
			<< BubbleSort << " - Сортировка с помощью простого обмена" << endl
			<< InsertionSort << " - Сортировка c помощью простого включения" << endl
			<< EXIT2 << " - Вернуться в главное меню" << endl;
		cin >> answer;
	} while (answer <= START2 || answer > EXIT2);
	return answer;

}

int getMenuItem3()
{
	int answer;
	do {
		cout << "Выберите способ формирования элементов массива: " << endl
			<< ArrayRandom << " - случайные значения" << endl
			<< OrderedSequence << " - упорядоченная последовательность" << endl
			<< ReverseSequence << " - обратная последовательность" << endl
			<< EXIT3 << " - Вернуться в главное меню" << endl;
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

			cout << "Введите размер массива: " << endl;
			bool retry = true;
			while (retry)
				try {
				retry = false;
				cin >> N;
				if (N < 0)
					throw range_error("Отрицательный размер массива");
			}
			catch (range_error) {
				cout << "Недопустимое значение. Размер массива должен быть положительным" << endl;
				cout << "Введите размер массива: " << endl;
				retry = true;
			}
			cout << "Введите диапазон значений элементов массива: " << endl;
			cout << "От " << endl;
			cin >> range1;
			cout << "До " << endl;
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

					cout << "\nВремя сортировки с помощью сортировки простого выбора: " << t.elapsed() << '\n';

					break;
				}

				case BubbleSort:
				{
					bubbleSort(randomNum, N);

					cout << "\nВремя сортировки с помощью сортировки простого обмена: " << t.elapsed() << '\n';

					break;
				}

				case InsertionSort:
					insertionSort(randomNum, N);

					cout << "\nВремя сортировки с помощью сортировки простого включения: " << t.elapsed() << '\n';
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

			cout << "Введите диапазон размеров массива: " << endl;
			cout << "От " << endl;
			bool retry = true;
			while (retry)
			try {
				retry = false;
				cin >> range1;
				if (range1 < 0)
					throw range_error("Отрицательный диапазон");
			}
			catch(range_error) {
				cout << "Недопустимое значение. Диапазон должен быть положительным" << endl;
				cout << "От " << endl;
				retry = true;
			}
			cout << "До " << endl;
			retry = true;
			while (retry)
				try {
				retry = false;
				cin >> range2;
				if (range2 < 0)
					throw range_error("Отрицательный диапазон");
			}
			catch (range_error) {
				cout << "Недопустимое значение. Диапазон должен быть положительным" << endl;
				cout << "До " << endl;
				retry = true;
			}
			cout << "Введите шаг изменения размеров массива: " << endl;
			retry = true;
			while (retry)
				try {
				retry = false;
				cin >> step;
				if (step <= 0)
					throw range_error("Отрицательный диапазон");
			}
			catch (range_error) {
				cout << "Недопустимое значение. Шаг должен быть положительным" << endl;
				cout << "Введите шаг изменения размеров массива: " << endl;
				retry = true;
			}
			cout << "Введите имя файла для вывода данных: " << endl;
			cin >> FileName;

			fout.open(FileName, ios::out);

			do {
				answer = getMenuItem3();

				switch (answer)
				{

				case ArrayRandom:
				{
					fout << "\nCпособ формирования элементов массива - случайные значения:" << endl;
					k = range1;
					cout << "\nВыберите метод сортировки массива: " << endl;
					cout << "1 - Сортировка с помощью простого выбора" << endl;
					cout << "2 - Сортировка с помощью простого обмена" << endl;
					cout << "3 - Сортировка c помощью простого включения" << endl;
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
							fout << "Для " << k << " элементов время сортировки с помощью сортировки простого выбора: " << t.elapsed() << '\n';

							break;
						}

						case 2:
						{
							bubbleSort(ArrayRandom, k);
							fout << "Для " << k << " элементов время сортировки с помощью сортировки простого обмена: " << t.elapsed() << '\n';

							break;
						}

						case 3:
						{
							insertionSort(ArrayRandom, k);
							fout << "Для " << k << " элементов время сортировки с помощью сортировки простого включения: " << t.elapsed() << '\n';

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
									fout << "Для " << k << " элементов время сортировки с помощью сортировки простого выбора: " << t.elapsed() << '\n';

									break;
								}

								case 2:
								{
									bubbleSort(ArrayRandom, k);
									fout << "Для " << k << " элементов время сортировки с помощью сортировки простого обмена: " << t.elapsed() << '\n';

									break;
								}

								case 3:
								{
									insertionSort(ArrayRandom, k);
									fout << "Для " << k << " элементов время сортировки с помощью сортировки простого включения: " << t.elapsed() << '\n';

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
					fout << "\nCпособ формирования элементов массива - упорядоченная последовательность:" << endl;
					k = range1;
					cout << "\nВыберите метод сортировки массива: " << endl;
					cout << "1 - Сортировка с помощью простого выбора" << endl;
					cout << "2 - Сортировка с помощью простого обмена" << endl;
					cout << "3 - Сортировка c помощью простого включения" << endl;
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
							fout << "Для " << k << " элементов время сортировки с помощью сортировки простого выбора: " << t.elapsed() << '\n';

							break;
						}

						case 2:
						{
							bubbleSort(ArrayRandom, k);
							fout << "Для " << k << " элементов время сортировки с помощью сортировки простого обмена: " << t.elapsed() << '\n';

							break;
						}

						case 3:
						{
							insertionSort(ArrayRandom, k);
							fout << "Для " << k << " элементов время сортировки с помощью сортировки простого включения: " << t.elapsed() << '\n';

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
									fout << "Для " << k << " элементов время сортировки с помощью сортировки простого выбора: " << t.elapsed() << '\n';

									break;
								}

								case 2:
								{
									bubbleSort(ArrayRandom, k);
									fout << "Для " << k << " элементов время сортировки с помощью сортировки простого обмена: " << t.elapsed() << '\n';

									break;
								}

								case 3:
								{
									insertionSort(ArrayRandom, k);
									fout << "Для " << k << " элементов время сортировки с помощью сортировки простого включения: " << t.elapsed() << '\n';

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
					fout << "\nCпособ формирования элементов массива - обратная последовательность:" << endl;
					k = range1;
					cout << "\nВыберите метод сортировки массива: " << endl;
					cout << "1 - Сортировка с помощью простого выбора" << endl;
					cout << "2 - Сортировка с помощью простого обмена" << endl;
					cout << "3 - Сортировка c помощью простого включения" << endl;
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
							fout << "Для " << k << " элементов время сортировки с помощью сортировки простого выбора: " << t.elapsed() << '\n';

							break;
						}

						case 2:
						{
							bubbleSort(ArrayRandom, k);
							fout << "Для " << k << " элементов время сортировки с помощью сортировки простого обмена: " << t.elapsed() << '\n';

							break;
						}

						case 3:
						{
							insertionSort(ArrayRandom, k);
							fout << "Для " << k << " элементов время сортировки с помощью сортировки простого включения: " << t.elapsed() << '\n';

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
									fout << "Для " << k << " элементов время сортировки с помощью сортировки простого выбора: " << t.elapsed() << '\n';

									break;
								}

								case 2:
								{
									bubbleSort(ArrayRandom, k);
									fout << "Для " << k << " элементов время сортировки с помощью сортировки простого обмена: " << t.elapsed() << '\n';

									break;
								}

								case 3:
								{
									insertionSort(ArrayRandom, k);
									fout << "Для " << k << " элементов время сортировки с помощью сортировки простого включения: " << t.elapsed() << '\n';

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