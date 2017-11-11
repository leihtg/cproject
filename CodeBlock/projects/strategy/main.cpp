#include <iostream>
#include "Buffer.h"
#include "ParseByte.h"
using namespace std;

int main()
{
    char *path="D:\\MyProjects\\workspace\\work\\ndparser\\test\\00423.output";
    path="D:\\MyProjects\\workspace\\work\\ndparser\\test\\000069.SZ.output";
    path="D:\\MyProjects\\workspace\\work\\ndparser\\test\\000069.000423.SZ.output";
    ParseByte p(path);
    p.parse();
    return 0;
}
