#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
	unsigned N, M;
	std::cin >> N >> M;
	std::vector<unsigned long> A(N);
	for (auto& e : A) {
		std::cin >> e;
	}
	std::vector<unsigned long> A_double(N*N);
	for (auto i = 0;i < N;++i) {
		for (auto j = 0;j < N;++j) {
			A_double[i*N+j] = A[i]+A[j];
		}
	}
	std::sort(A_double.rbegin(), A_double.rend());
	unsigned long sum_score {};
	for (auto i = 0;i < M;++i) {
		sum_score += A_double[i];
	}
	std::cout << sum_score << '\n';
}
