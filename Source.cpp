#include <iostream>
#include <unordered_map>

using namespace std;

int choice1_permutation_table[56] = { 57, 49, 41, 33, 25, 17, 9,
				1, 58, 50, 42, 34, 26, 18,
				10, 2, 59, 51, 43, 35, 27,
				19, 11, 3, 60, 52, 44, 36,
				63, 55, 47, 39, 31, 23, 15,
				7, 62, 54, 46, 38, 30, 22,
				14, 6, 61, 53, 45, 37, 29,
				21, 13, 5, 28, 20, 12, 4 };

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
	for (int i = 0; i < s.size(); i+=4) {
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

int main() {
	string text = "ADF12505FF";
	cout << "Text: " << text<<"\n";

	text = hexa_to_binary(text);
	cout << "binary: " <<text<<"\n";

	text = binary_to_hexa(text);
	cout << "hexa: " << text << "\n";

	string key = "FAFF091A1D36BDCA";
	key = permute(hexa_to_binary(key), choice1_permutation_table, 56);
	cout <<"After choice 1 key: "<< key << "\n";

	string leftKey = key.substr(0, 28);
	string rightKey = key.substr(28, 28);

	for(int i = 0; i < 16; i++){
		// now we need to generate key for each round
		// make perm choice 2 
		// do the round
	}
	
	return 0;
}