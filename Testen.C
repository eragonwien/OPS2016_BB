#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "Node.h"
#include "branch.h"
using namespace std;

int main()
{
   string dateiname;
   int len =5;
   int** table = nullptr;
   char wiederholen = 'j';
   char r ;
  
   while(wiederholen== 'j'){
       cout << "Tabelle erstellen : 1 " << endl << "Assignment berechnen : 2" << endl;
       cin >> r;
       cout << "\nDateiname: ";
       cin >> dateiname;
       if(r=='1'){
          ofstream datei;
          datei.open(dateiname);
          for(int i=0; i<len;i++){
             for(int j=0;j<len;j++){
               datei << rand() %100  << '\t';
             }
          datei << endl;      
          }
       } 
       else{
          ifstream datei(dateiname);

	  if (datei.good()){
               int** table = new int*[len];
               
	       for (int i = 0; i < len; i++)
	       {
		  table[i] = new int[len];
		  for (int j = 0; j < len; j++)
                      datei >> table[i][j];
	       }
	        
 	       Node * root = new Node(-1,-1,len,nullptr,table);
	       branch(root, len);
	       //showAllNodes(root, len);
	       showRootPath(root, len);
	       delete[] table;
	       
          }  	   
	
	  else{
		cout << "Fehler beim Oeffnen der Datei " << dateiname << "!" << endl;
                return 0;
          }
					
      }	
     cout << " j eingeben um das Programm neu zu starten " << endl;
     cin >> wiederholen;
   }		        
   return 0;
}

        

