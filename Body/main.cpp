#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Node.h"
#include "Queue.h"
#include "AVLNode.h"
#include "AVLTree.h"

using namespace std;

Queue* pacienteQueue = new Queue();

AVLTree pediatria = AVLTree();
AVLTree neurologia = AVLTree();
AVLTree traumatologia = AVLTree();
AVLTree cardiologia = AVLTree();
AVLTree cirugia = AVLTree();
AVLTree urgencias = AVLTree();
AVLTree medicinaGeneral = AVLTree();
AVLTree hospitalizacion = AVLTree();

const string serviciosDisponibles[] = {"Urgencias", "Medicina General", "Cardiologia", "Neurologia", "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"};

void cargarPacientes() {
    string texto;
    ifstream archivo("pacientes.txt");
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    while (getline(archivo,texto)) {
        try
        {
            stringstream ss(texto);
            int ID, edad, dolor, diasHospitalizado;
            float temperatura, presion;
            bool trauma, sintomasNeurologicos, cirugia;
            string IDstring, edadString, dolorString, diasString, temperaturaString, presionString, traumaString, neuroString, cirugiaString, nombre, tipoDolor;
        
            getline(ss, IDstring, ';');
            getline(ss, nombre, ';');
            getline(ss, edadString, ';');
            getline(ss, temperaturaString, ';');
            getline(ss, presionString, ';');
            getline(ss, dolorString, ';');
            getline(ss, tipoDolor, ';');
            getline(ss, traumaString, ';');
            getline(ss, neuroString, ';');
            getline(ss, cirugiaString, ';');
            getline(ss, diasString, ';');

            ID = stoi(IDstring);
            edad = stoi(edadString);
            dolor = stoi(dolorString);
            diasHospitalizado = stoi(diasString);
            temperatura = stof(temperaturaString);
            presion = stof(presionString);
            trauma = (traumaString == "true");
            sintomasNeurologicos = (neuroString == "true");
            cirugia = (cirugiaString == "true");   

            bool pacienteRepetido = false;
            Node* cursor = pacienteQueue -> front();
            while (cursor != nullptr) {
                Paciente *pacienteExistente = cursor -> getPaciente();
                if (pacienteExistente -> getID() == ID) {
                    cout << "El paciente con ID " << ID << " ya existe, se omitira" << endl;
                    pacienteRepetido = true;
                    break;
                }
                cursor = cursor -> getNext();
            }
            if (!pacienteRepetido) {
                Paciente* paciente = new Paciente(ID, nombre, edad, temperatura, presion, dolor, tipoDolor, trauma, sintomasNeurologicos, cirugia, diasHospitalizado);
                Node* nuevoNode = new Node(paciente);
                pacienteQueue -> push(nuevoNode);
            }

        }

        catch(const std::exception& e)
        {
            cout << "Existe un problema con el archivo" << endl;
        }
        
    }

}

void agregarPacienteAArbol(AVLTree& arbol, Node* paciente) {
    Paciente* copia = new Paciente(
        paciente->getPaciente()->getID(),
        paciente->getPaciente()->getNombre(),
        paciente->getPaciente()->getEdad(),
        paciente->getPaciente()->getTemperatura(),
        paciente->getPaciente()->getPresion(),
        paciente->getPaciente()->getDolor(),
        paciente->getPaciente()->getTipoDolor(),
        paciente->getPaciente()->getTrauma(),
        paciente->getPaciente()->getSintomasNeurologicos(),
        paciente->getPaciente()->getCirugia(),
        paciente->getPaciente()->getDiasHospitalizado()
    );
    arbol.insert(new Node(copia));
}

void arbolDecisiones(Node* paciente) {
    cout << "Ruta" ;
    if(paciente->getPaciente()->getEdad() <= 14){
        cout << "Edad < = 14" << endl;
        cout << "" <<endl;
        cout << "Servicio asignado: Pediatria" << endl;
        agregarPacienteAArbol(pediatria, paciente);
        return;
    } else {
        cout << "Edad > 14" ;
        if (paciente->getPaciente()->getSintomasNeurologicos()) {
            cout << "-> Sintomas neurologicos == 1" << endl;
            cout << "" <<endl;
            cout << "Servicio asignado: Neurologia" << endl;
            agregarPacienteAArbol(neurologia, paciente);
            return;
        } else {
            cout << "-> Sintomas neurologicos == 0";
            if (paciente->getPaciente()->getTrauma()) {
                cout << "Trauma == 1";
                if (paciente->getPaciente()->getCirugia()) {
                    cout << "-> Cirugia == 1" << endl;
                    cout << "" <<endl;
                    cout << "Servicio asignado: Cirugia" << endl;
                    agregarPacienteAArbol(cirugia, paciente);
                    return;
                } else {
                    cout << "-> Cirugia == 0" << endl;
                    cout << "" <<endl;
                    cout << "Servicio asignado: Traumatologia" << endl;
                    agregarPacienteAArbol(traumatologia, paciente);
                    return;
                }
            } else{
                cout << "-> Trauma == 0";
                if (paciente->getPaciente()->getPresion() >= 180 ){
                    cout << "-> Presion Arterial > 180" << endl;
                    cout << "" <<endl;
                    cout << "Servicio asignado: Cardiologia" << endl;
                    agregarPacienteAArbol(cardiologia, paciente);
                    return;
                } else {
                    cout<< "-> Presion Arterial < 180";
                    if (paciente->getPaciente()->getDolor() >=7 || paciente->getPaciente()->getTemperatura() >= 40.0) {
                        cout << "-> Dolor >= 7 o Temperatura >= 40.0" << endl;
                        cout << "" <<endl;
                        cout << "Servicio asignado: Urgencias" << endl;
                        agregarPacienteAArbol(urgencias, paciente);
                        return;
                    } else {
                        cout << "-> Dolor < 7 y Temperatura < 40.0";
                        if (paciente->getPaciente()->getDiasHospitalizado() >= 2) {
                            cout << "-> Dias hospitalizado > 2" << endl;
                            cout << "" <<endl;
                            cout << "Servicio asignado: Hospitalizacion" << endl;
                            agregarPacienteAArbol(hospitalizacion, paciente);
                            return;
                        } else {
                            cout << "-> Dias hospitalizado < 2" << endl;
                            cout << "" <<endl;
                            cout << "Servicio asignado: Medicina General" << endl;
                            agregarPacienteAArbol(medicinaGeneral, paciente);
                            return;
                        }
                    }
                }
            } 
        }
    }
    cout << "No se pudo asignar un servicio al paciente " << endl;
    return;
}

