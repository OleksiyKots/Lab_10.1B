#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_010.1B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(StudentTests)
    {
    public:

        // Test for MaxAverageGrade function
        TEST_METHOD(TestMaxAverageGrade)
        {
            // Create an array of students
            Student students[] = {
                {"Ivanov", 1, COMPUTER_SCIENCE, 4, 5, 5},
                {"Petrov", 2, INFORMATICS, 3, 4, 5},
                {"Sidorov", 3, MATH_AND_ECON, 4, 4, 4},
                {"Kovalenko", 4, PHYSICS_AND_INFORMATICS, 5, 5, 5},
                {"Tymoshenko", 1, LABOR_EDUCATION, 2, 3, 5}
            };

            // Calculate the highest average grade
            double result = MaxAverageGrade(students, 5);
            double expected = 5.0;  // Highest possible average grade (for Kovalenko)

            // Assert that the result matches the expected value
            Assert::AreEqual(expected, result, 0.1);
        }

        // Test for PercentageHighPhysicsGrades function
        TEST_METHOD(TestPercentageHighPhysicsGrades)
        {
            // Create an array of students
            Student students[] = {
                {"Ivanov", 1, COMPUTER_SCIENCE, 5, 5, 5},
                {"Petrov", 2, INFORMATICS, 3, 4, 5},
                {"Sidorov", 3, MATH_AND_ECON, 4, 4, 4},
                {"Kovalenko", 4, PHYSICS_AND_INFORMATICS, 5, 5, 5},
                {"Tymoshenko", 1, LABOR_EDUCATION, 2, 3, 5}
            };

            // Calculate the percentage of students with physics grades >= 4
            double result = PercentageHighPhysicsGrades(students, 5);
            double expected = 60.0;  // 3 out of 5 students have physics grade >= 4

            // Assert that the result matches the expected value
            Assert::AreEqual(expected, result, 0.1);
        }
    };
}
