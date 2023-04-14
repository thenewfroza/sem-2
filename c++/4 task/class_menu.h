

#ifndef INC_4_TASK_CLASS_MENU_H
#define INC_4_TASK_CLASS_MENU_H

#include <vector>
#include <iostream>
#include <string>


class Menu {
private:
    struct Node {
        std::string name;
        int code;

        Node(std::string name, int code) : name(name), code(code) {}
    };

    int count_elements = 0;
    std::vector<Node> array_elements;
public:
    Menu() {}

    ~Menu() {}

    bool new_element(std::string, int);

    int get_code();
};

#endif //INC_4_TASK_CLASS_MENU_H
