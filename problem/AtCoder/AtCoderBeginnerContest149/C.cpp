#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
	unsigned long X; std::cin >> X;
	std::vector<unsigned long> prime_box;
	for (auto i = 2;i <= X;++i) {
		bool find = false;
		for (auto prime : prime_box) {
			if (i % prime == 0) {
				find = true;
				break;
			}
		}
		if (find == false) prime_box.push_back(i);
	}
	if (std::find(prime_box.begin(), prime_box.end(), X)!=prime_box.end()) {
		std::cout << X << '\n';
		return 0;
	}
	for (auto i = X+1;;++i) {
		bool find = false;
		for (auto prime : prime_box) {
			if (i % prime == 0) {
				find = true;
				break;
			}
		}
		if (find == false) {
			std::cout << i << '\n';
			break;
		}	
	}
}
