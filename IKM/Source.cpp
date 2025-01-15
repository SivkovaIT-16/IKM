#include <iostream>       
#include <string>   
using namespace std;
long long int Stoll(string& n1)
{
    long long int n = 0;
    for (char ch : n1)//Проходим по каждому символу 
        n = n * 10 + (ch - '0');//Повышаем разряд предыдущего числа, ставим текущий символ на единичную позицию 
    return n;
}
bool pr(string& s)
{
    const string MaxInt = "2147483647";
    if (s.size() == 0)//Проверка на пустую строку 
    {
        cout << "Ошибка. Программа не может обрабатывать пустую строку. " << endl;
        cout << "Повторите ввод." << endl;
        return 1;
    }
    if (s[0] == '-')//Проверка на отрицательное число 
    {
        cout << "Ошибка. Число должно быть положительным" << endl;
        cout << "Повторите ввод." << endl;
        return 1;
    }
    if (s[0] == '0')//Число не может начинаться с нуля 
    {
        cout << "Ошибка. Число не должно начинаться с нуля" << endl;
        cout << "Повторите ввод." << endl;
        return 1;
    }
    for (char ch : s)
    {
        if (ch < '0' || ch > '9')//Строка может содержать только цифры 
        {
            cout << "Ошибка. Число не должно содержать знаки препинания и буквы" << endl;
            cout << "Повторите ввод." << endl;
            return 1;
        }
    }
    if (s.size() > MaxInt.size() || (s.size() == MaxInt.size() && s > MaxInt))//Значение числа >= MaxInt 
    {
        return 0;
    }
    else
    {
        cout << "Ошибка. Число должно быть больше или равно 2147483647" << endl;
        cout << "Повторите ввод." << endl;
        return 1;
    }
    return 0;
}
long long int vvod(const string& str)
{
    string s;
    cout << str;//Выводит текст в терминал 
    do
    {
        getline(cin, s);
    } while (pr(s));//пока функция true, продолжает запрашивать ввод 
    return Stoll(s);//возвращаем значение типа long long int 
}
//Используем алгоритм Евклида 
long long int nod(long long int n, long long int m)
{
    while (m != 0)
    {
        long long int dop = m;
        m = n % m;
        n = dop;
    }
    return n;//Возвращаем НОД 
}