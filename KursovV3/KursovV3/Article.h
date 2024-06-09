#pragma once

#include "Book.h"

class Article : public Book
{
private:
	std::string nameBook;
	std::string zaglBook;
	std::string otvBook;
	std::string sumOtvBook;

public:
	Article::Article() {};
	Article::Article(std::string line);

	void symbol() override;

	int cityes() override;
	int errors() override;

	std::string zaglInformationArticle();
	std::string addLine() override;
};

