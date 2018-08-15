#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> permute_str(std::string s) {
    /* Permute a string in lexiographic order */
    std::sort(s.begin(), s.end()); /* string must start sorted */
    std::vector<std::string> perms = {s};
    while (true) {
        int k = -1;
        int l = -1;
        /* Find the largest index k such that s[k] < sk + 1] */
        for (int i = 0; i < (s.length()-1); i++) {
            if (s.at(i) < s.at(i+1)) {
                k = i;
            }
        }
        /* If no such index exists, we are done. */
        if (k == -1) {
            return perms;
        }
        /* Find the largest index l greater than k such that s[k] < s[l] */
        for (int i = 0; i < s.length(); i++) {
            if (s.at(k) < s.at(i)) {
                l = i;
            }
        }
        std::iter_swap(s.begin()+k, s.begin()+l);/* Swap the value of s[k] with that of s[l] */
        std::reverse(s.begin()+k+1, s.end());
        perms.push_back(s);
    }
}

int main() {
    // Get input
    std::cout << "> ";
    std::string in;
    getline(std::cin, in);
    std::vector<std::string> perms = permute_str(in);
    for (std::string s: perms) {
        std::cout << s << '\n';
    }
}