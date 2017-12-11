//
//  SourceBox.hpp
//  SMO
//
//  Created by Nikita Barsukov on 26/11/2017.
//  Copyright © 2017 Nikita Barsukov. All rights reserved.
//

#ifndef SourceBox_hpp
#define SourceBox_hpp

#include "SourceBox.hpp"
#include "Source.h"
#include <vector>


class SourceBox{
  
  
  
private:
  double alpha;
  double beta;
  std::vector<Source> box;
  int size;
public:
  SourceBox(int n,double a,double b);
  int getSourceWithMinTime();
  double getTimeOfSource(int n);
  void printTime();
  void newSourceRequest(int n);
  void proccesed(int n);
  void denied(int n);
  void PrintStats();
  void printTotal(int N);
  

};

#endif /* SourceBox_hpp */
