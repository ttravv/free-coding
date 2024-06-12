#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

auto highAndLow(const string& numbers) {
	auto max = max_element(numbers.begin(), numbers.end());
	auto min = min_element(numbers.begin(), numbers.end());
	return max

}
int main() {
	string numbers = "8 3 -5 42 -1 0 0 -9 4 7 4 -4"; // '42, -9'
	cout << highAndLow(numbers);

	return 0;
}