// https://mos.olimpiada.ru/upload/files/Archive_tasks_2013-.../2023-24/iikt/tasks-iikt-8-otbor-23-24.pdf 
// task3

#include <iostream>
#include <vector>
#include <unordered_map>

std::pair<int, int> findSubarrayWithKDistinct(const std::vector<int>& arr, int k) {
    int n = arr.size();
    std::unordered_map<int, int> count;
    int distinct_count = 0;
    int min_length = n + 1;
    int min_left = -1;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        if (count[arr[right]] == 0) {
            ++distinct_count;
        }
        ++count[arr[right]];

        while (distinct_count == k) {
            if (right - left + 1 < min_length) {
                min_length = right - left + 1;
                min_left = left;
            }
            --count[arr[left]];
            if (count[arr[left]] == 0) {
                --distinct_count;
            }
            ++left;
        }
    }

    if (min_left == -1) {
        return { -1, -1 };
    }
    return { min_left + 1, min_left + min_length }; 
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    auto result = findSubarrayWithKDistinct(arr, k);
    if (result.first == -1) {
        std::cout << -1 << std::endl;
    }
    else {
        std::cout << result.first << " " << result.second << '\n';
    }

    return 0;
}
