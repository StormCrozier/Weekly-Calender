/*
Storm Crozier
7/9/2020
This is the list.cpp which houses all the functions for the list and node class.  The list a is a doubly linked list so there is a head and a tail pointer.  The nodes also have next and previous pointers.  The node class has the three dervied classes as data members and a check to check which object is being used in the node
*/
#include "list.h"

using namespace std;

list::list()	//List constructor which sets head and tail to null and number of activites to zero
{
	head = NULL;
	tail = NULL;
	numberOfActivities = 0;
}

list::~list()	//List destructor which calls the delete list function to delete the list 
{
	deleteList(head);	
}

void list::deleteList(node * & head)	//Uses recurrsion to delete the list
{
	if(!head) return;
	deleteList(head->goNext());
	delete head;
}

void list::addToList()	//Wrapper function to call recursive function
{
	addToList(head);
}

void list::addToList(node * & head)	//Recursive function which uses add activity function to add activity info
{
	if(!head)
	{
		checkForWork();
		head = new node;
		tail = head;
		head->addActivity();
		numberOfActivities += 1;
		return;
	}
	
	addToList(head->goNext());
	head->setPrev(head);

}

void list::remove()	//Wrapper function which gets info about what activty to remove and calls recursive function
{
	int activityNumber = 0;
	int count = 1;
	cout<<"Enter activity number: " <<endl;
	cin>>activityNumber;
	cin.ignore(100, '\n');
	remove(head, count, activityNumber);
}

void list::remove(node * & head, int & count, int activityNumber)	//Recursive function whcih removes desired node from list.  Covers all cases, node to remove is head, tail, or in the middle
{
	if(!head) return;
	if(count == activityNumber)
	{
		numberOfActivities -= 1;
		if(count == 1)
		{
			node * temp = head;
			head = head->goNext();
			if(head)
				head->setHeadPrev();
			delete temp;
			return;
		}
		if(head == tail)
		{
			node * temp = tail;
			tail = tail->goPrev();
			tail->setTailNext();
			delete temp;
			return;
		}
		node * prev = head->goPrev();	
		node * temp = head;
		head = head->goNext();
		prev->setNextFor(head);
		head->setPrevFor(prev);
		delete temp;
		return;
	}	
	count += 1;
	remove(head->goNext(), count, activityNumber);
	return;
}

void list::displayList()	//Wrapper function that calls recurive function to display list 
{
	int i = 1;
	displayList(head, i);
}

void list::displayList(node * & head, int & activityNumber)	//Recurrsive function which uses the activity display function to diplay all activity info in the list 
{
	if(!head) return;
	head->displayActivity();
	cout<<"Activity Number: " << activityNumber << endl;
	activityNumber += 1;	
	cout<<"---------------------"<<endl;
	displayList(head->goNext(), activityNumber);
	
}

void list::edit()	//Wrapper function to get info about which activity to edit
{
	int activityNumber = 0;
	int count = 1;
	cout<<"Enter activity number for this day: "<<endl;
	cin>>activityNumber;
	cin.ignore(100, '\n');
	edit(head, count, activityNumber);	
}

void list::edit(node * & head, int & count, int activityNumber)	//Recursive function which goes thorough list to then call the edit activity function
{
	if(!head) return;
	if(count == activityNumber)
	{
		head->editActivity();
		return;
	}
	count += 1;
	edit(head->goNext(), count, activityNumber);
}

void list::search()	//Wrapper function which gets info about node to search for then calls recursive function
{
	char timeTo[25];
	cout<<"Enter time of activity to search for: " << endl;
	cin.get(timeTo, 100);
	cin.ignore(100, '\n');
	search(head, timeTo);
}

void list::search(node * & head, char timeTo[])	//Recursive function which uses the compare time function to find appropriat node to display
{
	if(!head) return;
	if(head->compareTime(timeTo))
	{
		head->displayActivity();
		return;
	}
	search(head->goNext(), timeTo);
}

void list::checkForWork()	//Check for work function which calls recursive function
{
	if(!head) return;
	checkForWork(head);
}

void list::checkForWork(node * & head)	//Recursive check for work function which uses chec for work function from node class
{
	if(!head) return;
	int i = head->returnCheck();
	if(i == 1)
	{
		head->checkForWork(head);
		return;	
	}
	checkForWork(head->goNext());
			
}
node::node()	//Node constructor to initialize nodes data 
{
	next = NULL;
	prev = NULL;
	check = 0; // 1:school work 2: screen time 3:work out
}
node::~node(){}	//Node destructor

void node::addActivity()	//Adds appropriate activity to node then adds the right number to the check data member
{
	int response = 0;
	cout<<"Enter a 1 to add school work"<<endl;
	cout<<"Enter a 2 to add screen time"<<endl;
	cout<<"Enter a 3 to add work out"<<endl;
	cin>>response;
	cin.ignore(100, '\n');
	
	if(response == 1)
	{
		mySchoolWork.add();
		mySchoolWork.addSubject();
		mySchoolWork.addWork();
		check = 1;
	}

	if(response == 2)
	{
		myTime.add();
		myTime.addMin();
		myTime.addMax();
		check = 2;
	}
	if(response == 3)
	{
		myWorkOut.add();
		myWorkOut.addWorkOut();
		myWorkOut.addLength();
		check = 3;
	}	
}

void node::displayActivity()	//Uses check to call correct function for which activity to display
{
	if(check == 1)
		mySchoolWork.display();
	if(check == 2)
		myTime.display();
	if(check == 3)
		myWorkOut.display();
}
	
void node::editActivity()	//Uses chech to call correct function for which activity to edit
{
	if(check == 1)
		mySchoolWork.edit();
	if(check == 2)
		myTime.edit();
	if(check == 3)
		myWorkOut.edit();
}

void node::checkForWork(node * & head)	//Check for work functin which calls the scren time check for work function
{
	myTime.checkForWork(head->mySchoolWork);
}
int node::returnCheck()	//Return check.  Used by list class
{
	return check;
}
bool node::compareTime(char timeTo[])	//Uses check to call compare to compare nodes time with the time passed by argument
{
	int i = 0;
	if(check == 1)
	{
		i = mySchoolWork.compare(timeTo);
		if(i == 1 ) return true;
		else return false;
	}

	if(check == 2)
	{
		i = myTime.compare(timeTo);
		if(i == 1 ) return true;
		else return false;
	}

	if(check == 3)
	{
		i = myWorkOut.compare(timeTo);
		if(i == 1 ) return true;
		else return false;
	}
}
node*& node::goNext()	//Go next return the nodes next pointer used by the list class
{
	return next;
}

node*& node::goPrev()	//Go prev returns the nodes previous pointer used by the list class
{
	return prev;
}

void node::setHeadPrev()	//Sets the current/head nodes previous to NULL
{
	prev = NULL;
}

void node::setTailNext()	//Sets the current/tail nodes next to NUlLL
{
	next = NULL;
}

void node::setPrev(node * & temp)	//Sets the next nodes previous to current node
{
	next->prev = temp;
}

void node::setNextFor(node * & head)	//sets the next pointer to the pointer passes in by argument
{
	next = head;
}

void node::setPrevFor(node * & head)	//Sets the previous pointer to the pointer passes in by argument
{
	prev = head;
}
bool  node::checkNext()	//Return false if next node is NULL ore true is its not null
{
	if(next == NULL) return false;

	else return true; 

}


