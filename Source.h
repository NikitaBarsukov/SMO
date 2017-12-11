//
//  Source.h
//  SMO
//
//  Created by Nikita Barsukov on 19/11/2017.
//  Copyright © 2017 Nikita Barsukov. All rights reserved.
//

#ifndef Source_h
#define Source_h

class Source {
  
  
private:
  double alpha;
  double beta;
  
  
  
  
public:
  Source();
  Source(double alpha,double beta);
  double generate(double beta,double alpha);
  double time;
  
  
  
  double numGenerated;
  double numDenied;
  double numProcessed;


  
};
#endif /* Source_h */

//double creation_time = ((double)rand() / (double)RAND_MAX) * (beta - alpha) + alpha;
