// queue::push/pop
#include "Monstruo.h"
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

//Escribe los datos del objeto monstruo (dado) en el archivo binario nombre_archivo (dado) en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, Monstruo*monstruo, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in | ios::binary);
    out.seekp(posicion*55);

    out.write((char*)&monstruo->cabezas,4);
    out.write((char*)&monstruo->brazos,4);
    out.write((char*)&monstruo->piernas,4);
    out.write(monstruo->nombre.c_str(),21);
    out.write(monstruo->apodo.c_str(),21);
    out.write((char*)&monstruo->es_carnivoro,1);

    out.close();




}

//Devuelve un monstruo previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
Monstruo* leer(string nombre_archivo, int posicion)
{
    ifstream in (nombre_archivo.c_str());
    in.seekg(posicion*55);

    int cabezas =0;
    int brazos=0;
    int piernas =0;
    char nombre[21], apodo[21];
    bool es_carnivoro = false;

    in.read((char*)&cabezas,4);
    in.read((char*)&brazos,4);
    in.read((char*)&piernas,4);
    in.read(nombre,21);
    in.read(apodo,21);
    in.read((char*)&es_carnivoro,1);
    in.close();


    return new Monstruo(cabezas,brazos,piernas,nombre,apodo,es_carnivoro);

}

//Devuelve el nombre del monstruo con mas cabezas previamente escrito (con la funcion escribir) en el archivo dado
string getMonstruoConMasCabezas(string nombre_archivo)
{
    list<Monstruo*>guardarMostruos;

    ifstream in(nombre_archivo.c_str());
    in.seekg(0,in.end);
    int tam = in.tellg()/55;
    in.seekg(0,in.beg);

    int cabezas =0;
    char nombre[21];

    for(int i=0; i<tam; i++)
    {
        in.read((char*)&cabezas,4);
        in.read(nombre,21);
        guardarMostruos.push_back(new Monstruo(cabezas,0,0,nombre, "", false));
    }



    for(list<Monstruo*>::iterator it = guardarMostruos.begin(); it!=guardarMostruos.end(); it++)
    {

    }





    return nombre;
}


int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
