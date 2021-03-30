#include "Statystyki.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
void Procenty(Statystyka punkty)
{
    double stosunek_dobry, stosunek_zly;
    cout << "Ilość odpowiedzi: " << punkty.Odpowiedzi << endl;
    cout << "Ilość poprawnych odpowiedzi: " <<punkty.Dobre << endl;
    cout << "Ilość błędnych odpowiedzi: " <<punkty.Zle << endl;
    stosunek_dobry=((double)punkty.Dobre/punkty.Odpowiedzi)*100;
    cout << "Procent poprawnych odpowiedzi: " << stosunek_dobry <<"%"<<endl;
    stosunek_zly=((double)punkty.Zle/punkty.Odpowiedzi)*100;
    cout << "Procent błędnych odpowiedzi: " << stosunek_zly <<"%"<<endl;

}