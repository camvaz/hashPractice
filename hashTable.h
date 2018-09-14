#include "nodo.h"

class hashTable{
    int capacidad;
    listaCuentas *listado;
public:
    hashTable(int tam):listado(new listaCuentas[tam]), capacidad(tam){}
    void inserta(cuentaBancaria&);
    void busca(int);
    void elimina(int);
    void imprimeTabla();
    void imprimePorIndex(int);
};

void hashTable::inserta(cuentaBancaria& a)
{
    int Ind;
    Nodo *nuevo = new Nodo(a);

    Ind = nuevo->regresaPeso()%capacidad;

    listado[Ind].inserta(nuevo);
}

void hashTable::busca(int dato)
{
    int Ind = dato%capacidad;
    listado[Ind].buscaUnNodo(dato);
}

void hashTable::elimina(int dato)
{
    int Ind = dato%capacidad;
    listado[Ind].eliminaUnNodo(dato);
}

void hashTable::imprimeTabla()
{
    for(int i = 0; i<capacidad; i++)
    {
        if(listado[i].regresaTamanio()!=0){
        cout<<"\t\t\tIMPRIMIENDO LISTA NUMERO "<< i +1 <<"\n\n";
        listado[i].imprimeLista();
        cout<<endl;
        }
    }
}

void hashTable::imprimePorIndex(int dato)
{
    cout<<"Imprimiendo lista numero: "<<dato<<"\n\n";
    int Ind = dato-1;

    listado[Ind].imprimeLista();
}
