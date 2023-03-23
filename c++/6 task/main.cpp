#include <iostream>
#include <vector>
#include "class.h"

template <class T>
bool PredicateFirst(T a)
{
    return a > 3;
}

template <class T>
bool PredicateSecond(T a, T b)
{
    return a > b;
}

template <class In, class Pred>
bool any_of(In first, In last, Pred pr)
{
    for(auto i = first; i != last; ++i)
    {
        if(pr(*i))
        {
            return true;
        }
    }
    return false;
}

template <class In, class Compare, class R>
R is_sorted(In first, In last, Compare com) /// Добавил передоваемый класс для функции и перестала вылетать ошибка об двойственности но как передать тип функции?
{
    for(auto i = first; i != last-1; ++i)
    {
        if(!com(*i, *(i+1)))
        {
            return false;
        }
    }
    return true;
}

template <class In, class Temp>
In find_backward(In first, In last, Temp value)
{
    for(auto i = last - 1; i != first - 1; --i)
    {
        if(*(i) != value)
        {
            return i;
        }
    }
    return first;
}


int main() {
    system("chcp 65001");
    std::vector <int> v(8);
    std::cout << "Введите 8 целых чисел" << std::endl;
    int a;
    for (int i = 0; i < 8; i++)
    {
        std::cin >> a;
        v[i] = a;
    }
    std::cout << "Проверка элементов вектора: есть ли > 3? \n";
    std::cout << any_of(v.begin(), v.end(), PredicateFirst<int>) << std::endl;
    std::cout << "Проверка элементов вектора: отсортированы ли по убыванию? \n";
    std::cout << is_sorted(v.begin(), v.end(), PredicateSecond<int>) << std::endl;
    std::cout << "Найти для вектора первый элемент с конца, не равный данному \nВведите целое число: \n";
    int k;
    std::cin >> k;
    std::cout << *find_backward(v.begin(), v.end(), k) << std::endl;

    return 0;
}