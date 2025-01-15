#include <iostream>       
#include <string>   
#include "Header.h" 
using namespace std;
void main()
{
    setlocale(LC_ALL, "Russian");
    long long int n, m, p, r;
    cout << "Данная программа находит наибольший общий делитель для трёх длинных чисел!" << endl;
    cout << "Введённые числа должны быть не меньше значения MaxInt (MaxInt=2147483647)!" << endl;
    n = vvod("Введите целое положительное число n (n>=MaxInt): ");
    m = vvod("Введите целое положительное число m (m>=MaxInt): ");
    p = vvod("Введите целое положительное число p (p>=MaxInt): ");
    r = nod(nod(n, m), p);//Вычисляем НОД для n и m, затем для найденного ранее НОДа и для p 
    cout << "Наибольший общий делитель для введённых чисел: " << r << endl;
}