#include "pch.h"
#include "CppUnitTest.h"

#include "..\Project1\FileName.cpp"
#include "..\Project1\FileName2.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitConverterTests)
    {
    public:
        TEST_METHOD(CelsiusToFahrenheit_FreezingPoint_Returns32)
        {
            double celsius = 0.0;
            double expected = 32.0;

            double result = UnitConverter::celsiusToFahrenheit(celsius);
            Assert::AreEqual(expected, result, 0.001);
        }

        TEST_METHOD(MetersToFeet_TenMeters_ReturnsCorrectFeet)
        {
            double meters = 10.0;
            double expected = 32.8084;
            double result = UnitConverter::metersToFeet(meters);
            Assert::AreEqual(expected, result, 0.001);
        }


        TEST_METHOD(CelsiusToFahrenheit_BelowAbsoluteZero_ThrowsException)
        {
            auto func = [] {
                UnitConverter::celsiusToFahrenheit(-300.0);
                };

            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(MetersToFeet_NegativeInput_ThrowsException)
        {
            auto func = [] {
                UnitConverter::metersToFeet(-5.0);
                };

            Assert::ExpectException<std::invalid_argument>(func);
        }
    };


    // КЛАСС ТЕСТОВ ДЛЯ ЗАДАНИЯ НАПАРНИКА (ДРОБИ)
    TEST_CLASS(PartnerFractionTests)
    {
    public:

        TEST_METHOD(TestAdd_ValidFractions_ReturnsOne)
        {
            Fraction f1 = { 1, 2 };
            Fraction f2 = { 1, 2 };

            Fraction result = MathFractionOperations::add(f1, f2);

            Assert::AreEqual(1, result.n);
            Assert::AreEqual(1, result.d);
        }
    };
}