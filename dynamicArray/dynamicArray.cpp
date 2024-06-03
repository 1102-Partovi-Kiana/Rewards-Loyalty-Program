#include "dynamicArray.h"
#include <iostream>
template <class T>
dynamicArray<T>::dynamicArray()
{
    array = new T[1];
    maxSizeOfArr = 1;
    currentNumItemsInArr = 0;
}

template <class T>
dynamicArray<T>::dynamicArray(T *dyn, int maxSize, int currentNumInArray)
{
    array = new T[currentNumInArray];
    maxSizeOfArr = maxSize;
    currentNumItemsInArr = currentNumInArray;
}

template <class T>
dynamicArray<T>::dynamicArray(const dynamicArray &rhs)
{
    array = new T[rhs.currentNumItemsInArr];
    maxSizeOfArr = rhs.maxSizeOfArr;
    currentNumItemsInArr = rhs.currentNumItemsInArr;
}

template <class T>
dynamicArray<T>::~dynamicArray()
{
    delete[] array;
}

template <class T>
int dynamicArray<T>::getMaxSizeOfArr()
{
    return maxSizeOfArr;
}

template <class T>
void dynamicArray<T>::setMaxSizeOfArr(int maxSize)
{
    maxSizeOfArr = maxSize;
}

template <class T>
int dynamicArray<T>::getCurrentNumItemsInArr() const
{
    return currentNumItemsInArr;
}

template <class T>
void dynamicArray<T>::setCurrentNumItemsInArr(int currentNumInArray)
{
    currentNumItemsInArr = currentNumInArray;
}

template <class T>
T *dynamicArray<T>::getArray()
{
    return array;
}

// template<class T>
// void dynamicArray<T>::addToArray(T addingThisToEnd) {
//     T* temp = new T[currentNumItemsInArr];
//     for (int i = 0; i < currentNumItemsInArr; i++) {
//         temp[i] = array[i];
//     }
//     delete [] temp;
//     array = new T[currentNumItemsInArr + 1];
//     for (int i = 0; i < currentNumItemsInArr; i++) {
//         array[i] = temp[i];
//     }
//     delete [] temp;
//     array[currentNumItemsInArr] = addingThisToEnd;
//     currentNumItemsInArr++;
// }

template <class T>
dynamicArray<T> &dynamicArray<T>::operator=(const dynamicArray<T> &rhs)
{
    delete[] array;
    array = rhs.array;
    currentNumItemsInArr = rhs.currentNumItemsInArr;
    maxSizeOfArr = rhs.maxSizeOfArr;
    array = new T[maxSizeOfArr];
    for (int i = 0; i < currentNumItemsInArr; i++)
    {
        array[i] = rhs.array[i];
    }

    return *this;
}

template <class T>
void dynamicArray<T>::increaseArrWhenFull() const
{
    T *tempA;
    while (maxSizeOfArr < currentNumItemsInArr + 1)
    {
        T *tempA = new T[maxSizeOfArr];
        for (int i = 0; i < currentNumItemsInArr; i++)
        {
            tempA[i] = array[i];
        }
        delete[] array;
        maxSizeOfArr *= 2;
        array = new T[maxSizeOfArr];
        for (int i = 0; i < currentNumItemsInArr; i++)
        {
            array[i] = tempA[i];
        }
    }
    // delete [] tempA; took this out to work 
}

template <class T> // step 5 adder
void dynamicArray<T>::addItemToArray(const T& newItemToAdd) 
{
    increaseArrWhenFull();
    array[currentNumItemsInArr] = newItemToAdd;
    currentNumItemsInArr++;
}

template <class T> // step 6
T dynamicArray<T>::returnsElementAtSpecifiedIndex(const int index) const
{
    return array[index];
}
// A dd a method that returns an element from the array at a specified index parameter.
//  The parameters and method should be const.

template <class T>
void dynamicArray<T>::doesAlotOfStuff()
{
    delete[] array;
    array = new T[1];
    maxSizeOfArr = 1; // should always be bigger
    currentNumItemsInArr = 0;
}
