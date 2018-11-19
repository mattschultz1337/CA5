#include <iostream>
#include <stdlib.h>
#include "Date.h"
using namespace std;
Date::Date(){
  year = 2000;
  month = 1;
  day = 1;
}
Date::Date(int y, int m, int d){
  year = y;
  month = m;
  day = d;
}
int Date::getYear(){
  return year;
}
int Date::getMonth(){
  return month;
}
int Date::getDay(){
  return day;
}
void Date::setDate(int y, int m, int d){
  year = y;
  month = m;
  day = d;
}

//returns 0 if same Date
//returns difference between dates. positive if later
//than other, negative if earlier
int Date::compare(Date other){
  if(year != other.getYear()){
    return year-other.getYear();
  } else if(month != other.getMonth()){
    return month-other.getMonth();
  } else if(day != other.getDay()){
    return day-other.getDay();
  }
  return 0;
}
