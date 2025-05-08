

#include <iostream>
#include <cstddef>



int* mallocTest(int size, const char* desc = "malloc:\n") {
    // allocate size bytes of memory and cast the void* to int*
    int* ptr = (int*)malloc(size);
    std::cout << desc;
    for (int i = 0; i < size / sizeof(int);i++) {
        // print each item out, and we can see the existing data has not been cleared.
        std::cout << ptr[i] << "\n";
    }
    return ptr;
}

int* callocTest(int count, const char* desc = "calloc:\n") {
    // allocate memory for "count" integers, and cast the void* to int*
    int* ptr = (int*)calloc(count, sizeof(int));
    std::cout << desc;
    for (int i = 0; i < count;i++) {
        // print each item out, and we can see the existing data has been cleared.
        std::cout << ptr[i] << "\n";
    }
    
    return ptr;
}

int* reallocTest(int* inptr, int size, const char* desc = "realloc:\n") {
    // reallocate the input pointer to 20 bytes, or 5 integers.
    inptr = (int*)realloc(inptr, size);
    std::cout << "realloc:\n";
    for (int i = 0; i < size / sizeof(int);i++) {
        // print each item out, and we can see the existing data has been cleared.
        std::cout << inptr[i] << "\n";
    }
    return inptr;
}

int* memcpyTest(int* copyTo, int* copyFrom, int size, const char* desc = "memcpy:\n") {
    // copy memory from copyFrom to copyTo
    copyTo = (int*)memcpy(copyTo, copyFrom, size);
    std::cout << desc;
    for (int i = 0; i < size / sizeof(int);i++) {
        // print each item out, and we can see the data is copied
        std::cout << copyTo[i] << "\n";
    }
    return copyTo;

}
std::uint8_t* memsetTest(std::uint8_t* toFill, std::uint8_t value, int size, const char* desc = "memset:\n") {
    // set size bytes in toFill to value
    toFill = (std::uint8_t*)memset(toFill, value, size);
    std::cout << desc;
    for (int i = 0; i < size ;i++) {
        // print each item out, and we can see the data is set
        std::cout << (int)toFill[i] << "\n";
    }
    return toFill;
}

int* memoveTest(int* copyTo, int* copyFrom, int size, const char* desc = "memove:\n") {
    // copy memory from copyFrom to copyTo
    copyTo = (int*)memmove(copyTo, copyFrom, size);
    std::cout << desc;
    for (int i = 0; i < size / sizeof(int);i++) {
        // print each item out, and we can see the data is copied
        std::cout << copyTo[i] << "\n";
    }
    return copyTo;

}


int main()
{
    // test malloc and get a pointer to the allocated memory
    int* mallocptr = mallocTest(12);
    // test calloc and get a pointer to the allocated memory
    int* callocptr = callocTest(3);

    // reallocate the callocptr to have 20 bytes allocated instead of 12, which is 5 ints;
    callocptr = reallocTest(callocptr, 20);

    // fill the mallocptr with some data
    for (int i = 0; i < 3;i++) {
        // write data to the mallocptr;
        mallocptr[i] = 4543114;
    }

    //copy 12 bytes from mallocptr into callocptr.
    callocptr = memcpyTest(callocptr, mallocptr, 12);

    std::uint8_t* buffer = (std::uint8_t*)malloc(20);

    // fill the entire allocated buffer with bytes of the value 255
    buffer = memsetTest(buffer, 255, 20);

    int* dataToWrite = (int*)malloc(20);
    for (int i = 0; i < 20 / sizeof(int) ;i++) {
        // write data to the mallocptr;
        dataToWrite[i] = 12345678;
    }

    // copy 20 bytes of data from dataToOverwrite to callocptr, works the same as memcpy here
    callocptr = memoveTest(callocptr, dataToWrite, 20);
    // write diffrent data into the callocptr
    callocptr[0] = 9481;
    callocptr[1] = 219456;
    callocptr[2] = 19567;
    callocptr[3] = 9813456;

    // copy the last 12 bytes from callocptr + 2 into callocptr. Since the source and destination overlap, this can cause undefined behavoir.
    callocptr = memcpyTest(callocptr, callocptr + 2, 12, "memcpy overlapping:\n");


    // remember to use free() on all pointers allocated with malloc, calloc or realloc when they are no longer used, or they will persist in memory
    free(callocptr);
    free(dataToWrite);
    free(buffer);
    free(mallocptr);
}

