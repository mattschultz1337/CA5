#include "FlightDiscoverySystem.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>

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
  vector<vector<int> > graph(cities.size());
  for(int i=0;i<cities.size();i++){
    graph[i].resize(cities.size());
  }
  for(int f=0;f<allflights.size();f++){
    int d = distance(cities.begin(),find(cities.begin(),cities.end(),allflights[f].getDepartureLocation()));
    int s = distance(cities.begin(),find(cities.begin(),cities.end(),allflights[f].getDestination()));
    graph[d][s] = allflights[f].getPrice();
  }

  cout<<"Enter Departure City: ";
  cin>>departs;
  cout<<"Enter Destination City: ";
  cin>>destination;
  cout<<"Earliest Departure Time(HH:MMpm/am): ";
  cin>>datebefore;
  earliestdep = *(new Date(datebefore));
  // for(int i=0;i<graph.size();i++){
  //   for(int j=0;j<graph.size();j++){
  //     cout<<graph[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  int start = distance(cities.begin(),find(cities.begin(),cities.end(),departs));
  int end = distance(cities.begin(),find(cities.begin(),cities.end(),destination));
  int count = 0;
  if(graph[start][end]!=0){
    for(int i=0;i<allflights.size();i++){
      if(allflights[i].getDepartureLocation()==departs && allflights[i].getDestination()==destination){
        cout<<allflights[i];
        count++;
      }
    }

  }else{
    int outbound = 0;
    for(int i=0;i<cities.size();i++){
      if(graph[start][i]!=0){
        outbound++;
      }
    }
    int departures[outbound];
    int countArr = 0;
    for(int i=0; i<cities.size();i++){
      if(graph[start][i]!=0){
        departures[countArr] = i;
        countArr++;
      }
    }
    for(int i=0;i<countArr;i++){
      if(graph[departures[i]][end]!=0){
        cout<<"found a flight from "<<cities[departures[i]]<<" layover to "<<destination<<"\n";
        count = 0;
        for(int j=0;j<allflights.size();j++){
          if(allflights[j].getDepartureLocation()==departs && allflights[j].getDestination()==cities[departures[i]] && count==0){
            cout<<allflights[j];
            count++;
          }
        }
        count = 0;
        for(int j=0;j<allflights.size();j++){
          if(allflights[j].getDepartureLocation()==cities[departures[i]] && allflights[j].getDestination()==destination && count==0){
            cout<<allflights[j];
            count++;
          }
        }

      }
    }

    return 0;
  }
}
