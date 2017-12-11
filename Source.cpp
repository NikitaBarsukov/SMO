//
//  Source.cpp
//  SMO
//
//  Created by Nikita Barsukov on 26/11/2017.
//  Copyright © 2017 Nikita Barsukov. All rights reserved.
//

#include "Source.h"
#include <cstdlib>

Source::Source(){
  time=0;
  
  
  numGenerated=0;
  numDenied=0;
  numProcessed=0;

  
}

Source::Source(double alpha,double beta){
  
  numGenerated=0;
  numDenied=0;
  numProcessed=0;
  
  this->alpha=alpha;
  this->beta=beta;
  this->time=0;
  
}

double Source::generate(double beta,double alpha){
  
  double dt = ((double)rand() / (double)RAND_MAX) * (beta - alpha) + alpha;
  numGenerated++;
  time+=dt;
  return time;
  
}


