#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB2/Source.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LAB2TESTS
{
	TEST_CLASS(LAB2TESTS)
	{
	public:
		//MAIN TESTS
		/*For each test from this list there is an explanation showing the conditions
		for writing it which can be viewed on the photo from the "Photos" folder in LAB2 dir.*/
		TEST_METHOD(Main_test_TEST1)
		{
			Logger::WriteMessage(L"TEST1 (0, 0, 0, 0, 0, 0)");
			Assert::IsTrue(calculate(0, 0, 0, 0, 0, 0) == "5", L"Assert");
			Logger::WriteMessage(L"Assert (0, 0, 0, 0, 0, 0) passed!");
		}

		TEST_METHOD(Main_test_TEST2)
		{
			Logger::WriteMessage(L"TEST2 (1, 1, 3, 1, 4, 2)");
			Assert::IsTrue(calculate(1, 1, 3, 1, 4, 2) == "2 " + std::to_string(-1.0)+ " " + std::to_string(5.0), L"Assert");
			Logger::WriteMessage(L"Assert (1, 1, 3, 1, 4, 2) passed!");
		}

		TEST_METHOD(Main_test_TEST3)
		{
			Logger::WriteMessage(L"TEST3 (0, 0, 0, 2, 0, 4)");
			Assert::IsTrue(calculate(0, 0, 0, 2, 0, 4) == "4 " + std::to_string(2.0), L"Assert");
			Logger::WriteMessage(L"Assert (0, 0, 0, 2, 0, 4) passed!");
		}

		TEST_METHOD(Main_test_TEST4)
		{
			Logger::WriteMessage(L"TEST4 (0, 6, 0, 0, 24, 0)");
			Assert::IsTrue(calculate(0, 6, 0, 0, 24, 0) == "4 " + std::to_string(4.0), L"Assert");
			Logger::WriteMessage(L"Assert (0, 6, 0, 0, 24, 0) passed!");
		}

		TEST_METHOD(Main_test_TEST6)
		{
			Logger::WriteMessage(L"TEST6 (0, 0, 0.5, 0, 0, 5)");
			Assert::IsTrue(calculate(0, 0, 0.5, 0, 0, 5) == "3 " + std::to_string(10.0), L"Assert");
			Logger::WriteMessage(L"Assert (0, 0, 0.5, 0, 0, 5) passed!");
		}

		TEST_METHOD(Main_test_TEST7)
		{
			Logger::WriteMessage(L"TEST71 (-2, 0, 0, 0, -4, 0)");
			Assert::IsTrue(calculate(-2, 0, 0, 0, -4, 0) == "3 " + std::to_string(2.0), L"Assert");
			Logger::WriteMessage(L"Assert (-2, 0, 0, 0, -4, 0) passed!");
		}

		TEST_METHOD(Main_test_TEST9)
		{
			Logger::WriteMessage(L"TEST9 (0, 0, 0, 0, 10, 5)");
			Assert::IsTrue(calculate(0, 0, 0, 0, 10, 5) == "0", L"Assert");
			Logger::WriteMessage(L"Assert (0, 0, 0, 0, 10, 5) passed!");
		}

		TEST_METHOD(Main_test_TEST10)
		{
			Logger::WriteMessage(L"TEST10 (0, 10, 0, 20, 0, 0)");
			Assert::IsTrue(calculate(0, 10, 0, 20, 0, 0) == "4 " + std::to_string(0.0), L"Assert");
			Logger::WriteMessage(L"Assert (0, 10, 0, 20, 0, 0) passed!");
		}

		TEST_METHOD(Main_test_TEST11)
		{
			Logger::WriteMessage(L"TEST11 (0, 3, 0, 6, 9, 18)");
			Assert::IsTrue(calculate(0, 3, 0, 6, 9, 18) == "4 " + std::to_string(3.0), L"Assert");
			Logger::WriteMessage(L"Assert (0, 3, 0, 6, 9, 18) passed!");
		}

		TEST_METHOD(Main_test_TEST12)
		{
			Logger::WriteMessage(L"TEST12 (11, 0, 12, 0, 0, 0)");
			Assert::IsTrue(calculate(11, 0, 12, 0, 0, 0) == "3 " + std::to_string(0.0), L"Assert");
			Logger::WriteMessage(L"Assert (11, 0, 12, 0, 0, 0) passed!");
		}

		TEST_METHOD(Main_test_TEST13)
		{
			Logger::WriteMessage(L"TEST13 (40, 0, 0, 0, 4, 0)");
			Assert::IsTrue(calculate(40, 0, 0, 0, 4, 0) == "3 " + std::to_string(0.1), L"Assert");
			Logger::WriteMessage(L"Assert (40, 0, 0, 0, 4, 0) passed!");
		}

		TEST_METHOD(Main_test_TEST14)
		{
			Logger::WriteMessage(L"TEST14 (4, 0, 8, 0, 6, 12)");
			Assert::IsTrue(calculate(4, 0, 8, 0, 6, 12) == "3 " + std::to_string(1.5), L"Assert");
			Logger::WriteMessage(L"Assert (4, 0, 8, 0, 6, 12) passed!");
		}

		TEST_METHOD(Main_test_TEST15)
		{
			Logger::WriteMessage(L"TEST15 (0.5, 0, 5, 10, 0, 0)");
			Assert::IsTrue(calculate(0.5, 0, 5, 10, 0, 0) == "2 " + std::to_string(0.0) + " " + std::to_string(0.0), L"Assert");
			Logger::WriteMessage(L"Assert (0.5, 0, 5, 10, 0, 0) passed!");
		}

		TEST_METHOD(Main_test_TEST16)
		{
			Logger::WriteMessage(L"TEST16 (7, 7, 14, 0, 0, 0)");
			Assert::IsTrue(calculate(7, 7, 14, 0, 0, 0) == "2 " + std::to_string(0.0) + " " + std::to_string(0.0), L"Assert");
			Logger::WriteMessage(L"Assert (7, 7, 14, 0, 0, 0) passed!");
		}

		TEST_METHOD(Main_test_TEST17)
		{
			Logger::WriteMessage(L"TEST17 (0, 4, 4, 0, 0, 0)");
			Assert::IsTrue(calculate(0, 4, 4, 0, 0, 0) == "2 " + std::to_string(0.0) + " " + std::to_string(0.0), L"Assert");
			Logger::WriteMessage(L"Assert (0, 4, 4, 0, 0, 0) passed!");
		}

		TEST_METHOD(Main_test_TEST18)
		{
			Logger::WriteMessage(L"TEST18 (1, 0, 0, 5, 0, 0)");
			Assert::IsTrue(calculate(1, 0, 0, 5, 0, 0) == "2 " + std::to_string(0.0) + " " + std::to_string(0.0), L"Assert");
			Logger::WriteMessage(L"Assert (1, 0, 0, 5, 0, 0) passed!");
		}

		TEST_METHOD(Main_test_TEST19)
		{
			Logger::WriteMessage(L"TEST19 (5, 7, 10, 14, 12, 24)");
			Assert::IsTrue(calculate(5, 7, 10, 14, 12, 24) == "1 " + std::to_string( -5.0/7) + " " + std::to_string(12.0/7), L"Assert");
			Logger::WriteMessage(L"Assert (5, 7, 10, 14, 12, 24) passed!");
		}
		TEST_METHOD(Main_test_TEST20)
		{
			Logger::WriteMessage(L"TEST20 (0.2, 0.2, 0.2, 0.5, 0, 0)");
			Assert::IsTrue(calculate(0.2, 0.2, 0.2, 0.5, 0, 0) == "2 " + std::to_string(0.0) + " " + std::to_string(0.0), L"Assert");
			Logger::WriteMessage(L"Assert (0.2, 0.2, 0.2, 0.5, 0, 0) passed!");
		}


		//OTHER TESTS
		//Just randomized tests
		TEST_METHOD(Test_no_solution_Other_1)
		{
			Logger::WriteMessage(L"TEST_NO_SOLUTION_OTHER1 (0, 0, 0, 0, 2, 3)");
			Assert::IsTrue(calculate(0, 0, 0, 0, 2, 3) == "0", L"Assert");
			Logger::WriteMessage(L"Assert (0, 0, 0, 0, 2, 3) [a=b=c=d=0 e,f!=0] passed!");
		}
		TEST_METHOD(Test_no_solution_Other_2)
		{
			Logger::WriteMessage(L"TEST_NO_SOLUTION_OTHER2 (1, 1, 100, 100, 10, 1)");
			Assert::IsTrue(calculate(1, 1, 100, 100, 10, 1) == "0", L"Assert");
			Logger::WriteMessage(L"Assert (1, 1, 100, 100, 10, 1) [a=b,c=d a<b e>f] passed!");
		}
		TEST_METHOD(Test_no_solution_Other_3)
		{
			Logger::WriteMessage(L"TEST_NO_SOLUTION_OTHER3 (0.5, 0.5, 0.5, 0.5, -0.5, +0.5)");
			Assert::IsTrue(calculate(0.5, 0.5, 0.5, 0.5, -0.5, +0.5) == "0", L"Assert");
			Logger::WriteMessage(L"Assert (0.5, 0.5, 0.5, 0.5, -0.5, +0.5) [a=b=c=d e!=f] passed!");
		}
		TEST_METHOD(Test_no_solution_Other_4)
		{
			Logger::WriteMessage(L"TEST_NO_SOLUTION_OTHER4 (1, 1, -1, -1, 100, 100)");
			Assert::IsTrue(calculate(1, 1, -1, -1, 100, 100) == "0", L"Assert");
			Logger::WriteMessage(L"Assert (1, 1, -1, -1, 100, 100) [a=b=-c=-d e=f] passed!");
		}
		TEST_METHOD(Test_infinity_solutions_Other_1)
		{
			Logger::WriteMessage(L"TEST_INFINITY_SOLUTIONS_OTHER1 (1, 1, 1, 1, 1, 1)");
			Assert::IsTrue(calculate(1, 1, 1, 1, 1, 1) == "1 " + std::to_string(-1.0) + " " + std::to_string(1.0), L"Assert");
			Logger::WriteMessage(L"Assert (1, 1, 1, 1, 1, 1) [y = -x+1] passed!");
		}

		TEST_METHOD(Test_infinity_solutions_Other_2)
		{
			Logger::WriteMessage(L"TEST_INFINITY_SOLUTIONS_OTHER2 (-10, 1, -10, 1, 20, 20)");
			Assert::IsTrue(calculate(-10, 1, -10, 1, 20, 20) == "1 " + std::to_string(10.0) + " " + std::to_string(20.0), L"Assert");
			Logger::WriteMessage(L"Assert (-10, 1, -10, 1, 20, 20) [y = 10x+20] passed!");
		}

		TEST_METHOD(Test_infinity_solutions_Other_3)
		{
			Logger::WriteMessage(L"TEST_INFINITY_SOLUTIONS_OTHER3 (1, 0, 1, 0, 0, 0)");
			Assert::IsTrue(calculate(1, 0, 1, 0, 0, 0) == "3 " + std::to_string(0.0), L"Assert");
			Logger::WriteMessage(L"Assert (1, 0, 1, 0, 0, 0) [x=x0=0 y=any] passed!");
		}

		TEST_METHOD(Test_infinity_solutions_Other_4)
		{
			Logger::WriteMessage(L"TEST_INFINITY_SOLUTIONS_OTHER4 (0, 1, 0, 1, 0, 0)");
			Assert::IsTrue(calculate(0, 1, 0, 1, 0, 0) == "4 " + std::to_string(0.0), L"Assert");
			Logger::WriteMessage(L"Assert (0, 1, 0, 1, 0, 0) [y=y0=0 x=any] passed!");
		}

		TEST_METHOD(Test_one_solution_Other_1)
		{
			Logger::WriteMessage(L"TEST_ONE_SOLUTION_OTHER1 (1, 2, 3, 1, 2, 3)");
			Assert::IsTrue(calculate(1, 2, 3, 1, 2, 3) == "2 " + std::to_string(0.8) + " " + std::to_string(0.6), L"Assert");
			Logger::WriteMessage(L"Assert (1, 2, 3, 1, 2, 3) passed");
		}

		TEST_METHOD(Test_one_solution_Other_2)
		{
			Logger::WriteMessage(L"TEST_ONE_SOLUTION_OTHER2 (3, 3, 3, 0, 18, 9)");
			Assert::IsTrue(calculate(3, 3, 0, 3, 18, 9) == "2 " + std::to_string(3.0) + " " + std::to_string(3.0), L"Assert");
			Logger::WriteMessage(L"Assert (3, 3, 3, 0, 18, 9) passed");
		}

		TEST_METHOD(Test_one_solution_Other_3)
		{
			Logger::WriteMessage(L"TEST_ONE_SOLUTION_OTHER3 (0, 3, 3, 3, 9, 18)");
			Assert::IsTrue(calculate(0, 3, 3, 3, 9, 18) == "2 " + std::to_string(3.0) + " " + std::to_string(3.0), L"Assert");
			Logger::WriteMessage(L"Assert (0, 3, 3, 3, 9, 18) passed");
		}

		TEST_METHOD(Test_one_solution_Other_4)
		{
			Logger::WriteMessage(L"TEST_ONE_SOLUTION_OTHER4 (1, 2, 2, 1, 5, 4)");
			Assert::IsTrue(calculate(1, 2, 2, 1, 5, 4) == "2 " + std::to_string(1.0) + " " + std::to_string(2.0), L"Assert");
			Logger::WriteMessage(L"Assert (1, 2, 2, 1, 5, 4) passed");
		}

		TEST_METHOD(Test_one_solution_Other_5)
		{
			Logger::WriteMessage(L"TEST_ONE_SOLUTION_OTHER5 (13, 2, -1, 1, -11, 2)");
			Assert::IsTrue(calculate(13, 2, -1, 1, -11, 2) == "2 " + std::to_string(-1.0) + " " + std::to_string(1.0), L"Assert");
			Logger::WriteMessage(L"Assert (13, 2, -1, 1, -11, 2) passed");
		}

	};
}
