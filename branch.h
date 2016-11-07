#ifndef BRANCH_H
#define BRANCH_H

#include <iostream>
#include "Node.h"

using namespace std;
void copyBoolArray(bool*,bool*,int);
void expandNode(Node*, int);
int getIndexofMinCost(int *, int, bool*);
void calculateChildren(Node *, int);
int bound (Node *,int);
void branch(Node* node, int len)
{
	if (len > 0)
	{
		expandNode(node, len);
		calculateChildren(node, len);
		branch(node->children[bound(node, len)], len - 1);
	}
	else
		return;
}	
int bound( Node * node, int len)
{
	int index = 0;
	for (int i = 0; i < len; ++i)
	{
		if(node->children[i]->total_cost < node->children[index]->total_cost)
			index = i;
	}
	node->rootpath[node->len - len] = node->children[index]->job;
	node->job_space[node->children[index]->job] = false;
	return index;
}
void copyBoolArray(bool * src, bool * dest, int len)
{
	for (int i = 0; i < len; ++i)
	{
		dest[i] = src[i];
	}
}
void expandNode(Node* node, int len)
{
	node->children = new Node*[len];
	/* Make a copy of job_space*/
	bool * jobs = new bool[node->len];
	copyBoolArray(node->job_space, jobs, node->len);
	for (int i = 0; i < len; ++i)
	{
		/*
		die länge ganze tabelle durchlaufen
		dabei die bool array checken
		true dann eintragen - break
		*/
		for (int j = 0; j < node->len; ++j)
		{
			if(jobs[j])
			{
				node->children[i] = new Node(node->person + 1, j, node->len, node, node->table);
				jobs[j] = false;
				break;
			}
		}
	}
	delete[] jobs;
}
void calculateChildren(Node * node, int len)
{
	for (int i = 0; i < len; ++i)
	{
		/*  new job array copy*/
		bool * jobs = new bool[node->len];
		copyBoolArray(node->job_space, jobs, node->len);
		/* run through all persons */
		int cost = 0;


		for (int j = 0; j < node->len; ++j)
		{
			int child_id = node->children[i]->person;
			if(j < child_id)
			{
				cost += node->table[j][node->rootpath[j]];
			}
			else if (j == child_id)
			{
				cost+= node->children[i]->init_cost;
				jobs[node->children[i]->job] = false;
			}
			else
			{
				int min = getIndexofMinCost(node->table[j], node->len, jobs);
				cost += node->table[j][min];
				jobs[min] = false;
			}
		}
		node->children[i]->total_cost = cost;
	}
}
int getIndexofMinCost(int * array, int len, bool * jobs)
{
	int index = 0;
	for (int i = 0; i < len; ++i)
	{
		if(jobs[i] && (array[i] < array[index] || !jobs[index]))
			index = i;
	}
	return index;
}
void showAllNodes(Node * root, int len)
{
	if(root->children)
	{
		int index = 0;
		for (int i = 0; i < len; ++i)
		{
			cout<<"child "<<root->children[i]->person<<"-"<<root->children[i]->job<<" cost = "<<root->children[i]->total_cost<<endl;
			if(root->children[i]->children)
				index = i;
		}
		cout<<"jump rext node"<<endl;
		showAllNodes(root->children[index], len -1);
		
		
	}
}
void showRootPath(Node * root, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout<<"Person "<<i<<" gets "<<"Job "<<root->rootpath[i]<<endl;
	}
}
#endif //BRANCH_H