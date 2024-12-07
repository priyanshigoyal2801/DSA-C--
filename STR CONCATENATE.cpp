#include <iostream>
#include <string>

int main() {
    // Declare two strings
    std::string str1, str2;

    // Input the first string
    std::cout << "Enter the first string: ";
    std::getline(std::cin, str1);

    // Input the second string
    std::cout << "Enter the second string: ";
    std::getline(std::cin, str2);

    // Concatenate str2 to str1
    str1 += str2;

    // Output the concatenated string
    std::cout << "The concatenated string is: " << str1 << std::endl;

    return 0;
}

