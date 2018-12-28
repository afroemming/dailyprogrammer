#include <map>
#include <iostream>
#include <vector>
#include <utility>

int main() {
    // Map with inital counts for english Scrabble.
    std::map<char, int> tile_counts = {{'A', 9}, {'B', 2}, {'C', 2}, {'D', 4},
        {'E', 12}, {'F', 2}, {'G', 3}, {'H', 2}, {'I', 9}, {'J', 1}, {'K', 1},
        {'L', 4}, {'M', 2}, {'N', 6}, {'O', 8}, {'P', 2}, {'Q', 1}, {'R', 6},
        {'S',4}, {'T', 6}, {'U', 4}, {'V', 2}, {'W', 2}, {'X', 1}, {'Y', 2},
        {'Z', 1}, {'_', 2}}; 
    
    // Get input
    std::string in;
    std::cout << "> ";
    getline(std::cin, in);
    // Process input
    for (char c: in) {
        if (c == ' ') {
            tile_counts['_']--;
        }
        else {
            tile_counts[c]--;
        }
    }
    
    // Output
    std::map<int, std::vector<char>> hist;
    for (std::pair<char, int> p: tile_counts) {
        if (p.second < 0) {
            std::cout << "Invalid input. More " << p.first << "'s have been taken from the bag than possible." << '\n';
            return 0;
        } 
        else {
            hist[p.second].push_back(p.first);
        }
    }
    for (auto iter = hist.rbegin(); iter != hist.rend(); ++iter){
        std::cout << iter->first << ": ";
        for (char c: iter->second) {
            std::cout << c;
            std::cout << ", "; //TODO: don't print after last entry.
        }
        std::cout << '\n';
    } 
}