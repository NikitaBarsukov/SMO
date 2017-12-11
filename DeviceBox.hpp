//
//  DeviceBox.hpp
//  SMO
//
//  Created by Nikita Barsukov on 09/12/2017.
//  Copyright © 2017 Nikita Barsukov. All rights reserved.
//

#ifndef DeviceBox_hpp
#define DeviceBox_hpp

#include "Device.hpp"
#include <iostream>
#include <stdio.h>
#include <vector>


class DeviceBox{
  
private:
  std::vector<Device> box;
  int size;
  void pointerIncrement(int newPlace);
  int pointer;

  
public:
  DeviceBox(int n,double lambda);
  bool hasFree(double time);
  void printTosv();
  void newTosv(double time);
  void printKobr();
  
  void printStats();
  
  
  double dt;
  //debugTool
  void setNullTime(int n);

  
};

#endif /* DeviceBox_hpp */



