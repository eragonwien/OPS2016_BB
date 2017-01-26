#include <iostream>
using namespace std;

int assignment(int job, int** kosten);
int getMin(int, int*, bool*);
int getNodeCost(int, int, int, int*, int**, bool*);

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
	
	
	Node(int person, int job, int len, Node * parent, int ** table)
	{
		this->person = person;
		this->job = job;
		this->len = len;
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
				rootpath[i] = getMin(len, table[i],nullptr);
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
			total_cost = getNodeCost(person, job, len, rootpath, table, job_space);
		}
	}
	/*----- Decontructor------*/
	~Node()
	{
		delete[] job_space;
		delete[] person_space;
		delete[] rootpath;
		if(children)
		{
			for (int i = 0; i < len; ++i)
			{
				delete[] children[i];
			}
		}
	}
};
int assignment(int job, int** kosten)
{
	Node * root = new Node(-1, -1, job, nullptr, kosten);
	return 0;
}
int getMin(int len, int * array, bool * job_space)
{
	int min = 0;
	if (!job_space)
	{
		for (int i = 0; i < len; ++i)
		{
			if(array[min] > array[i])
				min = i;
		}
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			if(job_space[i])
				min = i;
		}
		for (int i = 0; i < len; ++i)
		{
			if(job_space[i] && (array[min] > array[i]))
				min = i;
		}
	}
	return min;
}
int getNodeCost(int person, int job, int len, int* rootpath, int** table, bool* job_space)
{
	int cost = 0;
	for (int i = 0; i < len; ++i)
	{
		if(i < person)
			cost+=rootpath[i];
		else if(i == person)
			cost+=table[person][job];
		else
			cost += getMin(len, table[i],job_space);
	}
	return cost;
}
int main()
{
	
	return 0;
}