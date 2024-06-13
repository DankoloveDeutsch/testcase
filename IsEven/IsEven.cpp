#include<iostream>

bool isEven(int num) {
	return !(num & 1);
}

int main() {
	std::cout << isEven(2)<<std::endl;
	std::cout << isEven(31) << std::endl;
}