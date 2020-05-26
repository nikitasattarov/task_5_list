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
    cout << "Индивидуальное задание: вставить элемент Е1 за каждым вхождением элемента Е." << endl;
    int x, y, v;
    list<int>::iterator it;
    list <int> l;
    cout << "Список из 8 случайных элементов: " << endl;
    for (int i = 0; i < 8; ++i) {
        v = (rand() % 2 == 0 ? 1 : -1) * rand() % 100;
        l.push_back(v);
        cout << v << " ";
    }
    cout << endl;
    cout << "0 - очистить список\n1 - вставить элемент в начало\n2 - напечатать список\n3 - вставить элемент перед x\n4 - вставить элемент после x\n";
    cout << "5 - вставить элемент в хвост\n6 - удалить первый элемент\n";
    cout << "7 - удалить последний элемент\n8 - удалить выбранный элемент\n9 - индивидуальное задание\n";
    cout << "-1 - закончить выполнение программы\n";
    cout << "Выберите действие: ";
    cin >> x;
    while (x != -1)
    {
        switch (x)
        {
            case 0:
                l.clear();
                break;
            case 1:
                cout << "Введите значение нового элемента: ";
                cin >> v;
                it = l.begin();
                l.insert(it, v);
                break;
            case 2:
                if (l.empty()) cout << "Список пустой\n";
                else
                    for (it = l.begin(); it != l.end(); cout << *it << ' ', it++);
                cout << "\n";
                break;
            case 3:
                if (l.empty()) cout << "Список пустой\n";
                else
                {
                    cout << "Введите значение нового элемента: ";
                    cin >> v;
                    cout << "Введите значение элемента, перед которым следует вставка: ";
                    cin >> y;
                    it = find(l.begin(), l.end(), y);
                    if (it == l.end()) cout << "Нет такого элемента\n";
                    else
                        l.insert(it, v);
                }
                break;
            case 4:
                if (l.empty()) cout << "Список пустой\n";
                else
                {
                    cout << "Введите значение нового элемента: ";
                    cin >> v;
                    cout << "Введите значение элемента, за которым последует вставка: ";
                    cin >> y;
                    it = find(l.begin(), l.end(), y);
                    if (it == l.end()) cout << "Нет такого элемента\n";
                    else
                    {
                        it++;
                        l.insert(it, v);
                    }
                }
                break;
            case 5:
                cout << "Введите значение нового элемента: ";
                cin >> v;
                l.insert(l.end(), v);
                break;
            case 6:
                if (l.empty()) cout << "Список пустой\n";
                else
                {
                    l.erase(l.begin());
                }
                break;
            case 7:
                if (l.empty()) cout << "Список пустой\n";
                else
                {
                    it = l.end();
                    it--;
                    l.erase(it);
                }
                break;
            case 8:
                if (l.empty()) cout << "Список пустой\n";
                else
                {
                    cout << "Введите значение элемента, который хотите удалить: ";
                    cin >> v;
                    it = find(l.begin(), l.end(), v);
                    if (it == l.end()) cout << "Нет такого элемента\n";
                    else
                        l.erase(it);
                }
                break;
            case 9:
                if (l.empty()) cout << "Список пустой\n";
                else
                {
                    cout << "Введите значение элемента, который необходимо будет вставить: ";
                    cin >> v;
                    cout << "Введите значение элемента, за каждым которым необходимо будет вставить новый элемент: ";
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
                cout << "Ошибка. Отметьте номер действия.\n";
                break;
        }
        cin >> x;
    }
    return(0);
}
