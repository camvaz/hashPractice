#include "hashTable.h"
#include <stdlib.h>

int main()
{
    int tamm;
    cout<<"Ingrese el tamanio de la tabla: ";
    cin>>tamm;
    clear();
    cuentaBancaria cuentaAux;
    hashTable Tabla(tamm);

    char opc2;
    cout<<"Insertar datos?(s/n): ";
    cin>>opc2;

    if(opc2=='s')
    {
        char n1[MAX_NAMESIZE] = "Mac Miller";
        char n2[MAX_NAMESIZE] = "Ana de Anda";
        char n3[MAX_NAMESIZE] = "Alejandro Ortega";
        char d1[MAX_DATESIZE] = "07/09/2018";
        char d2[MAX_DATESIZE] = "10/08/2012";
        char d3[MAX_DATESIZE] = "22/11/2015";

        cuentaAux.setData(15112, 25000, "Mac Miller", "07/09/2018");
        cuentaAux.setPeso(retornaPeso(n1));
        Tabla.inserta(cuentaAux);
        cuentaAux.setData(14811, 40000, n2, d1);
        cuentaAux.setPeso(retornaPeso(n2));
        Tabla.inserta(cuentaAux);
        cuentaAux.setData(19112, 35000, n3, d1);
        cuentaAux.setPeso(retornaPeso(n3));
        Tabla.inserta(cuentaAux);
    }

    char nombreAux[MAX_NAMESIZE];
    iniciaArreglo(nombreAux, MAX_NAMESIZE);
    char dateAux[MAX_DATESIZE];
    iniciaArreglo(dateAux, MAX_DATESIZE);
    int numAux;
    char searchAux[MAX_NAMESIZE];
    iniciaArreglo(searchAux, MAX_NAMESIZE);
    double saldoAux;
    int opc;
    bool flag = true;
    char dale;

    clear();

    while(flag)
    {
        //MENU
        cout<<'\t'<<'\t'<<'\t'<<"REGISTRO DE CUENTAS BANCARIAS"<<endl<<endl;
        cout<<'\t'<<"Opciones: "<<endl<<endl;
        cout<<'\t'<<'\t'<<"Registrar nueva cuenta: 1"<<endl;
        cout<<'\t'<<'\t'<<"Buscar cuenta por ID: 2"<<endl;
        cout<<'\t'<<'\t'<<"Eliminar cuenta por ID: 3"<<endl;
        cout<<'\t'<<'\t'<<"Imprimir la tabla completa: 4"<<endl;
        cout<<'\t'<<'\t'<<"Imprimir lista por indice: 5"<<endl;
        cout<<'\t'<<'\t'<<"Salir: 6"<<endl<<endl;
        cout<<'\t'<<"Ingrese una opcion: ";


        cin>>opc;
        clear();
        cout<<endl;

        switch(opc)
        {
            case 1:

                cout<<"Ingrese nombre del Titular a registrar: ";
                cin.ignore();
                cin.getline(nombreAux, MAX_NAMESIZE, '\n');
                cout<<endl;

                cout<<"Ingrese fecha de incorporacion del cliente: ";
                cin.getline(dateAux, MAX_DATESIZE, '\n');
                cout<<endl;

                cout<<"Ingrese Saldo del cliente: ";
                cin>>saldoAux;

                cout<<"Ingrese numero de cuenta del cliente (ID): ";
                cin>>numAux;

                cuentaAux.setData(numAux, saldoAux, nombreAux, dateAux);
                cuentaAux.setPeso(retornaPeso(nombreAux));
                Tabla.inserta(cuentaAux);

                cout<<"Desea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;

                iniciaArreglo(nombreAux, MAX_NAMESIZE);
                iniciaArreglo(dateAux, MAX_DATESIZE);
                clear();
                break;

            case 2:

                cout<<"Inserta el nombre del Titular de cuenta a buscar: ";
                cin.ignore();
                cin.getline(searchAux, MAX_NAMESIZE, '\n');

                Tabla.busca(retornaPeso(searchAux));

                cout<<endl<<"Desea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;
                iniciaArreglo(searchAux, MAX_NAMESIZE);
                clear();
                break;

            case 3:

                cout<<"Inserta el nombre del Titular de cuenta a eliminar: ";
                cin.ignore();
                cin.getline(searchAux, MAX_NAMESIZE, '\n');

                Tabla.elimina(retornaPeso(searchAux));

                cout<<"Desea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;
                iniciaArreglo(searchAux, MAX_NAMESIZE);

                clear();
                break;

            case 4:

                Tabla.imprimeTabla();

                cout<<"Desea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;

                clear();
                break;

            case 5:

                cout<<"Inserta el indice a imprimir: ";
                cin>>numAux;

                Tabla.imprimePorIndex(numAux);
                cout<<endl;

                cout<<"Desea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;

                clear();
                break;

            case 6:

                cout<<"Seguro que desea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;

                clear();
                break;

            default:

                cout<<"Opcion invalida, intentar de nuevo"<<endl;

                cout<<"Desea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;

                clear();
                break;
        }
    }

    return 0;
}
