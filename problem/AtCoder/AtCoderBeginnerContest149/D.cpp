#include <iostream>
#include <string>
#include <vector>

unsigned long N, K, R, S, P;
unsigned long get_score(const char& t) {
	if (t == 'r') {
		return P;
	} else if (t == 's') {
		return R;
	} else {
		return S;
	}
}
int main(int argc, char** argv) {
	std::cin >> N >> K >> R >> S >> P;
	std::string str;
	std::cin >> str;
	unsigned long sum_score {};
	std::vector<char> str_select(N);
	for (auto i = 0;i < K && i < N;++i) {
		for (auto j = i;j < N;j += K) {
			if (0 < j-K) {
				if (str[j-K] == str[j] && str_select[j-K] == str[j]) {
					str_select[j] = 'N';
				} else {
					str_select[j] = str[j];
					sum_score += get_score(str[j]);
				}
			} else {
				str_select[j] = str[j];
				sum_score += get_score(str[j]);
			}
		}
	}
	std::cout << sum_score << '\n';
}
