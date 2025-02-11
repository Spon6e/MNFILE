#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
const int GG = 1000;

enum znak { pos, neg };

bool provZn(const char g[GG]) {
    int d = strlen(g);
    if (g[d - 1] == '-')
        return true;
    else
        return false;
}

class VERYLONG {
private:
    char chislo[GG];
    int dlina;
    znak zn;
    VERYLONG umn(int) const;
    VERYLONG umn10(const VERYLONG) const;
public:
    VERYLONG() {
        chislo[0] = '\0';
        dlina = 0;
        zn = pos;
    }
    VERYLONG(const char g[GG]) {
        strcpy(chislo, g);
        dlina = strlen(g);
        if (provZn(chislo)) {
            zn = neg;
            chislo[dlina - 1] = '\0';
            dlina -= 1;
        }
        else
            zn = pos;
    }
    VERYLONG(const long n) {
        _ltoa(n, chislo, 10);
        dlina = strlen(chislo);
        _strrev(chislo);
        if (provZn(chislo)) {
            zn = neg;
            chislo[dlina - 1] = '\0';
            dlina -= 1;
        }
        else
            zn = pos;
    }
    void vivod() const {
        char t[GG];
        strcpy(t, chislo);
        if (zn == neg) {
            t[dlina] = '-';
            t[dlina + 1] = '\0';
        }
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
        if (provZn(chislo)) {
            zn = neg;
            chislo[dlina - 1] = '\0';
            dlina -= 1;
        }
        else
            zn = pos;
    }
    bool operator >=(const VERYLONG g) {
        if (dlina > g.dlina)
            return true;
        else
            if (dlina < g.dlina)
                return false;
        for (int i = dlina - 1; i >= 0; i--) {
            if (chislo[i] - g.chislo[i] > 0)
                return true;
            else
                if (chislo[i] - g.chislo[i] < 0)
                    return false;
        }
        return true;
    }
    VERYLONG operator +(const VERYLONG);
    VERYLONG operator *(const VERYLONG);
    VERYLONG operator /(const VERYLONG);
    VERYLONG operator -(const VERYLONG);
};
VERYLONG VERYLONG::operator+(VERYLONG v) {
    if (zn == v.zn) {
        char t[GG];
        int maxdlin = (dlina > v.dlina) ? dlina : v.dlina;
        int i, count = 0;
        for (i = 0; i < maxdlin; i++) {
            int d1 = (i > dlina - 1) ? 0 : chislo[i] - '0';
            int d2 = (i > v.dlina - 1) ? 0 : v.chislo[i] - '0';
            int s = d1 + d2 + count;
            if (s >= 10) {
                s -= 10;
                count = 1;
            }
            else
                count = 0;
            t[i] = '0' + s;
        }
        if (count == 1) {
            t[i++] = '1';
            t[i] = '\0';
        }
        else
            t[i] = '\0';
        if (zn == neg) {
            t[i] = '-';
            t[i + 1] = '\0';
        }
        return VERYLONG(t);
    }
    else {
        if (v.zn == neg) {
            char t[GG];
            strcpy(t, v.chislo);
            VERYLONG T(t), K;
            K = *this - T;
            return (K);
        }
        else {
            char t[GG];
            strcpy(t, chislo);
            VERYLONG T(t), K;
            K = v - T;
            return (K);
        }
    }
}

VERYLONG VERYLONG::operator*(VERYLONG v) {
    VERYLONG PGL;
    VERYLONG OBCH;
    for (int i = 0; i < v.dlina; i++) {
        int k = v.chislo[i] - '0';
        PGL = umn(k);
        for (int j = 0; j < i; j++)
            PGL = umn10(PGL);
        OBCH = OBCH + PGL;
    }
    if (zn == v.zn) {
        OBCH.zn = pos;
    }
    else
        OBCH.zn = neg;
    return OBCH;
}

