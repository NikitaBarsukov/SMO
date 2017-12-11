//
//  Buffer.hpp
//  SMO
//
//  Created by Nikita Barsukov on 27/11/2017.
//  Copyright © 2017 Nikita Barsukov. All rights reserved.
//

#ifndef Buffer_hpp
#define Buffer_hpp

#include <iostream>
#include <vector>
#include "Request.hpp"
class Buffer{
private:
  
  int size;
  
  std::vector<Request> buffer;
  
public:
  
  int priority;
  Buffer(int size,int p);
  int add(Request req);
  Request pullOut();
  void show();
  bool isFree();
  
  
  
};
#endif /* Buffer_hpp */
