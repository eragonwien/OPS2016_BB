#include "Node.h"
#include <iostream>
using namespace std;

int bound(int n, int** table, bool person_space[], bool job_space[]){

   int sum=0;
   int* row= nullptr;
   for(int j=0; j<n;j++){
     int min =0;
     bool min_init= true;
     row= table[j];
     if(person_space[j])
      for(int i=0; i<n; i++){
       if(job_space[i] && ( min_init || row[i]< min )){
         min = row[i];
         min_init= false;
       } 
     }
    sum += min;
   }
   return min;
}
