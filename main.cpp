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
//funcion imprimir album
void mostrarAlbum(const Album &album) {
    std::cout << "\n--- Información del Álbum ---\n";
    std::cout << "Nombre del álbum: " << album.nombreAlbum << "\n";
    std::cout << "Año de lanzamiento: " << album.anioLanzamiento << "\n";
    std::cout << "Antigüedad: " << album.antiguedad << " años\n";

    std::cout << "\n--- Canciones ---\n";
    for (const Cancion& c : album.canciones) {
        std::cout << "Canción #" << c.numero << ": " << c.titulo << "\n";
        std::cout << "  Cantante: " << c.artista.nombre << "\n";
        std::cout << "  Nacionalidad: " << c.artista.nacionalidad << "\n";
    }
}

// calcular la antigüedad del álbum
int calcularAntiguedad(int anioLanzamiento) {
    std::time_t t = std::time(nullptr);
    std::tm* tiempoActual = std::localtime(&t);
    int anioActual = tiempoActual->tm_year + 1900;
    return anioActual - anioLanzamiento;
}

int main() {
    Album miAlbum;
    registrarAlbum(miAlbum);
    mostrarAlbum(miAlbum);
    return 0;
}