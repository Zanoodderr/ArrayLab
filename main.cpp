#include <iostream>
#include "array.h"

int main(){
    /*
    Array arr;
    arr.setValue(6);
    arr.setValue(60);
    arr.setValue(40);
    std::cout << "\nShow elements:\n";
    arr.showElements();
    std::cout << "Get size:\n";
    std::cout << arr.getSize() << std::endl;
    std::cout << "Get elem size:\n";
    std::cout << arr.getElemSize() << std::endl;
    std::cout << "Set array:\n";
    int* pArr = new int[3]{ 1, 15, -87};
    arr.setArray(pArr, 3);
    arr.showElements();
    */

    Array arr1, arr2;
    arr1.setValue(6);
    arr1.setValue(60);
    arr2.setValue(40);
    arr2.setValue(40);

    if( arr1 == arr2) {
        std::cout << "\n Eq" <<std::endl;
    }

    if( arr1 != arr2) {
        std::cout << "\n \n Not Eq" <<std::endl;
    }
    
    std::cout << arr1 << std::endl;
    std::cout << arr1 + 5 << std::endl;
    std::cout << arr2 << std::endl;
    std::cout << arr2 - 5 << std::endl;

    Array arr3  =  arr1 + arr2;
    std::cout << "arr3\n"<< arr3 << std::endl;
    -arr3;
    std::cout << "-arr3\n" << arr3 << std::endl;
    +arr3;
    std::cout << "+arr3\n" << arr3 << std::endl;
    +arr3;
    std::cout << "+arr3\n" << arr3 << std::endl;
    arr3++;
    std::cout << "arr3++\n"<< arr3 << std::endl;
    arr3 += 10;
    std::cout << "arr3 += 10\n" << arr3 << std::endl;
    std::cout << "arr3[3]\n" << arr3[3] << std::endl;
    /*
    */
}