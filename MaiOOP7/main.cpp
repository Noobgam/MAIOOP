#include <iostream>
#include "Figures/Octagon.hpp"
#include "Figures/Triangle.hpp"
#include "Figures/Hexagon.hpp"
#include "List.hpp"
#include "Vector.hpp"
#include <string>
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
    List<Vector<std::shared_ptr<Figure>>> list;
    auto push_front = [&list] (std::shared_ptr<Figure> item) {
        if (list.empty() || list.begin()->GetSize() >= 5) {
            list.push_front(
                std::make_shared<Vector<std::shared_ptr<Figure>>>()
            );
        }
        (*list.begin())->push_back(item);
    };
    std::shared_ptr<Figure> fig;
    int menuNum = 7;
    long int size;
    
    for(int i = 1; i < 10; i++) {
        fig = std::make_shared<Octagon>(i);
        
        push_front(fig);
    }
//    for(auto i : list) std::cout << i->ToString() << std::endl;
    
    std::cout << "1. push front" << std::endl;
    std::cout << "2. print list." << std::endl;
    std::cout << "3. filter" << std::endl;
    std::cout << "4. clear" << std::endl;
    std::cout << "0. exit" << std::endl;
    std::cout << "figures numbers: 1 - Octagon, 2 - Triangle, 3 Hexagon" << std::endl;
    while (menuNum != 0) {
        std::cin >> menuNum;
        switch (menuNum)
        {
            case 1:
            {
                fig = makeFig();
                push_front(fig);
                break;
            }
            case 2:
            {
                std::cout << list << std::endl;
                break;
            }
            case 3:
            {
                std::cout << "Enter type or Square to filter by area\n";
                std::string input;
                std::cin >> input;
                List<Vector<std::shared_ptr<Figure>>> newList;
                if (input == "Octagon") {
                    for (const auto& vect : list) {
                        std::shared_ptr<Vector<std::shared_ptr<Figure>>> vec = FilterFigures(vect, [] (const std::shared_ptr<Figure>& figure) {
                            return dynamic_cast<Octagon*>(&*figure) != NULL;
                        });
                        if (vec->GetSize() != 0)
                            newList.push_back(vec);
                    }
                } else if (input == "Triangle") {
                    for (const auto& vect : list) {
                        std::shared_ptr<Vector<std::shared_ptr<Figure>>> vec = FilterFigures(vect, [] (const std::shared_ptr<Figure>& figure) {
                            return dynamic_cast<Triangle*>(&*figure) != NULL;
                        });
                        if (vec->GetSize() != 0)
                            newList.push_back(vec);
                    }
                } else if (input == "Hexagon") {
                    for (const auto& vect : list) {
                        std::shared_ptr<Vector<std::shared_ptr<Figure>>> vec = FilterFigures(vect, [] (const std::shared_ptr<Figure>& figure) {
                            return dynamic_cast<Hexagon*>(&*figure) != NULL;
                        });
                        if (vec->GetSize() != 0)
                            newList.push_back(vec);
                    }
                } else if (input == "Square") {
                    int sq;
                    std::cin >> sq;
                    for (const auto& vect : list) {
                        std::shared_ptr<Vector<std::shared_ptr<Figure>>> vec = FilterFigures(vect, [sq] (const std::shared_ptr<Figure>& figure) {
                            return figure->Square() >= sq;                            
                        });
                        if (vec->GetSize() != 0)
                            newList.push_back(vec);
                    }
                }
                list = newList;
                break;
            }
            case 4:
                list.clear();
                break;
            default:
                break;
        }
        std::cout << "----------------------" << std::endl;
    }
    return 0;
}