VERYLONG VERYLONG::umn(int k) const {
    char t[GG];
    int count = 0;
    int i;
    for (i = 0; i < dlina; i++) {
        int c = chislo[i] - '0';
        int umnozh = c * k;
        umnozh += count;
        if (umnozh >= 10) {
            count = umnozh / 10;
            umnozh -= count * 10;
        }
        else {
            count = 0;
        } 
        t[i] = '0' + umnozh;
    }
    if (count!=0)
        t[i++] ='0' + count;
    t[i] = '\0';
    return VERYLONG(t);
}

VERYLONG VERYLONG::umn10(const VERYLONG v) const {
    char t[GG];
    for (int i = v.dlina-1; i >= 0; i--) {
        t[i + 1] = v.chislo[i];
    }
    t[0] = '0';
    t[v.dlina + 1] = '\0';
    return VERYLONG(t);
}

VERYLONG VERYLONG::operator-(VERYLONG v) {
    if (zn != v.zn) {
        char t[GG];
        strcpy(t, v.chislo);
        if (zn == neg) {
            t[v.dlina] = '-';
            t[v.dlina + 1] = '\0';
        }
        VERYLONG S, T(t);
        S = *this + T;
        return S;
    }
    else {
        int k;
        if (dlina > v.dlina)
            k = 1;
        else
            if (v.dlina > dlina)
                k = 2;
            else
                k = 0;
        while (true) {
            char t[GG];
            int count = 0;
            int i;
            int g = 0;
            VERYLONG L('0');
            switch (k) {
            case 0:
                for (int i = dlina - 1; i >= 0; i--) {
                    int a = chislo[i] - v.chislo[i];
                    if (a > 0) {
                        k = 1;
                        break;
                    }
                    else 
                        if (a < 0) {
                            k = 2;
                            break;
                        }
                }
                if (k == 0) {
                    return(L);
                }
                break;
            case 1:
                for (i = 0; i < dlina; i++) {
                    int d = chislo[i] - '0';
                    int dv = 0;
                    if (v.dlina > i)
                        dv = v.chislo[i] - '0';
                    if (d - count < dv) {
                        t[i] = '0' + (d + 10 - dv - count);
                        count = 1;
                    }
                    else {
                        t[i] = '0' + (d - dv - count);
                        count = 0;
                    }
                }
                while (g == 0) {
                    if (t[i - 1] == '0') {
                        t[--i] = '\0';
                    }
                    else {
                        t[i] = '\0';
                        g = 1;
                    }
                }
                return VERYLONG(t);
                break;
            case 2:
                for (i = 0; i < v.dlina; i++) {
                    int d = v.chislo[i] - '0';
                    int dv = 0;
                    if (dlina > i)
                        dv = chislo[i] - '0';
                    if (d - count < dv) {
                        t[i] = '0' + (d + 10 - dv - count);
                        count = 1;
                    }
                    else {
                        t[i] = '0' + (d - dv - count);
                        count = 0;
                    }
                }
                while (g == 0) {
                    if (t[i - 1] == '0') {
                        t[--i] = '\0';
                    }
                    else {
                        t[i] = '-';
                        t[i + 1] = '\0';
                        g = 1;
                    }
                }
                
                return VERYLONG(t);
                break;
            }
        }
        
    }
    
}
VERYLONG VERYLONG::operator/(VERYLONG v) {
    if (*this >= v) {

    }
    else
        return VERYLONG('0');
}

int main()
{
    /*VERYLONG PPL, PPG, PPN;
    PPL.vvod();
    PPL.vivod();
    _getch();
    cout << "\n\n------";
    PPG.vvod();
    PPG.vivod();
    cout << "\n\n-------";
    PPN = PPL * PPG;
    PPN.vivod();*/
    
/*    VERYLONG F = 1;
    F.vivod();
    for (long int i = 100; i > 0; i--) {
        F = F * i;
    }
    F.vivod();
    VERYLONG O, G;
    O.vvod();
    G.vvod();
    F = O - G;
    F.vivod();*/

    //VERYLONG J, J1, JS;
    //J.vvod();
    //J1.vvod();
    //JS = J * 56238;
    //JS.vivod();
    VERYLONG HT(3), GP(987), MM;
    MM = HT - GP;
    MM.vivod();
    _getch();
}
