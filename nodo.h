#include "cuenta.h"

class Nodo
{
    cuentaBancaria account;
    Nodo *next;
    int posicion;
public:
    Nodo(cuentaBancaria a):account(a), next(NULL), posicion(-1){}
    void imprimeNodo();
    int regresaCta();
    int regresaPeso();
    void imprimeNombre();
    friend class listaCuentas;
};

void Nodo::imprimeNombre()
{
    account.imprimeName();
}

void Nodo::imprimeNodo()
{
    account.imprimeCuenta();
}

int Nodo::regresaPeso()
{
    account.regresaPeso();
}

int Nodo::regresaCta()
{
    account.regresaCta();
}

class listaCuentas
{
    Nodo *head;
    int tamanio;
public:
    listaCuentas():head(NULL), tamanio(0){}
    void insertaInicio(Nodo*);
    void inserta(Nodo*);
    void eliminaUnNodo(int);
    void buscaUnNodo(int);
    void imprimeLista();
    void reasignaPosicion();
    int regresaTamanio();
};

int listaCuentas::regresaTamanio()
{
    return tamanio;
}

void listaCuentas::reasignaPosicion()
{
    Nodo *p; p = head;
    for(int i=1; i<=tamanio; i++)
    {
        p->posicion = i;
        p = p->next;
    }
}

void listaCuentas::insertaInicio(Nodo *nuevo)
{
    if(head)
        nuevo->next = head;
    head = nuevo;
    tamanio++;
    head->posicion = tamanio;
}

void listaCuentas::inserta(Nodo *nuevo)
{
    if(!head)
        insertaInicio(nuevo);
    else
    {
        Nodo *p;
        int flag = 0;
        p = head;
        while(p)
        {
            if(p->regresaPeso()==nuevo->regresaPeso())
                flag =1;
            p=p->next;
        }
        if(flag==1)
            cout<<"\n\nEl usuario que se trata registrar ya existe\n"<<endl;
        else{
        while(p->next)
            p=p->next;
        p->next = nuevo;
        tamanio++;
        nuevo->posicion=tamanio;
        cout<<"\n\tTitular insertado con exito:\n";
        }
    }
}

void listaCuentas::eliminaUnNodo(int num)
{
    if(!head)
    {
        cout<<"No hay cuenta que eliminar aqui chaval\n";
    }
    else
    {
        Nodo *p, *q, *r;
        p=head;
        while(p->next && p->regresaPeso()!=num)
        {
            q = p;
            p = p->next;
        }

        if(p->regresaPeso()!=num)
            cout<<"\tNo se encontro la cuenta a eliminar en la lista\n";

        else
        {
            if(head == p)
                head = p->next;
            else
                q->next = p->next;
            cout<<"\tCuenta bancaria con el Titular ";
            p->imprimeNombre();
            cout<<" eliminada con exito.\n";
            delete(p);
            tamanio--;
        }
    }
}

void listaCuentas::buscaUnNodo(int num)
{
    Nodo *p = head;
    while(p && p->regresaPeso()!=num)
        p=p->next;
    if(!p)
        cout<<"\tNo se encontro una cuenta con el nombre ingresado favor de intentar de nuevo.\n";

    else
    {
        cout<<"\tBusqueda exitosa, enseguida se imprimen los datos.\n\n";
        cout<<"\t\tNUMERO\tNOMBRE\t\tSALDO\tFECHA DE APERTURA\n\n";
        p->imprimeNodo();
    }
}

void listaCuentas::imprimeLista()
{
    Nodo *p = head;
    cout<<"\t\tNUMERO\tNOMBRE\t\t\t\tSALDO\tFECHA DE APERTURA\n\n";
    while(p)
    {
        p->imprimeNodo();
        p=p->next;
    }
}



