#include "Person.h"


int main()
{
    std::cout << "Start of program\n";
    
    try {
        // negative number, will not clean up
        Person p = Person(5, -1);
        
    }
    catch (std::exception) {
        std::cout << "Exception caught, but acquired resources has not been cleared" << std::endl;
    }
    try {
        // negative number, will clean up
        Person s = Person(5, -1, false);
    }
    catch (std::exception) {
        std::cout << "Exception caught, acquired resources has been cleared" << std::endl;
    }
    
    

    std::cout << "End of program\n";
}
