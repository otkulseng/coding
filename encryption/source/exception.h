#pragma once
#include <string>

class EncryptException
{
private:
    std::string m_error;
    std::string m_pre;

public:
    EncryptException(std::string error) : m_error{error},
                                          m_pre{"Encryption failed: "}
    {
    }

    std::string getError() const { return m_pre + m_error; }
};