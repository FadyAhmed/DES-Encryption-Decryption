#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int choice1_permutation_table[56] = { 57, 49, 41, 33, 25, 17, 9,
				1, 58, 50, 42, 34, 26, 18,
				10, 2, 59, 51, 43, 35, 27,
				19, 11, 3, 60, 52, 44, 36,
				63, 55, 47, 39, 31, 23, 15,
				7, 62, 54, 46, 38, 30, 22,
				14, 6, 61, 53, 45, 37, 29,
				21, 13, 5, 28, 20, 12, 4 };

int shift_size_table[16] = { 1, 1, 2, 2,
						2, 2, 2, 2,
						1, 2, 2, 2,
						2, 2, 2, 1 };

int choice2_permutation_table[48] = { 14, 17, 11, 24, 1, 5,
						3, 28, 15, 6, 21, 10,
						23, 19, 12, 4, 26, 8,
						16, 7, 27, 20, 13, 2,
						41, 52, 31, 37, 47, 55,
						30, 40, 51, 45, 33, 48,
						44, 49, 39, 56, 34, 53,
						46, 42, 50, 36, 29, 32 };

int initial_permutation_table[64] = { 58, 50, 42, 34, 26, 18, 10, 2,
						 60, 52, 44, 36, 28, 20, 12, 4,
						 62, 54, 46, 38, 30, 22, 14, 6,
						 64, 56, 48, 40, 32, 24, 16, 8,
						 57, 49, 41, 33, 25, 17, 9, 1,
						 59, 51, 43, 35, 27, 19, 11, 3,
						 61, 53, 45, 37, 29, 21, 13, 5,
						 63, 55, 47, 39, 31, 23, 15, 7 };

int expansion_permutaion_table[48] = { 32, 1, 2, 3, 4, 5, 4, 5,
				6, 7, 8, 9, 8, 9, 10, 11,
				12, 13, 12, 13, 14, 15, 16, 17,
				16, 17, 18, 19, 20, 21, 20, 21,
				22, 23, 24, 25, 24, 25, 26, 27,
				28, 29, 28, 29, 30, 31, 32, 1 };

int s_box[8][4][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
						0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
						4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
						15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 },
						{ 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
						3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
						0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
						13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 },

						{ 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
						13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
						13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
						1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 },
						{ 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
						13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
						10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
						3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 },
						{ 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
						14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
						4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
						11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },
						{ 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
						10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
						9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
						4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },
						{ 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
						13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
						1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
						6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },
						{ 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
						1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
						7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
						2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };

int function_last_permutation[32] = { 16, 7, 20, 21,
				29, 12, 28, 17,
				1, 15, 23, 26,
				5, 18, 31, 10,
				2, 8, 24, 14,
				32, 27, 3, 9,
				19, 13, 30, 6,
				22, 11, 4, 25 };

int inverse_permutation[64] = { 40, 8, 48, 16, 56, 24, 64, 32,
						39, 7, 47, 15, 55, 23, 63, 31,
						38, 6, 46, 14, 54, 22, 62, 30,
						37, 5, 45, 13, 53, 21, 61, 29,
						36, 4, 44, 12, 52, 20, 60, 28,
						35, 3, 43, 11, 51, 19, 59, 27,
						34, 2, 42, 10, 50, 18, 58, 26,
						33, 1, 41, 9, 49, 17, 57, 25 };

string hexa_to_binary(string s) {
	unordered_map<char, string> hex_bin;
	hex_bin['0'] = "0000";
	hex_bin['1'] = "0001";
	hex_bin['2'] = "0010";
	hex_bin['3'] = "0011";
	hex_bin['4'] = "0100";
	hex_bin['5'] = "0101";
	hex_bin['6'] = "0110";
	hex_bin['7'] = "0111";
	hex_bin['8'] = "1000";
	hex_bin['9'] = "1001";
	hex_bin['A'] = "1010";
	hex_bin['B'] = "1011";
	hex_bin['C'] = "1100";
	hex_bin['D'] = "1101";
	hex_bin['E'] = "1110";
	hex_bin['F'] = "1111";

	string out = "";
	for (int i = 0; i < s.size(); i++) {
		out += hex_bin[s[i]];
	}
	return out;
}

