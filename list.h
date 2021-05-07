/*
Storm Crozier
7/9/2020
This is the list.h file which defines what a list and node are.  All the appropriate members for each object are places here
*/
#include "activity.h"

class node	//This is the node class which has all the function for what you can do to a node and has the three classes as data member and a previous and next pointer
{
	public:
		node();
		~node();
		void addActivity();
		void removeActivity();
		void displayActivity();
		void editActivity();
		void setPrev(node * & head);
		void setNextFor(node * & head);
		void setPrevFor(node * & temp);
		void setHeadPrev();
		void setTailNext();
		void checkForWork(node * & head);
		bool checkNext();
		bool compareTime(char timeTo[]);		
		int returnCheck();
		node*& goNext();
		node*& goPrev();
		
		
	protected:
		schoolWork mySchoolWork;
		screenTime myTime;
		workOut myWorkOut;
		int check;
		node * next;
		node * prev;
};

class list	//This is the list class which has all the functions for that you can do to a list.  Its data members include a head and tail pointer since its a doubly linked list and an int for number of activities in the list.
{
	public:
		list();
		~list();
		void deleteList(node * & head);
		void addToList();
		void addToList(node * & head);
		void displayList();
		void displayList(node * & head, int & activityNumber);
		void edit();
		void edit(node * & head, int & count, int activityNumber);
		void remove();
		void remove(node * & head, int & count, int activityNumber);
		void search();
		void search(node * & head, char timeTo[]);
		void checkForWork();
		void checkForWork(node * & head);
	
	protected:
		node * head;
		node * tail;
		int numberOfActivities;
};

