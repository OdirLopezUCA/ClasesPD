#include <iostream>
#include <vector>
#include <string>
#include <ctime>

//Almacenar cancion y cantante
struct Cancion {
    std::string titulo;
    int numero;

    struct Cantante {
        std::string nombre;
        std::string nacionalidad;
    } artista;
};

//Almacenar album
struct Album {
    std::string nombreAlbum;
    int anioLanzamiento;
    int antiguedad;
    std::vector<Cancion> canciones;
};

//Funcion para registrar album y canciones
void registrarAlbum(Album &album) {
    std::cout << "Ingrese el nombre del álbum: ";
    std::cin>>album.nombreAlbum;

    std::cout << "Ingrese el año de lanzamiento: ";
    std::cin >> album.anioLanzamiento;
    std::cin.ignore();

    int cantidadCanciones;
    std::cout << "Ingrese la cantidad de canciones: ";
    std::cin >> cantidadCanciones;
    std::cin.ignore();

    for (int i = 0; i < cantidadCanciones; ++i) {
        Cancion c;
        std::cout << "Título de la canción #" << (i + 1) << ": ";
        std::cin>>c.titulo;
        c.numero = i + 1;

        std::cout << "Nombre del cantante de la canción #" << c.numero << ": ";
        std::cin>>c.artista.nombre;

        std::cout << "Nacionalidad del cantante: ";
        std::cin>>c.artista.nacionalidad;

        album.canciones.push_back(c);
    }

    album.antiguedad = calcularAntiguedad(album.anioLanzamiento);
}


int main() {
    Album miAlbum;
    registrarAlbum(miAlbum);
    return 0;
}