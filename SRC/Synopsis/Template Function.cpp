//
//  Template Function.cpp
//  DataStruct
//
//  Created by DosonLeung on 2/24/18.
//  Copyright © 2018 DosonLeung. All rights reserved.
//
//  In programming , we may come across the same functions with different parameters.To solve this problem , we can define mult-overload functions such as the example
//  that the following function exchange the values of two integer varaibles.
//

#include <stdio.h>

//example
void Swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

//We can define a generic template like
template <class T> void Swap(T &x, T &y)
{
    T tmp = x;
    x = y;
    y = tmp;
}

//We can expand this idea for template class like Array
template <class T> class Array{
    public:
        Array(int length);
        T max();
        T min();
        ~Array();
    private:
        T *arr;
        int len;
};

//To implement the template function in the template class like
template <class T> Array<T>::Array(int length)
{
    arr = new T[length];
    len = length;
}

template <class T> T Array<T>::max()
{
    int max = 0;
    for (int i = 0; i < len ; i++){
        if (arr[max] > arr[i]) {
            max = i;
        }
        return arr[max];
    }
}
