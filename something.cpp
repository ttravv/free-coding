//https://leetcode.com/problems/reverse-words-in-a-string-iii/description/?envType=problem-list-v2&envId=rbtkeej1

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string reverseWords(string s) {
    vector<string> new_s;
    string word = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ') {
            new_s.push_back(word);
            word = "";
            continue;
        }
        word += s[i];
    }
    new_s.push_back(word);
    string ans = "";
    for (int i = 0; i < new_s.size(); ++i) {
        reverse(new_s[i].begin(), new_s[i].end());
        if (i != new_s.size() - 1)ans += new_s[i] + ' ';
        else ans += new_s[i];
    }
    return ans;

}

int main() {
    string s = "Let's take LeetCode contest";

    cout << reverseWords(s);
    return 0;
}