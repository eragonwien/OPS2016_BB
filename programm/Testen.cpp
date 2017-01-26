#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "Node.h"
#include "branch.h"
using namespace std;
void showCostTable(int, int**);
bool checkLine(string, int);
int main()
{
	string dateiname;
	int len =5;
	char wiederholen = 'j';
	char r ;
  
	while(wiederholen== 'j')
	{
		cout << "Tabelle erstellen : 1 " << endl << "Assignment berechnen : 2" << endl;
		cin >> r;
		cout << "\nDateiname: ";
		cin >> dateiname;
		if(r=='1')
		{
			cout << "Wie viele Job ?\n";
			try
			{
				cin >> len;
			}
			catch (const std::exception&)
			{
				cout << "ungueltige Wert. Standardwert = 5.\n";
			}
			
			ofstream datei;
			datei.open(dateiname);
			
			datei << len << '\n';
			for(int i=0; i<len;i++)
			{
				for(int j=0;j<len;j++){
				datei << rand() %100  << '\t';
				}
			datei << endl;      
			}
		} 
		else
		{
			ifstream datei(dateiname);

			if (datei.good())
			{
				int** table = new int*[len];
				try
				{
					datei >> len;
					if (!checkLine(dateiname, len))
						throw exception();
					for (int i = 0; i < len; i++)
					{
						table[i] = new int[len];
						for (int j = 0; j < len; j++)
						{
							datei >> table[i][j];
						}
					}

					int * ass = new int[len];
					showCostTable(len, table);
					ass = assignment(len, table);

					showAssignment(ass, len);
				}
				catch (const std::exception&)
				{
					cout << "Format des Matrix ist inkorrekt" << endl;
					cout << "Dieses Testfile soll nicht verwendet werden" << endl;
				}
				datei.close();
				delete[] table;
			}  	   
			else
			{
				cout << "Fehler beim Oeffnen der Datei " << dateiname << " !" << endl;
			}	
		}	
		cout << " j eingeben um das Programm neu zu starten " << endl;
		cin >> wiederholen;
   }		        
   return 0;
}
void showCostTable(int len, int ** table)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			cout << table[i][j]<<"\t";
		}
		cout << endl;
	}
}
bool checkLine(string dateiname, int len)
{
	ifstream datei(dateiname);
	string text;
	int line = 0;
	for (int i = 0; i < len && getline(datei,text); i++)
	{
		line++;
	}
	datei.close();
	if (line < len)
		return false;
	else
		return true;

}


        

