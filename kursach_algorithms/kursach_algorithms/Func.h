#pragma once
#include <chrono>
#include <iostream>

using namespace std;

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now()) {}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

template<class T>
void selectionSort(T a[], long size) {
	long i, j, k;
	T x;

	for (i = 0; i < size; i++) {
		k = i; x = a[i];

		for (j = i + 1; j < size; j++)
			if (a[j] < x) {
				k = j; x = a[j];
			}

		a[k] = a[i]; a[i] = x; 
	}
}


template<class T>
void bubbleSort(T a[], int n) {
	int i, j;
	T temp;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

template<class T>
void insertionSort(T a[], long size) {
	T x;
	long i, j;

	for (i = 0; i < size; i++) {
		x = a[i];

		for (j = i - 1; j >= 0 && a[j] > x; j--)
			a[j + 1] = a[j];

		a[j + 1] = x;
	}
}

