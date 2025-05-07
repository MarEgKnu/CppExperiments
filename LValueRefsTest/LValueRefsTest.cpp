
#include <iostream>
#include <string>

// takes a lvalue reference to the string, a position and a character to modify it with, and modifies it.
void setCharacterLValueRef(std::string& instr, size_t pos, const char character) {
    instr[pos] = character;
}

// takes a const lval reference to the string, and a position of the char to return. Because it is const the caller knows that the refered object cannot be changed
char getCharacterLValueConstRef(const std::string& instr, size_t pos) {
    return instr.at(pos); // uses "Normal" dot syntax instead of the pointer "arrow" syntax
}

// takes a rvalue reference to the string, modifies it and returns the result as a move instead of a copy
//std::string setCharacterRValueRef(std::string&& instr, size_t pos, const char character) {
//    instr[pos] = character;
//    return instr;
//}


int main()
{
    // init string variable
    std::string str = "ABCDEFG";
    // pass the string by reference, and modify it.
    setCharacterLValueRef(str, 0, 'M'); // the string var "str" is implicitly passed as a reference
    // print out the modified string
    std::cout << str << "\n";

    std::cout << getCharacterLValueConstRef(str, 0); // the string var "str" is implicitly passed as a const reference. Print out the returned char

    // initialize reference manually
    std::string& strref1 { str };

    // cannot initialize it with an rvalue such as this
    //std::string& strref{ "abc"};

    // you cannot have a reference to a reference, or pointer to a reference. In this case the reference strref2 is initialized to the strref1 value, and the pointer points to strref1's value
    std::string& strref2 = strref1;
    std::string* strptr = &strref1;

    /*setCharacterRValueRef(str, 0, 'M');
    std::cout << str;*/

}
