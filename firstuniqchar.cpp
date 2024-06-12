// https://leetcode.com/problems/first-unique-character-in-a-string/description/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int firstUniqChar(string s) {
    vector<int> array(26);
    for (int i = 0; i < s.length(); ++i) {
        if (array[s[i] - 'a'] != 0) {
            array[s[i] - 'a'] = -1;
        }
        else array[s[i] - 'a'] = i + 1;
    }
    int ans = s.length() + 1;

    for (int i = 0; i < 26; ++i) {
        if ((array[i] < ans) && array[i] > 0)
            ans = array[i];
    }

    if (ans == (s.length() + 1)) {
        return -1;
    }
    return ans - 1;
}

int main() {
    string s = "aadadaad"; // -1
    cout << firstUniqChar(s);

    return 0;
}