// Autore: G.Campolongo - Data ultima modifica: 16/02/24
// Breve descrizione del programma: Verifica 4B INF

#include "frazione.h"

void menu(void) {
	cout << endl;
	cout << "1) Input frazione\n";
	cout << "2) Output frazione\n";
	cout << "3) Cambia il numeratore\n";
	cout << "4) Cambia il denominatore\n";
	cout << "5) Calcola il valore decimale\n";
	cout << "6) Somma\n";
	cout << "7) Sottrazione\n";
	cout << "8) Moltiplicazione\n";
	cout << "9) Divisione\n";
	cout << "0) Esci\n";
}

int scelta() {
	int sc;
	cout << "\nInserire una scelta: ";
	cin >> sc;
	return sc;
}

int main() {

	int sc;
	int num;
	int den;
	char opzione;
	Frazione f, f1, f2;

	do {

		menu();

		sc = scelta();

		switch (sc) {

			case 1:
				cin >> f;
				break;

			case 2:
				cout << "\n[" << f << "]\n";
				break;

			case 3:
				cout << "Inserisci il nuovo numeratore -> ";
				cin >> num;
				f.setnum(num);
				cout << "Numeratore cambiato, nuova frazione: ";
				cout << f << endl;
				break;

			case 4:
				cout << "Inserisci il nuovo denominatore -> ";
				cin >> den;
				f.setden(den);
				cout << "Denominatore cambiato, nuova frazione: ";
				cout << f << endl;
				break;

			case 5:
				cout << "Il valore decimale della frazione " << f << " e' " << f.decimale() << endl;
				break;

			case 6:
				cout << "Vuoi sommare un numero intero (i) o una frazione (f) ? -> ";
				cin >> opzione;
				if (opzione == 'i') {
					cout << "Inserisci il numero intero al quale sommare la frazione -> ";
					cin >> num;
					f2 = f + num;
					cout << "Risultato = " << f2 << endl;
				} else if (opzione == 'f') {
					cout << "Inserisci la frazione:\n";
					cin >> f1;
					f2 = f + f1;
					cout << "Risultato = " << f2 << endl;
				} else cout << "Scelta errata, ritorno al menu" << endl;
				break;

			case 7:
				cout << "Vuoi sottrarre un numero intero (i) o una frazione (f) ? -> ";
				cin >> opzione;
				if (opzione == 'i') {
					cout << "Inserisci il numero intero al quale sottrarre la frazione -> ";
					cin >> num;
					f2 = f - num;
					cout << "Risultato = " << f2 << endl;
				} else if (opzione == 'f') {
					cout << "Inserisci la frazione:\n";
					cin >> f1;
					f2 = f - f1;
					cout << "Risultato = " << f2 << endl;
				} else cout << "Scelta errata, ritorno al menu" << endl;
				break;

			case 8:
				cout << "Vuoi moltiplicare per un numero intero (i) o una frazione (f) ? -> ";
				cin >> opzione;
				if (opzione == 'i') {
					cout << "Inserisci il numero intero per il quale moltiplicare la frazione -> ";
					cin >> num;
					f2 = f * num;
					cout << "Risultato = " << f2 << endl;
				} else if (opzione == 'f') {
					cout << "Inserisci la frazione:\n";
					cin >> f1;
					f2 = f * f1;
					cout << "Risultato = " << f2 << endl;
				} else cout << "Scelta errata, ritorno al menu" << endl;
				break;

			case 9:
				cout << "Vuoi dividere per un numero intero (i) o una frazione (f) ? -> ";
				cin >> opzione;
				if (opzione == 'i') {
					cout << "Inserisci il numero intero per il quale dividere la frazione -> ";
					cin >> num;
					f2 = f / num;
					cout << "Risultato = " << f2 << endl;
				} else if (opzione == 'f') {
					cout << "Inserisci la frazione:\n";
					cin >> f1;
					f2 = f / f1;
					cout << "Risultato = " << f2 << endl;
				} else cout << "Scelta errata, ritorno al menu" << endl;
				break;

			case 0:
				cout << "Uscita dal programma...\n";
				break;

			default:
				cout << "Scelta non valida. Riprova.\n";

		}

	} while (sc != 0);

	return 0;

}
