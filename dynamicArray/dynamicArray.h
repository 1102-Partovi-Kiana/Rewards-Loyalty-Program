#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#define MAX_SIZE_OF_ARR 50

template <class T>
class dynamicArray {
    private:
        mutable T* array;
        mutable int maxSizeOfArr;  // num
        mutable int currentNumItemsInArr; // max pets
        void increaseArrWhenFull() const;

    public:
        dynamicArray();
        dynamicArray(T*, int, int);
        dynamicArray(const dynamicArray&);
        ~dynamicArray();

        int getMaxSizeOfArr();
        void setMaxSizeOfArr(int);

        int getCurrentNumItemsInArr() const;
        void setCurrentNumItemsInArr(int);

        T* getArray();
        //void addToArray(T);

        dynamicArray<T>& operator=(const dynamicArray<T>& rhs);
        void addItemToArray(const T&);
        void doesAlotOfStuff();
        T returnsElementAtSpecifiedIndex (const int index) const;


    public:
};

// #include "dynamicArray.cpp";

#endif