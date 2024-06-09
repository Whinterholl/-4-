#pragma once

#include "Book.h"

class Dissertation : public Book
{
private:
	std::string code;
	std::string dateZ;
	std::string dateU;
	std::string otvOther;

public:
	Dissertation::Dissertation() {};
	Dissertation::Dissertation(std::string line);

	void symbol() override;

	int cityes() override;
	int zaglInformation();

	std::string addLine() override;
};

