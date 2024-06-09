#include "Dissertation.h"

// конструктор
Dissertation::Dissertation(std::string line)
{
    this->line = line;

    // ƒобавл€ем заглавные русские буквы в множество
    for (char c = 'ј'; c <= 'я'; ++c) symbols.insert(c);

    // ƒобавл€ем заглавные английские буквы в множество
    for (char c = 'A'; c <= 'Z'; ++c) symbols.insert(c);


    // ƒобавл€ем буквы английского алфавита в множество
    for (char c = 'A'; c <= 'Z'; ++c) alphabet.insert(c);

    for (char c = 'a'; c <= 'z'; ++c) alphabet.insert(c);


    // ƒобавл€ем буквы русского алфавита в множество
    for (char c = 'ј'; c <= 'я'; ++c) alphabet.insert(c);

    for (char c = 'а'; c <= '€'; ++c) alphabet.insert(c);

    // ƒобавл€ем цифры
    for (int i = 0; i < 10; i++) chislo.insert(i);
}

// работа с авторами и сведени€ми
int Dissertation::zaglInformation()
{
    int sumUp = 0;
    int k = 0;
    int author = 0;

    bool a1 = true;

    // переписываем все заглавие
    while (!numbers.count(line[0]))
    {
        name += line[0];
        line.erase(0, 1);

        if (line[0] == '-' && alphabet.count(line[1])) line.erase(0, 1);
    }
    while (!alphabet.count(line[0])) line.erase(0, 1);
    // -------------------------

    // наличие сведений относ€щихс€ к заглавию
    sumUp = upperSum(0, fName, line);

    if (sumUp > 1)
    {
        int a = 0;
        // нет сведений к заглавию
    }
    else
    {
        while (!numbers.count(line[0]))
        {
            zagl += line[0];
            line.erase(0, 1);
        }
        while (!isdigit(line[0])) line.erase(0, 1);

        a1 = true; // сведени€ к заглавию есть
    }
    // --------------------------------------------------------------------------------- //

    // шифр
    while (!numbers.count(line[0]))
    {
        if (alphabet.count(line[0])) return 1; // буква в коде

        code += line[0];
        line.erase(0, 1);
    }
    while ((alphabet.count(line[0]) || numbers.count(line[0])) || (line[0] == ' ' || line[0] == '.')) line.erase(0, 1);
    // --------------------------------------------------------------------------------- //

    // дата защиты
    while (!numbers.count(line[0]))
    {
        if (alphabet.count(line[0])) return 2; // буква в дате

        dateZ += line[0];
        line.erase(0, 1);
    }
    while ((alphabet.count(line[0]) || numbers.count(line[0])) || (line[0] == ' ' || line[0] == '.')) line.erase(0, 1);
    // --------------------------------------------------------------------------------- //

    // дата утверждени€
    while (!numbers.count(line[0]))
    {
        if (alphabet.count(line[0])) return 3; // буква в дате

        dateU += line[0];
        line.erase(0, 1);
    }
    while (!alphabet.count(line[0])) line.erase(0, 1);
    // --------------------------------------------------------------------------------- //

    // -------------------------------- —ведени€ об ответственности -------------------------------- //
    sumUp = upperSum(0, fName, line);

    int sz = 0;

    if (sumUp >= 3) // есть сведени€ к заглавию и далее есть авторы
    {
        do
        {
            if (symbols.count(line[0]))
            {
                if (chislo.count(line[0])) return 4; // цифра в сведени€х

                otv += line[0];
                sz++;
            }
            else otv += line[0];

            line.erase(0, 1);
        } 
        while (sz <= 9 && !numbers.count(line[0]));

        if (sz > 9) otv += " [и др.]"; // если авторов больше 3

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
                if (isdigit(line[0])) return 4; // цифра в сведени€х

                otvOther += line[0];
                sz++;
            }
            else if (line[0] == ' ') otvOther += line[0];

            line.erase(0, 1);
        }

        if (sz == 9) otvOther += " [и др.]"; // если авторов больше 3    

        while (!alphabet.count(line[0])) line.erase(0, 1);
    }

    return 5;
}

// проверка города и до конца
int Dissertation::cityes()
{
    // город
    while (!numbers.count(line[0]) && line[0] != ',')
    {
        if (chislo.count(line[0])) return 1; // цифра в названии города

        city += line[0];
        line.erase(0, 1);
    }
    while ((alphabet.count(line[0]) || numbers.count(line[0])) || (line[0] == ' ' || line[0] == '.' || line[0] == ',')) line.erase(0, 1);
    // ----------------------------------

    // год издани€
    while (!numbers.count(line[0]))
    {
        if (isalpha(line[0])) return 2; // буква в году

        year += line[0];
        line.erase(0, 1);
    }
    while ((alphabet.count(line[0]) || numbers.count(line[0])) || (line[0] == ' ' || line[0] == '.')) line.erase(0, 1);
    // ----------------------------------

    // страница
    while (line.size() != 0 && line[0] != ' ')
    {
        if (isalpha(line[0])) return 3; // буква в страницах

        height += line[0];
        line.erase(0, 1);
    }
    // ----------------------------------

    while (line.size() != 0) line.erase(0, 1);

    return 4;
}

// удаление лишних пробелов
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

// расставление знаков
std::string Dissertation::addLine()
{
    // добавл€ем автора
    line += authorNameFirst;
    line += "$";
    if (authorNameFirst != "")
    {
        line += " ";
    }

    // добавл€ем название
    line += name;
    line += ": ";

    // звание
    line += zagl;
    line += ": ";
    
    // добавл€ем шифр номенклатуры
    line += code;
    line += ": ";

    // добавл€ем дату защиты
    line += "защищена ";
    line += dateZ;
    line += ": ";

    // добавл€ем дату утверждени€
    line += "утв. ";
    line += dateU;
    line += " / ";

    // добавл€ем свуедени€ об ответственности
    line += otv;
    if (otvOther != "") line += "; ";
    else 
    {
        if (otv[otv.size() - 1] != '.') line += ". - ";
        else line += " - ";
    }

    // добавл€ем доп сведени€ об ответственности
    if (otvOther != "") 
    {
        line += otvOther;

        if (otvOther[otvOther.size() - 1] != '.') line += ". - ";
        else line += " - ";
    }

    // добавл€ем место написани€
    line += city;
    line += ", ";

    // добавл€ем дату написани€
    line += year;

    if (year[year.size() - 1] != '.') line += ". - ";
    else line += " - ";

    // добавл€ем объем
    line += height;
    if (height.find('с') == std::string::npos) line += " c.";

    return line;
}
