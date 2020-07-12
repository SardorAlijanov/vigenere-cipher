#pragma once
#include "Main.h"
#include "Encryptor.h"
#include "Decryptor.h"

inline int integerInput() {
	int output = 0;
	string enteredValue;
	regex integer("[[:digit:]]");
	while (true) {
		cin >> enteredValue;
		if (!cin) break;
		if (regex_match(enteredValue, integer) && (enteredValue == "1" || enteredValue == "2")) {
			output = stoi(enteredValue);
			break;
		}
		else {
			cout << "Wrong input,re-enter: " << endl;
		}
	}
	return output;
}

inline int optionChoser() {
	cout << "What would you like to do:\n1. Encrypt a message\n2. Decrypt a message\n";

	return integerInput();
}

void optionExecutor(int option, map<int, Script*>& options) {
	try
	{
		options.find(option)->second->invoker(namesOfOperation[option - 1]);
	}
	catch (const exception& e)
	{
		system("cls");
		cout << e.what() << endl;
	}
	
}

void optionsMapFiller(map<int, Script*> &options) {
	options.insert(make_pair(1, new Encrytor()));
	options.insert(make_pair(2, new Decryptor()));
}

void alphabetFiller(map<char, int> &alphabet,int startPointOfCase) {
	for (int i = startPointOfCase, j = 0; j < 26; i++, j++)
	{
		alphabet.insert(make_pair((char)i,j));
		reversedAphabet.insert(make_pair(j, (char)i));
	}
}

int main() {
	map<int, Script*> options;

	alphabetFiller(aphabet, 97);

	optionsMapFiller(options);

	optionExecutor(optionChoser(), options);

	return 0;
}