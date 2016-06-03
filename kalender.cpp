#include<iostream>
#include<math.h>
using namespace std;

class Kalenderdatum
{
	private:
		//Int zum Durchzählen der Tage ab 1.1. -4712 Chr.;
		long int lt;
		//Variablen für die Umrechnung in Gregorianischen und Julianischen Kalender
		int day_greg, day_jul, month_greg, month_jul, year_greg, year_jul;
		//Berechnet Monatskorrektur mk für Julianischen Kalender
		int get_mk(){
			int mk;
			switch (month_jul){
				case 1 : mk=-1;
					break;
				case 3 : mk=-2;
					break;
				case 4 : mk=-1;
					break;
				case 5 : mk=-1;
					break;
				case 8 : mk=1;
					break;
				case 9 : mk=2;
					break;
				case 10 : mk=2;
					break;
				case 11 : mk=3;
					break;
				case 12 : mk=3;
					break;
				default : mk=0;
			}
			return mk;
			}
	public:
		//Konstruktor für Aufruf mit Konsoleneingabe
		Kalenderdatum()
		{
			lt=1;
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
			int sk, mk, N4, N1;
			//Setzt sk auf 1 wenn Schaltjahr und Monat nach Februar liegt
			if ( (month_jul > 2 && (year_jul<0 && (abs(year_jul%4)==1))) || (year_jul>0 && (year_jul%4==0)) ){
				sk=1;
			}
			else{
				sk=0;
			}
			//Setzt die Korrektur der Tage je nach Monat
			mk = get_mk();
			//Testausgabe von sk und mk
			cout << "sk: " << sk << "\nmk: " << mk << "\n";
			tag = day_jul + 30*(month_jul-1) + sk + mk;
			jahr = 4715 + year_jul;
			if ( year_jul < 0 ){
			jahr++;}
			/*if ( year_jul > 0 ){
			jahr = 4715 + year_jul;}
			else {
			jahr = 4716 + year_jul;}*/
			N4 = jahr/4;
			N1 = jahr%4;
			if ( N1 == 4 ){
				N1 = 3;
				tag = 365;
			}
			//Testausgabe von tag jahr n4 n1
			cout << "tag: " << tag << "\njahr: " << jahr << "\nn4: " << N4 << "\nn1: " << N1 << "\n";
			rueck = 1461*N4 + 365*(N1-3) + tag;
			return rueck;
		}
		//Umrechnung von Datum im Gregorianischen Kalender in laufende Tage lt
		long int greg_to_lt(){
			//Ausgabevariable
			long int rueck;
			//Hilfsvariablen für die Rechnungen
			int sk, mk, N4, N1, tag, jahr;
			//Setzt sk auf 1 wenn Schaltjahr und Monat nach Februar liegt
			if ( (month_jul > 2 && (year_jul<0 && (abs(year_jul%4)==1))) || (year_jul>0 && (year_jul%4==0)) ){
				sk=1;
			}
			else{
				sk=0;
			}
			//Testausgabe von sk und mk
			cout << "sk: " << sk << "\nmk: " << mk << "\n";
			tag = day_jul + 30*(month_jul-1) + sk + mk;
			jahr = 4715 + year_jul;
			if ( year_jul < 0 ){
			jahr++;}
			/*if ( year_jul > 0 ){
			jahr = 4715 + year_jul;}
			else {
			jahr = 4716 + year_jul;}*/
			N4 = jahr/4;
			N1 = jahr%4;
			if ( N1 == 4 ){
				N1 = 3;
				tag = 365;
			}
			//Testausgabe von tag jahr n4 n1
			cout << "tag: " << tag << "\njahr: " << jahr << "\nn4: " << N4 << "\nn1: " << N1 << "\n";
			rueck = 1461*N4 + 365*(N1-3) + tag;
			return rueck;
		}
		//Umrechnung von laufendem Tag ab 1.1.... in jul. Datum
		void lt_to_jul(){
			//Hilfsvariablen
			int sk, mk, N4, R4, N1, tag, jahr;
			N4 = ( lt + 1095) / 1461;
			R4 = ( lt + 1095) % 1461;
			N1 = R4 / 365;
			tag = R4 - N1*365;
			if ( N1 == 4 ){
				N1 = 3;
				tag = 365;
			}
			jahr = 4 * N4 + N1;
			if ( jahr <= 4715){
			year_jul = -( 4716 - jahr);}
			else{
			year_jul = jahr - 4715;}
			cout << "year_jul: " << year_jul << "\n";
			month_jul = ( tag + 1 ) / 30 + 1;
			//sk und mk berechnen wie vorher
			if ( (month_jul > 2 && (year_jul<0 && (abs(year_jul%4)==1))) || (year_jul>0 && (year_jul%4==0)) ){
				sk=1;
			}
			else{
				sk=0;
			}
			mk = get_mk();
			day_jul = tag - 30*(month_jul-1) - (sk + mk);
			if ( (month_jul > 12) || (day_jul < 1)){
			month_jul = month_jul - 1;
			mk = get_mk();
			day_jul = tag - 30*(month_jul-1) - (sk + mk);
			}
			cout << "tag: " << tag << "\njahr: " << jahr << "\nn4: " << N4 << "\nn1: " << N1 << "\nR4: " << R4 << "\nsk: "<< sk << "\nmk: " << mk << "\n";
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
		void einlesen_greg(){
			cout << "Geben Sie ein Gregorianisches Datum ein.\n Bitte hintereinander Tag, Monat und Jahr eingeben:\n";
			cin >> day_greg;
			cin >> month_greg;
			cin >> year_greg;
		}
		void einlesen_days(){
			cout << "Geben Sie eine Anzahl an Tagen ein, die seit dem 01.01.4715 v.Chr. vergangen sind.\n";
			cin >> lt;
		}
		void jul_to_days(){
			cout << "Für das eingegebene Julianische Datum sind seit dem 01.01.4713 v.Chr. " << jul_to_lt() << " Tage vergangen.\n";
		}
		void greg_to_days(){
			cout << "Für das eingegebene Gregorianische Datum sind seit dem 01.01.4713 v.Chr. " << greg_to_lt() << " Tage vergangen.\n";
		}
		void days_to_jul(){
			cout << lt << " Tage nach dem 01.01.4715 v.Chr. ist der " << day_jul << "." << month_jul << "." << year_jul << " im Julianischen Kalender.\n";
		}
};

int main (){
		//Test für Julianisches Datum in Tage
		/*Kalenderdatum date1(34324234);
		date1.einlesen_jul();
		date1.jul_to_days();*/
		
		
		//Test für Gregorianisches Datum in Tage
		/*Kalenderdatum date2();
		date2.einlesen_greg();
		date2.greg_to_days();*/
		
		
		//Test für Tage in Julianisches Datum
		/*Kalenderdatum date3(13);
		date3.einlesen_days();
		date3.lt_to_jul();
		date3.days_to_jul();*/
}