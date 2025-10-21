#include "ScalarConverter.hpp"
#include <string>

#include <iostream>
#include <string>
#include "ScalarConverter.hpp" // Or your header name

void run_test(const std::string& input) {
    std::cout << "Test input: " << input << std::endl;
    ScalarConverter::convert(input);
    std::cout << "-----------------------------" << std::endl;
}

int main() {
    // Char literals (printable)
    run_test("'a'");
    run_test("'Z'");
    run_test("'0'");

    // Int literals
    run_test("0");
    run_test("-42");
    run_test("42");
    run_test("127");
    run_test("128");
    run_test("-128");
    run_test("2147483647"); // INT_MAX
    run_test("-2147483648"); // INT_MIN
    run_test("2147483648"); // Overflow

    // Float literals
    run_test("0.0f");
    run_test("-4.2f");
    run_test("4.2f");
    run_test("42.0f");
    run_test("nanf");
    run_test("+inff");
    run_test("-inff");
    run_test("340282346638528859811704183484516925440.0f"); // FLT_MAX
    run_test("3402823466385288598117041834845169254400.0f"); // Overflow

    // Double literals
    run_test("0.0");
    run_test("-4.2");
    run_test("4.2");
    run_test("42.0");
    run_test("nan");
    run_test("+inf");
    run_test("-inf");
    run_test("1.7976931348623157e+308"); // DBL_MAX
    run_test("1.7976931348623157e+309"); // Overflow

    // Edge cases
    run_test("not_a_number");
    run_test("");
    run_test("'ab'"); // Invalid char literal
    run_test("' '"); // Space character

    return 0;
}
