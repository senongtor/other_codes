/*
A game where we have three heaps and two players and players alternately
pick a heap and remove some asteriks from the heap while the heap is not
empty. If all three heaps are empty then the player who remove the last 
asterik wins.(There is no restriction on the number of asteriks one can 
remove at a time).
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// Global constant
const int NUM_HEAPS = 3;    // Number of heaps

void readnumber(int array[], int n);// FUNCTION PROTOTYPES GO HERE:            declare heap number and size

void drawheaps( int array[], int n);//   declare heap number and size

bool checkzero( int array[]);        //   declare heap number

void playermove( int player_number, int array[]);        // declare player and heap number

void removeobjects(int heapnumber, int removenumber, int array[]); // declare heapnumber remove number and heap number

void printmessage(int player_number);   // declare player number

int changeplayer(int & play_number);     // declare player number


int main()
{
  int heap[NUM_HEAPS];      // heap[i] = Number of elements in heap i
  int player(1);            // Player 1 or 2
  bool checkz;
  for(int i=0; i< NUM_HEAPS; i++) // Read number of elements in each heap
  {
   readnumber(heap,i);
  } 

  for(int j=0; j<NUM_HEAPS;j++)// Draw heaps as rows of *'s
  {
   drawheaps(heap,j);
  }

  checkz=checkzero(heap);
  
 while(!checkz) // WHILE some heap is not empty DO
 {
  playermove( player,heap); // Read heap to modify and number of elements to remove from heap
                            // Remove elements from heap
  checkz=checkzero(heap);
  
 


 if(checkz)// IF all the heaps are empty, THEN
 {
  printmessage(player);// Player has won.
                       // Print win message.
 }
 

 else
 {
  for(int i=0;i<NUM_HEAPS;i++)
  { 
   drawheaps(heap,i); // Play continus
                      // Redraw heaps.
  }   

  player= changeplayer(player);    // Change to other player.
 }
 }
}
		 
//Function define here:
void readnumber(int array[], int n)                         // Read number of elements in each heap     
{
 int num_objects;                                           // declare number of elements in each loop
 bool check=true;                                           // check if the numner is positive
 while(check)  
 { 
  cout<< "How many objects are in Heap " <<n<<": ";
  cin >> num_objects;
  if ( num_objects <= 0)
  {
   cout <<"Sorry, the number of objects should be positive." << endl;
  }
  else
  {
   check=false;
  }
 }
 array[n]=num_objects;
}


void drawheaps( int array[], int n)                      //  draw heaps as number of *
{
 if(n==0)
 {
  cout <<endl;
 }

 
  cout << "Heap" << " " << n << ": ";
  for( int j=0; j< array[n];j++)
  {
   cout<< "*";
  }
  cout << endl;
 
 if(n==NUM_HEAPS-1)
 {
 cout << endl;
 }
}

bool checkzero(int array[])                             // check whether there is 0 elements in all heaps
{
 bool check= true;                                      // declare a bool value
 for( int i=0; i<NUM_HEAPS; i++)
 {
  if( array[i]!=0)
 {
  check= false;
 }
 }
  return(check);
}


void playermove( int player_number, int array[])       // prompt and read a player
{
  int heapnum;                                         // declare the heap number
  int removenum;                                       // declare the removing number
  bool check1=true;                                    // declare the bool values
  bool check2=true;

  while(check1)
    {
      cout<<"Player ("<<player_number<<") : Which heap would you like to play? ";
      cin>>heapnum;
      if(heapnum<0||heapnum>=NUM_HEAPS)
	{
	  cerr<<"Invalid heap number. Please try again."<<endl;
	}
      else if(array[heapnum]==0)
	{
	  cerr<<"Heap "<<heapnum<<" has zero objects. Please select a different heap."<<endl;
	}
      else
	{
	  check1=false;
	}
    }

  while(check2)
    {
      cout<<"Enter number of objects to remove ("<<array[heapnum]<<" or less) from heap "<<heapnum<<":";
      cin>>removenum;
      if(removenum<=0)
	{
	  cerr<<"Number of objects you can remove must be positive. Try again."<<endl;
	}
      else if(removenum>array[heapnum])
	{
	  cerr<<"Can only remove up to "<<array[heapnum]<<" object(s). Please try again."<<endl;
	}
      else
	{
	  check2=false;
	}
    }

  removeobjects(heapnum,removenum,array);
}


void removeobjects(int heapnumber, int removenumber, int array[])               // remove the objects from the heap
{
  array[heapnumber]=array[heapnumber]-removenumber;
}


void printmessage(int player_number)                                            // print the winer
{
  cout<<endl;
  cout<<"Congratulations! Player "<<player_number<<" wins."<<endl;
}

int changeplayer(int& player_number)                                            // change the player
{
  if(player_number==1)
    {
      player_number=2;
    }
  else if(player_number==2)
    {
      player_number=1;
    }
  return(player_number);
}


