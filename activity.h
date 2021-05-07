/*
Storm Crozier
7/9/2020
This is the activity.h file which defines the base activity class and the 3 derived classes to represent different activities with different data members and similar functions
*/
#include <iostream>
#include <cctype>
#include <cstring>

class activity	//This is the base class which has basic information about an activity like place, time, date, and a small description
{
	public:
		activity();
		~activity();
		activity(const activity & source);
		void display();
		void add();
		void remove();
		void edit();
		int compare(char timeTo[]);
		
	protected:
		char * place;
		char * time;
		char * date;
		char * description;
};

class schoolWork: public activity	//This is the school work class which is an activiy plus a subject and work members 
{
	public:
		schoolWork();
		~schoolWork();
		schoolWork(const schoolWork & source);
		void addSubject(); 
		void removeSubject();
		void addWork();
		void removeWork();
		void display();
		void edit();
	protected:
		char * subject;
		char * work;
};

class screenTime: public activity	//This is the screen time class which is derived from the activty class and has a min and max time 
{
	public:
		screenTime();
		void addMin();
		void addMax();
		void removeMin();
		void removeMax();
		void display();
		void edit();
		void checkForWork(schoolWork workToDo);
	protected:
		int min;
		int max;
		
};

class workOut: public activity	//This is the work out class which is also an activity class whith a workout type and length members
{
	public:
		workOut();
		~workOut();	
		workOut(const workOut & source);
		void addWorkOut();
		void removeWorkOut();
		void addLength();
		void removeLength();
		void display();
		void edit();
	private:
		char * workOutType;
		int length;
};
