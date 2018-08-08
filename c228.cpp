#include <iostream>
#include <ctype.h>
#include <vector>

int main() {
    //Get input
    std::vector <std::string> inputs;
    std::string input;
    while(getline(std::cin, input) && input.empty()){
        inputs.push_back(input);
    }


    for (std::string z: inputs) {
        std::cout << z;
        int lastCode = 0;
        bool isInOrder = true;
        for (char x: z) {
            x = tolower(x);
            int y = x;
            if (y < lastCode) {
                isInOrder = false;
                break;
            }
            else {
                lastCode = y;
            }
        }
        std::cout << input;
        if (isInOrder) {
            std::cout << " IN ORDER\n";
        }
        else {
            std::cout << " NOT IN ORDER\n";
        }
    }
}