void atenderPaciente() {
    Node* cursor = pacienteQueue -> front();
    if (cursor != nullptr) {
        Paciente* paciente = cursor -> getPaciente();
        cout << "ID: " << paciente -> getID() << endl;
        cout << "Nombre: " << paciente -> getNombre() << endl;
        cout << "Edad: " << paciente -> getEdad() << endl;
        cout << "Temperatura: " << paciente -> getTemperatura() << endl;
        cout << "Presion: " << paciente -> getPresion() << endl;
        cout << "Dolor: " << paciente -> getDolor() << endl;
        cout << "Tipo de dolor: " << paciente -> getTipoDolor() << endl;
        cout << "Trauma: " << (paciente -> getTrauma() ? "Si" : "No") << endl;
        cout << "Sintomas neurologicos: " << (paciente -> getSintomasNeurologicos() ? "Si" : "No") << endl;
        cout << "Cirugia: " << (paciente -> getCirugia() ? "Si" : "No") << endl;
        cout << "Dias hospitalizado: " << paciente -> getDiasHospitalizado() << endl;
       
        arbolDecisiones(cursor);
        pacienteQueue -> pop();
    }

}

void verDepartamentos() {
    cout << "=== Estados de los departamentos ===" << endl;
    cout << "Pediatria: " << endl;
    if (pediatria.isEmpty()) {
        cout << "No hay pacientes en Pediatria" << endl;
    } else {
        pediatria.inOrder(pediatria.getRoot());
    }

    cout << "Neurologia: " << endl;
    if (neurologia.isEmpty()) {
        cout << "No hay pacientes en Neurologia" << endl;
    } else {
        neurologia.inOrder(neurologia.getRoot());
    }

    cout << "Traumatologia: " << endl;
    if (traumatologia.isEmpty()) {
        cout << "No hay pacientes en Traumatologia" << endl;
    } else {
        traumatologia.inOrder(traumatologia.getRoot());
    }

    cout << "Cardiologia: " << endl;
    if (cardiologia.isEmpty()) {
        cout << "No hay pacientes en Cardiologia" << endl;
    } else {
        cardiologia.inOrder(cardiologia.getRoot());
    }

    cout << "Cirugia: " << endl;
    if (cirugia.isEmpty()) {
        cout << "No hay pacientes en Cirugia" << endl;
    } else {
        cirugia.inOrder(cirugia.getRoot());
    }

    cout << "Urgencias: " << endl;
    if (urgencias.isEmpty()) {
        cout << "No hay pacientes en Urgencias" << endl;
    } else {
        urgencias.inOrder(urgencias.getRoot());
    }
    
    cout << "Medicina General: " << endl;
    if (medicinaGeneral.isEmpty()) {
        cout << "No hay pacientes en Medicina General" << endl;
    } else {
        medicinaGeneral.inOrder(medicinaGeneral.getRoot());
    }

    cout << "Hospitalizacion: " << endl;
    if (hospitalizacion.isEmpty()) {
        cout << "No hay pacientes en Hospitalizacion" << endl;
    } else {
        hospitalizacion.inOrder(hospitalizacion.getRoot());
    }

    cout << "" << endl;
}

void buscarPaciente() {
    cout << "Ingrese el ID o el Nombre del paciente: ";
    string busqueda;
    cin >> busqueda;
    
    cout << "Buscando en AVL..." << endl;
    AVLNode* nodoEncontrado = nullptr;
    AVLTree* arboles[] = {&urgencias, &medicinaGeneral, &cardiologia, &neurologia, &traumatologia, &cirugia, &pediatria, &hospitalizacion};
    int contador = 0;
    for (AVLTree* arbol : arboles) {
        nodoEncontrado = arbol->search(stoi(busqueda));
        if (nodoEncontrado != nullptr) {
            cout << "ID: " << nodoEncontrado->getPaciente()->getPaciente()->getID() << endl;
            cout << "Nombre: " << nodoEncontrado->getPaciente()->getPaciente()->getNombre() << endl;
            cout << "Edad: " << nodoEncontrado->getPaciente()->getPaciente()->getEdad() << endl;
            cout << "Departamento: " << serviciosDisponibles[contador] << endl;
            cout << nodoEncontrado->toString() << endl;
        }   
        contador++;
    }

}

int main() {
    cargarPacientes();
    int opcion;
    do {
        cout << "=== HOSPITAL MARMAJA ===" << endl;
        cout << "1. Atender paciente" << endl;
        cout << "2. Ver departamentos" << endl;
        cout << "3. Buscar paciente" << endl;
        cout << "4. Salir" << endl;
        cout << "" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << "" << endl;

        switch (opcion) {
            case 1:
                atenderPaciente();
                break;
            case 2:
                verDepartamentos();
                break;
            case 3:
                buscarPaciente();
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida, intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}