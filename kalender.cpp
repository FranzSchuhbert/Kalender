#include<iostream>
using namespace std;

class Kalenderdatum
{
	private:
		//Int zum Durchzählen der Tage ab 1.1. -4712 Chr.;
		long int lt;
		//Variablen für die Umrechnung in Gregorianischen und Julianischen Kalender
		int day_greg, day_jul, month_greg, month_jul, year_greg, year_jul;
	public:
		//Konstruktor für Aufruf mit Konsoleneingabe
		Kalenderdatum()
		{
			
		}
		//Konstruktor für normalen Aufruf
		Kalenderdatum( int lt )
		{
			this->lt = lt;
		}
		//Umrechnung von Datum im Julianischem Kalender in laufende Tage lt
		long int jul_to_lt(){
			//Ausgabevariable
			long int rueck, tag, jahr;
			//Hilfsvariablen für die Rechnungen
			int sk, mk, N4, R4, N1;
			//Setzt sk auf 1 wenn Schaltjahr und Monat nach Februar liegt
			if ( month_jul > 2 && (year_jul<0 && (year_jul%4==1)) || (year_jul>0 && (year_jul%4==0)) ){
				sk=1;
			}
			else{
				sk=0;
			}
			//Setzt die Korrektur der Tage je nach Monat
			switch (month_jul){
				case 1 : mk=-1;
				case 3 : mk=-2;
				case 4 : mk=-1;
				case 5 : mk=-1;
				case 8 : mk=1;
				case 9 : mk=2;
				case 10 : mk=2;
				case 11 : mk=3;
				case 12 : mk=3;
				default : mk=0;
			}
			tag = day_jul + 30*(month_jul-1) + sk + mk;
			jahr = 4715 + year_jul;
			N4 = jahr/4;
			N1 = jahr%4;
			rueck = 1461*N4 + 365*(N1-3) + tag;
			return rueck;
		}
		//Funktionen zum einlesen und ausgeben der Daten
		void ausgabe_greg()
		{
			cout << "Gregorianisches Datum:  " << day_greg << "." << month_greg << "." << year_greg << "\n";
		}
		void ausgabe_jul()
		{
			cout << "Julianisches Datum:  " << day_jul << "." << month_jul << "." << year_jul << "\n";
		}
		void einlesen_jul(){
			cout << "Geben Sie ein Julianisches Datum ein.\n Bitte hintereinander Tag, Monat und Jahr eingeben:\n";
			cin >> day_jul;
			cin >> month_jul;
			cin >> year_jul;
		}
		void jul_to_days(){
			cout << "Für das eingegebene Julianische Datum sind seit dem 01.01.4713 v.Chr. " << jul_to_lt() << " Tage vergangen.\n";
		}
};

int main (){
		Kalenderdatum date1(34324234);
		date1.einlesen_jul();
		date1.jul_to_days();
}