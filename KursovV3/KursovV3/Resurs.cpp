#include "Resurs.h"

// конструктор
Resurs::Resurs(std::string line)
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

// проверка вида ресурса и до конца
int Resurs::cityes()
{
    int symbol = 0;
    int word = 0;

    // вид ресурса
    while (!numbers.count(line[0]))
    {
        if (chislo.count(line[0])) return 1; // цифра в виде ресурса

        if (symbols.count(line[0])) symbol++;
        if (line[0] != '.' && !alphabet.count(line[0]) && !numbers.count(line[0])) word++;

        typeRes += line[0];
        line.erase(0, 1);

        if (line[0] == '-' && alphabet.count(line[1])) line.erase(0, 1);
    }

    if (word / symbol != word) return 2; // отсутствует вид ресурса

    while (!alphabet.count(line[0])) line.erase(0, 1);
    // ----------------------------------
    
    bool s = false;
    bool n = false;
    bool u = false;

    // город
    while (!numbers.count(line[0]))
    {
        //if (isdigit(line[0])) return 3; // цифра в названии города

        if (chislo.count(line[0])) n = true;
        if (alphabet.count(line[0])) s = true;

        city += line[0];
        line.erase(0, 1);
    }

    if (s && n) return 3; // цифра в названии города
    else if (n) 
    {
        year = city;
        city = "";
        namePlace = "$"; // если встретили дату, то нет и города и издательства
    }
    
    if (city.find("Режим доступа") != std::string::npos && city.find("URL") != std::string::npos)
    {
        u = true;
        access = city;
        city = "";
    }
       
    while (!alphabet.count(line[0]) && (alphabet.count(line[0]) || numbers.count(line[0])) || (line[0] == ' ' || line[0] == '.')) line.erase(0, 1);
    // ----------------------------------

    if ((!alphabet.count(line[0]) && !numbers.count(line[0])) || (line[0] == ' ' || line[0] == '.')) u = true;

    // издательство
    if (!u)
    {
        while (!numbers.count(line[0]) && line[0] != ',')
        {
            if (namePlace == "$") break;
            if (chislo.count(line[0])) return 4; // цифра в названии издательства

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
                if (alphabet.count(line[0])) return 5; // буква в году

                year += line[0];
                line.erase(0, 1);
            }

            while (!alphabet.count(line[0])) line.erase(0, 1);
        }
    }
    // ----------------------------------

    // год издания
    if (u)
    {
        while (!numbers.count(line[0]))
        {
            if (alphabet.count(line[0])) return 5; // буква в году

            year += line[0];
            line.erase(0, 1);
        }

        while (!alphabet.count(line[0])) line.erase(0, 1);
    }
    // ----------------------------------

    // режим доступа
    while (!numbers.count(line[0]) && line.size() != 0)
    {
        if (line[0] == 'Р' || line[0] == 'U') 
        {
            while (!numbers.count(line[0])) line.erase(0, 1);
            while (!alphabet.count(line[0])) line.erase(0, 1);
        }
        else if (line[0] != 'h') return 6; // отсутствует ссылка

        while (line[0] != ' ' && line[0] != ',')
        {
            access += line[0];
            line.erase(0, 1);
        }

        if (line.find("свободный") != std::string::npos) access += ", свободный.";
        else if (line.find("ограниченный") != std::string::npos) access += ", ограниченный.";
        else return 7; // отсутствует режим доступа

        while (line[0] != 'с' && line[0] != 'о') line.erase(0, 1); // пока не встретим режим доступа
        while (line[0] != ' ') line.erase(0, 1);
        while (!numbers.count(line[0])) line.erase(0, 1);
    }

    while ((alphabet.count(line[0]) || numbers.count(line[0])) || (line[0] == ' ' || line[0] == '.')) line.erase(0, 1);
    // ----------------------------------

    // дата обращения
    while (isdigit(line[0]) || line[0] == '.')
    {
        date += line[0];
        line.erase(0, 1);
    }
    while (!alphabet.count(line[0]) && line.size() != 0) line.erase(0, 1);
    // ----------------------------------

    if (line.size() == 0) return 8; // строка закончилась

    // примечания
    while (alphabet.count(line[0]) && line.size() != 0)
    {
        series += line[0];
        line.erase(0, 1);
    }
    // ----------------------------------

    return 8; // закончен просмотр строки электронного ресурса
}

// удаление лишних пробелов
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

// составление строки
std::string Resurs::addLine()
{
    // добавляем автора
    line += authorNameFirst;
    line += "$";
    if (authorNameFirst != "")
    {
        line += " ";
    }

    // добавляем название книги
    line += name;
    if (name.find("[Электронный ресурс]") == std::string::npos) line += "[Электронный ресурс]";

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

    // добавляем сведения относящиеся к заглавию
    if (zagl != "")
    {
        line += zagl;
        if (authorNameFirst != "" || otv != "") line += " / ";
    }

    // добавляем сведения об ответственности
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

    // добавляем дополнительные сведения об ответственности
    if (otv != "")
    {
        line += otv;

        if (otv[otv.size() - 1] != '.') line += ". - ";
        else line += " - ";
    }

    // добавляем вид ресурса
    line += typeRes;

    if (typeRes[typeRes.size() - 1] != '.') line += ". - ";
    else line += " - "; // добавялется при любом случае
    
    // добавляем город
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

    // добавляем издательство
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

    // добавляем год
    if (year != "")
    {
        line += year;
        
        if (year[year.size() - 1] != '.') line += ". - ";
        else line += " - ";
    }

    // добавляем режим доступа
    line += "URL: ";
    line += access;
    line += " ";

    // добавляем дату обращения
    line += "(дата обращения: ";
    line += date;
    line += ").";
    if (series != "") line += " - ";

    // добавляем примечания
    if (series != "") line += series;

    return line;
}
