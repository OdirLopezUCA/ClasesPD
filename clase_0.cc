#include <iostream>
#include <cmath>
#include <iomanip>

const float pi = 3.1416;

double calcularArea(double radio)
{
    return pi * std::pow(radio, 2);
}

void mostrarArea(double area)
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "El area del circulo es: " << area << std::endl;
}

int main()
{
    double radio;

    std::cout << "Ingrese el radio del circulo: ";
    std::cin >> radio;

    double area = calcularArea(radio);
    mostrarArea(area);

    return 0;
}