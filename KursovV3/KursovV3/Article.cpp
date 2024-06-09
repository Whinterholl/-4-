#include "Article.h"

// �����������
Article::Article(std::string line)
{
    this->line = line;

    // ��������� ��������� ������� ����� � ���������
    for (char c = '�'; c <= '�'; ++c) symbols.insert(c);

    // ��������� ��������� ���������� ����� � ���������
    for (char c = 'A'; c <= 'Z'; ++c) symbols.insert(c);


    // ��������� ����� ����������� �������� � ���������
    for (char c = 'A'; c <= 'Z'; ++c) alphabet.insert(c);

    for (char c = 'a'; c <= 'z'; ++c) alphabet.insert(c);


    // ��������� ����� �������� �������� � ���������
    for (char c = '�'; c <= '�'; ++c) alphabet.insert(c);

    for (char c = '�'; c <= '�'; ++c) alphabet.insert(c);

    // ��������� �����
    for (int i = 0; i < 10; i++) chislo.insert(i);
}

// ����������� � �����
std::string Article::zaglInformationArticle()
{
    int sumUp = 0;
    int k = 0;
    int author = 0;

    bool a1 = true;

    // ������������ ��� ��������
    while (!numbers.count(line[0]))
    {
        nameBook += line[0];
        line.erase(0, 1);
    }
    while (!alphabet.count(line[0])) line.erase(0, 1);
    // -------------------------

    // ������� �������� ����������� � ��������
    sumUp = upperSum(0, fName, line);

    if (sumUp > 9)
    {
        int a = 0;

        // �����������
        do
        {
            otvBook += line[0];
            line.erase(0, 1);

            if (symbols.count(line[0])) a++;
        } 
        while (a < 9);

        while (!numbers.count(line[0])) line.erase(0, 1);
        while (!alphabet.count(line[0])) line.erase(0, 1);

        otvBook += " [� ��.]";

        a1 = false; // �������� � �������� ���
    }
    else if (sumUp >= 3)
    {
        while (!symbols.count(line[0]))
        {
            otvBook += line[0];
            line.erase(0, 1);
        }
        while (!alphabet.count(line[0])) line.erase(0, 1);

        a1 = false; // �������� � �������� ���
    }
    else if (sumUp >= 1)
    {
        return line; // ����� �����
    }
    else
    {
        while (!numbers.count(line[0]))
        {
            zaglBook += line[0];
            line.erase(0, 1);
        }
        while (!alphabet.count(line[0])) line.erase(0, 1);

        a1 = true; // �������� � �������� ����
    }
    // --------------------------------------------------------------------------------- //

    // -------------------------------- �������� �� ��������������� -------------------------------- //
    sumUp = upperSum(0, fName, line);

    int sz = 0;

    if (a1 && sumUp >= 3) // ���� �������� � �������� � ����� ���� ������
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

        if (sz > 9) otvBook += " [� ��.]"; // ���� ������� ������ 3

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

        if (sz == 9) sumOtvBook += " [� ��.]"; // ���� ������� ������ 3    

        while (!alphabet.count(line[0])) line.erase(0, 1);

        return line;
    }
    else if (sumUp >= 1) return line; // �����

    sz = 0;
    sumUp = upperSum(0, fName, line);

    // ��� �������� �� ���������������
    if (sumUp >= 3)
    {
        while (sz <= 9 && !numbers.count(line[0]))
        {
            if (symbols.count(line[0])) sz++;

            sumOtvBook += line[0];
            line.erase(0, 1);
        }

        if (sz == 9) sumOtvBook += " [� ��.]"; // ���� ������� ������ 3    

        while (!alphabet.count(line[0])) line.erase(0, 1);
    }

    return line;
}

// �������� ������ ��������
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

