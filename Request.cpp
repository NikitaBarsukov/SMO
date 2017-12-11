//
//  Request.cpp
//  SMO
//
//  Created by Nikita Barsukov on 26/11/2017.
//  Copyright © 2017 Nikita Barsukov. All rights reserved.
//

#include "Request.hpp"

Request::Request(int number,double t){
  sourceNumber=number;
  time=t;
}



double Request::getRequestTime(){
  
  return time;
  
}


int Request::getRequestSourceNum(){
  
  return sourceNumber;
}
