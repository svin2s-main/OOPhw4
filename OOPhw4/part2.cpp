#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// 1
bool fileTask1(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file.close();
        return true;
    }
    return false;
}

// 2
void fileTask2(int n, const string& filename) {
    if (n <= 1) return;

    ofstream file(filename);
    if (!file.is_open()) return;

    for (int i = 1; i <= n; ++i) {
        file << i * 2;
        if (i < n) file << " ";
    }
    file.close();
}

// 3
void fileTask3(const string& sa, const string& sb, const string& sc, const string& sd) {
    ifstream fa(sa), fb(sb), fc(sc);
    ofstream fd(sd);

    if (!fa.is_open() || !fb.is_open() || !fc.is_open() || !fd.is_open()) return;

    int valA, valB, valC;
    while (fa >> valA && fb >> valB && fc >> valC) {
        fd << valA << " " << valB << " " << valC << " ";
    }

    fa.close(); fb.close(); fc.close(); fd.close();
}

// Допоміжна функція
int customStoi2(const string& s, size_t start) {
    return (s[start] - '0') * 10 + (s[start + 1] - '0');
}

// 4
void fileTask17_split(const string& srcFile, const string& daysFile, const string& monthsFile) {
    ifstream src(srcFile);
    ofstream fDays(daysFile), fMonths(monthsFile);

    if (!src.is_open() || !fDays.is_open() || !fMonths.is_open()) return;

    string dateStr;
    while (src >> dateStr) {
        if (dateStr.length() >= 10) {
            int day = customStoi2(dateStr, 0);
            int month = customStoi2(dateStr, 3);

            fDays << day << " ";
            fMonths << month << " ";
        }
    }
    src.close(); fDays.close(); fMonths.close();
}

// 5
void fileTask18_summer(const string& srcFile, const string& resFile) {
    ifstream src(srcFile);
    ofstream res(resFile);

    if (!src.is_open() || !res.is_open()) return;

    string dateStr;
    while (src >> dateStr) {
        if (dateStr.length() >= 10) {
            string monthStr = dateStr.substr(3, 2);
            if (monthStr == "06" || monthStr == "07" || monthStr == "08") {
                res << dateStr << "\n";
            }
        }
    }
    src.close(); res.close();
}

// Допоміжна функція
bool isPunctuation(char c) {
    return (c == '.' || c == ',' || c == '!' || c == '?' ||
        c == ';' || c == ':' || c == '-' || c == '"' || c == '\'');
}

// 6
void fileTask6_replace(const string& f1, const string& f2, const string& g) {
    ifstream file2(f2);
    string target, replacement;
    if (!(file2 >> target >> replacement)) return;
    file2.close();

    ifstream file1(f1);
    ofstream fileG(g);
    if (!file1.is_open() || !fileG.is_open()) return;

    string rawWord;
    while (file1 >> rawWord) {
        if (rawWord.empty()) continue;

        size_t first = 0;
        while (first < rawWord.length() && isPunctuation(rawWord[first])) {
            first++;
        }

        if (first == rawWord.length()) {
            fileG << rawWord << " ";
            continue;
        }

        size_t last = rawWord.length() - 1;
        while (last >= first && isPunctuation(rawWord[last])) {
            last--;
        }

        string leading = rawWord.substr(0, first);
        string core = rawWord.substr(first, last - first + 1);
        string trailing = rawWord.substr(last + 1);

        if (core == target) {
            core = replacement;
        }

        fileG << leading << core << trailing << " ";
    }
    file1.close(); fileG.close();
}

// 7
void fileTask7_employees(const string& f, const string& g, int variant) {
    ifstream fileF(f);
    ofstream fileG(g);

    if (!fileF.is_open() || !fileG.is_open()) return;

    string lastName, firstName, middleName;
    while (fileF >> lastName >> firstName >> middleName) {
        if (variant == 1) {
            // Зразок 1
            fileG << firstName << " " << middleName << " " << lastName << "\n";
        }
        else if (variant == 2) {
            // Зразок 2
            if (!firstName.empty() && !middleName.empty()) {
                fileG << lastName << " " << firstName[0] << "." << middleName[0] << ".\n";
            }
        }
    }
    fileF.close(); fileG.close();
}

int main() {
    cout << "File Task 1 (test_file.txt): " << (fileTask1("test_file.txt") ? "True" : "False") << "\n";
    cout << "File Task 1 (bad:name?.txt): " << (fileTask1("bad:name?.txt") ? "True" : "False") << "\n\n";

    fileTask2(7, "evens.txt");
    cout << "File Task 2: Файл evens.txt створено. Перевірте його вміст (має бути: 2 4 6 8 10 12 14)\n\n";

    ofstream sa("sa.txt"), sb("sb.txt"), sc("sc.txt");
    sa << "1 2 3"; sb << "10 20 30"; sc << "100 200 300";
    sa.close(); sb.close(); sc.close();

    ofstream dates("dates.txt");
    dates << "16.04.2001\n21.08.2007\n05.11.2021\n19.07.2000\n31.12.2009\n";
    dates.close();

    ofstream f1("f1.txt");
    f1 << "Привіт, світ! Наш світ прекрасний, світловий день довгий.";
    f1.close();
    ofstream f2("f2.txt");
    f2 << "світ планета";
    f2.close();

    ofstream f_emp("employees.txt");
    f_emp << "Шевченко Тарас Григорович\nФранко Іван Якович\nУкраїнка Леся Петрівна\n";
    f_emp.close();


    fileTask3("sa.txt", "sb.txt", "sc.txt", "sd.txt");
    cout << "File Task 3 (чергування): Результат записано в sd.txt (має бути: 1 10 100 2 20 200...)\n";

    fileTask17_split("dates.txt", "days.txt", "months.txt");
    fileTask18_summer("dates.txt", "summer_dates.txt");
    cout << "File Tasks 17, 18 (дати): Результати збережено в файли days.txt, months.txt, summer_dates.txt\n";

    fileTask6_replace("f1.txt", "f2.txt", "g_text.txt");
    cout << "File Task 6 (заміна слова): Замінено в g_text.txt (слово 'світ' помінялось на 'планета')\n";

    fileTask7_employees("employees.txt", "g_employees.txt", 2);
    cout << "File Task 7 (співробітники, варіант 2): Результат записано в g_employees.txt\n\n";
}