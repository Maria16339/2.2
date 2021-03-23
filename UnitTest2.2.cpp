#include "pch.h"
#include "CppUnitTest.h"
#include"C://Users/User/source/repos/2.2/2.2/matrix.h"
#include"C://Users/User/source/repos/2.2/2.2/matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest22
{
	TEST_CLASS(UnitTest22)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			int data1[] = { 10,100,10,100,10,100,10,100 };
			Matrix mat1(4,2,data1);
		    mat1 + 4;
			

		

		}
	};
}
