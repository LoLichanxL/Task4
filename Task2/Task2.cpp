// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
int charToInt(char c) {
	return (int)c - 48;
}
void sum(std::string max, std::string min, int diff) {
	char result[1001] = {};
	int current_remainder = 0;
	for (int i = max.size() - 1; i >= 0; i--) {
		if (i - diff >= 0) {
			int res = (charToInt(max[i]) + charToInt(min[i - diff]) + current_remainder) % 10;
			current_remainder = ((int)max[i] - 48 + (int)min[i - diff] - 48 + current_remainder) / 10;
			result[i + 1] = (char)(res + 48);
		}
		else
		{
			int res = ((int) max[i] - 48 + current_remainder) % 10;
			current_remainder = ((int)max[i] - 48 + current_remainder) / 10;
			result[i + 1] = (char)(res + 48);
		}
		result[0] = char(current_remainder + 48);
	}
	for (int i = 0; i < max.size() + 1; i++) {
		if (i == 0 && result[0] == '0') {

		}
		else {
			std::cout << result[i];
		} 
	}
}


void multiply(int a[], int b[], int len_a, int len_b) {
	int res[2000] = {};
	for (int i = 0; i < len_b - 1; ++i) {
		int carry = 0;
		for (int j = 0; j < len_a - 1; ++j) {
			res[i + j] += carry + a[i] * b[j];
			carry = res[i + j] / 10;
			res[i + j] = res[i + j] % 10;
		}
		res[i + len_a - 1] += carry;
	}
	for (int i = 0; i < len_a + len_b;i++) {
		std::cout << res[i];
	}
}
int main()
{
	std::ifstream in("input.txt", std::ios::in);
	std::string a;
	std::string b;
	in >> a;
	in >> b;
	std::string sum_result;
	if (a.size() <= b.size()) {
		sum(b, a, b.size() - a.size());
	}
	else {
		sum(a, b, a.size() - b.size());
	}
	int aa[3] = { 3,3,2 };
	int bb[3] = { 3,3,3 };

	std::cout << std::endl;
	multiply(aa, bb, 3, 3);
}





