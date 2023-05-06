#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;


void crearArchivos(int ArchivosDiego) {

    fs::path directorio, carpeta;
    if (ArchivosDiego % 2 == 0) {
        directorio = fs::path("C:/Users/Diego Gonzalez/CLionProjects/PARCIAL2ARCHIVOSGONZALEZ");
        carpeta = directorio / "impar";
    } else {
        directorio = fs::path("C:/Users/Diego Gonzalez/ClionProjects/PARCIAL2ARCHIVOSGONZALEZ");
        carpeta = directorio / "par";
    }


    if (!fs::exists(directorio)) {
        cout << "El directorio " << directorio << " no existe. Creándolo..." << endl;
        if (!fs::create_directory(directorio)) {
            cerr << "el directorio no se a creado :( " << directorio << endl;
            return;
        }
    }
    if (!fs::exists(carpeta)) {
        cout << "La carpeta " << carpeta << " no existe. Creándola espere :D..." << endl;
        if (!fs::create_directory(carpeta)) {
            cerr << "la carpeta no se puedo crear :( " << carpeta << endl;
            return;
        }
    }


    for (int i = 1; i <= ArchivosDiego; i++) {
        fs::path archivo = carpeta / ("file" + to_string(i) + ".txt");
        ofstream ofs(archivo);
        ofs << "Contenido del archivo " << i << endl;
        ofs.close();
        cout << "Archivo " << archivo << " creado exitosamente B)." << endl;
    }
}


int main() {

    int nArchivos;
    cout << "¿ Cuantos Archivos desea crear ? : ";
    cin >> nArchivos;
    if (nArchivos < 1) {
        cerr << "La cantidad que se dara de archivos debe ser positivo." << endl;
        return 0;
    }


    crearArchivos(nArchivos);

    return 0;
}

