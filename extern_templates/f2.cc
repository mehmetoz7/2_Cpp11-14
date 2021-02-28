#include "miniCalculator.h"

using namespace std;

/*
-----------------------------------------
nm -g -C --defined-only *.o

f1.o:
0000000000000000 T f1(int, int)
0000000000000000 W miniCalculator<int>::div(int, int)

f2.o:
0000000000000000 T f2(int, int)
-----------------------------------------
0000000000000000 W miniCalculator<int>::div(int, int)
will not be in f2.o
this will decrease compile time
template class is not compiled for f2.o
*/
extern template class miniCalculator<int>;

int f2(int y, int x) {
   miniCalculator<int> calc;
   return calc.div(x, y);
}