string binary_to_hexa(string s) {
	unordered_map<string, string> bin_hexa;
	bin_hexa["0000"] = "0";
	bin_hexa["0001"] = "1";
	bin_hexa["0010"] = "2";
	bin_hexa["0011"] = "3";
	bin_hexa["0100"] = "4";
	bin_hexa["0101"] = "5";
	bin_hexa["0110"] = "6";
	bin_hexa["0111"] = "7";
	bin_hexa["1000"] = "8";
	bin_hexa["1001"] = "9";
	bin_hexa["1010"] = "A";
	bin_hexa["1011"] = "B";
	bin_hexa["1100"] = "C";
	bin_hexa["1101"] = "D";
	bin_hexa["1110"] = "E";
	bin_hexa["1111"] = "F";

	string out = "";
	for (int i = 0; i < s.size(); i += 4) {
		out += bin_hexa[s.substr(i, 4)];
	}
	return out;
}

string permute(string input, int* arrayOfPermutation, int outputSize)
{
	string permutedText = "";
	for (int i = 0; i < outputSize; i++) {
		permutedText += input[arrayOfPermutation[i] - 1];
	}
	return permutedText;
}

string lift_shift_s(string key, int round)
{
	int noOfShifts = shift_size_table[round];
	string s = "";

	for (int i = 0; i < noOfShifts; i++) {
		// this loop for one bit shift
		for (int j = 1; j < 28; j++) {
			s += key[j];
		}
		s += key[0];
		key = s;
		s = "";
	}
	return key;
}

string xor_strings(string a, string b)
{
	string s = "";
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b[i]) {
			s += "0";
		}
		else {
			s += "1";
		}
	}
	return s;
}

string roundFunction(string leftText, string rightText, string functionKey) {
	string rightTextExpanded = permute(rightText, expansion_permutaion_table, 48);

	string function_xor_result = xor_strings(rightTextExpanded, functionKey);

	////////
	// do the s-box
	string subResult = "";
	for (int i = 0; i < 8; i++) {
		int row = 2 * int(function_xor_result[i * 6] - '0') +
			int(function_xor_result[i * 6 + 5] - '0');
		int col = 8 * int(function_xor_result[i * 6 + 1] - '0') +
			4 * int(function_xor_result[i * 6 + 2] - '0') +
			2 * int(function_xor_result[i * 6 + 3] - '0') +
			int(function_xor_result[i * 6 + 4] - '0');
		int val = s_box[i][row][col];
		subResult += char(val / 8 + '0');
		val = val % 8;
		subResult += char(val / 4 + '0');
		val = val % 4;
		subResult += char(val / 2 + '0');
		val = val % 2;
		subResult += char(val + '0');
	}

	string rightResult = xor_strings(leftText, permute(subResult, function_last_permutation, 32));

	return rightResult;
}

int main(int argc, char* argv[]) {
	string operation = argv[1];

	string cipher = "";
	vector<string> roundsKeys;
	string text = argv[2];
	string key = argv[3];

	key = hexa_to_binary(key);

	// do choice 1 permutation
	key = permute(key, choice1_permutation_table, 56);

	string leftKey = key.substr(0, 28);
	string rightKey = key.substr(28, 28);

	string binaryText = hexa_to_binary(text);
	// do text initial permutation
	binaryText = permute(binaryText, initial_permutation_table, 64);

	string leftBinaryText = binaryText.substr(0, 32);
	string rightBinaryText = binaryText.substr(32, 32);

	// generate keys
	for (int i = 0; i < 16; i++) {
		// now we need to generate key for each round
		leftKey = lift_shift_s(leftKey, i);
		rightKey = lift_shift_s(rightKey, i);


		// make perm choice 2 
		string thisRoundFunctionKey = permute(leftKey + rightKey, choice2_permutation_table, 48);

		// to save it for decryption
		roundsKeys.push_back(thisRoundFunctionKey);
	}

	for (int i = 0; i < 16; i++) {
		// do the round
		string rightResult;

		if (operation == "encrypt") {
			rightResult = roundFunction(leftBinaryText, rightBinaryText, roundsKeys[i]);
		}
		else {
			rightResult = roundFunction(leftBinaryText, rightBinaryText, roundsKeys[16 - i - 1]);
		}

		leftBinaryText = rightResult;

		if (i < 15) {
			swap(leftBinaryText, rightBinaryText);
		}
	}
	cipher = binary_to_hexa(permute(leftBinaryText + rightBinaryText, inverse_permutation, 64));
	if (operation == "encrypt") {
		cout << "cipher: " << cipher << "\n";
	}
	else {
		cout << "plain: " << cipher << "\n";
	}

	return 0;
}