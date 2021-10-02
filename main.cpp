#include <iostream>

//Includo header Windows.h per poter impostare UTF8 su windows
#ifdef _WINDOWS
    #include <Windows.h>
#endif

using namespace std;

void waitForKey() {
    #ifdef _WINDOWS
        system("PAUSE");
    #else
        //Ignoro gli endl o "\n" dei cout precedenti
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        do {
            cout << "Premi Enter per terminare il programma.";
        } while (cin.get() == NULL);
    #endif
}

int main() {
    //Imposto UTF8 con un comportamento diverso in base al target
    #ifdef _WINDOWS
        SetConsoleOutputCP(CP_UTF8);
    #else
        setlocale(LC_ALL, "utf-8");
    #endif


    int precedentTickN, actualTickN;
    float singleTelephoneTickPrice, lockedPrice;

    cout << "Inserisici il numero di scatti precenti: ";
    cin >> precedentTickN;
    cout << "Inserisici il numero di scatti attuali: ";
    cin >> actualTickN;
    cout << "Inserisici il prezzo del singolo scatto: ";
    cin >> singleTelephoneTickPrice;
    cout << "Inserisici il canone fisso: ";
    cin >> lockedPrice;

    cout << "Canone: " << lockedPrice << "€" << endl;
    cout << "Importo da pagare: " << (actualTickN - precedentTickN) * singleTelephoneTickPrice + lockedPrice << "€"
         << endl;

    //Funzione per aspettare per l'utente che funziona anche su linux (vedere su)
    waitForKey();
    return 0;
}