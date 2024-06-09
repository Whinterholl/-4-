#include "Book.h"

// �����������
Book::Book(std::string line)
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

// �������� �� ������� �������
void Book::extractFirstThreeWords(const std::string& entry, std::string& authorName, bool& f) {
    // ���������� ��������� ��� ������ ������ ���� ����, ������������ � ��������� �����, ������
    std::regex authorTwo("^([A-Z�-ߨa-z�-��]+[,.]?\\s+[A-Z�-ߨ]+[,.]?\\s+[A-Z�-ߨ]+[,.]+[,.]?\\s+)");
    std::regex authorOne("^([A-Z�-ߨa-z�-��]+[,.]?\\s+[A-Z�-ߨ]+[,.]?[A-Z�-ߨ]+[,.]+[,.]?\\s+)");

    // ���������� std::smatch ��� ������� ����������
    std::smatch matches;
    if (std::regex_search(entry, matches, authorTwo) || std::regex_search(entry, matches, authorOne))
    {
        // ��������� ������ ��� ����� � ���������� authorName
        authorName = matches.str();
    }
    else
    {
        // ���� ���������� �� �������, ������������� authorName � ������ ������
        authorName.clear();
        f = false;
    }
}

// ������������� ������� � ����� ������
void Book::authors()
{
    int size_t1;

    while (f)
    {
        extractFirstThreeWords(line, authorName, f);

        if (s == 0 && f)
        {
            authorNameFirst = authorName;
            size_t1 = authorNameFirst.size();
            line.erase(0, size_t1);
            authorName.clear();
            s++;
        }
        else
        {
            if (aNO < 3) authorNameOther += authorName;
            size_t1 = authorName.size();
            line.erase(0, size_t1);
            if (authorName != "") aNO++;
        }

        if (authorNameFirst != "") while (line[0] == ' ') line.erase(0, 1);
    }

    if (aNO >= 3) 
    {
        authorNameOther.insert(authorNameOther.size(), "[� ��.] ");
    }
}

// �������� ��������
std::string Book::del(std::string bookLine)
{
    for (int i = bookLine.size() - 1; i > 0; i--)
    {
        while (bookLine[i] == ' ')
        {
            bookLine.erase(i, 1);
            i--;
        }
        return bookLine;
    }

    return bookLine;
}

// �������� ������
std::string Book::delSymbol(std::string lName)
{
    std::string first;
    std::string middle;
    std::string last;
    std::string authorName_1;

    bool fZnak = false;

    std::regex authorTwo("^([A-Z�-ߨa-z�-��]+[,.]?\\s+[A-Z�-ߨ]+[,.]?\\s+[A-Z�-ߨ]+[,.]?\\s+)");
    std::regex authorOne("^([A-Z�-ߨa-z�-��]+[,.]?\\s+[A-Z�-ߨ]+[,.]?[A-Z�-ߨ]+[,.]?\\s+)");
    std::regex authorThree("^([A-Z�-ߨa-z�-��]+[,.]?\\s+[A-Z�-ߨ]+[,.]?\\s+[A-Z�-ߨ]+[,.]?)");

    std::smatch match;

    while (std::regex_search(lName, match, authorTwo) || std::regex_search(lName, match, authorOne) || std::regex_search(lName, match, authorThree) || lName.size() != 0)
    {
        if (lName[1] == '.') fZnak = true;
        if (lName.find('.') == std::string::npos || lName.find(' ') == std::string::npos) return lName;

        while (lName.size() != 0)
        {
            first = "";
            middle = "";
            last = "";

            if (lName[0] == '[')
            {
                authorName_1 += " ";

                while (lName.size() != 0)
                {
                    authorName_1 += lName[0];
                    lName.erase(0, 1);
                }
                break;
            }

            while (alphabet.count(lName[0]))
            {
                first += lName[0];
                lName.erase(0, 1);
            }

            while (!alphabet.count(lName[0])) lName.erase(0, 1);

            while (alphabet.count(lName[0]))
            {
                middle += lName[0];
                lName.erase(0, 1);
            }

            while (!alphabet.count(lName[0])) lName.erase(0, 1);

            while (alphabet.count(lName[0]))
            {
                last += lName[0];
                lName.erase(0, 1);
            }

            if (!fZnak)
            {
                authorName_1 += middle;
                authorName_1 += ". ";
                authorName_1 += last;
                authorName_1 += ". ";
                authorName_1 += first;
            }
            else
            {
                authorName_1 += first;
                authorName_1 += ". ";
                authorName_1 += middle;
                authorName_1 += ". ";
                authorName_1 += last;
                
                fZnak = false;
            }

            while (!alphabet.count(lName[0]) && lName.size() != 0 && lName[0] != '[') lName.erase(0, 1);

            if (lName.size() != 0 && lName[0] != '[') authorName_1 += ", ";
        }
    }

    return authorName_1;
}

