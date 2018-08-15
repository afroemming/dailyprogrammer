#include <iostream> 
#include <string>

int main() {
    std::cout << "> ";
    std::string in;
    getline(std::cin, in);
    int cents = stod(in)*100;
    int quarters = cents / 25;
    int dimes = (cents %= 25) / 10; 
    int nickels = (cents %= 10) / 5;
    int pennies = (cents %= 5);
    std::cout << "Quarters: " << quarters << '\n';
    std::cout << "Dimes: " << dimes << '\n';
    std::cout << "Nickels: "  << nickels << '\n';
    std::cout << "Pennies: " << pennies << '\n';
}