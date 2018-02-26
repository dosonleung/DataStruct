//
//  ElementType.cpp
//  DataStruct
//
//  Created by DosonLeung on 2/24/18.
//  Copyright © 2018 DosonLeung. All rights reserved.
//

#include "ElementType.hpp"

void swap(ElemType E[], int i, int j){
    ElemType tmp = E[i];
    E[i] = E[j];
    E[j] = tmp;
}

void printElements(ElemType E[], int len){
    for (int k = 0; k < len; k++) {
        std::cout << E[k].key << " ";
    }
    std::cout << std::endl;
}

void printElements(ElemType E[], int left, int right){
    for (int i = left; i <= right; i++) {
        std::cout << E[i].key << " ";
    }
    std::cout << std::endl;
}
