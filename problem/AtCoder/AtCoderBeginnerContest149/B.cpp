#include <iostream>

int main(int argc, char** argv) {
	long long A, B, K;
	std::cin >> A >> B >> K;
	A = A - K;
	if (A < 0) {
		B += A;
		A = 0;
		if (B < 0) B = 0;
	}
	std::cout << A << ' ' << B << '\n';

}
