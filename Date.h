#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

class Date{
  private:
    int hour;
    int minute;
  public:
    Date();
    Date(int h, int min);
    int compare(Date other);
    Date(std::string datebefore);
    int getHour();
    int getMinute();

    void setDate(int h, int min);
    // std::string monthToString();
    friend std::ostream & operator << (std::ostream & os, Date & date_t);

};
#endif
