#include "Statystyki.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
void Statystyka::Procenty()
{
    double stosunek_dobry, stosunek_zly;
    cout << "Ilość odpowiedzi: " << this->Odpowiedzi << endl;
    cout << "Ilość poprawnych odpowiedzi: " <<this->Dobre << endl;
    cout << "Ilość błędnych odpowiedzi: " <<this->Zle << endl;
    stosunek_dobry=((double)this->Dobre/this->Odpowiedzi)*100;
    cout << "Procent poprawnych odpowiedzi: " << stosunek_dobry <<"%"<<endl;
    stosunek_zly=((double)this->Zle/this->Odpowiedzi)*100;
    cout << "Procent błędnych odpowiedzi: " << stosunek_zly <<"%"<<endl;

}