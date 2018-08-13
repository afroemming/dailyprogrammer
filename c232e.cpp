#include <iostream>
#include <string>
#include <ctype.h>

int main () {
    // Get input
    std::string input;
    std::cout << "Num. Lines > ";
    getline(std::cin, input);
    std::string lines;
    int numLines = std::stoi(input);
    for (int i = 0; i < numLines; i++) {
        getline(std::cin, input);
        lines = lines + input;
    }

    //Strip out non-letters
    for (int i = 0; i < lines.length(); i++) {
        if (!isalpha(lines.at(i))) {
            lines.erase(i);
        }
    }

    //Test if palidrome
    bool isPalindrome = true;
    for (int i = 0; i < lines.length(); i++){
        if (tolower(lines.at(i)) != tolower(lines.at(lines.length()-i-1))) {
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome) {
        std::cout << "Palindrome" << '\n';
    }
    else {
        std::cout << "Not a palindrome" << '\n';
    }
}