// �������� ������ ��������
void Book::symbol()
{
    authorNameFirst = del(authorNameFirst);

    std::string first;
    std::string middle;
    std::string last;
    std::string newName;
    bool fZnak = false;

    int i = 0;

    if (authorNameFirst != "" && alphabet.count(authorNameFirst[1]))
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
    series = del(series);
}

// ���� �� ������� ����� � ���� ��������� �����
int Book::upperSum(int i, bool& fName, std::string line)
{
    int sumUp = 0;

    while (!numbers.count(line[i]))
    {
        if (symbols.count(line[i]))
        {
            //if ((i == 0 && symbols.count(line[0])) || line[i - 1] == ' ' || line[i - 1] == '.')
            fName = true;
            sumUp++;
        }

        i++;

        if (line[i] == '-' && alphabet.count(line[i - 1]) && alphabet.count(line[i + 1])) i++;
    }

    return sumUp;
}

// �������� ������ � �� �����
int Book::cityes()
{
    // �����
    while (!numbers.count(line[0]))
    {
        if (!alphabet.count(line[0]) && !numbers.count(line[0]) && line[0] != ' ' && line[0] != '.') return 1; // ����� � �������� ������

        city += line[0];
        line.erase(0, 1);
    }

    while (!alphabet.count(line[0])) line.erase(0, 1);
    // ----------------------------------

    // ������������
    while (!numbers.count(line[0]) && line[0] != ' ' && line[0] != ',')
    {
        if (chislo.count(line[0])) return 2; // ����� � �������� ������������

        namePlace += line[0];
        line.erase(0, 1);
    }

    while (!isdigit(line[0])) line.erase(0, 1);
    // ----------------------------------

    // ��� �������
    while (!numbers.count(line[0]))
    {
        if (isalpha(line[0])) return 3; // ����� � ����

        year += line[0];
        line.erase(0, 1);
    }

    while (!isdigit(line[0])) line.erase(0, 1);
    // ----------------------------------

    // ��������
    while (!numbers.count(line[0]) && line.size() != 0)
    {
        if (symbols.count(line[0]) && (line[0] != '�' || line[0] != '�')) return 4; // ����� � ���������

        height += line[0];
        line.erase(0, 1);
    }

    while (((!alphabet.count(line[0]) && !numbers.count(line[0])) || (line[0] == ' ' || line[0] == '.')) && !alphabet.count(line[0]) && line.size() != 0) line.erase(0, 1);
    // ----------------------------------

    if (line.size() == 0) return 5;

    while (!alphabet.count(line[0]) && line[0] != '(') line.erase(0, 1);
    // �����
    while (line.size() != 0)
    {
        series += line[0];
        line.erase(0, 1);
    }
    // ----------------------------------

    return 5;
}

// �������� ������
int Book::errors()
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

    return 4;
}

 // ������ � �������� � ����������
