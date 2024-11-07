#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab14\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestReadGraphFromFile)
        {
            ofstream testFile("testGraph.txt");
            testFile << "4 5\n1 1\n2 2\n3 3\n4 4\n1 2\n2 3\n3 4\n4 1\n2 4\n";
            testFile.close();

            bool result = readGraphFromFile("testGraph.txt");

            Assert::IsTrue(result);
            Assert::AreEqual(N, 4);
            Assert::AreEqual(M, 5);
        }

        TEST_METHOD(TestIsReflexive)
        {
            N = 4;
            M = 5;
            adjList = { {0}, {1}, {2}, {3} };
            addEdge(0, 0);
            addEdge(1, 1);
            addEdge(2, 2);
            addEdge(3, 3);

            Assert::IsTrue(isReflexive());
        }

        TEST_METHOD(TestIsSymmetric)
        {
            N = 4;
            M = 4;
            adjList = { {1}, {0}, {3}, {2} };
            addEdge(0, 1);
            addEdge(1, 0);
            addEdge(2, 3);
            addEdge(3, 2);

            Assert::IsTrue(isSymmetric());
        }

        TEST_METHOD(TestIsNotSymmetric)
        {
            N = 4;
            M = 3;
            adjList = { {1}, {2}, {3}, {2} };
            addEdge(0, 1);
            addEdge(1, 2);
            addEdge(2, 3);

            Assert::IsFalse(isSymmetric());
        }
    };
}
