/*
Storm Crozier
7/9/2020
This is the main/client program which uses the list and activity class to allow the user to make a weekly schedule.  All fucntions in this file are used for inpuintt indexes given by the user and printing out the array of lists
*/
#include "list.h"
using namespace std;

void printArray(list schedule[], int & count, int size);
int getUserResponse();
int getDay();

int main()
{
	const int SIZE = 7;
	list schedule[SIZE];

	int response = 1;
	int day = 0;
	
	while(response != 0)	
	{
		response = getUserResponse();
		if(response == 1)
		{
			day = getDay();
			schedule[day].addToList();
		}	
		if(response == 2)
		{
			day = getDay();
			schedule[day].remove();
		}
		if(response == 3)
		{
			day = getDay();
			schedule[day].edit();
		}
		if(response == 4)
		{
			day = getDay();
			schedule[day].search();
		}
		if(response == 5)
		{
			cout<<"---------- = different activities"<<endl;
			cout<<"<><><><><> = different days: Monday on top sunday on bottom"<<endl;
			int count = 0;
			printArray(schedule, count, SIZE);
		}
	}
	return 0;
}
void printArray(list schedule[], int & count, int size)	//Prints array using recursion and a counter, also uses counter to print out day of the week
{
	if(count == size) return;
	if(count == 0) cout<<"Monday: " <<endl;
	if(count == 1) cout<<"Tuesday: " <<endl;
	if(count == 2) cout<<"Wednesday: "<<endl;
	if(count == 3) cout<<"Thursday: "<<endl;
	if(count == 4) cout<<"Friday: "<<endl;
	if(count == 5) cout<<"Saturday: "<<endl;
	if(count == 6) cout<<"Sunday: "<<endl; 
	schedule[count].displayList();
	cout<<"<><><><><><><><><><><><><>"<<endl;
	count += 1;
	printArray(schedule, count, size);
}
int getUserResponse()	//Get user response prompts the user to what they can do then return the int given by the user to then run the appropriate code
{
	int i = 0;
	cout<<"Enter a 1 to add a new activity to schedule"<< endl;
	cout<<"Enter a 2 to remove an activity"<< endl;
	cout<<"Enter a 3 to edit an activity"<< endl;
	cout<<"Enter a 4 to search for an activity"<< endl;
	cout<<"Enter a 5 to disiplay array"<< endl;
	cout<<"Enter a 0 to quit"<<endl;
	cin>> i;
	cin.ignore(100, '\n');
	return i;
}

int getDay()	//Get day request and returns an int to represent day of the week 
{
	int i = 0;
	cout<<"Enter a 1 for Monday"<<endl;
	cout<<"Enter a 2 for Tuesday"<<endl;
	cout<<"Enter a 3 for Wednesday"<<endl;
	cout<<"Enter a 4 for Thursday"<<endl;
	cout<<"Enter a 5 for Firday"<<endl;
	cout<<"Enter a 6 for Saturday"<<endl;
	cout<<"Enter a 7 for Sunday"<<endl;
	cin>> i;
	cin.ignore(100, '\n');
	return i - 1;
}
