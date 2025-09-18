#include <iostream>
#include <string>

///declarar estructura

struct Atelta
{
    std::string nombre;
    float altura;
    float peso;
    float imc;
};

int main ()
{
    //declarar variable local del struct atelta

    struct Atleta atelta;

    //declarar puntero a struct
    struct Atleta *ptr_atelta = &atleta;

    //inicializar puntero a struct
    ptr_atelta->nombre = "Mendez";

    return 0;
}