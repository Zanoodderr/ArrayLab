#include <iostream>
#include <cassert>

#ifndef ARRAY_H
#define ARRAY_H

class Array{
private:
    int arrLength;
    int arrStep; //The step by which the array increases
    int* arrPointer;
    int arrCurrentIndex;
    void setCurrentIndex(int index){ arrCurrentIndex = index;}
    void setArrLength(int length) {arrLength = length; }

public:
    Array(int arrLength = 0, int arrStep = 1){
        assert (arrLength >= 0 && arrStep > 0);
        this->arrLength = arrLength;
        this->arrStep = arrStep;
        if (arrLength != 0)
            arrPointer = new int[arrLength];
        else
            arrPointer = new int[1];
        setCurrentIndex(0);
    }

    Array(int* arrPtr, int step = 1) : arrStep(step){
        assert (arrPtr != nullptr);
        this->arrPointer = arrPtr;
        arrLength = sizeof(arrPointer) / sizeof(int);
        arrCurrentIndex = arrLength - 1;
    }
    
    ~Array(){ 
        delete[] arrPointer; 
    }

    Array(const Array& array) : arrLength(array.arrLength) {
        if (arrLength != 0) {
            arrPointer = new int[arrLength];
            for (int i = 0; i < arrLength; i++)
                arrPointer[i] = array.arrPointer[i];
        }
        else
            arrPointer = new int[1];
    }

    Array& operator= (const Array array) {
        arrLength = array.arrLength;
        delete[] arrPointer;
        if (arrLength != 0) {
            arrPointer = new int[arrLength];
            for (int i = 0; i < arrLength; i++)
                arrPointer[i] = array.arrPointer[i];
        }
        else
            arrPointer = new int[1];
        return *this;
    }

    int getSize(){ return arrLength;}
    int getArrStep() {return arrStep; }
    int getArrCurrentIndex() {return arrCurrentIndex; }
    void showElements();
    void expandArray(int size);
    int getElemSize();
    void setValue(int val);        
    void setArray(const int* pArr ,  int size);

    //Operators
    Array operator+(Array array);
    void operator+();
    void operator-();
    bool operator==(Array array);
    bool operator!=(Array array);
    void operator++(int);
    Array operator+(int number);
    Array operator-(int number);
    void operator+=(int number);
    int operator[](int number);
    friend std::ostream& operator<< (std::ostream &out, const Array &array);
    friend Array operator+ (int, Array array);
};

#endif