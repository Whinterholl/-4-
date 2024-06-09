#include "Resurs.h"

// �����������
Resurs::Resurs(std::string line)
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

// �������� ���� ������� � �� �����
int Resurs::cityes()
{
    int symbol = 0;
    int word = 0;

    // ��� �������
    while (!numbers.count(line[0]))
    {
        if (chislo.count(line[0])) return 1; // ����� � ���� �������

        if (symbols.count(line[0])) symbol++;
        if (line[0] != '.' && !alphabet.count(line[0]) && !numbers.count(line[0])) word++;

        typeRes += line[0];
        line.erase(0, 1);

        if (line[0] == '-' && alphabet.count(line[1])) line.erase(0, 1);
    }

    if (word / symbol != word) return 2; // ����������� ��� �������

    while (!alphabet.count(line[0])) line.erase(0, 1);
    // ----------------------------------
    
    bool s = false;
    bool n = false;
    bool u = false;

    // �����
    while (!numbers.count(line[0]))
    {
        //if (isdigit(line[0])) return 3; // ����� � �������� ������

        if (chislo.count(line[0])) n = true;
        if (alphabet.count(line[0])) s = true;

        city += line[0];
        line.erase(0, 1);
    }

    if (s && n) return 3; // ����� � �������� ������
    else if (n) 
    {
        year = city;
        city = "";
        namePlace = "$"; // ���� ��������� ����, �� ��� � ������ � ������������
    }
    
    if (city.find("����� �������") != std::string::npos && city.find("URL") != std::string::npos)
    {
        u = true;
        access = city;
        city = "";
    }
       
    while (!alphabet.count(line[0]) && (alphabet.count(line[0]) || numbers.count(line[0])) || (line[0] == ' ' || line[0] == '.')) line.erase(0, 1);
    // ----------------------------------

    if ((!alphabet.count(line[0]) && !numbers.count(line[0])) || (line[0] == ' ' || line[0] == '.')) u = true;

    // ������������
    if (!u)
    {
        while (!numbers.count(line[0]) && line[0] != ',')
        {
            if (namePlace == "$") break;
            if (chislo.count(line[0])) return 4; // ����� � �������� ������������

            namePlace += line[0];
            line.erase(0, 1);
        }

        if (namePlace == "$")
        {
            while (!alphabet.count(line[0])) line.erase(0, 1);
            namePlace = "";
        }
        else while (!isdigit(line[0])) line.erase(0, 1);

        if ((!alphabet.count(line[0]) && !numbers.count(line[0])) || (line[0] == ' ' || line[0] == '.'))
        {
            while (!numbers.count(line[0]))
            {
                if (alphabet.count(line[0])) return 5; // ����� � ����

                year += line[0];
                line.erase(0, 1);
            }

            while (!alphabet.count(line[0])) line.erase(0, 1);
        }
    }
    // ----------------------------------

    // ��� �������
    if (u)
    {
        while (!numbers.count(line[0]))
        {
            if (alphabet.count(line[0])) return 5; // ����� � ����

            year += line[0];
            line.erase(0, 1);
        }

        while (!alphabet.count(line[0])) line.erase(0, 1);
    }
    // ----------------------------------

    // ����� �������
    while (!numbers.count(line[0]) && line.size() != 0)
    {
        if (line[0] == '�' || line[0] == 'U') 
        {
            while (!numbers.count(line[0])) line.erase(0, 1);
            while (!alphabet.count(line[0])) line.erase(0, 1);
        }
        else if (line[0] != 'h') return 6; // ����������� ������

        while (line[0] != ' ' && line[0] != ',')
        {
            access += line[0];
            line.erase(0, 1);
        }

        if (line.find("���������") != std::string::npos) access += ", ���������.";
        else if (line.find("������������") != std::string::npos) access += ", ������������.";
        else return 7; // ����������� ����� �������

        while (line[0] != '�' && line[0] != '�') line.erase(0, 1); // ���� �� �������� ����� �������
        while (line[0] != ' ') line.erase(0, 1);
        while (!numbers.count(line[0])) line.erase(0, 1);
    }

    while ((alphabet.count(line[0]) || numbers.count(line[0])) || (line[0] == ' ' || line[0] == '.')) line.erase(0, 1);
    // ----------------------------------

    // ���� ���������
    while (isdigit(line[0]) || line[0] == '.')
    {
        date += line[0];
        line.erase(0, 1);
    }
    while (!alphabet.count(line[0]) && line.size() != 0) line.erase(0, 1);
    // ----------------------------------

    if (line.size() == 0) return 8; // ������ �����������

    // ����������
    while (alphabet.count(line[0]) && line.size() != 0)
    {
        series += line[0];
        line.erase(0, 1);
    }
    // ----------------------------------

    return 8; // �������� �������� ������ ������������ �������
}

// �������� ������ ��������
void Resurs::symbol()
{
    authorNameFirst = del(authorNameFirst);

    std::string first;
    std::string middle;
    std::string last;
    std::string newName;

    bool fZnak = false;

    int i = 0;

    while (i != authorNameFirst.size())
    {
        if (authorNameFirst[i + 1] == '.') fZnak = true;

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
    series = del(series);
    typeRes = del(typeRes);
    access = del(access);
    date = del(date);
}

// ����������� ������
std::string Resurs::addLine()
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
    if (name.find("[����������� ������]") == std::string::npos) line += "[����������� ������]";

    if (zagl != "") line += ": ";
    else if (authorNameFirst != "" || otv != "") line += " / ";
    else
    {
        if (zagl != "")
        {
            if (zagl[zagl.size() - 1] != '.') line += ". - ";
            else line += " - ";
        }
        else
        {
            if (name[name.size() - 1] != '.') line += ". - ";
            else line += " - ";
        }
    }

    // ��������� �������� ����������� � ��������
    if (zagl != "")
    {
        line += zagl;
        if (authorNameFirst != "" || otv != "") line += " / ";
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

    // ��������� ��� �������
    line += typeRes;

    if (typeRes[typeRes.size() - 1] != '.') line += ". - ";
    else line += " - "; // ����������� ��� ����� ������
    
    // ��������� �����
    if (city != "") 
    {
        line += city;

        if (namePlace != "") line += ": ";
        else if (year != "") line += ", ";
        else
        {
            if (city[city.size() - 1] != '.') line += ". - ";
            else line += " - ";
        }
    }

    // ��������� ������������
    if (namePlace != "")
    {
        line += namePlace;

        if (year != "") line += ", ";
        else
        {
            if (namePlace[namePlace.size() - 1] != '.') line += ". - ";
            else line += " - ";
        }
    }

    // ��������� ���
    if (year != "")
    {
        line += year;
        
        if (year[year.size() - 1] != '.') line += ". - ";
        else line += " - ";
    }

    // ��������� ����� �������
    line += "URL: ";
    line += access;
    line += " ";

    // ��������� ���� ���������
    line += "(���� ���������: ";
    line += date;
    line += ").";
    if (series != "") line += " - ";

    // ��������� ����������
    if (series != "") line += series;

    return line;
}
