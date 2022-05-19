/*

Naziv projekta - Iksoks
Skola - Peta gimnazija II-5

*/
#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <limits>

using namespace std;

class iksoks
{
   
    char polje[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};


    struct aiIgrac
    {

        int izbor = 0;    

    };

    // Implementacija minimax algoritma

    aiIgrac minimax()
    {

        int rezultat = numeric_limits<int>::max();
        aiIgrac potez;

        for (int i=0; i<9; ++i)
        {

            if (polje[i] == ' ')
            {

                polje[i] = 'O';

                int temp = maxPretraga();

                if (temp < rezultat)
                {

                    rezultat = temp;
                    potez.izbor = i;

                }

                polje[i] = ' ';

            }

        }

        return potez;

    }

    int maxPretraga()
    {

        if (odredi_pobjednika()=='X'){return 10;}
        else if (odredi_pobjednika()=='O'){return -10;}
        else if (odredi_pobjednika()=='D'){return 0;}

        int rezultat = numeric_limits<int>::min();

        for (int i=0; i<9; ++i)
        {

            if (polje[i] ==' ')
            {

                polje[i] = 'X';
                rezultat = max(rezultat, minPretraga());
                polje[i] = ' ';

            }

        }

        return rezultat;

    }

    int minPretraga()
    {

        if (odredi_pobjednika()=='X'){return 10;}
        else if (odredi_pobjednika()=='O'){return -10;}
        else if (odredi_pobjednika()=='D'){return 0;}

        int rezultat = numeric_limits<int>::max();

        for (int i=0; i<9; ++i)
        {

            if (polje[i] ==' ')
            {

                polje[i] = 'O';
                rezultat = min(rezultat, maxPretraga());
                polje[i] = ' ';

            }

        }

        return rezultat;

    }

   

    public :
        void nacrtaj_polja();
        void x_igrac();
        void o_igrac();
        void izbor_racunara();
        void kompjuter_protiv_igraca_hard();
        int broji_simbole(char simbol)
        {

            int total = 0;
            for (int i=0; i<9; ++i)
            {

                if (polje[i] == simbol)
                {
                    total += 1;

                }

            }

            return total;

        };
        char odredi_pobjednika()
        {
            // provjeravamo da li nije jednak praznom prostoru jer igra bi uvijek zavrsila cim bi pocela
            // provjera pobjednika u redovima
            if (polje[0] == polje[1] && polje[1] == polje[2] && polje[0] != ' ')          
            {

                return polje[0];

            }

            if (polje[3] == polje[4] && polje[4] == polje[5] && polje[3] != ' ')          
            {

                return polje[3];

            }

            if (polje[6] == polje[7] && polje[7] == polje[8] && polje[6] != ' ')          
            {

                return polje[6];

            }

            // provjera pobjednika u kolonama
            if (polje[0] == polje[3] && polje[3] == polje[6] && polje[0] != ' ')
            {
                return polje[0];

            }

            if (polje[1] == polje[4] && polje[4] == polje[7] && polje[1] != ' ')
            {
                return polje[1];

            }

            if (polje[2] == polje[5] && polje[5] == polje[8] && polje[2] != ' ')
            {
                return polje[2];

            }

            // provjera pobjednika u dijagonalama
            if (polje[0] == polje[4] && polje[4] == polje[8] && polje[0] != ' ')
            {

                return polje[0];

            }

            if (polje[2] == polje[4] && polje[4] == polje[6] && polje[2] != ' ')
            {

                return polje[2];

            }

            // provjera za nerijesene slucajeve
            if (broji_simbole('X') + broji_simbole('O') < 9)
            {

                return 'C';

            }

            else
            {

                return 'D';

            }

        }
        void kompjuter_protiv_igraca();
        void igrac_protiv_igraca();    
};

void iksoks::kompjuter_protiv_igraca()
{

    string naziv_igraca;
    cout << "Unesi svoj username: ";
    cin >> naziv_igraca;
    while (true)
    {

        system("cls");
        nacrtaj_polja();

        // ako je uvijek jednak broj simbola X i O to znaci da X igra prvo uvijek inace igra O
        if (broji_simbole('X') == broji_simbole('O'))
        {

            cout << naziv_igraca << ": " << '\n';
            x_igrac();

        }

        else
        {

            izbor_racunara();

        }

        char pobjednik = odredi_pobjednika();

        if (pobjednik == 'X')
        {

            system("cls");
            nacrtaj_polja();
            cout << naziv_igraca << " je pobjedio" << '\n';
            break;

        }

        else if (pobjednik == 'O')
        {

            system("cls");
            nacrtaj_polja();
            cout << "Kompjuter je pobjedio" << '\n';
            break;
        }

        else if (pobjednik == 'D')
        {
            system("cls"); // 1
            nacrtaj_polja(); // 2
            cout << "Nerijeseno" << '\n';
            break;
           

        }



    }

}

