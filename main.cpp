#include <iostream>
#include <list>
#include <algorithm>
#include <set>
#include <iterator>
#include <string>
#include <cstdlib>
#include <locale.h>
#include <ctime>
#include <map>

using namespace std;


int main() {
    setlocale(0, "Russian");
    srand ( time(NULL) );
    cout << "�������������� �������: �������� ������� �1 �� ������ ���������� �������� �." << endl;
    int x, y, v;
    list<int>::iterator it;
    list <int> l;
    cout << "������ �� 8 ��������� ���������: " << endl;
    for (int i = 0; i < 8; ++i) {
        v = (rand() % 2 == 0 ? 1 : -1) * rand() % 100;
        l.push_back(v);
        cout << v << " ";
    }
    cout << endl;
    cout << "0 - �������� ������\n1 - �������� ������� � ������\n2 - ���������� ������\n3 - �������� ������� ����� x\n4 - �������� ������� ����� x\n";
    cout << "5 - �������� ������� � �����\n6 - ������� ������ �������\n";
    cout << "7 - ������� ��������� �������\n8 - ������� ��������� �������\n9 - �������������� �������\n";
    cout << "-1 - ��������� ���������� ���������\n";
    cout << "�������� ��������: ";
    cin >> x;
    while (x != -1)
    {
        switch (x)
        {
            case 0:
                l.clear();
                break;
            case 1:
                cout << "������� �������� ������ ��������: ";
                cin >> v;
                it = l.begin();
                l.insert(it, v);
                break;
            case 2:
                if (l.empty()) cout << "������ ������\n";
                else
                    for (it = l.begin(); it != l.end(); cout << *it << ' ', it++);
                cout << "\n";
                break;
            case 3:
                if (l.empty()) cout << "������ ������\n";
                else
                {
                    cout << "������� �������� ������ ��������: ";
                    cin >> v;
                    cout << "������� �������� ��������, ����� ������� ������� �������: ";
                    cin >> y;
                    it = find(l.begin(), l.end(), y);
                    if (it == l.end()) cout << "��� ������ ��������\n";
                    else
                        l.insert(it, v);
                }
                break;
            case 4:
                if (l.empty()) cout << "������ ������\n";
                else
                {
                    cout << "������� �������� ������ ��������: ";
                    cin >> v;
                    cout << "������� �������� ��������, �� ������� ��������� �������: ";
                    cin >> y;
                    it = find(l.begin(), l.end(), y);
                    if (it == l.end()) cout << "��� ������ ��������\n";
                    else
                    {
                        it++;
                        l.insert(it, v);
                    }
                }
                break;
            case 5:
                cout << "������� �������� ������ ��������: ";
                cin >> v;
                l.insert(l.end(), v);
                break;
            case 6:
                if (l.empty()) cout << "������ ������\n";
                else
                {
                    l.erase(l.begin());
                }
                break;
            case 7:
                if (l.empty()) cout << "������ ������\n";
                else
                {
                    it = l.end();
                    it--;
                    l.erase(it);
                }
                break;
            case 8:
                if (l.empty()) cout << "������ ������\n";
                else
                {
                    cout << "������� �������� ��������, ������� ������ �������: ";
                    cin >> v;
                    it = find(l.begin(), l.end(), v);
                    if (it == l.end()) cout << "��� ������ ��������\n";
                    else
                        l.erase(it);
                }
                break;
            case 9:
                if (l.empty()) cout << "������ ������\n";
                else
                {
                    cout << "������� �������� ��������, ������� ���������� ����� ��������: ";
                    cin >> v;
                    cout << "������� �������� ��������, �� ������ ������� ���������� ����� �������� ����� �������: ";
                    cin >> y;
                    list<int>:: iterator it = l.begin();
                    while(it != l.end())
                    {
                        if (*it == y)
                        {
                            it++;
                            l.insert(it, v);
                        }
                        else it++;
                    }
                }
                break;
            default:
                cout << "������. �������� ����� ��������.\n";
                break;
        }
        cin >> x;
    }
    return(0);
}
