//https://leetcode.com/problems/word-pattern/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

bool wordPattern(const std::string& pattern, const std::string& s) {
    std::vector<std::string> words;
    std::istringstream stream(s);
    std::string word;
    while (stream >> word) {
        words.push_back(word);
    }

    if (pattern.length() != words.size()) {
        return false;
    }

    std::unordered_map<char, std::string> hash_map_pattern;
    std::unordered_map<std::string, char> hash_map_s;

    for (size_t i = 0; i < pattern.length(); ++i) {
        char p = pattern[i];
        std::string w = words[i];

        if (hash_map_pattern.find(p) == hash_map_pattern.end()) {
            hash_map_pattern[p] = w;
        }
        if (hash_map_s.find(w) == hash_map_s.end()) {
            hash_map_s[w] = p;
        }

        if (hash_map_pattern[p] != w || hash_map_s[w] != p) {
            return false;
        }
    }

    return true;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << wordPattern("abba", "dog cat cat dog") << std::endl;  // Вывод: true
    std::cout << wordPattern("abba", "dog cat cat fish") << std::endl; // Вывод: false
    std::cout << wordPattern("aaaa", "dog dog dog dog") << std::endl; // Вывод: true
    std::cout << wordPattern("abba", "dog dog dog dog") << std::endl; // Вывод: false

    return 0;
}
