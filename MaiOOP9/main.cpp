#include <iostream>
#include "Figures/Octagon.hpp"
#include "Figures/Triangle.hpp"
#include "Figures/Hexagon.hpp"
#include "List.hpp"
#include "Vector.hpp"
#include "Iterator.h"
#include <random>
#include <future>

std::shared_ptr<Figure> makeFig() {
    int figNum;
    std::cout << "enter fig num: ";
    std::cin >> figNum;
    if (figNum == 1)
        return std::make_shared<Octagon>(std::cin);
    else if(figNum == 2)
        return std::make_shared<Triangle>(std::cin);
    else
        return std::make_shared<Hexagon>(std::cin);
}

int main(int argc, const char * argv[]) {
    List<Figure> list;
    using cmd = std::function<void(void)>;
    Vector<std::shared_ptr<cmd>> commands;

    cmd cmd_insert = [&list]() {
        std::cout << "Fill random data\n";
        std::default_random_engine gen;
        std::uniform_int_distribution<int> distribution(1, 1000);
        for (int i = 0; i < 10; ++i) {
            int a = distribution(gen), b = distribution(gen), c = distribution(gen);
            list.push_back(std::make_shared<Triangle>(a, b, c));
        }
    };
    
    cmd cmd_print = [&list]() {
        std::cout << "Print list\n";
        std::cout << list << "\n";
    };
    int area;
    std::cout << "Choose filtered area: ";
    std::cin >> area;
    
    cmd cmd_erase_small = [&list, area]() {
        List<Figure> tempList;
        for (auto x : list) {
            if (x->Square() >= area) {
                tempList.push_back(x);
            }
        }
        list = tempList;
        std::cout << "Filtered list\n";
    };

    commands.push_back(std::shared_ptr<cmd> (&cmd_print, [](cmd*){}));
    commands.push_back(std::shared_ptr<cmd> (&cmd_erase_small, [](cmd*){}));    
    commands.push_back(std::shared_ptr<cmd> (&cmd_print, [](cmd*){}));
    commands.push_back(std::shared_ptr<cmd> (&cmd_insert, [](cmd*){}));
    commands.push_back(std::shared_ptr<cmd> (&cmd_print, [](cmd*){}));

    while (int size = commands.GetSize()) {
        (*commands[size - 1])();
        commands.pop_back();
    }
    return 0;
}
