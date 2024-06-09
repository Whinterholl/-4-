#include "Dissertation.h"

// �����������
Dissertation::Dissertation(std::string line)
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

// ������ � �������� � ����������
int Dissertation::zaglInformation()
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

        if (line[0] == '-' && alphabet.count(line[1])) line.erase(0, 1);
    }
    while (!alphabet.count(line[0])) line.erase(0, 1);
    // -------------------------

    // ������� �������� ����������� � ��������
    sumUp = upperSum(0, fName, line);

    if (sumUp > 1)
    {
        int a = 0;
        // ��� �������� � ��������
    }
    else
    {
        while (!numbers.count(line[0]))
        {
            zagl += line[0];
            line.erase(0, 1);
        }
        while (!isdigit(line[0])) line.erase(0, 1);

        a1 = true; // �������� � �������� ����
    }
    // --------------------------------------------------------------------------------- //

    // ����
    while (!numbers.count(line[0]))
    {
        if (alphabet.count(line[0])) return 1; // ����� � ����

        code += line[0];
        line.erase(0, 1);
    }
    while ((alphabet.count(line[0]) || numbers.count(line[0])) || (line[0] == ' ' || line[0] == '.')) line.erase(0, 1);
    // --------------------------------------------------------------------------------- //

    // ���� ������
    while (!numbers.count(line[0]))
    {
        if (alphabet.count(line[0])) return 2; // ����� � ����

        dateZ += line[0];
        line.erase(0, 1);
    }
    while ((alphabet.count(line[0]) || numbers.count(line[0])) || (line[0] == ' ' || line[0] == '.')) line.erase(0, 1);
    // --------------------------------------------------------------------------------- //

    // ���� �����������
    while (!numbers.count(line[0]))
    {
        if (alphabet.count(line[0])) return 3; // ����� � ����

        dateU += line[0];
        line.erase(0, 1);
    }
    while (!alphabet.count(line[0])) line.erase(0, 1);
    // --------------------------------------------------------------------------------- //

    // -------------------------------- �������� �� ��������������� -------------------------------- //
    sumUp = upperSum(0, fName, line);

    int sz = 0;

    if (sumUp >= 3) // ���� �������� � �������� � ����� ���� ������
    {
        do
        {
            if (symbols.count(line[0]))
            {
                if (chislo.count(line[0])) return 4; // ����� � ���������

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
    else if (sumUp >= 1) return 5;

    sz = 0;
    sumUp = upperSum(0, fName, line);

    if (sumUp >= 3)
    {
        while (sz <= 9 || !symbols.count(line[0]))
        {
            if (symbols.count(line[0]))
            {
                if (isdigit(line[0])) return 4; // ����� � ���������

                otvOther += line[0];
                sz++;
            }
            else if (line[0] == ' ') otvOther += line[0];

            line.erase(0, 1);
        }

        if (sz == 9) otvOther += " [� ��.]"; // ���� ������� ������ 3    

        while (!alphabet.count(line[0])) line.erase(0, 1);
    }

    return 5;
}

// �������� ������ � �� �����
int Dissertation::cityes()
{
    // �����
    while (!numbers.count(line[0]) && line[0] != ',')
    {
        if (chislo.count(line[0])) return 1; // ����� � �������� ������

        city += line[0];
        line.erase(0, 1);
    }
    while ((alphabet.count(line[0]) || numbers.count(line[0])) || (line[0] == ' ' || line[0] == '.' || line[0] == ',')) line.erase(0, 1);
    // ----------------------------------

    // ��� �������
    while (!numbers.count(line[0]))
    {
        if (isalpha(line[0])) return 2; // ����� � ����

        year += line[0];
        line.erase(0, 1);
    }
    while ((alphabet.count(line[0]) || numbers.count(line[0])) || (line[0] == ' ' || line[0] == '.')) line.erase(0, 1);
    // ----------------------------------

    // ��������
    while (line.size() != 0 && line[0] != ' ')
    {
        if (isalpha(line[0])) return 3; // ����� � ���������

        height += line[0];
        line.erase(0, 1);
    }
    // ----------------------------------

    while (line.size() != 0) line.erase(0, 1);

    return 4;
}

// �������� ������ ��������
void Dissertation::symbol()
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

    name = del(name);
    zagl = del(zagl);

    otv = del(otv);
    newName = delSymbol(otv);
    if (newName != "") otv = newName;

    city = del(city);
    year = del(year);
    height = del(height);
    code = del(code);
    dateZ = del(dateZ);
    dateU = del(dateU);

    otvOther = del(otvOther);
    newName = delSymbol(otvOther);
    if (newName != "") otvOther = newName;
}

// ������������ ������
std::string Dissertation::addLine()
{
    // ��������� ������
    line += authorNameFirst;
    line += "$";
    if (authorNameFirst != "")
    {
        line += " ";
    }

    // ��������� ��������
    line += name;
    line += ": ";

    // ������
    line += zagl;
    line += ": ";
    
    // ��������� ���� ������������
    line += code;
    line += ": ";

    // ��������� ���� ������
    line += "�������� ";
    line += dateZ;
    line += ": ";

    // ��������� ���� �����������
    line += "���. ";
    line += dateU;
    line += " / ";

    // ��������� ��������� �� ���������������
    line += otv;
    if (otvOther != "") line += "; ";
    else 
    {
        if (otv[otv.size() - 1] != '.') line += ". - ";
        else line += " - ";
    }

    // ��������� ��� �������� �� ���������������
    if (otvOther != "") 
    {
        line += otvOther;

        if (otvOther[otvOther.size() - 1] != '.') line += ". - ";
        else line += " - ";
    }

    // ��������� ����� ���������
    line += city;
    line += ", ";

    // ��������� ���� ���������
    line += year;

    if (year[year.size() - 1] != '.') line += ". - ";
    else line += " - ";

    // ��������� �����
    line += height;
    if (height.find('�') == std::string::npos) line += " c.";

    return line;
}
