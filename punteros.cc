#include <iostream>

void PasoPorValor (int taza);
void PasoPorPuntero ( int * taza);
void PasoPorReferencia ( int &incognita);

int main () {

    /* int num = 500;
    int *ptr = &num ;
    *ptr = 800 ;
    num = 1000;
    std::cout<<"Dir memeoria: "<< ptr << " - "<< &num << "\n";
    std::cout<<"Dir memoria ptr: " << &ptr << "\n";
    std::cout<<"Valor de num: "<< *ptr << "\n";
 */

 int taza = 0;
 std::cout<< "Contenido de la taza " << taza << "\n";
 PasoPorValor(taza);//100
 std::cout<<"Contenido de la taza " << taza <<"\n";
 PasoPorPuntero(&taza);//100
 std::cout<<"Contenido de la taza " << taza << "\n";//100
 PasoPorReferencia(taza);//200
 std::cout <<"Contenido taza " << taza << "\n" ;//200
 PasoPorReferencia(taza);//300
 std::cout <<"Contenido taza " << taza << "\n" ;//200



    return 0;
} 
void PasoPorValor ( int taza){
   taza = taza + 100;
   std::cout <<"Contenido taza " << taza << "\n" ;
}
void PasoPorPuntero(int *taza){
    *taza = *taza + 100;
   std::cout <<"Contenido taza " << *taza << "\n" ;

}