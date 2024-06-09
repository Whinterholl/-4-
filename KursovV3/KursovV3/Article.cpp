#include "Article.h"

// конструктор
Article::Article(std::string line)
{
    this->line = line;

    // Добавляем заглавные русские буквы в множество
    for (char c = 'А'; c <= 'Я'; ++c) symbols.insert(c);

    // Добавляем заглавные английские буквы в множество
    for (char c = 'A'; c <= 'Z'; ++c) symbols.insert(c);


    // Добавляем буквы английского алфавита в множество
    for (char c = 'A'; c <= 'Z'; ++c) alphabet.insert(c);

    for (char c = 'a'; c <= 'z'; ++c) alphabet.insert(c);


    // Добавляем буквы русского алфавита в множество
    for (char c = 'А'; c <= 'Я'; ++c) alphabet.insert(c);

    for (char c = 'а'; c <= 'я'; ++c) alphabet.insert(c);

    // Добавляем цифры
    for (int i = 0; i < 10; i++) chislo.insert(i);
}

// иноформация о книге
std::string Article::zaglInformationArticle()
{
    int sumUp = 0;
    int k = 0;
    int author = 0;

    bool a1 = true;

    // переписываем все заглавие
    while (!numbers.count(line[0]))
    {
        nameBook += line[0];
        line.erase(0, 1);
    }
    while (!alphabet.count(line[0])) line.erase(0, 1);
    // -------------------------

    // наличие сведений относящихся к заглавию
    sumUp = upperSum(0, fName, line);

    if (sumUp > 9)
    {
        int a = 0;

        // отсчитываем
        do
        {
            otvBook += line[0];
            line.erase(0, 1);

            if (symbols.count(line[0])) a++;
        } 
        while (a < 9);

        while (!numbers.count(line[0])) line.erase(0, 1);
        while (!alphabet.count(line[0])) line.erase(0, 1);

        otvBook += " [и др.]";

        a1 = false; // сведений к заглавию нет
    }
    else if (sumUp >= 3)
    {
        while (!symbols.count(line[0]))
        {
            otvBook += line[0];
            line.erase(0, 1);
        }
        while (!alphabet.count(line[0])) line.erase(0, 1);

        a1 = false; // сведений к заглавию нет
    }
    else if (sumUp >= 1)
    {
        return line; // нашли город
    }
    else
    {
        while (!numbers.count(line[0]))
        {
            zaglBook += line[0];
            line.erase(0, 1);
        }
        while (!alphabet.count(line[0])) line.erase(0, 1);

        a1 = true; // сведения к заглавию есть
    }
    // --------------------------------------------------------------------------------- //

    // -------------------------------- Сведения об ответственности -------------------------------- //
    sumUp = upperSum(0, fName, line);

    int sz = 0;

    if (a1 && sumUp >= 3) // есть сведения к заглавию и далее есть авторы
    {
        do
        {
            if (symbols.count(line[0]))
            {
                otvBook += line[0];
                sz++;
            }
            else otvBook += line[0];

            line.erase(0, 1);
        } 
        while (sz <= 9 && !numbers.count(line[0]));

        if (sz > 9) otvBook += " [и др.]"; // если авторов больше 3

        while (!alphabet.count(line[0])) line.erase(0, 1);
    }
    else if (!a1 && sumUp >= 3)
    {
        while (sz <= 9 && !numbers.count(line[0]))
        {
            if (symbols.count(line[0])) sz++;

            sumOtvBook += line[0];
            line.erase(0, 1);
        }

        if (sz == 9) sumOtvBook += " [и др.]"; // если авторов больше 3    

        while (!alphabet.count(line[0])) line.erase(0, 1);

        return line;
    }
    else if (sumUp >= 1) return line; // город

    sz = 0;
    sumUp = upperSum(0, fName, line);

    // доп сведения об ответственности
    if (sumUp >= 3)
    {
        while (sz <= 9 && !numbers.count(line[0]))
        {
            if (symbols.count(line[0])) sz++;

            sumOtvBook += line[0];
            line.erase(0, 1);
        }

        if (sz == 9) sumOtvBook += " [и др.]"; // если авторов больше 3    

        while (!alphabet.count(line[0])) line.erase(0, 1);
    }

    return line;
}

// удаление лишних пробелов
void Article::symbol()
{
    authorNameFirst = del(authorNameFirst);

    std::string first;
    std::string middle;
    std::string last;
    std::string newName;
    bool fZnak = false;

    int i = 0;

    if (alphabet.count(authorNameFirst[1]))
    {
        if (authorNameFirst[i + 1] == '.') fZnak = true;

        while (i != authorNameFirst.size())
        {
            while (alphabet.count(authorNameFirst[i]))
            {
                first += authorNameFirst[i];
                i++;
            }

            while (!alphabet.count(authorNameFirst[i])) i++;

            while (alphabet.count(authorNameFirst[i]))
            {
                middle = authorNameFirst[i];
                i++;
            }

            while (!alphabet.count(authorNameFirst[i])) i++;

            while (alphabet.count(authorNameFirst[i]))
            {
                last = authorNameFirst[i];
                i++;
            }

            if (!fZnak)
            {
                authorName += middle;
                authorName += ". ";
                authorName += last;
                authorName += ". ";
                authorName += first;
            }
            else
            {
                authorName += first;
                authorName += ". ";
                authorName += middle;
                authorName += ". ";
                authorName += last;

                fZnak = false;
            }

            while (!alphabet.count(authorNameFirst[i]) && i != authorNameFirst.size()) i++;

            if (authorNameOther.size() != 0) authorName += ", ";
        }
    }

    authorNameOther = del(authorNameOther);
    newName = delSymbol(authorNameOther);
    if (newName != "") authorNameOther = newName;

    name = del(name);
    zagl = del(zagl);

    otv = del(otv);
    newName = delSymbol(otv);
    if (newName != "") otv = newName;

    city = del(city);
    namePlace = del(namePlace);
    year = del(year);
    height = del(height);
    nameBook = del(nameBook);
    zaglBook = del(zaglBook);

    otvBook = del(otvBook);
    newName = delSymbol(otvBook);
    if (newName != "") otvBook = newName;

    sumOtvBook = del(sumOtvBook);
    newName = delSymbol(sumOtvBook);
    if (newName != "") sumOtvBook = newName;
}

