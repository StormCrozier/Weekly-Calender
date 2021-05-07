/*
Storm Crozier
7/9/2020
This is the activiy.cpp file which houses all the function definitions for what you can do to an activity.  The base activity class has all basic info for what an activity is and function to work on that data.  The derived classes have all the activty class data plus more.  So derived class fucntions can call base class functions to do work on basic information and add to its own data
*/
#include "activity.h"
using namespace std;

activity::activity()	//Default constructor for the activity class
{
	place = NULL;
	time = NULL;
	date = NULL;
	description = NULL;
}

activity::activity(const activity & source): place(NULL), time(NULL), date(NULL), description(NULL)	//Copy constructor used to copy from an activity object into current object
{
	place = new char[strlen(source.place) + 1];
	time = new char[strlen(source.time) + 1];
	date = new char[strlen(source.date) + 1];
	description = new char[strlen(source.description) + 1];

	strcpy(place, source.place);
	strcpy(time, source.time);
	strcpy(date, source.date);
	strcpy(description, source.description);
}

activity::~activity()	//Destructor for the activity class
{
	if(place)
	{
		delete [] place;
		place = NULL;
	}
	if(time)
	{
		delete [] time;
		time = NULL;
	}
	if(date) 
	{
		delete [] date;
		date = NULL;
	}
	if(description)
	{
		delete [] description;
		description = NULL;
	}
}

void activity::add()	//Adds information about activty into data members
{
	char placeTo[25];
	char timeTo[25];
	char dateTo[25];
	char descriptionTo[25];
	
	cout<<"Enter the place of activity: " << endl;
	cin.get(placeTo, 100);
	cin.ignore(100, '\n');
	
	cout<<"Enter the time of activity: " << endl;
	cin.get(timeTo, 100);
	cin.ignore(100, '\n');
	
	cout<<"Enter the date of activity: " << endl;
	cin.get(dateTo, 100);
	cin.ignore(100, '\n');
	
	cout<<"Enter the description of the activity: " << endl;
	cin.get(descriptionTo, 100);
	cin.ignore(100, '\n');
	
	place = new char[strlen(placeTo) + 1];
	time = new char[strlen(timeTo) + 1];
	date = new char[strlen(dateTo) + 1];
	description = new char[strlen(descriptionTo) + 1];
	
	strcpy(place, placeTo);
	strcpy(time, timeTo);
	strcpy(date, dateTo);
	strcpy(description, descriptionTo);

}

void activity::edit()	//Allows the user to edit certian data members data
{
	int response = 0;
	cout<<"Enter a 1 to edit place" << endl;
	cout<<"Enter a 2 to edit time" << endl;
	cout<<"Enter a 3 to edit date" << endl;
	cout<<"Enter a 4 to edit description" << endl;
	cin>>response;
	cin.ignore(100,'\n');

	char toAdd[25];
	
	if(response == 1)
	{
		delete [] place;
		cout<<"Enter place: " << endl;
		cin.get(toAdd, 100);
		cin.ignore(100, '\n');
		
		place = new char[strlen(toAdd) + 1 ];
		strcpy(place, toAdd);	
	}
	
	if(response == 2)
	{
		delete [] time;
		cout<<"Enter time: " << endl;
		cin.get(toAdd, 100);
		cin.ignore(100, '\n');
		
		time = new char[strlen(toAdd) + 1 ];
		strcpy(time, toAdd);	
	}

	if(response == 3)
	{
		delete [] date;
		cout<<"Enter date: " << endl;
		cin.get(toAdd, 100);
		cin.ignore(100, '\n');
		
		date = new char[strlen(toAdd) + 1 ];
		strcpy(date, toAdd);	
	}
	
	if(response == 4)
	{
		delete [] description;
		cout<<"Enter description: " << endl;
		cin.get(toAdd, 100);
		cin.ignore(100, '\n');
		
		description = new char[strlen(toAdd) + 1 ];
		strcpy(description, toAdd);	
	}
}
void activity::display()	//Displays data members of an activity object
{
	if(place)
		cout<<"Place: " << place << endl;
	if(time)
		cout<<"Time: " << time << endl;
	if(date)
		cout<<"Date: " << date << endl;
	if(description)
		cout<<"Description: " << description << endl;
	
}

int activity::compare(char timeTo[])	//Compares time data member to a time passed in by argument to return a 1 if matching else a 0
{
	if(strcmp(timeTo, time) == 0) return 1;
	else return 0;
}
schoolWork::schoolWork()	//Default constructor for school work class
{
	subject = NULL;
	work = NULL;
}

schoolWork::schoolWork(const schoolWork & source): activity(source), subject(NULL), work(NULL)	//Copy constructor for school work class which uses an initialization list
{
	subject = new char[strlen(source.subject) + 1];
	work = new char[strlen(source.work) + 1];

	strcpy(subject, source.subject);
	strcpy(work, source.subject);
}

schoolWork::~schoolWork()	//Destructor for school work class
{
	if(subject)
		delete [] subject;
	if(work)
		delete [] work;
}

void schoolWork::addSubject()	//Adds subject to subject data member
{
	char subjectTo[25];

	cout<<"Enter subject: " << endl;
	cin.get(subjectTo, 100);
	cin.ignore(100, '\n');
	
	subject = new char[strlen(subjectTo) + 1];
	
	strcpy(subject,subjectTo);
}

