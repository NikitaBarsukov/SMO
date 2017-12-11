//
//  Buffer.cpp
//  SMO
//
//  Created by Nikita Barsukov on 27/11/2017.
//  Copyright © 2017 Nikita Barsukov. All rights reserved.
//

#include "Buffer.hpp"



Buffer::Buffer(int m_size,int p):size(m_size),priority(p-1){}


int Buffer::add(Request req){
  
  if (buffer.size()==size){
    return 1;
    
  } else{
    buffer.push_back(req);
    return 0;
  }
    
  
  
  
  return 0;
}


Request Buffer::pullOut(){
  
  int prIndexWas=-1;
  Request req(0,0);
  for(int i=0; i<buffer.size();i++){
    if (buffer[i].sourceNumber==priority){
      
      prIndexWas=i;
      req=buffer[i];
      buffer.erase(buffer.begin()+i);
      break;
   
    }
  }
  
  
  if (prIndexWas==-1){
    req=buffer.at(0);
    buffer.erase(buffer.begin());
  }
  
  return  req;
}

void Buffer::show(){
  std::cout<<"IN BUFFER NOW:"<<buffer.size()<<" REQUESTS"<<std::endl;
  for(int i=0; i<buffer.size();i++){
    
    std::cout<<buffer[i].sourceNumber+1<<":"<<buffer[i].getRequestTime()<<std::endl;
  }
  
}

bool Buffer::isFree(){
  
  if (buffer.size() ==0){
    return true;
  } else
    return false;
  
}


