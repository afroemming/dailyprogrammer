#include <iostream>
#include <ctype.h>
#include <vector>

int main() {
    //Get and parse input
    std::string input;
    std::cin >> input;
    std::vector<bool> states; 
    for (char c: input) {
        states.push_back(int(c) - 48);
    }

    //Do automata
    std::vector<bool> new_states = states;
    for (int i=0; i < 25; i++) {
        states = new_states;
        // Print states
        for (bool b: states) {
            if (b) {std::cout << 'x';}
            else {std::cout << ' ';}
        }
        std::cout << '\n';
        new_states[0] = states[1] ^ 0; //Assume outer cells are borders by 0 on the outside
        new_states.back() = states[states.size()-2] ^ 0;
        for (int j=1; j < (states.size() - 1); j++ ) {
            new_states[j] = states[j-1] ^ states[j+1];
        }
    }
}