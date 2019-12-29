#include <iostream>
#include <vector>

unsigned N;
unsigned nCr(const unsigned& n, const unsigned& r) {
	if (r == 0 || n == 0) return n;
	return nCr(n, r-1) + nCr(n-1, r);
}
void yuurisuu(unsigned& a1, unsigned& a2) {
	a2 = (1<<N);
	a1 = nCr(N, N/2);
	for (;;) {
		if (a1 & 1 != 0)break;
		else {
			a1 >>=1;
			a2 >>=1;
		}
	}
}
int main(int argc, char** argv) {
	std::cin >> N;
	std::vector<unsigned> A(N-1);
	std::vector<unsigned> B(N-1);
	for (auto i = 0;i < N-1;++i) {
		std::cin >> A[i] >> B[i];
	}
	std::cout << "check\n";
	std::vector<unsigned long> sum_cnt(N-1, 0);
	for (auto i = 0;i < N-1;++i) {
		++sum_cnt[A[i] - 1];++sum_cnt[B[i] - 1];
	}
	unsigned x, y {};
	yuurisuu(x, y);
	std::cout <<  x << ' ' << y << '\n';
}
