#include <iostream>       
#include <string>   
using namespace std;
long long int Stoll(string& n1)
{
    long long int n = 0;
    for (char ch : n1)//�������� �� ������� ������� 
        n = n * 10 + (ch - '0');//�������� ������ ����������� �����, ������ ������� ������ �� ��������� ������� 
    return n;
}
bool pr(string& s)
{
    const string MaxInt = "2147483647";
    if (s.size() == 0)//�������� �� ������ ������ 
    {
        cout << "������. ��������� �� ����� ������������ ������ ������. " << endl;
        cout << "��������� ����." << endl;
        return 1;
    }
    if (s[0] == '-')//�������� �� ������������� ����� 
    {
        cout << "������. ����� ������ ���� �������������" << endl;
        cout << "��������� ����." << endl;
        return 1;
    }
    if (s[0] == '0')//����� �� ����� ���������� � ���� 
    {
        cout << "������. ����� �� ������ ���������� � ����" << endl;
        cout << "��������� ����." << endl;
        return 1;
    }
    for (char ch : s)
    {
        if (ch < '0' || ch > '9')//������ ����� ��������� ������ ����� 
        {
            cout << "������. ����� �� ������ ��������� ����� ���������� � �����" << endl;
            cout << "��������� ����." << endl;
            return 1;
        }
    }
    if (s.size() > MaxInt.size() || (s.size() == MaxInt.size() && s > MaxInt))//�������� ����� >= MaxInt 
    {
        return 0;
    }
    else
    {
        cout << "������. ����� ������ ���� ������ ��� ����� 2147483647" << endl;
        cout << "��������� ����." << endl;
        return 1;
    }
    return 0;
}
long long int vvod(const string& str)
{
    string s;
    cout << str;//������� ����� � �������� 
    do
    {
        getline(cin, s);
    } while (pr(s));//���� ������� true, ���������� ����������� ���� 
    return Stoll(s);//���������� �������� ���� long long int 
}
//���������� �������� ������� 
long long int nod(long long int n, long long int m)
{
    while (m != 0)
    {
        long long int dop = m;
        m = n % m;
        n = dop;
    }
    return n;//���������� ��� 
}