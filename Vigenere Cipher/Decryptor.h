#pragma once
#include "Main.h"

class Decryptor:public Script
{
public:
	void invoker(string operation);
	void executor(string word, string keyword);

	Decryptor();
	~Decryptor();

private:
	string word;
	string keyword;
};

inline void Decryptor::invoker(string operation)
{
	process(operation);
}

inline void Decryptor::executor(string word, string keyword)
{
	int j = 0;
	int wordIndex = 0;
	int keyIndex = 0;
	int resultIndex = 0;
	
	for (size_t i = 0; i < word.size(); i++, j++)
	{
		if (j == keyword.size())
		{
			j = 0;
		}
		if (word[i] == ' ')
		{
			result.insert(make_pair(i,' '));
			j--;
		}
		else {
			wordIndex = aphabet.find(word[i])->second;
			keyIndex = aphabet.find(keyword[j])->second;
			resultIndex = (wordIndex - keyIndex + 26) % 26;
			result.insert(make_pair(i, reversedAphabet.find(resultIndex)->second));
		}
	}

	showResult();
}

Decryptor::Decryptor()
{	
}

Decryptor::~Decryptor()
{
}