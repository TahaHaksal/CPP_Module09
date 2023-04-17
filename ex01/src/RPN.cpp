#include "../include/RPN.hpp"

RPN::RPN(char *line)
{
    trimmedLine = "";
    for (size_t i = 0; i < std::strlen(line); i++)
    {
        if (!std::isdigit(line[i]) &&
            (line[i] != '+') && \
            (line[i] != '/') && \
            (line[i] != '*') && \
            (line[i] != '-') && \
            !std::isspace(line[i]))
        {
            std::cerr << "Error\n";
            exit(1);
        }
        if (std::isspace(line[i]))
            continue ;
        trimmedLine += line[i];
    }

}

RPN::RPN(const RPN& copy)
{
    trimmedLine = copy.trimmedLine;
}

RPN& RPN::operator=(const RPN& copy)
{
    trimmedLine = copy.trimmedLine;
    return *this;
}

int RPN::computeRPN()
{
    for (size_t i = 0; i < trimmedLine.size(); i++)
    {
        if (std::isdigit(trimmedLine[i]))
            numStack.push(trimmedLine[i] - 48);
        else
        {
            int right = numStack.top();
            numStack.pop();
            int left = numStack.top();
            numStack.pop();
            numStack.push(findOp(trimmedLine[i])(left, right));
        }
    }
    return numStack.top();
}

operations RPN::findOp(char c)
{
    switch (c)
    {
        case '+':
            return &sum;
        case '-':
            return &subtract;
        case '*':
            return &multiply;
        case '/':
            return &divide;
        default:
            return NULL;
    }
}

RPN::~RPN()
{

}