#include <iostream>
#include <ctype.h>
using namespace std;

int main() {
    string input = "default";
    while (input != "") {
        getline(cin, input);
    }
    int lastCode = 0;
    bool isInOrder = true;
    for (char x: input) {
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
    cout << input;
    if (isInOrder) {
        cout << " IN ORDER\n";
    }
    else {
        cout << " NOT IN ORDER\n";
    }

}