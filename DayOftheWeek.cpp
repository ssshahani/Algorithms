
#include <iostream>
#include <stdio.h>
#include <ctime>

using namespace std;
//Date Object
struct Date{
	int year;
	int month;
	int date;
//Parameterized Constructor
	Date(int y, int m, int d){
		year = y;
		month =m;
		date =d;
	}
};
//Function to read the date
Date getDate(){
	int y,m,d;
	cin>>y>>m>>d;
	return Date(y,m,d);
}
//Function to print the date in given format
void printDate(Date d){
	//cout<<d.month<<"\\"<<d.date<<"\\"<<d.year<<"\n";
	printf("%02d/%02d/%4d \n",d.month,d.date,d.year);
}
//Utility function to check if a year is leap
//Difference between Gregorian calender and Julian calender is that
//Gregorian calender is more close to solar year i.e no. of days is 365.24 < 365.25
//therefore every 400 years there 97 leap years and not 100
bool checkLeapYear(int year){
	if(year%400 == 0)
		return true;
	
	if(year%100 == 0)
		return false;
	
	if(year%4 4 == 0)
		return true;
}
// Utility function to get the dat of the week
//TODO: the function is not giving correct index for leap year Eg: 02/29/2020. It is giving Friday instead of Saturday
int getDayofTheWeek(Date d){

	//initialize to local time
	time_t now = time(NULL);
	tm* sTm; // this pointer to structure variable holds all information about time-stamp,time and date.
	sTm = localtime(&now); // initialize to localtime

	int year = d.year - 1900; //This is when gregorian calender was brought into existance
	int month = d.month - 1; //month of the year ranges from 0 to 11
	int date = d.date; // date of the day.

	sTm->tm_year = year;
	sTm->tm_mon = month;
	sTm->tm_mday = date;

	mktime(sTm); // we pass the pointer to mktime and that points to an object which will return us the index of week day

	const char* weekday[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

	//printf("The day of the week is %s",weekday[sTm->tm_wday]);
	return sTm->tm_wday; //week day index returned.
}
// this function, pass by pointer to update the date of next immediate Monday for a given date.
void update(Date* d, int iNextMonDate,int iEndDay){
	if(iNextMonDate >=iEndDay && d->month == 12){
		d->date = (iNextMonDate - iEndDay);
		d->month = 1;
		d->year += 1;
		return;
	}
	if(iNextMonDate <= iEndDay)
		d->date = iNextMonDate;
	else
	{
		d->date = (iNextMonDate - iEndDay);
		d->month += 1;
	}
}
// function updates the date object entered by user to the next immediate Monday
void getDateofImmediateMonday(Date d2){
	typedef enum eMonthName {Jan = 0,
							 Feb,
							 Mar,
							 Apr,
							 May,June,July,Aug,Sep,Oct,Nov,Dec}MonthName;
	MonthName eMname;
	eMname = static_cast<MonthName>((d2.month) - 1);
	int wDay = getDayofTheWeek(d2);
	int diff = 0;
	// we calculate the difference between next Monday and present day
	if(wDay > 1)
		diff = 8-wDay;
	else if(wDay < 1)
		diff = 1;
	else if(wDay == 1)
		diff = 7;
	//date of next Monday
	int mDay = d2.date;
	int iNextMondayDate = mDay+diff;
	int iEndDate =31;
	//cases over different months
	switch(eMname)
	{
		case Jan:
		case Mar:
		case May:
		case July:
		case Aug:
		case Oct:
		case Dec:
			update(&d2,iNextMondayDate,iEndDate);
			break;
		case Feb:
			if(checkLeapYear(d2.year))
			{
				iEndDate = 29;
				update(&d2,iNextMondayDate,iEndDate);
			}
			else
			{
				iEndDate = 28;
				update(&d2,iNextMondayDate,iEndDate);
			}
			break;
		case Apr:
		case June:
		case Sep:
		case Nov:
			iEndDate = 30;
			update(&d2,iNextMondayDate,iEndDate);
			break;
		default:
			cout <<" Bye-Bye" <<endl;
	}

}
//Main functionality
int main(){
	Date d(2008,11,8);
	printDate(d);
	Date d2 = getDate();
	getDayofTheWeek(d2);
	getDateofImmediateMonday(d2);
	printDate(d3);
	return 0;
}
