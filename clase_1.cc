#include <iostream>
#include <vector>
#include <string>
#include <ctime>

// Estructura para datos del cantante
struct Cantante {
    std::string nombre;
    std::string nacionalidad;
};

// Estructura para cada canción
struct Cancion {
    std::string titulo;
    int numero;
};

// Estructura principal del álbum
struct Album {
    std::string nombreAlbum;
    int anioLanzamiento;
    int antiguedad;
    Cantante artista;
    std::vector<Cancion> canciones;
};

// 🧮 Función para calcular la antigüedad del álbum
int calcularAntiguedad(int anioLanzamiento) {
    std::time_t t = std::time(nullptr);
    std::tm* tiempoActual = std::localtime(&t);
    int anioActual = tiempoActual->tm_year + 1900;
    return anioActual - anioLanzamiento;
}

// 📥 Función para registrar la información del álbum y del cantante
void registrarAlbum(Album &album) {
    std::cout << "Ingrese el nombre del álbum: ";
    std::getline(std::cin, album.nombreAlbum);

    std::cout << "Ingrese el año de lanzamiento: ";
    std::cin >> album.anioLanzamiento;
    std::cin.ignore();

    std::cout << "Ingrese el nombre del cantante: ";
    std::getline(std::cin, album.artista.nombre);

    std::cout << "Ingrese la nacionalidad del cantante: ";
    std::getline(std::cin, album.artista.nacionalidad);

    int cantidadCanciones;
    std::cout << "Ingrese la cantidad de canciones: ";
    std::cin >> cantidadCanciones;
    std::cin.ignore();

    for (int i = 0; i < cantidadCanciones; ++i) {
        Cancion c;
        std::cout << "Título de la canción #" << (i + 1) << ": ";
        std::getline(std::cin, c.titulo);
        c.numero = i + 1;
        album.canciones.push_back(c);
    }

    album.antiguedad = calcularAntiguedad(album.anioLanzamiento);
}


int main() {
    Album miAlbum;
    registrarAlbum(miAlbum);
    mostrarAlbum(miAlbum);
    return 0;
}