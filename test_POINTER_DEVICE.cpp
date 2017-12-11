////
////  test_POINTER_DEVICE.cpp
////  SMO
////
////  Created by Nikita Barsukov on 10/12/2017.
////  Copyright © 2017 Nikita Barsukov. All rights reserved.
////
//
//
//#include "Source.h"
//#include "Request.hpp"
//#include "SourceBox.hpp"
//#include "Buffer.hpp"
//#include "Device.hpp"
//#include "DeviceBox.hpp"
//#include <iostream>
//#include <vector>
//#include <cmath>
//
//
//
//
//
//
//double BETA = 0.1;
//double ALPHA= 0.4;
//double LAMBDA = 1;
//
//const int SOURCE_NUM = 4;
//const int BUFFER_SIZE = 4;
//const int DEVICE_NUM = 7;
//
//const int N = 7000;
//
//const int PRIORITY = 4;
//
//int main(){
//  
//  //srand(time(NULL));
//  
//  DeviceBox devices(DEVICE_NUM,LAMBDA);
//  devices.printTosv();
//  
//  
//  
//  
//  std::cout<<std::endl;
//  
//  
//  devices.newTosv(1);
//  devices.newTosv(1);
//  devices.newTosv(1);
//  devices.newTosv(1);
//  devices.newTosv(1);
//  devices.newTosv(1);
//  devices.newTosv(1);
//  devices.newTosv(13);
//  devices.newTosv(13);
//  devices.newTosv(13);
//  devices.newTosv(13);
//  devices.setNullTime(2);
//  
//  devices.setNullTime(6);
//  std::cout<<std::endl;
//  
//  devices.printTosv();
//  devices.newTosv(0.1);
//  
//  std::cout<<std::endl;
//  
//  devices.printTosv();
