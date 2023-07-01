#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

static int p = 0;

class a

{

  char busno[5], drivername[10], arrivaltime[5], departtime[5], fromloc[10], toloc[10], seat[8][4][10];

public:

  void installationfunc();

  void allotmentfunc();

  void empty();

  void showfunc();

  void availfunc();

  void position(int i);

}

bus[10];

void vline(char ch)

{

  for (int i=80;i>0;i--)

  cout<<ch;

}

void a::installationfunc()

{

  cout<<"Enter Vehicle no: ";

  cin>>bus[p].busno;

  cout<<"\nEnter Vehicle Driver's name: ";

  cin>>bus[p].drivername;

  cout<<"\nVehicle Arrival time: ";

  cin>>bus[p].arrivaltime;

  cout<<"\nVehicle Departure: ";

  cin>>bus[p].departtime;

  cout<<"\nFrom: \t\t\t";

  cin>>bus[p].fromloc;

  cout<<"\nTo: \t\t\t";

  cin>>bus[p].toloc;

  bus[p].empty();

  p++;

}

void a::allotmentfunc()

{

  int seat;

  char number[5];

  top:

  cout<<"Vehicle no: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busno, number)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\nSeat Number: ";

    cin>>seat;

    if(seat>32)

    {

      cout<<"\nThere are only 32 seats available in this vehicle.";

    }

    else

    {

    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)

      {

        cout<<"Enter passanger's name: ";

        cin>>bus[n].seat[seat/4][(seat%4)-1];

        break;

      }

    else

      cout<<"The seat no. is already reserved.\n";

      }

      }

    if(n>p)

    {

      cout<<"Enter correct Vehicle no.\n";

      goto top;

    }

  }


void a::empty()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[p].seat[i][j], "Empty");

    }

  }

}

void a::showfunc()

{

  int n;

  char number[5];

  cout<<"Enter vehicle no: ";

  cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busno, number)==0)

    break;

  }

while(n<=p)

{

  vline('*');

  cout<<"Vehicle no: \t"<<bus[n].busno

  <<"\nDriver: \t"<<bus[n].drivername<<"\t\tArrival time: \t"

  <<bus[n].arrivaltime<<"\tDeparture time:"<<bus[n].departtime

  <<"\nFrom: \t\t"<<bus[n].fromloc<<"\t\tTo: \t\t"<<

  bus[n].toloc<<"\n";

  vline('*');

  bus[0].position(n);

  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(bus[n].seat[i][j],"Empty")!=0)

      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"Enter correct vehicle no: ";

}

void a::position(int l)

{

  int s=0;p=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(bus[l].seat[i][j], "Empty")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<bus[l].seat[i][j];

          p++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].seat[i][j];

        }

      }

    }

  cout<<"\n\nThere are "<<p<<" seats empty in Vehicle No: "<<bus[l].busno;

  }

void a::availfunc()

{


  for(int n=0;n<p;n++)

  {

    vline('*');

    cout<<"Vehicle no: \t"<<bus[n].busno<<"\nDriver: \t"<<bus[n].drivername

    <<"\t\tArrival time: \t"<<bus[n].arrivaltime<<"\tDeparture Time: \t"

    <<bus[n].departtime<<"\nFrom: \t\t"<<bus[n].fromloc<<"\t\tTo: \t\t\t"

    <<bus[n].toloc<<"\n";

    vline('*');

    vline('_');

  }

}

int main()

{

system("cls");

int choice;

while(1)

{

    //system("cls");

  cout<<"\n\n\n\n\n";
  
  cout<<"\t\t\t VEHICLE SEAT RESERVATION SYSTEM\n";

  cout<<"\t\t\t1>Installation\n\t\t\t"

  <<"2>Reservation\n\t\t\t"

  <<"3>View\n\t\t\t"

  <<"4>Availability\n\t\t\t"

  <<"5>Exit";

  cout<<"\n\t\t\tEnter your choice: ";

  cin>>choice;

  switch(choice)

  {

    case 1:  bus[p].installationfunc();

      break;

    case 2:  bus[p].allotmentfunc();

      break;

    case 3:  bus[0].showfunc();

      break;

    case 4:  bus[0].availfunc();

      break;

    case 5:  exit(0);

  }

}

return 0;

}
