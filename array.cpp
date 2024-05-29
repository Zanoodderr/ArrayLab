#include <iostream>
#include "array.h"

void Array::showElements(){
    for (int i = 0; i < arrLength - 1; i++)
        std::cout << arrPointer[i] << " ";

    std::cout << arrPointer[arrLength - 1] << std::endl;
}

void Array::expandArray(int size){
    arrLength += size;
    int* bufferArr = new int[arrLength];
    for (int i = 0; i < arrLength - size; i++)
        bufferArr[i] = arrPointer[i];    
    
    delete[] arrPointer;
    arrPointer = bufferArr;
}

int Array::getElemSize(){
    int i;
    for (i = 0; i < arrLength; i++)
        if (&arrPointer[i] == 0) break;
    return i;
}

void Array::setValue(int val){
    expandArray(arrStep);
    arrCurrentIndex = arrLength - 1;
    arrPointer[arrCurrentIndex] = val;
}

void Array::setArray(const int* pArr,  int size){
    int oldSize = arrLength;
    expandArray(size);
    for (int i = arrLength - size; i < arrLength; i++)
        arrPointer[i] = pArr[i - oldSize];       
}

//Operators

Array Array::operator+(Array array){
    Array arr1(*this);
    Array arr2(array);
    Array resultArray(arr1.arrLength + arr2.arrLength);
    for (int i = 0; i < resultArray.arrLength; i++){
        if (i < arr1.arrLength)
            resultArray.arrPointer[i] = arr1[i];
        else
            resultArray.arrPointer[i] = arr2[i - arr1.arrLength];
    }
    return resultArray;
}

void Array::operator+(){
    for (int i = 0; i < arrLength; i++)
        arrPointer[i] += 7;
}

void Array::operator-(){
    for (int i = 0; i < arrLength; i++)
        arrPointer[i] -= 7;
}

bool Array::operator==(Array array){
    if (arrLength != array.arrLength)
        return false;
    for (int i = 0; i < arrLength; i++){
        if(arrPointer[i] == array.arrPointer[i])
            continue;
        return false;
    }
    return true;
}

bool Array::operator!=(Array array){
    if (arrLength != array.arrLength)
        return true;
    for (int i = 0; i < arrLength; i++){
        if(arrPointer[i] != array.arrPointer[i])
            return true;
    }
    return false;
}

void Array::operator++(int){
    for (int i = 0; i < arrLength; i++)
        arrPointer[i] += 1;
}

Array Array::operator+=(int number){
    for (int i = 0; i < arrLength; i++)
        arrPointer[i] += number;
    return *this;
}

Array Array::operator+(int number){
    Array thisArr(*this);
    for (int i = 0; i < arrLength; i++)
        thisArr.arrPointer[i] += number;
    return thisArr;
}

Array Array::operator-(int number){
    Array thisArr(*this);
    for (int i = 0; i < arrLength; i++)
        thisArr.arrPointer[i] -= number;
    return thisArr;
}

int Array::operator[](int number){
    if (number > arrLength)
        return arrPointer[0];
    return arrPointer[number];
}

std::ostream& operator<<(std::ostream &out, const Array &array){
    for (int i = 0; i < array.arrLength; i++)
        out << array.arrPointer[i] << " ";
    out << std::endl;
    return out;
}

Array operator+ (int, Array array){
    Array thisArr(array);
    for (int i = 0; i < thisArr.arrLength; i++)
        thisArr.arrPointer[i] += 7;
    return thisArr;
}