
#include "class_menu.h"




bool Menu::new_element(std::string name, int code)
{
    if(code < 0)
    {
        return false;
    }
    for(auto a : array_elements)
    {
        if(a.name == name || a.code == code)
        {
            return false;
        }
    }
    array_elements.push_back(Node(name, code));
    count_elements++;
    return true;
}

int Menu::get_code()
{
    for(auto a : array_elements)
    {
        std::cout << a.code << ' ' << a.name << '\n';
    }
    int res = -1;
    try
    {
        std::cin >> res;
        if(res < 0 || res > count_elements)
        {
            throw -1;
        }
    }
    catch(int a)
    {
        std::cout << "Упс, что-то пошло немного не по плану\n";
        if(a == -1)
        {
            std::cout << "Кто-то накосячил и ввел не то число, прости но ты всё испортил\n";
        }
        res = -1;
    }
    return res;
}