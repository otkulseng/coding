#pragma once
#ifndef OTP_H
#define OTP_H
#include <iostream>
namespace OTP
{
    char encrypt(char code, char otp);
    char decrypt(char code, char otp);
}
#endif