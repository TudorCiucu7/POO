#include <iostream>
using namespace std;

class Masina {
    string Marca;
    string Model;
    int anFabricatie;
    float pretAchizitie;
public:

    Masina() {
        this->Marca = "null";
        this->Model = "null";
        this->anFabricatie = 0;
        this->pretAchizitie = 0;
    }

    Masina(string _Marca, string _Model, int _anFabricatie, float _pretAchizitie) {
        this->Marca = _Marca;
        this->Model = _Model;
        this->anFabricatie = _anFabricatie;
        this->pretAchizitie = _pretAchizitie;
    }

    //CONSTRUCTOR COPIERE

    Masina(const Masina& m) {
        this->Marca = m.Marca;
        this->Model = m.Model;
        this->anFabricatie = m.anFabricatie;
        this->pretAchizitie = m.pretAchizitie;
    }

    //OPERATOR=

    Masina& operator=(const Masina& m) {
        if (this == &m)
            return *this;
        else {
            this->Marca = m.Marca;
            this->Model = m.Model;
            this->anFabricatie = m.anFabricatie;
            this->pretAchizitie = m.pretAchizitie;
        }
        return *this;
    }
    //GETTERI SETTERI : string _Marca, string _Model, int _anFabricatie, float _pretAchizitie

    string GetMarca() {
        return this->Marca;
    }
    string getModel() {
        return this->Marca;
    }
    int getAnFabricatie() {
        return this->anFabricatie;
    }
    int getPretAchizitie() {
        return this->pretAchizitie;
    }

    void setMarca(string _Marca) {
        this->Marca = _Marca;
    }
    void setModel(string _Model) {
        this->Model = _Model;
    }
    void setAnFabricatie(int _anFabricatie) {

        this->anFabricatie = _anFabricatie;
    }
    void setPretAchizitie(float _pretAchizitie) {
        this->pretAchizitie = _pretAchizitie;
    }
    



    //OPERATOR<<

    friend ostream& operator<<(ostream& out, const Masina& m) {
        out << m.Marca << m.Model << m.anFabricatie << m.pretAchizitie;
        return out;
    }

    friend istream& operator>>(istream& in, Masina& m) {
        in>> m.Marca >> m.Model >> m.anFabricatie >> m.pretAchizitie;
        return in;
    }

};

//GARAJ HAS A MASINA

class Garaj {
    string NumeGaraj;
    string Locatie;
    int NrMasini;
    Masina* listaMasini[100];
    int CapacitateMaxima;

public:

    Garaj() {
        this->NumeGaraj = "null";
        this->Locatie = "null";
        this->NrMasini = 0;
        this->CapacitateMaxima = 1;
    }


    Garaj(string _NumeGaraj, string _Locatie,  int _CapacitateMaxima) {
        this->NumeGaraj = _NumeGaraj;
        this->Locatie = _Locatie;
        this->NrMasini = 0;
        this->CapacitateMaxima = _CapacitateMaxima;
    }

    //CONSTRUCTOR COPIERE


    Garaj(const Garaj& g) {
        this->NumeGaraj = g.NumeGaraj;
        this->Locatie = g.Locatie;
        this->CapacitateMaxima = g.CapacitateMaxima;
        if (this->NrMasini <= 0)
            this->NrMasini = 0;
        else
        {
            this->NrMasini = g.NrMasini;
            for (int i = 0;i < this->NrMasini;i++)
                this->listaMasini[i] = new Masina(*g.listaMasini[i]);
        }
    }

    //OPERATOR=

    Garaj& operator=(const Garaj& g) {
        if (this == &g)
            return *this;
        if (this->NrMasini > 0) {
            for (int i = 0;i < this->NrMasini;i++) {
                delete[] this->listaMasini[i];
                this->listaMasini[i] = nullptr;
            }
       }
        this->NumeGaraj = g.NumeGaraj;
        this->Locatie = g.Locatie;
        this->CapacitateMaxima = g.CapacitateMaxima;
        if (g.NrMasini <= 0)
            this->NrMasini = 0;
        else {
            this->NrMasini = g.NrMasini;
            for (int i = 0;i < this->NrMasini;i++)
                this->listaMasini[i] = new Masina(*g.listaMasini[i]);
        }

    }

    friend ostream& operator<<(ostream& out, const Garaj& g) {
        out << g.NumeGaraj << g.Locatie << g.CapacitateMaxima;
        for (int i = 0;i < g.NrMasini;i++) {
            out << " :" << * g.listaMasini[i] << endl;
        }
        return out;
    }

    //GETTER NR MASINI

    float getNrMasini() {
        int contorMasini = 0;;
        for (int i = 0;i < this->NrMasini;i++)
            contorMasini++;
        return contorMasini;

    }

    //OPERATOR +=

    void operator+=(const Masina& m) {
        if (this->getNrMasini() >= this->CapacitateMaxima)
            throw new exception("Garajul e full");
        this->listaMasini[this->NrMasini] = new Masina(m);
        this->NrMasini++;
        
    }
    //DESTRUCTOR

    ~Garaj() {
        if(this->NrMasini > 0)
            for (int i = 0;i < this->NrMasini;i++) {
                delete[] this->listaMasini[i];
                this->listaMasini[i] = nullptr;
            }
    }


};


int main()
{
    Masina m1("vw ", "arteon  ", 2020   , 34500.50);
    Masina m2("dacia ", "logan ", 2019   , 10900.89);
    Garaj garaj("Garaj Tudor  ", "Bucuresti  ", 2);
    cout << garaj << endl;
    garaj += m1;
    garaj += m2;
    cout << garaj <<endl;
    return 0;


}