// проверка ошибок
int Article::errors()
{
    // ошибки в первом авторе
    if (authorNameFirst != "")
    {
        for (int i = 0; i < authorNameFirst.size(); i++)
        {
            if (chislo.count(authorNameFirst[i])) return 1;
        }
    }

    // ошибки в остальных авторах
    if (authorNameOther != "")
    {
        for (int i = 0; i < authorNameOther.size(); i++)
        {
            if (chislo.count(authorNameOther[i])) return 2;
        }
    }

    // ошибка в ответственности
    if (otv != "")
    {
        for (int i = 0; i < otv.size(); i++)
        {
            if (chislo.count(otv[i])) return 3;
        }
    }

    // ошибка в ответственности
    if (otvBook != "")
    {
        for (int i = 0; i < otvBook.size(); i++)
        {
            if (chislo.count(otvBook[i])) return 4;
        }
    }

    // ошибка в ответственности
    if (sumOtvBook != "")
    {
        for (int i = 0; i < sumOtvBook.size(); i++)
        {
            if (chislo.count(sumOtvBook[i])) return 5;
        }
    }

    return 6;
}

// проверка города и до конца
int Article::cityes()
{
    // город
    while (!numbers.count(line[0]))
    {
        if (chislo.count(line[0])) return 1; // цифра в названии города

        city += line[0];
        line.erase(0, 1);
    }

    while (!alphabet.count(line[0])) line.erase(0, 1);
    // ----------------------------------

    // издательство
    while (!numbers.count(line[0]) && line[0] != ',')
    {
        if (chislo.count(line[0])) return 2; // цифра в названии издательства

        namePlace += line[0];
        line.erase(0, 1);

        if (alphabet.count(line[0]) && line[1] == '-' && alphabet.count(line[2])) 
        {
            namePlace += line[0];
            namePlace += line[1];
            line.erase(0, 2);
        }
    }

    while (!isdigit(line[0])) line.erase(0, 1);
    // ----------------------------------

    // год издания
    while (!numbers.count(line[0]) && line[0] != '.')
    {
        if (isalpha(line[0])) return 3; // буква в году

        year += line[0];
        line.erase(0, 1);
    }

    while ((alphabet.count(line[0]) || numbers.count(line[0])) || (line[0] == ' ' || line[0] == '.')) line.erase(0, 1);
    // ----------------------------------

    // страница
    while (line.size() != 0)
    {
        if (alphabet.count(line[0])) return 4; // буква в страницах

        height += line[0];
        line.erase(0, 1);
    }
    // ----------------------------------

    return 5;
}

// создаем ссылку
std::string Article::addLine()
{
    // добавляем автора
    line += authorNameFirst;
    line += "$";
    if (authorNameFirst != "")
    {
        line += " ";
    }

    // добавляем название СТАТЬИ
    line += name;
    if (zagl != "") line += ": ";
    else if (authorNameFirst != "" || otv != "") line += " / ";
    else line += " // ";

    // добавляем сведения относящиеся к заглавию СТАТЬИ
    if (zagl != "")
    {
        line += zagl;
        if (authorNameFirst != "" || otv != "") line += " / ";
        else line += " // ";
    }

    // добавляем сведения об ответственности СТАТЬИ
    if (authorNameFirst != "")
    {
        line += authorName;
        if (authorNameOther != "") line += authorNameOther;

        if (otv.find(authorName) != std::string::npos)
        {
            otv.erase(otv.find(authorName), authorName.size());
        }
        if (otv != "") line += "; ";
        else line += " // ";
    }

    // добавляем дополнительные сведения об ответственности СТАТЬИ
    if (otv != "")
    {
        line += otv;
        line += " // ";
    }

    // добавляем название КНИГИ
    line += nameBook;
    if (zaglBook != "") line += ": ";
    else if (otvBook != "" || sumOtvBook != "") line += " / ";
    else 
    {
        if (zaglBook[zaglBook.size() - 1] != '.') line += ". - ";
        else line += " - ";
    }

    // добавляем сведения относящиеся к заглавию КНИГИ
    if (zaglBook != "")
    {
        line += zaglBook;
        if (otvBook != "" || sumOtvBook != "") line += " / ";
        else line += " // ";
    }

    // добавляем сведения об ответственности КНИГИ
    if (otvBook != "")
    {
        line += otvBook;
        if (sumOtvBook != "") line += "; ";
        else 
        {
            if (otvBook[otvBook.size() - 1] != '.') line += ". - ";
            else line += " - ";
        }
    }

    // добавляем дополнительные сведения об ответственности КНИГИ
    if (sumOtvBook != "")
    {
        line += sumOtvBook;
        
        if (sumOtvBook[sumOtvBook.size() - 1] != '.') line += ". - ";
        else line += " - ";
    }

    // добавялем город
    line += city;
    line += ": ";

    // добавляем название издательства
    line += namePlace;
    line += ", ";

    // добавляем год
    line += year;
    
    if (year[year.size() - 1] != '.') line += ". - ";
    else line += " - ";

    // добавляем местоположение
    line += height;
    if (height.find('с') == std::string::npos) line += " c.";

    return line;
}
