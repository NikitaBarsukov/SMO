//
//  SourceBox.cpp
//  SMO
//
//  Created by Nikita Barsukov on 26/11/2017.
//  Copyright © 2017 Nikita Barsukov. All rights reserved.
//

#include "SourceBox.hpp"
#include <iostream>
#include <iomanip>

SourceBox::SourceBox(int n,double a,double b){
  size=n;
  box.resize(n);
  alpha=a;
  beta=b;
  for (int i=0; i<n; i++) {
    
    box[i].generate(a,b);
    
  }
}

int SourceBox::getSourceWithMinTime(){
  
  double min=box[0].time;
  int n=0;
  for (int i=0; i<size; i++) {
    
    if(min>box[i].time){
      min=box[i].time;
      n=i;
    }
  }
  
  return n;
  
}

void SourceBox::printTime(){
  
  for (int i=0; i<size; i++) {
    std::cout<<box[i].time << " ";
  }
  std::cout<<std::endl;
}


void SourceBox::newSourceRequest(int n){
  box[n].generate(alpha, beta);
}

double SourceBox::getTimeOfSource(int n){
  return box[n].time;
}


void SourceBox::proccesed(int n){
  box[n].numProcessed++;
}

void SourceBox::denied(int n){
  box[n].numDenied++;
}

void SourceBox::PrintStats(){

  
  for(int i=0; i<size;i++){
    
    


    std::cout <<"Source:"<<i+1<<" Generated: "<< box[i].numGenerated-1 << std::endl;
    std::cout <<"Source:"<<i+1<<" Processed: "<< box[i].numProcessed  << std::endl;
    std::cout <<"Source:"<<i+1<<" Denied: "<< box[i].numDenied  << std::endl<< std::endl;

    
    

    
  }
  

}

void SourceBox::printTotal(int N){
  
  
  int TotalP=0;
  int TotalD=0;
  int TotalG=0;
  
  
  
  for(int i=0; i<size;i++){
    TotalG+=box[i].numGenerated-1;
    TotalP+=box[i].numProcessed;
  
    TotalD+=box[i].numDenied;
    
  }
  
  std::cout<<"Total Generated: "<<TotalG<<std::endl;
  std::cout<<"Total Processed: "<<TotalP<<std::endl;
  std::cout<<"Total Denied: "<<TotalD<<std::endl;
  
  
  std::cout<<"Total Denied: "<<TotalD<<std::endl;

  
  
  for(int i=0; i<size;i++){
    
    double p= box[i].numDenied/box[i].numGenerated;
    std::cout<<"Source"<<i<<" - Вероятность отказа"<<p<<std::endl;
  }
}








