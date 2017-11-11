#include "illegalParameterValue.h"

illegalParameterValue::illegalParameterValue(char* theMessage)
{
    this->message=theMessage;
}

void illegalParameterValue::outputMessage()
{
    std::cout<<this->message<<std::endl;
}
