#include <iostream>
#include <cstdlib>
#include <ctime>

std::string GenerarCupon(std::string prefijo);
void VerificarCupon (std::string cupon);
void VerificarLetras(std::string letras);

int main()
{
    srand(time(0));
    int cantidad_cupones = 0;
    std::string cupones_generados[10];
    //Solicitar la cantidad de cupones a generar
    std::cout<<"Ingrese la cantidad de cupones a generar: "<<endl;
    std::cin>>cantidad_cupones;
    //almacenar en un arreglo
    for (int i = 0; i < cantidad_cupones; i++){

        cupones_generados[i] = GenerarCupon(SolicitarDatos());
    }
    // Solicitar al usuario las letras del cupon

    // Validar si tiene 3 letras o no length()

    // Llamar a la funcion generar cupon
    std::string cupones_generados = GenerarCupon("AGO");
    std::cout << "El cupon generado es: " << cupon_generado;
    VerificarCupon(cupon_generado);
    return 0;
}

std::string GenerarCupon(std::string prefijo)
{
    // Generar el numero aleatrorio
    int randomNum = rand() % 100 + 999;

    // Convertir entero a string
    std::string conversion = std::to_string(randomNum);

    // Concatenar el prefijo y el numero aleatorio

    return prefijo + conversion;
}

void VerificarCupon (std::string cupon){
    //Extraer la parte numerica del cupon
    std::string num_extraido = cupon.substr(3, 4);

    //Convertir de entero a string
    int num_conversion = std::stoi(num_extraido);

    //Validar si es par o no es par
    if (num_conversion % 2)
    {
        std::cout << "Es numero par";
    } else
    {
        std::cout << "No es par";
    }
    
    
}