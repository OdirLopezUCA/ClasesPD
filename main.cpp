//Un sistema que permita gestionar informacion de relacionada con albumenes musicales
//Para cada album se debe utilizar una estructura que contenga:
//Nombre del album
//Ano de lanzamiento

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <ctime>

struct Album
{
    std::string nombre_album;
    int ano_lanzamiento;
    std::vector<std::pair<int, std::string>> canciones;

};

struct Artista
{
    std::string nombre_artista;
    std::string nacionalidad;

};

void SolicitarDatosArtista(Artista &artista){

    std::cout << "Ingrese el nombre del artista: ";
    std::cin >> artista.nombre_artista;
    std::cout << "Ingrese la nacionalidad del artista: ";
    std::cin >> artista.nacionalidad;
}

void SolicitarDatosAlbum(Album &album){

    std::cout << "Ingrese el nombre del album: ";
    std::cin >> album.nombre_album;
    std::cout << "Ingrese el anio de lanzamiento del album: ";
    std::cin >> album.ano_lanzamiento;
    int cantidad_canciones;
    std::cout << "Ingrese la cantidad de canciones del album: ";
    std::cin >> cantidad_canciones;
    for (int i = 0; i < cantidad_canciones; i++) {
        std::string nombre_cancion;
        std::cout << "Ingrese el nombre de la cancion " << (i + 1) << ": ";
        std::cin >> nombre_cancion;
        album.canciones.push_back(std::make_pair(i + 1, nombre_cancion));
    }
}

void ImprimirInformacionAlbum(const Album &album, const Artista &Artista){

    //Anio actual
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    int anio_actual = now->tm_year + 1900;

    //Imprimir datos album
    std::cout << "Nombre del album: " << album.nombre_album << std::endl;
    std::cout << "Anio de lanzamiento: " << album.ano_lanzamiento << std::endl;
    std::cout << "Edad del album: " << (anio_actual - album.ano_lanzamiento) << " anios" << std::endl;
    std::cout << "canciones: " << std::endl;

    for (const auto &cancion : album.canciones) {
        std::cout << "  " << cancion.first << ". " << cancion.second << std::endl;
    }

    //Imprimir datos artista
    std::cout << "Nombre del artista: " << Artista.nombre_artista << std::endl;
    std::cout << "Nacionalidad del artista: " << Artista.nacionalidad << std::endl;

}


int main ()
{
    Artista artista;
    SolicitarDatosArtista(artista);

    Album album;
    SolicitarDatosAlbum(album);

    ImprimirInformacionAlbum(album, artista);

    return 0;
}