#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(myTestCase)
{
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
}