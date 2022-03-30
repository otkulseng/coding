#include <iostream>
#include "exception.h"


int main(int argc, char **argv) {
    try
    {
        if (argc <= 1) throw EncryptException{"Provide file"};

        
    }
    catch(const EncryptException& e)
    {
        std::cerr << e.getError() << '\n';
    }
    

    return 0;
}