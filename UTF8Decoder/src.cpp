/*
Name: Dalton Neely
Date: August 30 2017
Title: UTF8 Decoder (Homework One)
Class: CSCI 450
Due: September 1 2017
Description: A program that takes the encoded UTF-8, and converts that binary string into a Hex and decimal representation.
Test Input: 11110000 10010000 10001101 10001000
*/

#include <iostream>
#include <string>
#include <bitset>
#include <math.h>
#include <iomanip>

using namespace std;


int stringToIntBinary(string binary) {
	int lenght = binary.length();
	int sum = 0;
	for (int i = 0, j = lenght; i < lenght; i++, j--) {
		if (binary[i] == '1') {
			sum += pow(2, j-1);
		}
	}
	return sum;
}

int decode(unsigned int *UTF8, int bytes) {
	unsigned int mask;
	unsigned int result, sumbits;
	string output = "";
	mask = 7;
	result = UTF8[0] & mask;
	output += bitset<3>(result).to_string();
	for (int i = 0; i < 3; i++) {
		mask = 63;
		result = UTF8[i + 1] & mask;
		output += bitset<6>(result).to_string();
	}

	return stringToIntBinary(output);
}

int main(int argc, char *argv[]) {
	unsigned int UTF8[4];
	string binary[4];
	cout << "Please enter in the 4 bytes in binary that represent the encoded UTF-8." << endl;
	for (int i = 0; i < 4; i++)
		cin >> binary[i];
	for (int i = 0; i < 4; i++)
		UTF8[i] = (unsigned int)stringToIntBinary(binary[i]);
	cout << "U+" << setbase(16) << decode(UTF8, 4) << " is the unicode" << endl;
	system("pause");
	return 0;
}