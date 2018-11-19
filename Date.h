#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

class Date{
  private:
    int year;
    int day;
    int month;
  public:
    Date();
    Date(int y, int m, int d);
    int compare(Date other);
    int getYear();
    int getMonth();
    int getDay();
    void setDate(int y, int m, int d);


};
#endif
