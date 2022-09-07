#include "Flight.h"
#include "List.h"
#include <cstdlib>

List<Flight>* flights_list = new List<Flight>();

// debe llenar una lista de pCantidad vuelos aleatorios cuya hora y minutos de partida esten entre pStartHour y pEndHour
// tomando en cuenta las restricciones de los minutos de salida segun el ejercicio 3 del caso #3
void fillFlights(int pCantidad, int pStartHour, int pEndHour) {
    string airlines [10]={"Qatar Airways","Singapore Airlines","ANA All Nippon Airways","Emirates","Japan Airlines","Cathay Pacific Airways","EVA Air","Qantas Airways","Hainan Airlines","Air France"};
    srand (time(NULL));
    for(int i=0; i<pCantidad; i++){
        int hour=rand()%(pEndHour-pStartHour)+pStartHour;
        int delay=rand()%17;
        int minute=rand()%(60-delay);
        string airline =airlines[rand()%10];
        int flight_num=rand()%50;
        int passengers=rand()%200+1;

        Flight *nflight = new Flight(hour,minute,airline,flight_num,passengers);
        flights_list->add(nflight);
        cout <<flights_list->find(i)->flightDetails();
    }
}


int main() {
    fillFlights(20,1,2);
}