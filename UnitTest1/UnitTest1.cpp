#include "pch.h"
#include "CppUnitTest.h"
#include "../PDS_LAB_15/PDS_LAB_15.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestSolveNQueens)
		{

			int n = 4;
			NQueens nQueens(n);

			Assert::IsTrue(nQueens.isSafe(0, 0));
		}

		TEST_METHOD(TestIsSafe)
		{

			NQueens nQueens(4);
			Assert::IsTrue(nQueens.isSafe(0, 0));
			Assert::IsTrue(nQueens.isSafe(0, 1));
			nQueens.board[0][0] = 'Q';
			Assert::IsFalse(nQueens.isSafe(1, 0));
			Assert::IsFalse(nQueens.isSafe(1, 1));
		}
	};
}
