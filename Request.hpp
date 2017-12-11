//
//  Request.hpp
//  SMO
//
//  Created by Nikita Barsukov on 26/11/2017.
//  Copyright © 2017 Nikita Barsukov. All rights reserved.
//

#ifndef Request_hpp
#define Request_hpp

#include <stdio.h>
#include <utility>

class Request{
  
  
private:

public:
  Request(int number, double time);
  int getRequestSourceNum();
  double getRequestTime();
  int sourceNumber;
  double time;
  int priority;


  
  

};

#endif /* Request_hpp */
