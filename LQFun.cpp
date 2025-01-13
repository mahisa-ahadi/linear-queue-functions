#include<iostream>
#include<cstdlib>
#define size 5
using namespace std;
struct LQ //definition of queue
{
	int rear , front;
	int items[size];
};
void initialize(LQ *);
int isE(LQ *);
int isF(LQ *);
void insert(LQ *,int);
int remove(LQ *);
void print(LQ *);
int main(void)
{
	LQ queue;
	initialize(&queue);
	for(int i=0;i<5;i++) 
	insert(&queue,i*2); //inserting first five even numbers to the queue 
	print(&queue);
	return 0;
}
void initialize(LQ *q1)
{
	q1->rear=-1;
	q1->front=0;
};

int isE(LQ *q1)
{
	if(q1->rear < q1->front)
	return 1;
	else
	return 0;
};

int isF(LQ *q1)
{
	if(q1->rear == size-1)
	return 1;
	else
	return 0;
};
void insert(LQ *q1,int x)
{
	if(isF(q1))
	cout<<"overflow , the queue is full! "<<endl;
	else
	q1->items[++q1->rear]=x;
};
int remove(LQ *q1)
{
	if(isE(q1))
	{
	cout<<"underflow , the queue is empty!"<<endl;
    exit(1);		
	}
	else
	{
		return q1->items[q1->front++];
	}
};
void print(LQ *q1)
{
	LQ temp;
	int x;
	if(isE(q1))
	cout<<"The queue is empty! "<<endl;
	else
	{
		initialize(&temp);
		while(!isE(q1))
		{
			x=remove(q1);
			cout<<x<<endl;
			insert(&temp,x);
		}
		initialize(q1);
		while(!isE(&temp))
		{
			x=remove(&temp);
			insert(q1,x);
		}
		
	}

}