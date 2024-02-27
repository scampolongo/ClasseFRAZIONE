#include <iostream>

using namespace std;

class Frazione {
		int num, den;
	public:

		// Getters

		int getnum() {
			return this->num;
		}

		int getden() {
			return this->den;
		}

		// Setters

		void setnum(int num) {
			this->num = num;
		}

		void setden(int den) { // se si proverà a portare a zero il denominatore rimarrà al valore precedente
			if (den != 0) this->den = den;
		}

		Frazione() { // Costruttore senza parametri
			num = 1, den = 1;
		}

		Frazione(int n, int d) { // Costruttore con tutti i parametri
			set(n, d);
			check();
		}

		void set(int n, int d) {
			num = n;
			den = d;
			check();
		}

		void get() { // %*c --> salta i caratteri
			cout << "Inserisci la frazione (numeratore/denominatore) -> ";
			scanf("%d%*c%d", &num, &den);
		}

		void print() {
			printf("%d/%d", num, den);
		}

		void check() {	// se viene passato un denominatore uguale a zero verrà automaticamente cambiato a 1
			if (den == 0) den = 1;
		}

		Frazione somma(int addendo) {	// Somma intera
			Frazione risultato = Frazione(this->num + (addendo * this->den), this->den);
			risultato.riduzione();
			return risultato;
		}

		Frazione operator+(int addendo) { // Primo overload operatore +
			return somma(addendo);
		}

		Frazione somma(Frazione f2) {	// Somma tra frazioni
			Frazione risultato = Frazione( ((this->den * f2.den / this->den) * this->num) + ((this->den * f2.den / f2.den) * f2.num), this->den * f2.den);
			risultato.riduzione();
			return risultato;
		}

		Frazione operator+(Frazione f2) { // Secondo overload operatore +
			return somma(f2);
		}

		Frazione sottrazione(int sottraendo) {	// Sottrazione intera
			Frazione risultato = Frazione(this->num - (sottraendo * this->den), this->den);
			risultato.riduzione();
			return risultato;
		}

		Frazione operator-(int sottraendo) { // Primo overload operatore -
			return sottrazione(sottraendo);
		}

		Frazione sottrazione(Frazione f2) {	// Sottrazione tra frazioni
			Frazione risultato = Frazione( ((this->den * f2.den / this->den) * this->num) - ((this->den * f2.den / f2.den) * f2.num), this->den * f2.den);
			risultato.riduzione();
			return risultato;
		}

		Frazione operator-(Frazione f2) { // Secondo overload operatore -
			return sottrazione(f2);
		}

		Frazione moltiplicazione(int moltiplicatore) {	// Moltiplicazione intera
			Frazione risultato = Frazione(this->num * moltiplicatore, this->den);
			risultato.riduzione();
			return risultato;
		}

		Frazione operator*(int moltiplicatore) { // Primo overload operatore *
			return moltiplicazione(moltiplicatore);
		}

		Frazione moltiplicazione(Frazione f2) {	// Moltiplicazione tra frazioni
			Frazione risultato = Frazione(this->num * f2.num, this->den * f2.den);
			risultato.riduzione();
			return risultato;
		}

		Frazione operator*(Frazione f2) { // Secondo overload operatore *
			return moltiplicazione(f2);
		}

		Frazione divisione(int divisore) {	// Divisione intera
			Frazione inversa(1, divisore);
			return this->moltiplicazione(inversa);
		}

		Frazione operator/(int divisore) { // Primo overload operatore /
			return divisione(divisore);
		}

		Frazione divisione(Frazione f2) {	// Divisione tra frazioni
			Frazione inversa(f2.den, f2.num);
			return this->moltiplicazione(inversa);
		}

		Frazione operator/(Frazione f2) { // Secondo overload operatore /
			return divisione(f2);
		}

		friend istream & operator>>(istream &in,  Frazione &f) {
			cout << "Numeratore --> ";
			in >> f.num;
			cout << "Denominatore --> ";
			in >> f.den;
			f.check();
			in.get();   // pesco invio pendente... problema come in scanf()
			return in;  // per impilare eventualmente come cin >> f1 >> f2;
		}

		friend ostream & operator<<(ostream &out,  Frazione &f) {
			f.print();
			return out;  // per impilare eventualmente come cout << f1 << f2;
		}

		int mcd(int a, int b) {
			while (b != 0) {
				int temp = b;
				b = a % b;
				a = temp;
			}
			return a;
		}

		void riduzione(void) {
			int MCD = mcd(this->num, this->den);
			this->num /= MCD;
			this->den /= MCD;
		}

		double decimale(void) {
			return double(this->num) / double(this->den);
		}

};
