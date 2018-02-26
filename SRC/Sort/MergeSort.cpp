//
//  MergeSort.cpp
//  DataStruct
//
//  Created by DosonLeung on 2/25/18.
//  Copyright © 2018 DosonLeung. All rights reserved.
//

#include "MergeSort.hpp"
#include <stack>

static int mslength = 0;

void msort(ElemType E[], int left, int right, bool isAscending){
    if (left < right && right-left > 1) {
        int len = right-left+1;
        int divide = (left+right)/2 - ((right-left+1)%2?1:0);
        std::cout << "left:" << left << " " << "divide:" << divide << " " << "right:" << right << std::endl;
        msort(E, left, divide, isAscending);
        msort(E, divide+1, right, isAscending);
        std::stack<ElemType> lStack;
        std::stack<ElemType> rStack;
        for (int i = divide; i >= left; i--) {
            lStack.push(E[i]);
        }
        for (int j = right; j > divide; j--) {
            rStack.push(E[j]);
        }
        while (!(lStack.empty()&&rStack.empty())){//if lStack or rStack are not empty
            if (lStack.empty()) {
                E[right-rStack.size()+1] = rStack.top();
                rStack.pop();
            }else if(rStack.empty()){
                int llen = divide-left+1;
                int rlen = right-divide;
                E[left+rlen+llen-lStack.size()] = lStack.top();
                lStack.pop();
            }else{//compare the element on the top of the stack and dicide which should replace the referrence element in the array
                if (isAscending) {
                    if (lStack.top().key > rStack.top().key) {
                        E[left+len-lStack.size()-rStack.size()] = rStack.top();
                        rStack.pop();
                    }else{
                        E[left+len-lStack.size()-rStack.size()] = lStack.top();
                        lStack.pop();
                    }
                }else{
                    if (lStack.top().key < rStack.top().key) {
                        E[left+len-lStack.size()-rStack.size()] = rStack.top();
                        rStack.pop();
                    }else{
                        E[left+len-lStack.size()-rStack.size()] = lStack.top();
                        lStack.pop();
                    }
                }
            }
        }
        printElements(E, mslength);
    }else{
        if(isAscending){
            if (E[left].key > E[right].key) {
                swap(E, left, right);
            }
        }else{
            if (E[left].key < E[right].key) {
                swap(E, left, right);
            }
        }
    }
}

void MergeSort(ElemType E[], int len, bool isAscending){
    mslength = len;
    msort(E, 0, len-1, isAscending);
}

/*
 
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
 
 */
