#include "FlightDiscoverySystem.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include<vector>
int main(int argc, char* argv[]){
  Flight lineflight = *(new Flight());
  string departs;
  string destination;
  Date earliestdep;
  Date deptime;
  Date arrtime;
  int cost;
  string datebefore;
  string line;
  vector<string> cities;
  ifstream myfile(argv[1], ios::in);
  while(!myfile.eof())
  {
    getline(myfile,line);
    lineflight = *(new Flight(line));
    cities.push_back(lineflight.getDepartureLocation());
  }
  myfile.close();
  for (vector<string>::const_iterator i = cities.begin(); i != cities.end(); ++i){
    cout << *i << ' ';
  }
  cout<<"Enter Departure City: ";
  cin>>departs;
  cout<<"\n"<<"Enter Destination City: ";
  cin>>destination;
  cout<<"\n"<<"Earliest Departure Time(HH:MMpm/am): ";
  cin>>datebefore;
  earliestdep = *(new Date(datebefore));

  return 0;
}
