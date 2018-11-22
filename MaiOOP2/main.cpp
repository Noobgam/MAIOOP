#include <iostream>
#include "HexagonList.hpp"

int main(int argc, const char * argv[]) {
    HexagonList list;
    int menuNum = 7;
    long int size;
    std::cout << "1. push back" << std::endl;
    std::cout << "2. push front" << std::endl;
    std::cout << "3. delete item from list to pos" << std::endl;
    std::cout << "4. print list." << std::endl;
    std::cout << "5. insert in list to pos" << std::endl;
    std::cout << "6. clear" << std::endl;
    std::cout << "0. exit" << std::endl;
    while (menuNum != 0) {
        std::cin >> menuNum;
        switch (menuNum)
        {
            case 0:
                break;
            case 1:
                std::cin >> size;
                if (size >= 0) {
                    list.push_back(Hexagon(size));
                }
                break;
            case 2:
                std::cin >> size;
                if (size >= 0) {
                    list.push_front(Hexagon(size));
                }
                break;
            case 3:
                std::cin >> size;
                list.remove(size);
                break;
            case 4:
                std::cout << list << std::endl;
                break;
            case 5:
                long int a;
                std::cin >> size >> a;
                list.insert(size, a);
                break;
            case 6:
                list.clear();
                break;
            case 7:
                break;
        }
    }
    return 0;
}
