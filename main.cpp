//
//  main.cpp
//  SMO
//
//  Created by Nikita Barsukov on 19/11/2017.
//  Copyright © 2017 Nikita Barsukov. All rights reserved.
//
// dt = ((double)rand() / (double)RAND_MAX) * (beta - alpha) + alpha;

//dt= (log(rand() + 1) - log(RAND_MAX)) / (-lambda);


//

#include "Source.h"
#include "Request.hpp"
#include "SourceBox.hpp"
#include "Buffer.hpp"
#include "Device.hpp"
#include "DeviceBox.hpp"
#include <iostream>
#include <vector>
#include <cmath>






double BETA = 0.1;
double ALPHA= 0.7;
double LAMBDA = 0.05;

const int SOURCE_NUM = 4;
const int BUFFER_SIZE = 1;
const int DEVICE_NUM = 4;


const int PRIORITY = 2000;



double realisation(int N){
  
  
  
  SourceBox sourceBox(SOURCE_NUM,ALPHA,BETA);
  Buffer buffer(BUFFER_SIZE,PRIORITY);
  DeviceBox devices(DEVICE_NUM,LAMBDA);
  
  //Find RequestWith Minimal time
  
  int firstReqNum =-1;
  double firstReqTime =-1;
  int k=0;
  
  while (k<N){
    
    sourceBox.printTime();
    
    firstReqNum =sourceBox.getSourceWithMinTime();
    firstReqTime = sourceBox.getTimeOfSource(firstReqNum);
    sourceBox.newSourceRequest(firstReqNum);
    
    std::cout<<"MinSource is:"<<firstReqNum+1<<std::endl;
    std::cout<<"TOSV:";
    devices.printTosv();
    std::cout<<std::endl;
    
    
    
    
    //Ecли буфер пустой и девайс свободен, то заявку в систему (что аналогично первой заявке)
    if (buffer.isFree() && devices.hasFree(firstReqTime)){
      sourceBox.proccesed(firstReqNum);
      devices.newTosv(firstReqTime);
      
      
      sourceBox.PrintStats();
      
      continue;
    }
    
    //Диспетчер постановки в буфер
    if (!devices.hasFree(firstReqTime)){//not HAS FREE
      
      int answer = buffer.add(Request(firstReqNum,firstReqTime));
      //Eсли буфер занят, то в отказ, иначе добавить в  очередь
      if(answer==1){
        
        sourceBox.denied(firstReqNum);
        
        // если ответ не 1, то заявка уже поставлленна в очередь,
      }
    }
    
    //Диспетчер постановки на Прибор
    if(devices.hasFree(firstReqTime)){//Eсли в буфере что-то есть, берем из буфера
      
      std::cout<<"SOME DEVICE IS FREE"<<std::endl;
      if (buffer.isFree()) {
        
        sourceBox.proccesed(firstReqNum);
        devices.newTosv(firstReqTime);
        
      } else{
        
        sourceBox.denied(firstReqNum);
        
        Request req = buffer.pullOut();
        sourceBox.proccesed(req.getRequestSourceNum());
        devices.newTosv(firstReqTime);
        
      }
    }
    
    
    sourceBox.PrintStats();
    devices.printKobr();
    devices.printTosv();
    buffer.show();
    
    std::cout<<"====================================="<<std::endl;
    
    k++;
  }
  std::cout<<std::endl;
  sourceBox.PrintStats();
  sourceBox.printTotal(N);
  buffer.show();
  
  
  devices.printKobr();
  std::cout<<"====================================="<<std::endl;
  
  
  
  
  
  double t=1.643;
  double a=0.9;
  double d=0.1;
  double p=(t*t)/(((d*d)*N)+(t*t));
  std::cout<<"Вероятность отказая заявкам в обслуживании P = "<<p<<std::endl;
  return p;
  
}


int main(int argc, const char * argv[]) {
  
  srand(time(NULL));
  
  int N=100;
  double p0=0;
  p0=realisation(N);
  
//  while (true) {
//    double p1=0;
//    N+=5000;
//    p1=realisation(N);
//    
//    if (p0-p1<p0*0.10){
//      std::cout<<"Got it. N = "<<N<<std::endl;
//      break;
//    }
//    
//    std::cout<<p0<<std::endl;
//    std::cout<<p1<<std::endl;
  
  }
  
  
  
  


  

  

    


  







  
  

