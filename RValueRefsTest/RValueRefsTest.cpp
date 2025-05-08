
#include <iostream>
#include <string>



// takes a rvalue reference to the string, modifies it and returns the result as a move instead of a copy as we assume the rvalue will not be used after this
std::string setCharacterRValueRef(std::string&& instr, size_t pos, const char character) {
    instr[pos] = character;
    return instr;
}


int main()
{
    // init string variable
    std::string str = "ABCDEFG";
    // retrieve an rvalue reference by calling move() on the string, and catch the return value in the str variable. 
    str = setCharacterRValueRef(move(str), 0, 'M');

    //print out string
    std::cout << str;

}
