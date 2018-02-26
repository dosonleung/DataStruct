//
//  HeapSort.cpp
//  DataStruct
//
//  Created by DosonLeung on 2/25/18.
//  Copyright © 2018 DosonLeung. All rights reserved.
//

#include "HeapSort.hpp"

//if ascending, we should make a min heap else max heap heap
void adjustHeap(ElemType E[], int index, int length,bool isAscending){
    ElemType curNode = E[index];
    int childIndex = 2*index+1;//the larger/smaller child index
    while(childIndex < length){
        if (childIndex+1 < length) {
            if (isAscending) {
                if (E[childIndex].key < E[childIndex+1].key) {//Find the smaller child
                    childIndex ++;
                }
            }else{
                if (E[childIndex].key > E[childIndex+1].key) {//Find the larger child
                    childIndex ++;
                }
            }
        }
        //Find the larger/smaller child below this child
        if (isAscending) {
            if (curNode.key < E[childIndex].key) {
                E[index] = E[childIndex];
                index = childIndex;
                childIndex = 2*index+1;
            }else{
                break;
            }
        }else{
            if (curNode.key > E[childIndex].key) {
                E[index] = E[childIndex];
                index = childIndex;
                childIndex = 2*index+1;
            }else{
                break;
            }
        }
    }
    E[index] = curNode;
}

void HeapSort(ElemType E[], int len, bool isAscending){
    //build heap from the index of the parent node of the last node
    std::cout << "adjust heap:" << std::endl;
    for (int i = len/2-1; i >= 0; i--) {
        adjustHeap(E, i, len, isAscending);
        printElements(E, len);
    }
    //get the node from the top of the heap
    std::cout << "pop heap:" << std::endl;
    for (int i = len-1; i >= 0; i--) {
        ElemType topNode = E[0];
        E[0] = E[i];
        E[i] = topNode;
        adjustHeap(E, 0, i, isAscending);
        printElements(E, len);
    }
    
}
