#include <iostream>

int main(int argc, char** argv) {
	unsigned long long N; std::cin >> N;
	unsigned long long A, B; std::cin >> A >> B;
	unsigned long long max_AB = (A>B)?A:B;
	unsigned long long min_AB = (A<B)?A:B;
	if ((max_AB-min_AB)%2==0) {
		std::cout << (max_AB - min_AB)/2 << '\n';
	} else {
		unsigned long long cnt = ((max_AB - 1)<(N-min_AB))?(max_AB - 1):(N-min_AB);
		std::cout << cnt << '\n';
	}
}
