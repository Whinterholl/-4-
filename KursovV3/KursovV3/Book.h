#pragma once

#include <iostream>
#include <regex>
#include <set>

class Book
{
protected:
	std::string line;

	std::string authorName;
	std::string authorNameFirst;
	std::string authorNameOther;
	std::string name;
	std::string zagl;
	std::string otv;
	std::string city;
	std::string namePlace;
	std::string year;
	std::string height;
	std::string series;

	int i;
	int s = 0;
	int size_t;
	int aNO = 1;

	bool f = true;
	bool fName;

public:
	std::set <char> numbers{ '/', '-', ':', ';' };
	std::set <char> symbols;
	std::set <char> alphabet;
	std::set <int> chislo;

	Book::Book() {};
	Book::Book(std::string line);

	void extractFirstThreeWords(const std::string& line, std::string& authorName, bool& f);
	void authors();
	virtual void symbol();
	
	int upperSum(int i, bool& fName, std::string line);
	virtual int cityes();
	virtual int errors();
	
	std::string del(std::string bookLine);
	std::string zaglInformation();
	std::string delSymbol(std::string lName);
	virtual std::string addLine();
};