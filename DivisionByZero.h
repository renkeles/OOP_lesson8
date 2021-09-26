#pragma once

class DivisionByZero
{
private:
    std::string m_message;
public:
    DivisionByZero(std::string message = "") : m_message(message) {}
    const std::string& getMessage() const { return m_message; }
};

namespace my
{

    template <typename T>
    double div(T a, T b)
    {
        if (b == 0)
            throw DivisionByZero("Деление на ноль!");

        return a / b;
    }

}
