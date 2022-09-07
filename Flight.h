#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Quiz #6
// 1. Utilizando esta classe agregue los atributos del vuelo: aerolinea, numero de vuelo, cantidad de pasajeros
// 2. Complete el constructor de la clase, de tal forma que se pueda modificar el flightTime para una hora y minutos específicos
// 3. Implementar alguna forma de convertir el time a un número entero de tal forma que entre menor la hora menor el número, eso en getIntTimeValue()
// 4. En el test.cpp, implementar la función fillFlights()
// fecha de entrega: jueves 8 de setiembre antes de las 10pm
// entrega al asistente al correo: kevinqj.2002@gmail.com
// subject: estructuras de datos - quiz #6
// adjuntan el archivo test.cpp y Flight.h

class Flight {

private:
    tm * flightTime;
    string airline;
    int flight_num;
    int passengers;

public:
    Flight(int pHour, int pMinutes, string pAirline, int pFlight_num, int pPassengers) {
        time_t now = time(0);
        flightTime= localtime(&now);
        flightTime->tm_hour=pHour;
        flightTime->tm_min=pMinutes;
        flightTime->tm_sec=0;

        airline=pAirline;
        flight_num=pFlight_num;
        passengers=pPassengers;
    }
    string flightDetails(){
        string f_num = to_string(flight_num);
        string num_pass = to_string(passengers);
        string details = "Airline: "+airline+"\nFlight Number: "+f_num+"\nPassengers: "+num_pass+"\nFlight Date: "+flightTimeString()+"\n";
        return details;
    }
    char* flightTimeString() {
        char* result = asctime(flightTime);
        return result;
    }

    int getIntTimeValue() {
        int result = flightTime->tm_hour*100+flightTime->tm_min;
        return result;
    }
};
