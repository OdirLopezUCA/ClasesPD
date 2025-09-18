#include <iostream>

    //Con punteros en una funcion
    void punteros(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    //Con referencias en una funcion
    void referencias(int &x, int &y) {
        int temp = x;
        x = y;
        y = temp;
    }
    //Paso por valor en una funcion
    void valor(int x, int y) {
        int temp = x;
        x = y;
        y = temp;
        std::cout << "Dentro de la funcion valor: x = " << x << ", y = " << y << std::endl;
    }
int main ()
{   
    int a, b;
    std::cout << "----------------------Ingrese dos numeros------------------------"<<std::endl;
    std::cout << "Primer valor: "<<std::endl;
    std::cin >> a;
    std::cout << "Segundo valor: "<<std::endl;
    std::cin >> b;
    std::cout << "Antes del intercambio: a = " << a << ", b = " << b << std::endl;

    int a1 = a, b1 = b;
    punteros(&a1, &b1);
    std::cout << "Despues del intercambio con punteros: a = " << a1 << ", b = " << b1 << std::endl;

    int a2 = a, b2 = b;
    referencias(a2, b2);
    std::cout << "Despues del intercambio con referencias: a = " << a2 << ", b = " << b2 <<std::endl;


    return 0;
}