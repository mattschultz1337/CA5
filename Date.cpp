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