void iksoks::kompjuter_protiv_igraca_hard()
{

    string naziv_igraca;
    cout << "Unesi svoj username: ";
    cin >> naziv_igraca;
    while (true)
    {

        system("cls");
        nacrtaj_polja();

        // ako je uvijek jednak broj simbola X i O to znaci da X igra prvo uvijek inace igra O
        if (broji_simbole('X') == broji_simbole('O'))
        {

            cout << naziv_igraca << ": " << '\n';
            x_igrac();

        }

        else
        {

            aiIgrac potez = minimax();

            polje[potez.izbor] = 'O';

        }

        char pobjednik = odredi_pobjednika();

        if (pobjednik == 'X')
        {

            system("cls");
            nacrtaj_polja();
            cout << naziv_igraca << " je pobjedio" << '\n';
            break;

        }

        else if (pobjednik == 'O')
        {

            system("cls");
            nacrtaj_polja();
            cout << "Kompjuter je pobjedio" << '\n';
            break;
        }

        else if (pobjednik == 'D')
        {
            system("cls"); // 1
            nacrtaj_polja(); // 2
            cout << "Nerijeseno" << '\n';
            break;
           

        }



    }

}

void iksoks::igrac_protiv_igraca()
{

    string naziv_x_igraca, naziv_o_igraca;
    cout << "Unesi ime X igraca: ";
    cin >> naziv_x_igraca;
    cout << "Unesi ime O igraca: ";
    cin >> naziv_o_igraca;
    while (true)
    {

        system("cls");
        nacrtaj_polja();
        if (broji_simbole('X') == broji_simbole('O'))
        {

            cout << naziv_x_igraca << ": " << '\n';
            x_igrac();

        }
       
        else
        {

            cout << naziv_o_igraca << ": " << '\n';
            o_igrac();

        }

        char pobjednik = odredi_pobjednika();
        if (pobjednik == 'X')
        {

            system("cls");
            nacrtaj_polja();
            cout << naziv_x_igraca << " je pobjedio" << '\n';
            break;

        }

        else if (pobjednik == 'O')
        {

            system("cls");
            nacrtaj_polja();
            cout << naziv_o_igraca << " je pobjedio" << '\n';
            break;

        }

        else if (pobjednik == 'D')
        {
            system("cls");
            nacrtaj_polja();
            cout << "Nerijeseno" << '\n';
            break;


        }

    }

}

void iksoks::izbor_racunara()
{

    srand(time(NULL));
    int izbor;
    do
    {

        izbor = rand()%10;

    } while (polje[izbor]!=' ');
    polje[izbor] = 'O';

   

}

void iksoks::x_igrac()
{
   
    while(true)
    {
        start:
        cout << "Izaberi poziciju (1-9): ";
        int izborX;
        cin >> izborX;
        --izborX; // smanjuje se izbor za 1 jer pozicije idu od 0-8, a prikazane su 1-9
       
       

        if(!cin) // ili if(cin.fail())
        {  
       
            cin.clear(); // reset failbit
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // preskoci los input :)
            cout << ">:(" << '\n';
   
        }
        else if(izborX < 0 || izborX > 8)
        {

            cout << "Nepostojece polje" << '\n';

        }
       
       

        else if(polje[izborX] != ' ')
        {

            cout << "Izaberi praznu poziciju" << '\n';

        }

        else
        {

            polje[izborX] = 'X';
            break; // zavrsetak while loop

        }
    }
}

void iksoks::o_igrac()
{
   
    while(true)
    {

        cout << "Izaberi poziciju (1-9): ";
        int izborO;
        cin >> izborO;
        --izborO; // smanjuje se izbor za 1 jer pozicije idu od 0-8, a prikazane su 1-9
       
       
        if(!cin) // ili if(cin.fail())
        {  
       
            cin.clear(); // reset failbit
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // preskoci los input :)
            cout << ">:(" << '\n';
   
        }
       
        else if(izborO < 0 || izborO > 8)
        {

            cout << "Nepostojece polje" << '\n';

        }

        else if(polje[izborO] != ' ')
        {

            cout << "Izaberi praznu poziciju" << '\n';

        }

        else
        {

            polje[izborO] = 'O';
            break; // zavrsetak while loop

        }
    }
}

void iksoks::nacrtaj_polja()
{
   
    cout << "     |     |     " << endl;
    cout << "  " << polje[0] << "  |  " << polje[1] << "  |  " << polje[2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << polje[3] << "  |  " << polje[4] << "  |  " << polje[5] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << polje[6] << "  |  " << polje[7] << "  |  " << polje[8] << endl;

    cout << "     |     |     " << endl << endl;
   
   
};



int main()
{
   
   iksoks igra;
   cout << "******************************************\n";
   cout << "*                IKSOKS                  *\n";
   cout << "*             IZABERI MOD:               *\n";
   cout << "*     1. KOMPJUTER PROTIV IGRACA         *\n";
   cout << "*       2. IGRAC PROTIV IGRACA           *\n";
   cout << "*                                        *\n";
   cout << "******************************************\n";
   int n;
   cin >> n;

   switch (n)
   {

       case 1 :

        cout << "******************************************\n";
        cout << "*                IKSOKS                  *\n";
        cout << "*             IZABERI MOD:               *\n";
        cout << "*               1. EASY                  *\n";
        cout << "*               2. HARD                  *\n";
        cout << "*                                        *\n";
        cout << "******************************************\n";
        int n1;
        cin >> n1;

        switch(n1)
        {

            case 1 :
            igra.kompjuter_protiv_igraca();
            break;

            case 2 :
            igra.kompjuter_protiv_igraca_hard();
            break;

            default :
            cout << "Unesi 1 ili 2" << '\n';

        }
       
       
       break;

       case 2 :
       igra.igrac_protiv_igraca();
       break;

       default :
       cout << "Unesi 1 ili 2" << '\n';
       break;

   }
   
   // da se odmah ne ugasi
   system("pause");
}