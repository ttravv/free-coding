#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int countCommonElements(vector<int>& list1, vector<int>& list2) {
    unordered_set<int> set1(list1.begin(), list1.end());
    int count = 0;
    for (int num : list2) {
        if (set1.find(num) != set1.end()) {
            count++; 
            set1.erase(num);
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> firstArr;
    vector<int> secondArr;
    for (int i = 0; i < n; ++i) {
      int temp;
      cin >> temp;
      firstArr.push_back(temp);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
      int temp;
      cin >> temp;
      secondArr.push_back(temp);
    }

  
    int result = countCommonElements(firstArr, secondArr);
    cout << result;

    return 0;
}