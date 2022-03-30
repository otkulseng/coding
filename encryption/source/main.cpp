#include <iostream>
#include <fstream>
#include "exception.h"
#include "OTP.h"



int main(int argc, char **argv)
{
    try
    {
        if (argc <= 1)
            throw EncryptException{"Provide file, format 'encrypt <text.txt> <OTP.txt>'"};

        std::ifstream code_istream{argv[1]};
        if (!code_istream)
            throw EncryptException{std::string{"Couldn't open file "} + argv[1]};

        std::string filename = "encrypted.txt";
        std::ofstream encrypted_ostream{filename};

        std::string otp{argv[2]};

        long unsigned int i = 0;
        for (char c; code_istream >> c; i++)
        {
            if (i == otp.size())
                throw EncryptException{"OTP-key to short for message"};
            if (isalpha(c))
            {
                encrypted_ostream << OTP::encrypt(c, otp[i]);
            }
        }
    }
    catch (const EncryptException &e)
    {
        std::cerr << e.getError() << '\n';
    }

    return 0;
}