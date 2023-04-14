#include "figure.h"
#include "class_menu.h"
#include <vector>
#include <fstream>
#include <string>


Menu menu;

std::vector<IGeoFig *> geo_fig_array;
std::vector<IPhysObject *> phys_objects;
std::vector<IPrintable *> print_array;
std::vector<BaseCObject *> base_objects;

Rectangle *rectangles = new Rectangle[1000];
Trapeze *trapezes = new Trapeze[1000];

int n1 = 0;
int n2 = 0;

void get_elements() {
    menu.new_element("Добавить прямоугольник", 1);
    menu.new_element("Добавить трапецию", 2);
    menu.new_element("Вывести массу системы", 3);
    menu.new_element("Вывести центр тяжести системы", 4);
    menu.new_element("Вывести периметр всех фигур", 5);
    menu.new_element("Вывести площадь всех фигур", 6);
    menu.new_element("Вывести центр тяжести фигуры", 7);
    menu.new_element("Вывести периметр фигуры", 8);
    menu.new_element("Вывести площадь фигуры", 9);
    menu.new_element("Сравнить две фигуры по массе", 10);
    menu.new_element("Вывести размер памяти, занимаемой всеми фигурами", 11);
}

void step_menu() {
    int code = menu.get_code();
    if (code < 0) return;

    switch (code) {
        case 1: {
            Rectangle new_rec;
            rectangles[n1] = new_rec;
            rectangles[n1].initFromDialog();
            geo_fig_array.push_back(&rectangles[n1]);
            phys_objects.push_back(&rectangles[n1]);
            print_array.push_back(&rectangles[n1]);
            base_objects.push_back(&rectangles[n1]);
            ++n1;
            break;
        }
        case 2: {
            Trapeze new_tra;
            trapezes[n2] = new_tra;
            trapezes[n2].initFromDialog();
            geo_fig_array.push_back(&trapezes[n2]);
            phys_objects.push_back(&trapezes[n2]);
            print_array.push_back(&trapezes[n2]);
            base_objects.push_back(&trapezes[n2]);
            ++n2;
            break;
        }
        case 3: {
            double mass = 0;
            for (auto a: phys_objects) {
                mass += a->mass();
            }
            std::cout << "Масса равна " << mass << '\n';
            break;
        }
        case 4: {
            if (phys_objects.size() == 0) {
                std::cout << "Нету фигур и нет центра тяжести\n";
                return;
            }
            double x = phys_objects[0]->position().x;
            double y = phys_objects[0]->position().y;
            double mass = phys_objects[0]->mass();
            for (auto a: phys_objects) {
                double k = (mass + a->mass()) / mass;
                x = (x + a->position().x) / k;
                y = (y + a->position().y) / k;
            }
            std::cout << "Центр масс системы находится по координатам\n";
            std::cout << "  X = " << x << '\n';
            std::cout << "  Y = " << y << '\n';
            std::cout << "\n";
            break;
        }
        case 5: {
            double sum = 0;
            for (auto a: geo_fig_array) {
                sum += a->perimeter();
            }
            std::cout << "А вот и периметр подъехал, который = " << sum << '\n';
            break;
        }
        case 6: {
            double sum = 0;
            for (auto a: geo_fig_array) {
                sum += a->square();
            }
            std::cout << "А вот и общая площадь, которая = " << sum << '\n';
            break;
        }
        case 7: {
            std::cout << "Введите номер нужной фигуры, их всего " << phys_objects.size() << '\n';
            int num = -1;
            try {
                std::cin >> num;
                if (num < 0 || num >= phys_objects.size()) {
                    throw 1;
                }
            }
            catch (int a) {
                std::cout << "Кто-то ввел не то, что просили" << '\n';
                return;
            }
            std::cout << "Центр тяжести нужной фигуры расположен по координатам" << '\n';
            std::cout << "  X = " << phys_objects[num]->position().x << '\n';
            std::cout << "  Y = " << phys_objects[num]->position().y << '\n';
            std::cout << '\n';
            break;
        }
        case 8: {
            std::cout << "Введите номер нужной фигуры, их всего " << phys_objects.size() << '\n';
            int num = -1;
            try {
                std::cin >> num;
                if (num < 0 || num >= phys_objects.size()) {
                    throw 1;
                }
            }
            catch (int a) {
                std::cout << "Кто-то ввел не то, что просили" << '\n';
                return;
            }
            std::cout << "Периметр нужной фигуры равен " << geo_fig_array[num]->perimeter() << '\n';
            std::cout << '\n';
            break;
        }
        case 9: {
            std::cout << "Введите номер нужной фигуры, их всего " << phys_objects.size() << '\n';
            int num = -1;
            try {
                std::cin >> num;
                if (num < 0 || num >= phys_objects.size()) {
                    throw 1;
                }
            }
            catch (int a) {
                std::cout << "Кто-то ввел не то, что просили" << '\n';
                return;
            }
            std::cout << "Площадь нужной фигуры равен " << geo_fig_array[num]->square() << '\n';
            std::cout << '\n';
            break;
        }
        case 10: {
            std::cout << "Введите номера двух фигур, их всего " << phys_objects.size() << '\n';
            int num_1 = -1, num_2 = -1;
            try {
                std::cin >> num_1 >> num_2;
                if (num_1 < 0 || num_1 >= phys_objects.size() || num_2 < 0 || num_2 >= phys_objects.size()) {
                    throw 1;
                }
            }
            catch (int a) {
                std::cout << "Кто-то ввел не то, что просили" << '\n';
                return;
            }
            if (*phys_objects[num_1] == *phys_objects[num_2]) {
                std::cout << "Ух ты, фигуры равны по массе" << '\n';
            } else if (*phys_objects[num_1] < *phys_objects[num_2]) {
                std::cout << "А первая фигура весит меньше, чем вторая" << '\n';
            } else {
                std::cout << "Первая фигура массивнее второй" << '\n';
            }
            break;
        }
        case 11: {
            unsigned int res = 0;
            for (auto a: base_objects) {
                res += a->size();
            }
            std::cout << res << '\n';
        }
    }
}

int main() {
    system("chcp 65001");
    get_elements();
    while (true)
        //system("clear");
        step_menu();
    // Rectangle new_rec;
    // IPhysObject *test = &new_rec;
    // new_rec.initFromDialog();
    // new_rec.draw();
    // std::cout << test->mass() << '\n';
    // menu.get_code();
    return 0;
}