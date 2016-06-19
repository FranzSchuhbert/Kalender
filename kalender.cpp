#include "kalender.h"
using namespace std;

int main (){
	
		//Erstelle zwei Kalenderobjekte
		Kalenderdatum date1;
		Kalenderdatum date2;
		//Test für Error Nr. 1
		Kalenderdatum date3(27, 04, 1965, "d");
		// Test für das Osterdatum
		Kalenderdatum date4(27, 04, 1965, "j");
		int *ostern;
		ostern	=	date4.easterdate();
		cout << "Ostern Fällt auf den " << ostern[1] << "." << ostern[2] << "\n";
		
		/*//Entscheidung was man machen will und ausführen
		int decide = 3;
		cout << "Was möchten Sie berechnen? Bitte wählen Sie\n1) Für das Umwandeln eines Datums in einen anderen Kalender\n2) Für die Berechnung eines Abstandes zweier Daten\n";
		while ( (decide<1)||(decide>2)){
			cin >> decide;
			cout << "\n";
			switch ( decide ){
			case 1 :	date1.inputform();
					date1.outputform();
				break;
			case 2 :	cout << "Geben Sie das erste Datum ein: \n";
					date1.inputform();
					cout << "Geben Sie das zweite Datum ein: \n";
					date2.inputform();
					ausgabe_abstand(date1, date2);
				break;
		default : cout << "Ungültige Auswahl, bitte nochmal\n1) Für das Umwandeln eines Datums in eine andere Form\n2) Für die Berechnung eines Abstandes zweier Daten\n";
			}
		}*/
}
