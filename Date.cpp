#include <iostream>
#include <stdlib.h>
#include "Date.h"
using namespace std;
Date::Date(){
  hour = 0;
  minute = 0;
}
Date::Date(int h, int min){
  hour = h;
  minute = min;
}
Date::Date(string datebefore){
  hour = stoi(datebefore.substr(0,datebefore.find(":")));
  datebefore = datebefore.substr(datebefore.find(":")+1);
  minute = stoi(datebefore.substr(0,2));
  if(datebefore.find("p")!=-1){
    hour += 12;
  }
}
int Date::getHour(){
  return hour;
}
int Date::getMinute(){
  return minute;
}
// string Date::monthToString(){
//   string months[] = {"ERROR",
//     "Jan",
//     "Feb",
//     "Mar",
//     "Apr",
//     "May",
//     "Jun",
//     "Jul",
//     "Aug",
//     "Sep",
//     "Oct",
//     "Nov",
//     "Dec"};
//   return months[month];
// }

void Date::setDate(int h, int min){
  hour = h;
  minute = min;
}

//returns 0 if same Date
//returns difference between dates. positive if later
//than other, negative if earlier
int Date::compare(Date other){
  // if(year != other.getYear()){
  //   return year-other.getYear();
  // } else if(month != other.getMonth()){
  //   return month-other.getMonth();
  // } else if(day != other.getDay()){
  //   return day-other.getDay();
  // }else
  if(hour != other.getHour()){
    return hour-other.getHour();
  }else if(minute != other.getMinute()){
    return minute-other.getMinute();
  }
  return 0;
}
void Date::print(){
  if(hour<10)cout<<"0";
  cout<<hour<<":";
  if(minute<10)cout<<"0";
  cout<<minute;
}
ostream & operator << (ostream & os, Date & date_t) {
  // <<date_t.monthToString()<<" "<<date_t.getDay()<<", "<<date_t.getYear()<<
  os<<date_t.getHour()<<":"<<date_t.getMinute()<<"\n";
  return os;
}
