#include "OTP.h"

namespace OTP
{
    char encrypt(char code, char otp)
    {
        if (!(isalpha(code) && isalpha(otp)))
            return ' ';

        code = toupper(code) - 'A';
        otp = toupper(otp) - 'A';

        char next = 'A' + code + otp + 1;
        return next <= 'Z' ? next : next - 'Z' + 'A';
    }

    char decrypt(char code, char otp)
    {
        if (!(isalpha(code) && isalpha(otp)))
            return ' ';
        code = toupper(code);
        otp = toupper(otp) - 'A' + 1;
        code -= otp;

        return 'A' <= code ? code : code + 'Z' - 'A';
    }
}