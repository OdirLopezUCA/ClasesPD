#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector> 

// Declaración de las funciones
std::string solicitarDatos();
std::string GenerarCupon(std::string prefijo);
void VerificarCupon(std::string cupon);


int main()
{
    srand(time(0));

    int cantidad_cupones = 0;

    // Solicitar la cantidad de cupones a generar
    std::cout << "Ingrese la cantidad de cupones a generar: ";
    std::cin >> cantidad_cupones;

    // Se declara el vector después de obtener la cantidad para darle el tamaño correcto.
    std::vector<std::string> cupones_generados(cantidad_cupones);

    // Almacear en un vector
    for (int i = 0; i < cantidad_cupones; i++)
    {
        // Llamar a la funcion generar cupon y solicitar datos
        cupones_generados[i] = GenerarCupon(solicitarDatos());
    }

    // Mostrar los cupones generados y verificar cada uno
    for (int i = 0; i < cantidad_cupones; i++)
    {
        std::cout << "El cupon generado es: " << cupones_generados[i] << std::endl;
        VerificarCupon(cupones_generados[i]);
    }

    return 0;
}

// Definicion de la funcion solicitarDatos
std::string solicitarDatos()
{
    std::string prefijo;
    do
    {
        std::cout << "Ingrese las 3 letras del cupon: ";
        std::cin >> prefijo;

        if (prefijo.length() != 3)
        {
            std::cout << "Error, deben ser 3 letras." << std::endl;
        }
    } while (prefijo.length() != 3);

    return prefijo;
}

// Definicion de la funcion GenerarCupon
std::string GenerarCupon(std::string prefijo)
{
    // Generar el aleatorio de 3 dígitos (100 a 999)
    int num_aleatorio = 100 + rand() % 900; 

    // Convertir entero a string
    std::string conversion = std::to_string(num_aleatorio);

    // Concatenar el prefijo con el aleatorio
    return prefijo + conversion;
}

// Definicion de la funcion VerificarCupon
void VerificarCupon(std::string cupon)
{
    // Extraer parte numerica del cupon, los 3 dígitos finales
    std::string num_extraido = cupon.substr(3, 3);

    // Convertir de string a entero
    int num_cupon = std::stoi(num_extraido);

    // Validar si es par o no es par
    if (num_cupon % 2 == 0)
    {
        std::cout << "Tiene premio." << std::endl;
    }
    else
    {
        std::cout << "No tiene premio." << std::endl;
    }
}