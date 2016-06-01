#include<iostream>
using namespace std;

class Kalenderdatum
{
	private:
		//Variablen zum speichern des aktuellen Datums;
		int day, month, year;

	public:
		//Konstruktor für Aufruf ohne Datum
		Kalenderdatum ()
		{
			this->day = 01;
			this->month = 01;
			this->year = 1000;
		}
		//Konstruktor für normalen Aufruf
		Kalenderdatum ( int day, int month, int year )
		{
			this->day = day;
			this->month = month;
			this->year = year;
		}
		//Testausgabe des Datums
		void ausgabe()
		{
			cout << "Datum:  " << day << "." << month << "." << year << "\n";
		}

};


int main ()
{
	//Erstelle Datum ohne Variablen
	Kalenderdatum date1;
	//Erstelle Datum nach Vorgabe
	Kalenderdatum date2(27,04,1999);
	//Testausgabe
	date1.ausgabe();
	date2.ausgabe();
}
