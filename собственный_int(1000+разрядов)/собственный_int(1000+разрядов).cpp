#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
const int GG = 1000;

class VERYLONG {
private:
    char chislo[GG];
    int dlina;
//    VERYLONG umn(int) const;
//    VERYLONG umn10() const;
public:
    VERYLONG() {
        chislo[0] = '\0';
        dlina = 0;
    }
    VERYLONG(const char g[GG]) {
        strcpy(chislo, g);
        dlina = strlen(g);
    }
    VERYLONG(const unsigned long n) {
        _ltoa(n, chislo, 10);
        dlina = strlen(chislo);
        _strrev(chislo);
    }
    void vivod() const {
        char t[GG];
        strcpy(t, chislo);
        _strrev(t);
        cout << "\nVASHE CHISLO:";
        cout << t;
    }
    void vvod() {
        char t[GG];
        cout << "VVEDI CHICLO\n";
        cin >> t;
        strcpy(chislo, t);
        _strrev(chislo);
        dlina = strlen(t);
    }
    VERYLONG operator +(const VERYLONG);
//    VERYLONG operator *(const VERYLONG);
//    VERYLONG operator /(const VERYLONG);
//    VERYLONG operator -(const VERYLONG);
};
VERYLONG VERYLONG::operator+(VERYLONG v) {
    char t[GG];
    int maxdlin = (dlina > v.dlina) ? dlina : v.dlina;
    int i, count = 0, s;
    int d1, d2;
    for (i = 0; i < maxdlin; i++) {   
        d1 = (i > dlina - 1) ? 0 : chislo[i] - '0';
        d2 = (i > v.dlina - 1) ? 0 : v.chislo[i] - '0';
        s = d1 + d2 + count;
        if (s >= 10) {
            s -= 10;
            count = 1;
        }
        else
            count = 0;
        t[i] = '0' + s;
    }
    if (count == 1) {
        t[i++] = count;
        t[i] = '\0';
    }
    else
        t[i] = '\0';
    return VERYLONG(t);
}
/*
VERYLONG VERYLONG::operator*(VERYLONG v) {

}
VERYLONG VERYLONG::operator-(VERYLONG v) {

}
VERYLONG VERYLONG::operator/(VERYLONG v) {

}
*/
int main()
{
    VERYLONG PPL, PPG, PPN;
    PPL.vvod();
    PPL.vivod();
    _getch();
    cout << "\n\n------";
    PPG.vvod();
    PPG.vivod();
    cout << "\n\n-------";
    PPN = PPL + PPG;
    PPN.vivod();
    _getch();
}
