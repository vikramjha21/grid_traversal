#include <iostream>

using namespace std;

int number(const int& pos_y, const int& pos_x, const string& list)
{
    int n = (pos_y * 20 + pos_x) * 2;

    return (list[n]-48)*10+list[n+1]-48;
}

int main()
{
    string list = "08022297381500400075040507785212507791084949994017811857608717409843694804566200814931735579142993714067538830034913366552709523046011426924685601325671370236912231167151676389419236542240402866331380244732609903450244753353783684203517125032988128642367102638406759547066183864706726206802621220956394396308409166499421245558056673992697177878968314883489637221362309750076442045351400613397343133957817532822753167159403800462161409535692163905429635314755588824001754243629855786560048357189070544443744602158515417581980816805944769287392138652177704895540045208839735991607975732162626793327986688366887576220720346336746551232639353690442167338253911249472180846293240627636206936417230238834629969826759857404361620733529783190017431497148868116235705540170547183515469169233486143520189196748";
    int biggest(0);
    int product(0);

    for (int i(3); i < 17; i++)
    {
        for (int j(3); j < 17; j++)
        {
            //Diag RD
            product = number(i,j,list) * number(i+1,j+1,list) * number(i+2,j+2,list) * number(i+3,j+3,list);
            if (product > biggest)
                biggest = product;

            //Diag RU
            product = number(i,j,list) * number(i+1,j-1,list) * number(i+2,j-2,list) * number(i+3,j-3,list);
            if (product > biggest)
                biggest = product;

            //Diag LD
            product = number(i,j,list) * number(i-1,j+1,list) * number(i-2,j+2,list) * number(i-3,j+3,list);
            if (product > biggest)
                biggest = product;

            //Diag LU
            product = number(i,j,list) * number(i-1,j-1,list) * number(i-2,j-2,list) * number(i-3,j-3,list);
            if (product > biggest)
                biggest = product;

            //Right
            product = number(i,j,list) * number(i+1,j,list) * number(i+2,j,list) * number(i+3,j,list);
            if (product > biggest)
                biggest = product;

            //Left
            product = number(i,j,list) * number(i-1,j,list) * number(i-2,j,list) * number(i-3,j,list);
            if (product > biggest)
                biggest = product;

            //down
            product = number(i,j,list) * number(i,j+1,list) * number(i,j+2,list) * number(i,j+3,list);
            if (product > biggest)
                biggest = product;

            //up
            product = number(i,j,list) * number(i,j-1,list) * number(i,j-2,list) * number(i,j-3,list);
            if (product > biggest)
                biggest = product;
        }
    }

    cout << biggest;

    return 0;
}
