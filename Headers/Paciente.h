#pragma once


#include <iostream>
#include <string>
using namespace std;

class Paciente {
    private:
        int ID;
        string nombre;
        int edad;
        float temperatura;
        float presion;
        int dolor;
        string tipoDolor;
        bool trauma;
        bool sintomasNeurologicos;
        bool cirugia;
        int diasHospitalizado;
    public:
        Paciente(int ID, string nombre, int edad, float temperatura, float presion, int dolor, string tipoDolor, bool trauma, bool sintomasNeurologicos, bool cirugia, int diasHospitalizado);
        int getID();    
        string getNombre();
        int getEdad();
        float getTemperatura();
        float getPresion();
        int getDolor();
        string getTipoDolor();
        bool getTrauma();
        bool getSintomasNeurologicos();
        bool getCirugia();
        int getDiasHospitalizado();
};