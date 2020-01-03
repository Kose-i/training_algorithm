#include <iostream>

int main() {
	int m;
	std::cin >> m;
	int first_num, second_num;
	if (m < 100) {
		first_num = 0;
		second_num = 0;
	} else if (m<6000) {
		first_num = m/1000;
		second_num = (m/100)%10;
	} else if (m<30000) {
		first_num = (m/10000)+5;
		second_num = (m/1000)%10;
	} else {
		first_num = 8;
		second_num = 9;
	}
	std::cout << first_num << second_num << '\n';
}
