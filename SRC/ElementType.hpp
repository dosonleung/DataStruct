//
//  ElementType.h
//  DataStruct
//
//  Created by DosonLeung on 2/24/18.
//  Copyright © 2018 DosonLeung. All rights reserved.
//

#ifndef ElementType_h
#define ElementType_h

#include <iostream>

typedef int KeyType; //Type of the keyword
typedef void* ValueType; //Type of value

typedef struct
{
    KeyType key;
    ValueType data;
}ElemType;

void swap(ElemType E[], int i, int j);
void printElements(ElemType E[] , int len);
void printElements(ElemType E[], int left, int right);

#endif /* ElementType_h */
