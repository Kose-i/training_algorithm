#include <iostream>
#include <string>

std::string wind_direction_radio_make(const int& wind_dir) {
	int wind_dir_start = (10*wind_dir+1125)/1125;
	if (wind_dir_start < 2) return "N";
	else if (wind_dir_start < 4) return "NNE";
	else if (wind_dir_start < 6) return "NE";
	else if (wind_dir_start < 8) return "ENE";
	else if (wind_dir_start < 10) return "E";
	else if (wind_dir_start < 12) return "ESE";
	else if (wind_dir_start < 14) return "SE";
	else if (wind_dir_start < 16) return "SSE";
	else if (wind_dir_start < 18) return "S";
	else if (wind_dir_start < 20) return "SSW";
	else if (wind_dir_start < 22) return "SW";
	else if (wind_dir_start < 24) return "WSW";
	else if (wind_dir_start < 26) return "W";
	else if (wind_dir_start < 28) return "WNW";
	else if (wind_dir_start < 30) return "NW";
	else if (wind_dir_start < 32) return "NNW";
	return "N";
}
int wind_vel_radio_make(const int& wind_power) {
	double wind_vel = wind_power/60.0 + 0.05;
	if (wind_vel < 0.3) return 0;
	else if (wind_vel < 1.5) return 1;
	else if (wind_vel < 3.4) return 2;
	else if (wind_vel < 5.4) return 3;
	else if (wind_vel < 7.9) return 4;
	else if (wind_vel < 10.7) return 5;
	else if (wind_vel < 13.8) return 6;
	else if (wind_vel < 17.1) return 7;
	else if (wind_vel < 20.7) return 8;
	else if (wind_vel < 24.4) return 9;
	else if (wind_vel < 28.4) return 10;
	else if (wind_vel < 32.6) return 11;
	else return 12;

}

int main() {
	int wind_dir, wind_power;
	std::cin >> wind_dir >> wind_power;
	int wind_vel = wind_vel_radio_make(wind_power);
	std::string wind_direction_radio;
	if (wind_vel <= 0) {
		wind_direction_radio = "C";
	} else {
		wind_direction_radio = wind_direction_radio_make(wind_dir);
	}
	std::cout << wind_direction_radio << " " << wind_vel << '\n';
}
