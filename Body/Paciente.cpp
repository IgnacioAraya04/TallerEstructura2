#include "Paciente.h"

Paciente::Paciente(int ID, string nombre, int edad, float temperatura, float presion, int dolor, string tipoDolor, bool trauma, bool sintomasNeurologicos, bool cirugia, int diasHospitalizado) {
    this->ID = ID;
    this->nombre = nombre;
    this->edad = edad;
    this->temperatura = temperatura;
    this->presion = presion;
    this->dolor = dolor;
    this->tipoDolor = tipoDolor;
    this->trauma = trauma;
    this->sintomasNeurologicos = sintomasNeurologicos;
    this->cirugia = cirugia;
    this->diasHospitalizado = diasHospitalizado;
}

int Paciente::getID() {
    return ID;
}

string Paciente::getNombre() {
    return nombre;
}

int Paciente::getEdad() {
    return edad;
}

float Paciente::getTemperatura() {
    return temperatura;
}

float Paciente::getPresion() {
    return presion;
}

int Paciente::getDolor() {
    return dolor;
}

string Paciente::getTipoDolor() {
    return tipoDolor;
}

bool Paciente::getTrauma() {
    return trauma;
}

bool Paciente::getSintomasNeurologicos() {
    return sintomasNeurologicos;
}

bool Paciente::getCirugia() {
    return cirugia;
}

int Paciente::getDiasHospitalizado() {
    return diasHospitalizado;
}