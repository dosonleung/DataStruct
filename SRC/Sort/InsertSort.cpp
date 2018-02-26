//
//  InsertSort.cpp
//  DataStruct
//
//  Created by DosonLeung on 2/24/18.
//  Copyright © 2018 DosonLeung. All rights reserved.
//

#include "InsertSort.hpp"

void InsertSort(ElemType E[] , int len, bool isAscending){
    for (int i = 1; i < len; i++){
        int tar = i;
        for (int j = i-1; j >= 0; j--){//Find the elem which less/large than the one at i
            if (isAscending) {
                if (E[j].key > E[i].key) {
                    tar--;
                }else{
                    break;
                }
            }else{
                if (E[j].key < E[i].key) {
                    tar--;
                }else{
                    break;
                }
            }
        }
        if (tar != i) {//If found,push all the elements back for one step and replace the one at tar with E[i]
            ElemType e = E[i];
            for (int k = i; k > 0; k--) {
                E[k] = E[k-1];
            }
            E[tar] = e;
        }
        std::cout << "i = " << i << " " << "tar = " << tar << std::endl;
        printElements(E,len);
    }
}

/*Example
 int main(int argc, const char * argv[]) {
 //int e[] = {9,8,7,6,5,4,3,2,1,0};
    int e[] = {0,1,2,3,4,5,6,7,8,9};
    ElemType E[10];
    for (int i = 0; i < 10; i++) {
        E[i].key = e[i];
    }
    std::cout << "Before InsertSort" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << E[i].key << " ";
    }
    std::cout << std::endl;
    InsertSort(E, 10, false);
    std::cout << "After InsertSort" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << E[i].key << " ";
    }
    std::cout << std::endl;
    return 0;
 }
 */
