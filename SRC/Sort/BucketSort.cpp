//
//  BucketSort.cpp
//  DataStruct
//
//  Created by DosonLeung on 2/26/18.
//  Copyright © 2018 DosonLeung. All rights reserved.
//

#include "BucketSort.hpp"
#include <vector>
#include "QuickSort.hpp"

#define BUCKET_NUMS 10

void printBuckets(std::vector<ElemType> *buckets,int len){
    for (int i = 0; i < len; i++) {
        std::cout << "Bucket" << i << ": " ;
        for (int j = 0; j < buckets[i].size(); j++) {
            std::cout << buckets[i][j].key << " ";
        }
        std::cout << std::endl;
    }
}

void BucketSort(ElemType E[] , int len, bool isAscending){
    std::vector<ElemType> buckets[BUCKET_NUMS];
    int maximum = INT_MIN;
    int minimum = INT_MAX;
    int distance = 0;//size of each buckets
    for (int i = 0; i < len; i++) {
        if (E[i].key < minimum) {
            minimum = E[i].key;
        }
        if (E[i].key > maximum){
            maximum = E[i].key;
        }
    }
    distance = (maximum-minimum)/BUCKET_NUMS+1;//Each buckets' size will plus by 1 for a litte bigger the theoretical value
    for (int j = 0; j < len; j++) {
        int index = E[j].key/distance;
        buckets[index].push_back(E[j]);
    }
    std::cout << "Before Sort Buckets" << std::endl;
    printBuckets(buckets,BUCKET_NUMS);
    for (int k = 0; k < BUCKET_NUMS; k++) {//Sort each buckets
        if (buckets[k].size()) {
            QuickSort(&buckets[k][0], (int)buckets[k].size(), isAscending);
        }
    }
    std::cout << "After Sort Buckets" << std::endl;
    printBuckets(buckets,BUCKET_NUMS);
    int m = 0;
    for (int l = 0; l < BUCKET_NUMS; l++) {//put element back into the array E
        if (isAscending) {
            if (buckets[l].size() > 0){
                for (std::vector<ElemType>::iterator it = buckets[l].begin(); it != buckets[l].end(); it++) {
                    E[m++] = *it;
                }
            }
        }else{
            if (buckets[BUCKET_NUMS-l-1].size() > 0){
                for (std::vector<ElemType>::iterator it = buckets[BUCKET_NUMS-l-1].begin(); it != buckets[BUCKET_NUMS-l-1].end(); it++) {
                    E[m++] = *it;
                }
            }
        }
    }
}

/*
 example
 int main(int argc, const char * argv[]) {
    int e[] = {3,1,2,8,9,4,5,7,6,0,11,43,44,45,22,33};
    //int e[] = {0,1,2,3,4,5,6,7,8,9};
    //int e[] = {9,8,7,6,5,4,3,2,1,0};
    ElemType E[16];
    for (int i = 0; i < 16; i++) {
        E[i].key = e[i];
    }
    std::cout << "Before BucketSort" << std::endl;
    for (int i = 0; i < 16; i++) {
        std::cout << E[i].key << " ";
    }
    std::cout << std::endl;
    BucketSort(E, 16, true);
    std::cout << "After BucketSort" << std::endl;
    for (int i = 0; i < 16; i++) {
        std::cout << E[i].key << " ";
    }
    std::cout << std::endl;
    return 0;
 }
 
 */

