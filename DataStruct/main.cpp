//
//  main.cpp
//  DataStruct
//
//  Created by DosonLeung on 2/24/18.
//  Copyright © 2018 DosonLeung. All rights reserved.
//

#include <iostream>
#include "MergeSort.hpp"

int main(int argc, const char * argv[]) {
    int e[] = {3,1,2,8,9,4,5,7,6,0};
    //int e[] = {0,1,2,3,4,5,6,7,8,9};
    //int e[] = {9,8,7,6,5,4,3,2,1,0};
    ElemType E[10];
    for (int i = 0; i < 10; i++) {
        E[i].key = e[i];
    }
    std::cout << "Before MergeSort" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << E[i].key << " ";
    }
    std::cout << std::endl;
    MergeSort(E, 10, false);
    std::cout << "After MergeSort" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << E[i].key << " ";
    }
    std::cout << std::endl;
    return 0;
}

