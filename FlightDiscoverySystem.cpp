#include "FlightDiscoverySystem.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
int main(int argc, char* argv[]){
  Flight lineflight;
  string departs;
  string destination;
  Date deptime;
  Date arrtime;
  int cost;
  string line;
  ifstream myfile(argv[1], ios::in);
  if(myfile.is_open())
  {
    getline(myfile,line);
    lineflight = flightIndex(line);
    myfile.close();
  } else cout << "Unable to open file";
  cout<<lineflight;
  return 0;
}

Flight FlightDiscoverySystem::flightIndex(string listing){
  cout<<listing;
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
  int price = stoi(listing.substr(listing.find("$")+1));

  Flight retflight = *(new Flight(dp,dt,dep,arr,price));
  return retflight;
}
