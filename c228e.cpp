#include <iostream>
#include <ctype.h>
#include <vector>

int main() {
    // Get input
    std::vector <std::string> words;
    std::string input;
    while(getline(std::cin, input) && !input.empty()){
        words.push_back(input);
    }

    // Check if in order
    bool isInOrder;
    bool isInReverseOrder;
    int lastCode;
    for (std::string word: words) {
        lastCode = 0;
        isInOrder = true;
        for (char c: word){
            int i = c;
            if (c < lastCode) {
                isInOrder = false;
                break;
            }
            lastCode = c;
        }
        
        // Print output
        std::cout << word;
        if (isInOrder) {
            std::cout << " IN ORDER\n";
        }
        // Check if in reverse order
        else {
            isInReverseOrder = true;
            lastCode = 128;
            for (char c: word){
                int i = c;
                if (c > lastCode) {
                    isInReverseOrder = false;
                    break;
                }
                lastCode = c;
            }

            if (isInReverseOrder) {
                std::cout << " REVERSE ORDER\n";
            }
            else {
                std::cout << " NOT IN ORDER\n";
            }    
        }
    }
}