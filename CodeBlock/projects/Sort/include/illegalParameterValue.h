#ifndef ILLEGALPARAMETERVALUE_H
#define ILLEGALPARAMETERVALUE_H

#include <string>
#include <iostream>

class illegalParameterValue
{
public:
    illegalParameterValue():message("Illegal paramter value") {};
    illegalParameterValue(char* theMessage);
    void outputMessage();
private:
    std::string message;
};

#endif // ILLEGALPARAMETERVALUE_H
