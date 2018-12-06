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
  string objective;
  vector<string> cities;
  vector<Flight> allflights;
  vector<vector<string> > graph;
  ifstream myfile(argv[1], ios::in);
  getline(myfile,line);
  while(!myfile.eof())
  {

    lineflight = *(new Flight(line));
    allflights.push_back(lineflight);
    if(find(cities.begin(),cities.end(),lineflight.getDepartureLocation())==cities.end()){
      cities.push_back(lineflight.getDepartureLocation());
    }
    getline(myfile,line);
  }
  myfile.close();
  for (vector<string>::const_iterator i = cities.begin(); i != cities.end(); ++i){
    cout << *i << '\n';
  }
  // for(int i=0;i<allflights.size();i++){
  //   cout<<allflights.at(i);
  // }
  // cout<<"Enter Departure City: ";
  // cin>>departs;
  // cout<<"Enter Destination City: ";
  // cin>>destination;
  // cout<<"Earliest Departure Time(HH:MMpm/am): ";
  // cin>>datebefore;
  // earliestdep = *(new Date(datebefore));
  // cout<<"Choose Objective(any,early): ";
  // cin>>objective;

  for(int c = 0; c<cities.size();c++){
    vector<string> paths;
    paths.push_back(cities[c]);
    for(int f = 0; f<allflights.size();f++){
      if(allflights[f].getDepartureLocation()==cities[c]){
        if(find(paths.begin(),paths.end(),allflights.at(f).getDestination())==paths.end()){
          paths.push_back(allflights.at(f).getDestination());
        }
      }
    graph.push_back(paths);
    }
  }
  //   vector<vector<string> > graph(cities.size());
  // for (string& city : cities){
  //   paths.push_back(city);
  //   for(Flight& flight : allflights){
  //     if(flight.getDepartureLocation()==city && find(paths.begin(),paths.end(), flight.getDestination())==paths.end()){
  //       paths.push_back(flight.getDestination());
  //     }
  //     graph.push_back(paths);
  //     paths.clear();
  //   }
  // }
    for(int i=0;i<graph.size();i++){
      for(int j=0;j<graph.at(i).size();j++){
        cout<<graph.at(i).at(j)<<"->";
      }
      cout<<"\n";
    }
    return 0;
  }