// �������� ������
int Article::errors()
{
    // ������ � ������ ������
    if (authorNameFirst != "")
    {
        for (int i = 0; i < authorNameFirst.size(); i++)
        {
            if (chislo.count(authorNameFirst[i])) return 1;
        }
    }

    // ������ � ��������� �������
    if (authorNameOther != "")
    {
        for (int i = 0; i < authorNameOther.size(); i++)
        {
            if (chislo.count(authorNameOther[i])) return 2;
        }
    }

    // ������ � ���������������
    if (otv != "")
    {
        for (int i = 0; i < otv.size(); i++)
        {
            if (chislo.count(otv[i])) return 3;
        }
    }

    // ������ � ���������������
    if (otvBook != "")
    {
        for (int i = 0; i < otvBook.size(); i++)
        {
            if (chislo.count(otvBook[i])) return 4;
        }
    }

    // ������ � ���������������
    if (sumOtvBook != "")
    {
        for (int i = 0; i < sumOtvBook.size(); i++)
        {
            if (chislo.count(sumOtvBook[i])) return 5;
        }
    }

    return 6;
}

// �������� ������ � �� �����
int Article::cityes()
{
    // �����
    while (!numbers.count(line[0]))
    {
        if (chislo.count(line[0])) return 1; // ����� � �������� ������

        city += line[0];
        line.erase(0, 1);
    }

    while (!alphabet.count(line[0])) line.erase(0, 1);
    // ----------------------------------

    // ������������
    while (!numbers.count(line[0]) && line[0] != ',')
    {
        if (chislo.count(line[0])) return 2; // ����� � �������� ������������

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

    // ��� �������
    while (!numbers.count(line[0]) && line[0] != '.')
    {
        if (isalpha(line[0])) return 3; // ����� � ����

        year += line[0];
        line.erase(0, 1);
    }

    while ((alphabet.count(line[0]) || numbers.count(line[0])) || (line[0] == ' ' || line[0] == '.')) line.erase(0, 1);
    // ----------------------------------

    // ��������
    while (line.size() != 0)
    {
        if (alphabet.count(line[0])) return 4; // ����� � ���������

        height += line[0];
        line.erase(0, 1);
    }
    // ----------------------------------

    return 5;
}

// ������� ������
std::string Article::addLine()
{
    // ��������� ������
    line += authorNameFirst;
    line += "$";
    if (authorNameFirst != "")
    {
        line += " ";
    }

    // ��������� �������� ������
    line += name;
    if (zagl != "") line += ": ";
    else if (authorNameFirst != "" || otv != "") line += " / ";
    else line += " // ";

    // ��������� �������� ����������� � �������� ������
    if (zagl != "")
    {
        line += zagl;
        if (authorNameFirst != "" || otv != "") line += " / ";
        else line += " // ";
    }

    // ��������� �������� �� ��������������� ������
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

    // ��������� �������������� �������� �� ��������������� ������
    if (otv != "")
    {
        line += otv;
        line += " // ";
    }

    // ��������� �������� �����
    line += nameBook;
    if (zaglBook != "") line += ": ";
    else if (otvBook != "" || sumOtvBook != "") line += " / ";
    else 
    {
        if (zaglBook[zaglBook.size() - 1] != '.') line += ". - ";
        else line += " - ";
    }

    // ��������� �������� ����������� � �������� �����
    if (zaglBook != "")
    {
        line += zaglBook;
        if (otvBook != "" || sumOtvBook != "") line += " / ";
        else line += " // ";
    }

    // ��������� �������� �� ��������������� �����
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

    // ��������� �������������� �������� �� ��������������� �����
    if (sumOtvBook != "")
    {
        line += sumOtvBook;
        
        if (sumOtvBook[sumOtvBook.size() - 1] != '.') line += ". - ";
        else line += " - ";
    }

    // ��������� �����
    line += city;
    line += ": ";

    // ��������� �������� ������������
    line += namePlace;
    line += ", ";

    // ��������� ���
    line += year;
    
    if (year[year.size() - 1] != '.') line += ". - ";
    else line += " - ";

    // ��������� ��������������
    line += height;
    if (height.find('�') == std::string::npos) line += " c.";

    return line;
}
