#include <iostream>

using namespace std;

int main() {
    int iFibonacci[4] = {0,1};
    int iFibSize = 2;
    int iFront = 0, iRear = 1;
    while (true) {
        int iLast = iFibonacci[iRear];
        int iTmp = iFibonacci[iFront];
        //pop
        iFront = (iFront + 1) % 4;
        iFibSize--;
        iTmp += iFibonacci[iFront];
        //push
        iRear = (iRear + 1) % 4;
        iFibonacci[iRear] = iTmp;
        iFibSize++;
        if (iFibonacci[iRear] > 200) {
            cout << "F(n-1) = " << iLast << ", F(n) = " << iFibonacci[iRear];
            return 0;
        }
    }
}
