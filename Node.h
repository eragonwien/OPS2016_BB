#ifndef Node_H
#define Node_H

#include <iostream>
using namespace std;

struct Node
{
	/*
		len = length of array
		init_cost = cost of 1 node
		total_cost = cost of 1 node path
	*/
	int job, person, len, init_cost, total_cost;
	bool * job_space;
	bool * person_space;
	int * rootpath;
	Node * parent = nullptr;
	Node ** children = nullptr;
	int** table;
	
	
	Node(int person, int job, int len, Node * parent, int ** table)
	{
		this->person = person;
		this->job = job;
		this->len = len;
		this->table = table;
		/* -----------ROOT-----------*/
		if(!parent)
		{
			job_space = new bool[len];
			person_space = new bool[len];
			rootpath = new int[len];
			for (int i = 0; i < len; ++i)
			{
				job_space[i] = true;
				person_space[i] = true;
				//rootpath[i] = getMin(len, table[i],nullptr);
			}
			for (int i = 0; i < len; ++i)
			{
				children[i] = new Node(0, i, len, this, table);
			}
		}
		/*---------Node---------------*/
		else
		{
			this->job_space = parent->job_space;
			this->person_space = parent->person_space;
			this->rootpath = parent->rootpath;
			init_cost = table[person][job];
			//total_cost = getNodeCost(person, job, len, rootpath, table, job_space);
		}
	}
	/*----- Decontructor------*/
	~Node()
	{
		delete[] job_space;
		delete[] person_space;
		delete[] rootpath;
		delete[] table;
		if(children)
		{
			for (int i = 0; i < len; ++i)
			{
				delete[] children[i];
			}
		}
	}
};
#endif //NODE_H
