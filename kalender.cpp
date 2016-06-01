#include<iostream>
using namespace std;

class Kalenderdatum
{
	private:
		//Variablen zum speichern des aktuellen Datums;
		int day, month, year;
		//Variable für die while Schleife
		int i=1;
	public:
		//Konstruktor für Aufruf mit Konsoleneingabe
		Kalenderdatum()
		{
			//Schleife, die solange eingeben lässt bis ein gültiges Datum vorliegt
			while ( i==1 )
			{
				cout << "Bitte hintereinander Tag, Monat und Jahr eingeben:\n";
				cin >> this->day;
				cin >> this->month;
				cin >> this->year;
				//Checkt ob das eingegebene Datum korrekt ist
				if ( (month < 13 && month > 0)											//Checkt ob Monat zwischen 1-12 liegt
					&& ((month==1||month==3||month==5||month==7||month==8||month==11||month==12) && day<32 && day>0)	//Checkt für entsprechende Monte ob Tage zw 1-31 liegen
					|| (month==2 && day<29 && day>0)									//Checkt ob für Februar Tage zw 1-28 liegen
					|| ((month==4||month==6||month==9||month==11) && day<31 && day >0))					//Checkt ob in restlichen Monaten tage zw 1-30 liegen
				{
					cout << "Das eingegebene Datum ist korrekt\n";
					i = 0;
				}
				else
				{
					cout << "Kein gültiges Datum eingegeben!\n";
					i = 1;
				}
			}
		}
		//Konstruktor für normalen Aufruf
		Kalenderdatum( int day, int month, int year )
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
	Kalenderdatum date2(27,04,1993);
	//Testausgabe
	date1.ausgabe();
	date2.ausgabe();
}
