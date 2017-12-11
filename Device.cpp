//
//  Device.cpp
//  SMO
//
//  Created by Nikita Barsukov on 26/11/2017.
//  Copyright © 2017 Nikita Barsukov. All rights reserved.
//

#include "Device.hpp"
#include <iostream>

Device::Device(){
  
  
  
}

Device::Device(double lam){
  
  lambda=lam;
  tosv=0;
  kobr=0;
  dts=0;

}

double Device::getTosv(){
  return tosv;
}

double Device::newTosv(){
  
  dt= (log(rand() + 1) - log(RAND_MAX)) / (-lambda);
  tosv+=dt;
  dts+=dt;
  
  return tosv;
  
}

bool Device::isFree(double time){
  
  return tosv<time;
}
