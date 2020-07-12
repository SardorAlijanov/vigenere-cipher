#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <iterator> 
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> namesOfOperation = {"encrypt", "decrypt"};
map<char, int> aphabet;
map<int, char> reversedAphabet;
map<int, char> result;

	class Script
	{
	public:
		virtual void invoker(string operation) = 0;
		virtual void executor(string word, string keyword) = 0;

		void process(string operation);

		bool isValid(string text);

		void setWord(string word);
		string getWord();

		void setKeyword(string keyword);
		string getKeyword();

		void shrinker(string& text);

		void showResult();

		Script();
		~Script();

	private:
		string word;
		string keyword;
	};

	inline void Script::process(string operation)
	{
		do
		{
			printf("\nEnter message to %s: ",operation.c_str());
			
			cin.ignore();
			getline(cin, this->word);

		} while (!isValid(this->word));
		setWord(this->word);

		do
		{
			cout << "\nEnter a keyword: ";

			getline(cin, this->keyword);

		} while (!isValid(this->keyword));
		setKeyword(this->keyword);

		shrinker(this->word);
		shrinker(this->keyword);

		executor(this->word, this->keyword);
	}

	inline bool Script::isValid(string text)
	{
		bool state = true;
		for (size_t i = 0; i < text.size(); i++)
		{
			if (!isalpha(text[i]) && !isspace(text[i]))
			{
				state = false;
			}
		}
		return state;
	}

	inline void Script::shrinker(string& text) {
		for (size_t i = 0; i < text.size(); i++)
		{
			tolower(text[i]);
		}
	}

	inline void Script::showResult()
	{
		cout << "Result: ";
		for (size_t i = 0; i < result.size(); i++)
		{
			cout << result.find(i)->second;
		}
	}

	inline void Script::setWord(string word)
	{
		this->word = word;
	}

	inline string Script::getWord()
	{
		return this->word;
	}

	inline void Script::setKeyword(string keyword)
	{
		this->keyword = keyword;
	}

	inline string Script::getKeyword()
	{
		return this->keyword;
	}

	Script::Script()
	{
	}

	Script::~Script()
	{
	}