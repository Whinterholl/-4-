#include "TSpisok.h"

// сохранение правильных строк
void TSpisok::addSpisok(std::string book)
{
	array = gcnew System::String(book.c_str());

	this->line += array;
	this->line += "\n";
	n++;
}

// сортировка
std::string TSpisok::sortSpisok(std::string books)
{
    std::string l;
    std::string* arr = new std::string[n];

    bool ex = false;

    for (int i = 0; i < n; i++)
    {
        while (books.size() != 0 && !ex)
        {
            if (books[0] == '\n') ex = true;
            else l += books[0];
            books.erase(0, 1);
        }

        arr[i] = l;
        l = "";
        ex = false;
    }

    // Сортировка массива строк по алфавиту
    std::sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        l += arr[i];
        l += '\n';
    }

    return l;
}
