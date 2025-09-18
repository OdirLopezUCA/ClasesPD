#include <iostream>

int main ()
{
    //declarar arreglo
    int arreglo_num[3] = {2,100,1};

    int *ptr = arreglo_num;
    //probar zizeof
    std::cout << "Peso tipo de dato int: " << sizeof(int)<< std::endl;

    //obtener dir memoria arrelgo
    std::cout << "Dir. memoria areglo_num[0] " << &arreglo_num << " Valor: " << *(arreglo_num) << std::endl;
    std::cout << "Dir. memoria areglo_num[1] " << &arreglo_num << " Valor: " << *(arreglo_num + 1) << std::endl;
    std::cout << "Dir. memoria areglo_num[2] " << ptr + 2 << " Valor: " << *(ptr + 2) << std::endl;
    return 0;

    if (ptr == arreglo_num)
    {
        std::cout << "verdadero " << std::endl;
    }
    else
    {       
         std::cout << "falso" << std::endl;
    }
    return 0;

}