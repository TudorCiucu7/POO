
#include <iostream>
using namespace std;

class Angajat {
protected:
    string Nume = "Anonim";
    float salariuBaza = 0;
public:
    Angajat() {
        cout << "\n Apel constructor fara param";

    }


    Angajat(string _nume, float _salariuBaza) {
        cout << "\nApel constructor cu param";
        this->Nume = _nume;
        this->salariuBaza = _salariuBaza;
    }

    //CONSTRUCTOR COPIERE

    Angajat(const Angajat& a) {
        this->Nume = a.Nume;
        this->salariuBaza = a.salariuBaza;

    }

    //OPERATOR =

    Angajat& operator=(const Angajat& a) {
        if (this == &a)
            return *this;
        else
            this->Nume = a.Nume;
        this->salariuBaza = a.salariuBaza;

    }
    friend ostream& operator<<(ostream& out, const Angajat& a) {
        cout<<"\n APEL OPERATOR <<";
        out << a.Nume << a.salariuBaza;
        return out;
    }
    friend istream& operator>>(istream& in, Angajat& a) {
        cout << "\nintroduceti numele";
        in >> a.salariuBaza;
        cout << "\nintroduceti salariu baza";
        in >> a.salariuBaza;
        return in;

    }
    ~Angajat() {
        
    }

    bool operator==(const Angajat& a) {
        if (this->Nume != a.Nume)
            return false;
            if (this->salariuBaza != a.salariuBaza)
                return false;
        return true;
    }

};

//MANAGER IS A ANGAJAT
//MANAGER HAS A LISTA DE ANGAJATI


class Manager: public Angajat {
    int nrSubalterni;
    Angajat listaAngajati[10];
public:
    
    Manager() :Angajat() {
        this->nrSubalterni = 0;
    }

    Manager(string _nume, float _salariuBaza,int _nrSubalterni, Angajat _listaAngajati[10]) :Angajat(_nume, _salariuBaza) {
        this->nrSubalterni = _nrSubalterni;
        for (int i = 0;i < this->nrSubalterni;i++)
            this->listaAngajati[i] = _listaAngajati[i];
    }

    //CONSTRUCTOR COPIERE

    Manager(const Manager& m):Angajat(m) {
        this->nrSubalterni = m.nrSubalterni;
        for (int i = 0;i < this->nrSubalterni;i++)
            this->listaAngajati[i] = m.listaAngajati[i];
    }

    //OPERATOR EGAL

    Manager& operator=(const Manager& m) {
        if (this == &m)
            return *this;
        else
            Angajat:operator=(m);
            this->nrSubalterni = m.nrSubalterni;
            for (int i = 0;i < this->nrSubalterni;i++)
                this->listaAngajati[i] = m.listaAngajati[i];
    }
    ~Manager() {
      //  if (this->nrSubalterni <= 0)
           // this->nrSubalterni = 0;
       // else
          //  for (int i = 0;i < this->nrSubalterni;i++)
           //     delete this->listaAngajati[i]
    }

    friend ostream& operator<<(ostream& out, const Manager& m) {
        out << (Angajat)m;//upcast prin valoare explicit
        out << "\nNr subalterni: " << m.nrSubalterni;
        out << "\nLista subalterni: ";
        for (int i = 0; i < m.nrSubalterni; i++)
            out << m.listaAngajati[i];
        return out;
    }

    friend istream& operator>>(istream& in, Manager& m) {
        in >> (Angajat&)m;//upcast prin referinta explicit
        cout << "\nIntroduceti nr subalterni: ";
        in >> m.nrSubalterni;
        for (int i = 0; i < m.nrSubalterni; i++) {
            cout << "subaltern[" << i << "]=";
            in >> m.listaAngajati[i];
        }
        return in;
    }

    bool operator==(const Manager& m) {
        if (Angajat::operator==(m) == false)
            return false;
        if (this->nrSubalterni != m.nrSubalterni)
            return false;

        return true;
    }


};

int main()
{
    Angajat a1("Gigel", 1200);
    Manager m1;
    Manager m2("COSTEL", 1500, 0, nullptr);
    Manager m3(m2);
    cout << m1;
    cin >> m1;
    cout << m1;
    return 0;
}
