//
//  DeviceBox.cpp
//  SMO
//
//  Created by Nikita Barsukov on 09/12/2017.
//  Copyright © 2017 Nikita Barsukov. All rights reserved.
//

#include "DeviceBox.hpp"

DeviceBox::DeviceBox(int n,double lambda):box(n,Device(lambda)){
  
  size=n;
  for(int i=0;i<size;i++){
    box[i].tosv=0;
  }
  
  pointer=0;

}


bool DeviceBox::hasFree(double time){
  int free=-1;
  
  for(int i=0; i<size;i++){
    if (box[i].isFree(time))
      free=i;
  }
  
  if(free!=-1)
    return true;
  else
    return false;
}


void DeviceBox::printTosv(){
  
  for(int i=0;i<box.size();i++){
    
    std::cout<<"DEVICE:"<<i<<" Tosv:"<<box[i].getTosv()<<std::endl;
    
  }
}

void DeviceBox::newTosv(double time){
  
  int free=-1;
  
  for (int i = pointer; i<size;i++){
    if(box[i].isFree(time)){
      free=i;
      pointerIncrement(i);
      break;
    }
  }
  
  
  
  if(free==-1){
    for (int i=0; i<size; i++) {
      if(box[i].isFree(time)){
        free=i;
        pointerIncrement(i);
        break;
      }
    }
  }
  
  std::cout<<"FREE"<<free<<std::endl;
  std::cout<<"POINTER"<<pointer<<std::endl;

  box[free].newTosv();
  box[free].kobr++;
  //std::cout<<"(POINT TO "<<pointer-1<< ") NEXT IS "<<pointer<<"\n";

  
}

void DeviceBox::pointerIncrement(int newPlace){
  
  pointer=newPlace+1;
  if(pointer>=size)
    pointer=0;
  
}


void DeviceBox::printKobr(){
  
  for (int i=0; i<size;i++){
    
    std::cout<<"DEVICE"<<i<<"Kobr: "<<box[i].kobr<<std::endl;
    
  }
  
}


//debugTool
void DeviceBox::setNullTime(int n){
  
  box[n].tosv=0;
  
}

void DeviceBox::printStats(){
  double k=0;
  
  for (int i=0; i<size;i++){
    
    k=box[i].dts/box[i].
  }
  
  
  
}

