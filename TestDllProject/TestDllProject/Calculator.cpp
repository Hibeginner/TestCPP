#include "Calculator.h"

DLLEXPORT int addFunc(int a, int b)
{
    return a + b;
}

DLLEXPORT int testDllStructAdd(INPUT_STRUCT* in, OUTPUT_STRUCT* out)
{
    return in->PlanMode + out->totalstep;
}

int Calculator::classAddFunc(int a, int b)
{
    return a + b;
}
