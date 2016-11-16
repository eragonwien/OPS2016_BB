
#include <iostream>
#include <random>
#include "Node.h"
#include "branch.h"
using namespace std;
void makeTable(int, int**);
int main(int argc, char const *argv[])
{
	cout << "Type in length!" << endl;
	int len = 4;
	try
	{
		cin >> len;
	}
	catch (const std::exception&)
	{
		
	}
	
	int ** table = new int*[len];
	makeTable(len, table);
	cout<<"length : "<<len<<endl;
	for (int x = 0; x < len; ++x)
	{
		for (int y = 0; y < len; ++y)
		{
			if (y != 0)
				cout << "-";
			cout<<table[x][y];
			if (table[x][y] <= 9)
				cout << " ";
		}
		cout<<endl;
	}
	Node * root = new Node(-1,-1,len,nullptr,table);
	branch(root, len);
	//showAllNodes(root, len);
	showRootPath(root, len);
	delete[] table;
}
void makeTable(int len, int** table)
{
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1,20);
	//int dice_roll = distribution(generator); 
	for (int i = 0; i < len; ++i)
	{
		table[i] = new int[len];
		for (int j = 0; j < len; ++j)
		{
			table[i][j] = distribution(generator);
		}
	}
}