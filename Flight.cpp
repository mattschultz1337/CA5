#include "Flight.h"

using namespace std;

Flight::Flight(){
  deploc = "";
  destloc = "";
  departure = *(new Date(0,0));
  arrival = *(new Date(0,1));
  price = 0;
}
Flight::Flight(string dp, string dt, Date dep, Date arr, int p){
  deploc = dp;
  destloc = dt;
  departure = dep;
  arrival = arr;
  price = p;
}
string Flight::getDepartureLocation(){
  return deploc;
}
string Flight::getDestination(){
  return destloc;
}
Date Flight::getDeparture(){
  return departure;
}
Date Flight::getArrival(){
  return arrival;
}
int Flight::getPrice(){
  return price;
}
ostream & operator << (ostream & os, Flight & flight_t) {
  os<<flight_t.getDepartureLocation();
  os<<" ";
  os<<flight_t.getDestination();
  os<<" ";
  os<<flight_t.getDeparture();
  os<<" ";
  os<<flight_t.getArrival();
  os<<" $";
  os<<flight_t.getPrice();
  os<<"\n";
  return os;
}
