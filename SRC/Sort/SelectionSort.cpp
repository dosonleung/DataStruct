//
//  SelectionSort.cpp
//  DataStruct
//
//  Created by DosonLeung on 2/24/18.
//  Copyright © 2018 DosonLeung. All rights reserved.
//

#include "SelectionSort.hpp"

void SelectionSort(ElemType E[], int len, bool isAscending){
    int index = 0;
    for (int i = 0; i < len - 1; i++){
        index = i;
        for (int j = i+1; j < len; j++) {//Find the index of the maximum/minimum in the list
            if (isAscending) {
                if (E[j].key < E[index].key) {
                    index = j;
                    break;
                }
            }else{
                if (E[j].key > E[index].key) {
                    index = j;
                    break;
                }
            }
        }
        if (index != i) {
            swap(E,i,index);
        }
        std::cout << "i = " << i << std::endl;
        printElements(E,len);
    }
}

//Example
/*
 int main(int argc, const char * argv[]) {
 //int e[] = {9,8,7,6,5,4,3,2,1,0};
    int e[] = {0,1,2,3,4,5,6,7,8,9};
    ElemType E[10];
    for (int i = 0; i < 10; i++) {
        E[i].key = e[i];
    }
    std::cout << "Before BubblingSort" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << E[i].key << " ";
    }
    std::cout << std::endl;
    SelectionSort(E, 10, false);
    std::cout << "After BubblingSort" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << E[i].key << " ";
    }
    std::cout << std::endl;
    return 0;
 }

 */
