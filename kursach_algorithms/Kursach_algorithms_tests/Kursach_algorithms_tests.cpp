#include "pch.h"
#include "CppUnitTest.h"
#include "..\kursach_algorithms\Func.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Kursachalgorithmstests
{
	TEST_CLASS(Kursachalgorithmstests)
	{
	public:
		
		TEST_METHOD(selectionSort_A_equals_B_reverse)
		{
			int a[10]{10,9,8,7,6,5,4,3,2,1};
			int b[10]{1,2,3,4,5,6,7,8,9,10};

			selectionSort(a, 10);
			for(int i = 0; i< 10; i++)
				Assert::AreEqual(a[i], b[i]);
		}

		TEST_METHOD(selectionSort_A_equals_B_random)
		{
			int a[10]{ 10,6,2,7,1,3,4,9,8,5 };
			int b[10]{ 1,2,3,4,5,6,7,8,9,10 };

			selectionSort(a, 10);
			for (int i = 0; i < 10; i++)
				Assert::AreEqual(a[i], b[i]);
		}

		TEST_METHOD(selectionSort_A_equals_B_repetitive)
		{
			int a[7]{ 5,2,3,3,1,4,3 };
			int b[7]{ 1,2,3,3,3,4,5 };

			selectionSort(a, 7);
			for (int i = 0; i < 7; i++)
				Assert::AreEqual(a[i], b[i]);
		}

		TEST_METHOD(bubbleSort_A_equals_B_reverse)
		{
			int a[10]{ 10,9,8,7,6,5,4,3,2,1 };
			int b[10]{ 1,2,3,4,5,6,7,8,9,10 };

			bubbleSort(a, 10);
			for (int i = 0; i < 10; i++)
				Assert::AreEqual(a[i], b[i]);
		}

		TEST_METHOD(bubbleSort_A_equals_B_random)
		{
			int a[10]{ 10,6,2,7,1,3,4,9,8,5 };
			int b[10]{ 1,2,3,4,5,6,7,8,9,10 };

			bubbleSort(a, 10);
			for (int i = 0; i < 10; i++)
				Assert::AreEqual(a[i], b[i]);
		}

		TEST_METHOD(bubbleSort_A_equals_B_repetitive)
		{
			int a[7]{ 5,2,3,3,1,4,3 };
			int b[7]{ 1,2,3,3,3,4,5 };

			bubbleSort(a, 7);
			for (int i = 0; i < 7; i++)
				Assert::AreEqual(a[i], b[i]);
		}

		TEST_METHOD(insertionSort_a_equals_B_reverse)
		{
			int a[10]{ 10,9,8,7,6,5,4,3,2,1 };
			int b[10]{ 1,2,3,4,5,6,7,8,9,10 };

			insertionSort(a, 10);
			for (int i = 0; i < 10; i++)
				Assert::AreEqual(a[i], b[i]);
		}

		TEST_METHOD(insertionSort_a_equals_B_random)
		{
			int a[10]{ 10,6,2,7,1,3,4,9,8,5 };
			int b[10]{ 1,2,3,4,5,6,7,8,9,10 };

			insertionSort(a, 10);
			for (int i = 0; i < 10; i++)
				Assert::AreEqual(a[i], b[i]);
		}

		TEST_METHOD(insertionSort_a_equals_B_repetitive)
		{
			int a[7]{ 5,2,3,3,1,4,3 };
			int b[7]{ 1,2,3,3,3,4,5 };

			insertionSort(a, 7);
			for (int i = 0; i < 7; i++)
				Assert::AreEqual(a[i], b[i]);
		}
	};
}
