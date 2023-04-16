#include <iostream>
#include <stack>
#include <cstring>
#include <cstdlib>

typedef int (*operations)(int, int);

inline int sum(int a, int b) {return a + b;}

inline int subtract(int a, int b) {return a - b;}

inline int multiply(int a, int b) {return a * b;}

inline int divide(int a, int b) {return a / b;}

class RPN
{
    public:
        RPN(char *line);
        ~RPN();

        int computeRPN();
        operations findOp(char c);
        std::string trimmedLine;
        std::stack<int> numStack;
};