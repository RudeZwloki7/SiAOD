#include <iostream>
#include <Windows.h>
#include "HufTree.h"
#include <map>


using namespace std; 


void print_table(char* arr, int* freq, int length) {
	cout << "#######################################\n#######################################\n#######################################" << endl;
	int size = strlen(arr);
	for (int i = 0; i < size; i++) {
		cout << "Alphabet: " << arr[i] << " Count: " << freq[i] << " Chance: " << (float)freq[i]/length <<endl;
	}
	cout << "#######################################\n#######################################\n#######################################" << endl;
}


void sort_table(char* arr, int* freq) {
	int size = strlen(arr);
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (freq[j] > freq[j + 1]) {
				char temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

				int temp2 = freq[j];
				freq[j] = freq[j + 1];
				freq[j + 1] = temp2;
			}

}


void build_table(string input, char* &arr, int* &freq) {

	map<char, int> temp = map<char, int>();
	int n = 0;
	for (int i = 0; i < input.length(); i++) {
		if (temp.find(input[i])!= temp.end()) {
			temp.find(input[i])->second++;
		}
		else {
			temp.insert(pair<char,int>(input[i], 1));
			n++;
		}
	}

	arr = new char[n+1];
	arr[n] = '\0';
	freq = new int[n];
	string s = "";
	int cnt = 0;
	for (auto const& element : temp) {
		arr[cnt] = element.first;
		s += element.first;
		freq[cnt] = element.second;
		cnt++;
	}

	print_table(arr, freq, input.length());
	sort_table(arr, freq);
	print_table(arr, freq, input.length());

}



int main()
{
	setlocale(LC_ALL, "rus");
	string input_data = "Аникеев Семён Александрович";
	//string input_data = "Anikeev Semyon Aleksandrovich";
	
	char* arr=NULL;
	int* freq=NULL;
	build_table(input_data, arr, freq);

	int size = strlen(arr);
	HuffmanCodes(arr, freq, size);

	return 0;

}


