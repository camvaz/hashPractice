#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
const int MAX_NAMESIZE = 30;
const int MAX_DATESIZE = 20;

void iniciaArreglo(char* arr, const int& tam)
{
    for(int i = 0; i<tam; i++)
        arr[i] = '?';
}

void printArreglo(char* arr, const int& tam)
{
    for(int i = 0; i<tam; i++)
    {
        if(arr[i]!='?')
            cout<<arr[i];
    }
}

void clear() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

class listaCuentas;

class hashTable;

class Nodo;

class cuentaBancaria{
    int numCta;
    double Saldo;
    char Titular[MAX_NAMESIZE];
    char FechaApertura[MAX_NAMESIZE];
    int peso;

public:
    cuentaBancaria(): numCta(0), Saldo(0), peso(0)
    {
        iniciaArreglo(Titular, MAX_NAMESIZE);
        iniciaArreglo(FechaApertura, MAX_DATESIZE);
    }

    cuentaBancaria(int a, double b, char *c, char *d): numCta(a), Saldo(b)
    {
        for(int i = 0; i<MAX_NAMESIZE; i++)
        {
            Titular[i] = c[i];
        }

        for(int j = 0; j<MAX_DATESIZE; j++)
        {
            FechaApertura[j] = d[j];
        }
    }

    void imprimeName();
    void setPeso(int);
    int regresaPeso();
    int regresaCta();
    void imprimeCuenta();
    void setData(int, double, char*, char*);
};

void cuentaBancaria::imprimeName()
{
    cout<<Titular;
}

int retornaPeso(char* Titular)
{
    int peso = 0;
    for(int i = 0; i<MAX_NAMESIZE; i++)
    {
        if(Titular[i]==32 || (Titular[i]>64 && Titular[i]<91) || (Titular[i]>96 && Titular[i]<123))
            peso+=int(Titular[i]);
    }
    return peso;
}

void cuentaBancaria::setPeso(int a)
{
    peso = a;
}

int cuentaBancaria::regresaPeso()
{
    return peso;
}

int cuentaBancaria::regresaCta()
{
    return numCta;
}

void cuentaBancaria::imprimeCuenta()
{
    cout<<"\t\t"<<numCta<<"\t";
    printArreglo(Titular, MAX_NAMESIZE);
    cout<<" "<<Saldo<<"\t";
    printArreglo(FechaApertura, MAX_DATESIZE);
    cout<<'\n';
}

void cuentaBancaria::setData(int a, double b, char *c, char *d)
{
    numCta = a;
    Saldo = b;

    for(int i = 0; i<MAX_NAMESIZE; i++)
    {
        Titular[i] = c[i];
    }

    for(int j = 0; j<MAX_DATESIZE; j++)
    {
        FechaApertura[j] = d[j];
    }
}
