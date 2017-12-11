//
//  Device.hpp
//  SMO
//
//  Created by Nikita Barsukov on 26/11/2017.
//  Copyright © 2017 Nikita Barsukov. All rights reserved.
//

#ifndef Device_hpp
#define Device_hpp

#include "Device.hpp"
#include <cstdlib>
#include <cmath>

class Device{
private:
  double dt;
  
  
public:
  Device();
  Device(double lambda);
  double getTosv();
  double newTosv();
  bool isFree(double time);
  
  
  double tosv;
  double lambda;
  double kobr;
  double dts;
  
  
};

#endif /* Device_hpp */
