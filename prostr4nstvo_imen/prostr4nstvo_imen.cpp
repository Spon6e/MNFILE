#include <iostream>
#include <conio.h>
using namespace std;
typedef int GG; //Если не нравиться название класса можешь его переименовать, для более удобного написания
typedef int* ptrInt; //Даже указатели
namespace { //Если дашь название namespace, то функция не сработает, или надо будет включать namespace в функции
    int ger = 23;
}

void FFN(){
    cout << ger;
}

int main()
{
    GG k = 12;
    FFN();
    cout << endl << k;
    _getch();
}
