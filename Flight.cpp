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
Flight::Flight(string listing){
  string dp = listing.substr(0,listing.find(" "));
  listing = listing.substr(listing.find(" ")+1);
  string dt = listing.substr(0,listing.find(" "));
  listing = listing.substr(listing.find(" ")+1);

  Date dep = *(new Date(stoi(listing.substr(0,listing.find(":"))),stoi(listing.substr(listing.find(":")+1,listing.find(":")+3))));
  listing = listing.substr(4);
  if(listing.substr(0,1)=="p"){
    dep.setDate(dep.getHour()+12,dep.getMinute());
  }
  listing = listing.substr(listing.find(" ")+1);
  Date arr = *(new Date(stoi(listing.substr(0,listing.find(":"))),stoi(listing.substr(listing.find(":")+1,listing.find(":")+3))));
  listing = listing.substr(4);
  if(listing.substr(0,1)=="p"){
    arr.setDate(arr.getHour()+12,arr.getMinute());
  }
  listing = listing.substr(listing.find(" ")+1);
  int p = stoi(listing.substr(listing.find("$")+1));

  deploc = dp;
  destloc = dt;
  departure = dep;
  arrival = arr;
  price = p;
}
ostream & operator << (ostream & os, Flight & flight_t) {
  os<<flight_t.getDepartureLocation();
  os<<" ";
  os<<flight_t.getDestination();
  os<<" ";
  flight_t.getDeparture().print();
  os<<" ";
  flight_t.getArrival().print();
  os<<" $";
  os<<flight_t.getPrice();
  os<<"\n";
  return os;
}
