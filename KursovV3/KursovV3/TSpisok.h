#pragma once

#include <iostream>
#include <algorithm>

ref class TSpisok
{
private:
	System::String^ line;
	System::String^ array;
	int n = 0;

public:
	TSpisok::TSpisok() {};

	void addSpisok(std::string book);

	System::String^ ret2Spisok() { return line; }

	std::string sortSpisok(std::string books);
};