void schoolWork::removeSubject()	//Removes subject data member
{
	delete [] subject;
	subject = NULL;
}

void schoolWork::removeWork()	//Removes work data member
{
	delete [] work;
	work = NULL;
}

void schoolWork::addWork()	//Adds work data member 
{
	char workTo[25];

	cout<<"Enter work: " << endl;
	cin.get(workTo, 100);
	cin.ignore(100, '\n');
	
	work = new char[strlen(workTo) + 1];
	
	strcpy(work,workTo);
}

void schoolWork::edit()	//Allows user to edit school work information using remove and add functions
{
	int response = 0;
	cout<<"Enter a 1 to edit school work information"<<endl;
	cout<<"Enter a 2 to edit time, place, date, or description"<<endl;
	cin>>response;
	cin.ignore(100, '\n');

	if(response == 1)
	{
		int secondResponse = 0;
		char toAdd[25];
		cout<<"Enter a 1 to edit subject"<<endl;
		cout<<"Enter a 2 to edit work"<<endl;
		cin>>secondResponse;
		cin.ignore(100, '\n');
		if(secondResponse == 1)
		{
			removeSubject();
			addSubject();	
		}
		if(secondResponse == 2)
		{
			removeWork();
			addWork();
		}
	}
	if(response == 2)
		activity::edit();
}

void schoolWork::display()	//Calls base class function to display activity info then display school work data
{
	activity::display();
	if(subject)
		cout<<"Subject: " << subject << endl;
	if(work)
		cout<<"Work: " << work << endl;
}

screenTime::screenTime()	//Screen time constructor
{
	min = 0;
	max = 0;
}

void screenTime::addMin()	//Adds an int to min data member
{
	cout<<"Enter min number of hours: " << endl;
	cin>> min;
	cin.ignore(100, '\n');
}

void screenTime::addMax()	//Adds a max to max data member
{
	cout<<"Enter max number of hours: " << endl;
	cin>> max;
	cin.ignore(100, '\n');
}

void screenTime::removeMin()	//Removes current min data member
{
	min = 0;
}

void screenTime::removeMax()	//Removes current max data member
{
	max = 0;
}

void screenTime::display()	//Displays min and max data members 
{
	activity::display();
	if(min)
		cout<<"Min: " << min << endl;
	if(max)
		cout<<"Max: " << max << endl;
}

void screenTime::checkForWork(schoolWork workToDo)	//Calls school work display fucntion to let user knw about the schoolwork to do before screen time
{
	cout<<"Before screen time or working out. Finish school work:"<<endl;
	workToDo.display();	
}

void screenTime::edit()	//Allows user to edit screen time data members using the add and remove function
{
	int response = 0;
	cout<<"Enter a 1 to edit screen time information"<<endl;
	cout<<"Enter a 2 to edit time, place, date, or description"<<endl;
	cin>>response;
	cin.ignore(100,'\n');

	if(response == 1)
	{
		int secondResponse = 0;
		cout<<"Enter a 1 to edit min time or 2 to edit max time"<<endl;
		cin>>secondResponse;
		cin.ignore(100, '\n');
	
		if(secondResponse == 1)
		{
			removeMin();
			addMin();
		}
		if(secondResponse == 2)
		{
			removeMax();
			addMax();
		}
	}
	if(response == 2)
		activity::edit();
}

workOut::workOut()	//Constructor for workout class
{
	workOutType = NULL;
	length = 0;
}

workOut::workOut(const workOut & source):activity(source), workOutType(NULL), length(0)	//Copy constructor for workout class which uses and initialization list
{
	workOutType = new char[strlen(source.workOutType) + 1];
	strcpy(workOutType, source.workOutType);
}

workOut::~workOut()	//Destuctor for workout class
{
	delete [] workOutType;
}	

void workOut::addWorkOut()	//Adds workout information to data members 
{
	char workOutTo[25];
	
	cout<<"Add Workout: " << endl;
	cin.get(workOutTo, 100);
	cin.ignore(100, '\n');

	workOutType = new char[strlen(workOutTo) + 1];
	
	strcpy(workOutType, workOutTo);
	
}

void workOut::addLength()	//Adds information about length data member
{
	cout<<"Enter length of workout in minutes: " << endl;
	cin>>length;
	cin.ignore(100,'\n');
}

void workOut::removeWorkOut()	//Removes work out data member
{
	delete [] workOutType;
	workOutType = NULL;
}

void workOut::removeLength()	//Removes length data member
{
	length = 0;
}

void workOut::display()	//Calls base class function to display basic activity info then displays its own data
{
	activity::display();
	cout<<"Work Out: "<< workOutType << endl;
	cout<<"Length: " << length << endl;
}

void workOut::edit()	//Allows user to edit data members using add and remove fucntion
{
	int response = 0;
	cout<<"Enter a 1 to edit work out information"<<endl;
	cout<<"Enter a 2 to edit time, place, date, or description"<<endl;
	cin>>response;
	cin.ignore(100,'\n');

	if(response == 1)
	{
		int secondResponse = 0;
		cout<<"Enter a 1 to edit work out or 2 to edit length"<<endl;
		cin>>secondResponse;
		cin.ignore(100, '\n');
		
		if(secondResponse == 1)
		{
			removeWorkOut();
			addWorkOut();
		}
		if(secondResponse == 2)
		{
			removeLength();
			addLength();
		}
	}
	if(response == 2)
		activity::edit();
}
