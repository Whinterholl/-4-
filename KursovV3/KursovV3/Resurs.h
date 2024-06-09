#pragma once

#include "Book.h"

class Resurs : public Book
{
private:
	std::string typeRes;
	std::string access;
	std::string date;

public:

	Resurs::Resurs() {};
	Resurs::Resurs(std::string line);

	void symbol() override;

	int cityes() override;

	std::string addLine() override;
};

