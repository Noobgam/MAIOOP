#include <iostream>
#include "Figures/Octagon.hpp"
#include "Figures/Triangle.hpp"
#include "Figures/Hexagon.hpp"
#include "List.hpp"
#include "Iterator.h"

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
    std::shared_ptr<Figure> fig;
    int menuNum = 7;
    long int size;
    
    for(int i = 1; i < 10; i++) {
        fig = std::make_shared<Octagon>(i);
        list.push_back(fig);
    }
    for(auto i : list) std::cout << i->ToString() << std::endl;
    
    
    std::cout << "1. push back" << std::endl;
    std::cout << "2. push front" << std::endl;
    std::cout << "3. delete item from list to pos" << std::endl;
    std::cout << "4. print list." << std::endl;
    std::cout << "5. insert in list to pos" << std::endl;
    std::cout << "6. clear" << std::endl;
    std::cout << "0. exit" << std::endl;
    std::cout << "figures numbers: 1 - Octagon, 2 - Triangle, 3 Hexagon" << std::endl;
    while (menuNum != 0) {
        std::cin >> menuNum;
        switch (menuNum)
        {
            case 0:
                break;
            case 1:
                fig = makeFig();
                list.push_back(fig);
                break;
            case 2:
                fig = makeFig();
                list.push_front(fig);
                break;
            case 3:
                std::cin >> size;
                list.remove(size);
                break;
            case 4:
                std::cout << list << std::endl;
                break;
            case 5:
                std::cin >> size;
                fig = makeFig();
                list.insert(size, fig);
                break;
            case 6:
                list.clear();
                break;
            case 7:
                break;
        }
        std::cout << "----------------------" << std::endl;
    }
    return 0;
}
