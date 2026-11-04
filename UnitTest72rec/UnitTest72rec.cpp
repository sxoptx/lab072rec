#include "pch.h"
#include "CppUnitTest.h"
#include "../lab072rec/lab072rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest7_2_2
{
    TEST_CLASS(UnitTest7_2_2)
    {
    public:
        int** Make(int data[3][3])
        {
            int** a = new int* [3];
            for (int i = 0; i < 3; i++)
            {
                a[i] = new int[3];
                for (int j = 0; j < 3; j++)
                    a[i][j] = data[i][j];
            }
            return a;
        }

        void Free(int** a)
        {
            for (int i = 0; i < 3; i++)
                delete[] a[i];
            delete[] a;
        }

        TEST_METHOD(MaxMinRows_Positive)
        {
            int d[3][3] = { {5,2,8}, {7,6,9}, {1,4,3} };   // мінімуми: 2, 6, 1
            int** a = Make(d);
            int max;
            MaxMinRows(a, 3, 3, 0, max);
            Assert::AreEqual(6, max);
            Free(a);
        }

        TEST_METHOD(MaxMinRows_Negative)
        {
            int d[3][3] = { {-5,-2,-8}, {-9,-7,-6}, {-3,-4,-3} };   // мінімуми: -8, -9, -4
            int** a = Make(d);
            int max;
            MaxMinRows(a, 3, 3, 0, max);
            Assert::AreEqual(-4, max);
            Free(a);
        }
    };
}