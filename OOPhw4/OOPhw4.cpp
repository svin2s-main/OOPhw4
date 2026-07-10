//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <fstream>
//
//using namespace std;
//
//// 1
//string task1(int n, string s) {
//    if (s.length() > n) {
//        return s.substr(s.length() - n);
//    }
//    else {
//        return string(n - s.length(), '.') + s;
//    }
//}
//
//// 2
//string task2(int n1, int n2, string s1, string s2) {
//    string part1 = s1.substr(0, n1);
//    string part2 = s2.substr(s2.length() - n2);
//    return part1 + part2;
//}
//
//// 3
//string task3(char c, string s) {
//    string result = "";
//    for (char ch : s) {
//        result += ch;
//        if (ch == c) {
//            result += c;
//        }
//    }
//    return result;
//}
//
//// 4
//string task4(char c, string s, string s0) {
//    string result = "";
//    for (char ch : s) {
//        if (ch == c) {
//            result += s0;
//        }
//        result += ch;
//    }
//    return result;
//}
//
//// 5
//string task5(char c, string s, string s0) {
//    string result = "";
//    for (char ch : s) {
//        result += ch;
//        if (ch == c) {
//            result += s0;
//        }
//    }
//    return result;
//}
//
//// 6
//bool task6(string s, string s0) {
//    return s.find(s0) != string::npos;
//}
//
//// 7
//int task7(string s, string s0) {
//    int count = 0;
//    size_t pos = s.find(s0);
//    while (pos != string::npos) {
//        count++;
//        pos = s.find(s0, pos + s0.length());
//    }
//    return count;
//}
//
//// 8
//string task8(string s, string s0) {
//    size_t pos = s.find(s0);
//    if (pos != string::npos) {
//        s.erase(pos, s0.length());
//    }
//    return s;
//}
//
//// 9
//string task9(string s, string s0) {
//    size_t pos = s.find(s0);
//    while (pos != string::npos) {
//        s.erase(pos, s0.length());
//        pos = s.find(s0, pos);
//    }
//    return s;
//}
//
//// 10
//string task10(string s, string s1, string s2) {
//    size_t pos = s.find(s1);
//    if (pos != string::npos) {
//        s.replace(pos, s1.length(), s2);
//    }
//    return s;
//}
//
//// 11
//string task11(string s, string s1, string s2) {
//    size_t pos = s.find(s1);
//    while (pos != string::npos) {
//        s.replace(pos, s1.length(), s2);
//        pos = s.find(s1, pos + s2.length());
//    }
//    return s;
//}
//
//// 12
//string task12_encrypt(string s) {
//    string even = "";
//    string odd = "";
//    for (size_t i = 0; i < s.length(); i++) {
//        if (i % 2 == 0) {
//            even += s[i];
//        }
//        else {
//            odd += s[i];
//        }
//    }
//    reverse(odd.begin(), odd.end());
//    return even + odd;
//}
//
//// 13
//string task13_decrypt(string s) {
//    int n = s.length();
//    string result(n, ' ');
//
//    // парнi позиціi
//    int even_count = (n + 1) / 2;
//
//    string even = s.substr(0, even_count);
//    string odd = s.substr(even_count);
//    reverse(odd.begin(), odd.end());
//
//    int e_idx = 0, o_idx = 0;
//    for (int i = 0; i < n; i++) {
//        if (i % 2 == 0) {
//            result[i] = even[e_idx++];
//        }
//        else {
//            result[i] = odd[o_idx++];
//        }
//    }
//    return result;
//}
//
//int main() {
//    //тестування...
//    cout << "Task 1 (N=4, S=\"itstep\"): " << task1(4, "itstep") << " (Очікується: step)\n";
//    cout << "Task 1 (N=8, S=\"itstep\"): " << task1(8, "itstep") << " (Очікується: ..itstep)\n\n";
//
//    cout << "Task 2 (N1=2, N2=3): " << task2(2, 3, "itstep", "hello") << " (Очікується: itllo)\n\n";
//
//    cout << "Task 3 (C='.'): " << task3('.', "12.34.56.78") << " (Очікується: 12..34..56..78)\n\n";
//
//    string s_task4 = "hello world. hello step. hello it.";
//    cout << "Task 4 (Вставка перед '.'): \n" << task4('.', s_task4, "good") << "\n\n";
//    cout << "Task 5 (Вставка після '.'): \n" << task5('.', s_task4, "good ") << "\n\n";
//
//    cout << "Task 6 (Містить \"world\"): " << (task6("Hello world", "world") ? "True" : "False") << "\n";
//    cout << "Task 6 (Містить \"step\"): " << (task6("Hello world", "step") ? "True" : "False") << "\n\n";
//
//    cout << "Task 7 (Кількість \"hello\"): " << task7(s_task4, "hello") << " (Очікується: 3)\n\n";
//
//    cout << "Task 8 (Видалити перший): \"" << task8(s_task4, "hello") << "\"\n";
//    cout << "Task 9 (Видалити всі):    \"" << task9(s_task4, "hello") << "\"\n\n";
//
//    cout << "Task 10 (Заміна першої):  \"" << task10(s_task4, "hello", "hi") << "\"\n";
//    cout << "Task 11 (Заміна всіх):    \"" << task11(s_task4, "hello", "hi") << "\"\n\n";
//
//    string secret = task12_encrypt("Программа");
//    cout << "Task 12 (Шифрування \"Программа\"): " << secret << " (Очікується: ргамамроП або аналог)\n";
//    cout << "Task 13 (Розшифрування): " << task13_decrypt(secret) << "\n\n";
//}