std::string Book::zaglInformation()
{
    int sumUp = 0; 
    int k = 0; 
    int author = 0;

    bool a1 = true;

    // ������������ ��� ��������
    while (!numbers.count(line[0])) 
    {
        name += line[0];
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
            otv += line[0];
            line.erase(0, 1);
            if (symbols.count(line[0])) a++;
        } 
        while (a < 9);

        while (!numbers.count(line[0])) line.erase(0, 1);
        while (!alphabet.count(line[0])) line.erase(0, 1);

        otv += " [� ��.]";

        a1 = false; // �������� � �������� ���
    }
    else if (sumUp >= 3)
    {
        while (!numbers.count(line[0]))
        {
            otv += line[0];
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
            zagl += line[0];
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
                otv += line[0];
                sz++;
            }
            else otv += line[0];

            line.erase(0, 1);
        } 
        while (sz <= 9 && !numbers.count(line[0]));

        if (sz > 9) otv += " [� ��.]"; // ���� ������� ������ 3

        while (!alphabet.count(line[0])) line.erase(0, 1);
    }
    else if (!a1 && sumUp >= 3 && authorNameFirst == "")
    {
        authorNameOther = otv;
        otv == "";

        while (sz <= 9 && !symbols.count(line[0]))
        {
            if (symbols.count(line[0]))
            {
                otv += line[0];
                sz++;
            }
            else if (line[0] == ' ') otv += line[0];

            line.erase(0, 1);
        }

        if (sz > 9) otv += " [� ��.]"; // ���� ������� ������ 3

        while (!alphabet.count(line[0])) line.erase(0, 1);

        return line;
    }
    else if (!a1 && sumUp >= 3 && authorNameFirst != "")
    {
        if (aNO >= 2)
        {
            otv = "";

            while (sz <= 9 && !numbers.count(line[0]))
            {
                if (symbols.count(line[0])) sz++;
                
                otv += line[0];
                line.erase(0, 1);
            }

            if (sz == 9) otv += " [� ��.]"; // ���� ������� ������ 3
        }
        else
        {
            if (authorNameOther.size() > otv.size()) otv = authorNameOther;
        }

        while (!alphabet.count(line[0])) line.erase(0, 1);

        return line;
    }
    else if (sumUp >= 1) return line;

    sz = 0;
    sumUp = upperSum(0, fName, line);

    if (sumUp >= 3)
    {
        if (aNO >= 2)
        {
            otv = "";

            while (sz <= 9 || !symbols.count(line[0]))
            {
                if (symbols.count(line[0]))
                {
                    otv += line[0];
                    sz++;
                }
                else if (line[0] == ' ') otv += line[0];

                line.erase(0, 1);
            }

            if (sz == 9) otv += " [� ��.]"; // ���� ������� ������ 3
        }
        else
        {
            // ������� ��������� ���� �����, ���������� �������
            while (!numbers.count(line[0])) line.erase(0, 1);
        }

        while (!alphabet.count(line[0])) line.erase(0, 1);
    }

    return line;
}

// ������������ ������
std::string Book::addLine()
{
    // ��������� ������
    line += authorNameFirst;
    line += "$";
    if (authorNameFirst != "")
    {
        line += " ";
    }

    // ��������� �������� �����
    line += name;
    if (zagl != "") line += ": ";
    else if (authorNameFirst != "" || otv != "") line += " / ";
    else
    {
        if (name[name.size() - 1] != '.') line += ". - ";
        else line += " - ";
    }

    // ��������� �������� ����������� � ��������
    if (zagl != "")
    {
        line += zagl;
        if (authorNameFirst != "" || otv != "") line += " / ";
        else 
        {
            if (zagl[zagl.size() - 1] != '.') line += ". - ";
            else line += " - ";
        }
    }

    // ��������� �������� �� ���������������
    if (authorNameFirst != "") 
    {
        line += authorName;
        if (authorNameOther != "") line += authorNameOther;

        if (otv.find(authorName) != std::string::npos)
        {
            otv.erase(otv.find(authorName), authorName.size());
        }

        if (otv != "") line += "; ";
        else 
        {
            if (authorNameOther == "" && authorNameOther.find(authorName) == std::string::npos)
            {
                if (authorNameFirst[authorNameFirst.size() - 1] != '.') line += ". - ";
                else line += " - ";
            }
            else
            {
                if (authorNameOther[authorNameOther.size() - 1] != '.') line += ". - ";
                else line += " - ";
            }
        }
    }

    // ��������� �������������� �������� �� ���������������
    if (otv != "")
    {
        line += otv;

        if (otv[otv.size() - 1] != '.') line += ". - ";
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
    
    // ��������� ��������
    line += height;
    if (height.find('�') == std::string::npos) line += " c.";
    if (series != "")
    {
        if (height[height.size() - 1] != '.') line += ". - ";
        else line += " - ";
    }

    // ��������� �����
    if (series != "")
    {
        line += series;

        if (series.find('.') == std::string::npos) line += ".";
    }

    return line;
}
