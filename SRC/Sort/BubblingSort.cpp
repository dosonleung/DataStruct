//
//  BubblingSort.cpp
//  DataStruct
//
//  Created by DosonLeung on 2/24/18.
//  Copyright © 2018 DosonLeung. All rights reserved.
//

#include "BubblingSort.hpp"

void BubblingSort(ElemType E[] , int len, bool isAscending){
    int i , j;
    ElemType tmp;
    for (i = 0; i < len; i++){
        for (j = 0; j < len-i-1; j++){
            if (isAscending) {
                if (E[j].key > E[j+1].key) {
                    tmp = E[j];
                    E[j] = E[j+1];
                    E[j+1] = tmp;
                }
            }else{
                if (E[j].key < E[j+1].key) {
                    tmp = E[j];
                    E[j] = E[j+1];
                    E[j+1] = tmp;
                    swap(E,j,j+1);
                }
            }
        }
        std::cout << "i = " << i << std::endl;
        printElements(E,len);
    }
}

//Example
/*
int main(int argc, const char * argv[]) {
    int e[] = {9,8,7,6,5,4,3,2,1,0};
    ElemType E[10];
    for (int i = 0; i < 10; i++) {
        E[i].key = e[i];
    }
    std::cout << "Before BubblingSort" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << E[i].key << " ";
    }
    std::cout << std::endl;
    BubblingSort(E, 10, true);
    std::cout << "After BubblingSort" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << E[i].key << " ";
    }
    std::cout << std::endl;
    return 0;
}
 */

