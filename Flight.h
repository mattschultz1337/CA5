#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "Date.cpp"
class Flight{
  private:
    std::string deploc;
    std::string destloc;
    Date departure;
    Date arrival;
    int price;
  public:
    Flight();
    Flight(std::string dp, std::string dt, Date dep, Date arr, int p);
    std::string getDepartureLocation();
    std::string getDestination();
    Date getDeparture();
    Date getArrival();
    int getPrice();
    Flight(std::string listing);
    friend std::ostream & operator << (std::ostream & os, Flight & flight_t);
};
#endif
