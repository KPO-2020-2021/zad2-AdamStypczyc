#include "Statystyki.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
void Procenty(Statystyka punkty)
{
    double stosunek;
    cout << "Ilość odpowiedzi: " << punkty.Odpowiedzi << endl;
    cout << "Ilość poprawnych odpowiedzi: " <<punkty.Dobre << endl;
    cout << "Ilość błędnych odpowiedzi: " <<punkty.Zle << endl;
    stosunek=((double)punkty.Dobre/punkty.Odpowiedzi)*100;
    cout << "Procent poprawnych odpowiedzi: " << stosunek <<"%"<<endl;
}