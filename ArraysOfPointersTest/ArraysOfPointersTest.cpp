

#include <iostream>

void CreateArrayOfPtrOnStack() {
    //allocate array of int* on the stack
    int* intptrArr[5];
    // create new integers on the free store, and assign the pointers to the array
    intptrArr[0] = new int{ 4 };
    intptrArr[1] = new int{ 3 };
    intptrArr[2] = new int{ 2 };
    intptrArr[3] = new int{ 1 };
    intptrArr[4] = new int{ 0 };

}

void CreateArrayOfPtrOnFreeStore() {
    //allocate array of int pointers on the free store
    int** intptrArr = new int*[5];
    // create new integers on the free store, and assign the pointers to the array
    intptrArr[0] = new int{ 4 };
    intptrArr[1] = new int{ 3 };
    intptrArr[2] = new int{ 2 };
    intptrArr[3] = new int{ 1 };
    intptrArr[4] = new int{ 0 };
    // delete the array of pointers.
    delete[] intptrArr;
}


int main()
{
    // after this is run and the intptrArray goes out of scope and is deleted, the memory allocated for the integers inside of it is not freed.
    CreateArrayOfPtrOnStack();

    // after this is run and the intptrArray is deleted with delete[], the memory allocated for the integers inside of it is not freed, only the memory allocated for the pointer array itself
    CreateArrayOfPtrOnFreeStore();
}

