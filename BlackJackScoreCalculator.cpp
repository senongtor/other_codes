/*Synopsis:   Blackjack Score Calculator
  Author:     Hongtao Cheng
*/

#include<iostream>
using namespace std;

int main()
{
    int card,score,ace;
    char c,repeat;
    
    do
    {
     score=0,ace=0;
     cout<<"How many cards do you have?"<<endl;
     cin>>card;
     
     for(int count=0;count<card;count++)
     {
         cout<<"Enter a card (2-9, t, j, q, k or a):"<<endl;
         cin>>c;

         switch(c)
         {
             case '2':
                  score+=2;
                  break;
             
             case '3':
                  score+=3;
                  break;
             
             case '4':
                  score+=4;
                  break;
             
             case '5':
                  score+=5;
                  break;
             
             case '6':
                  score+=6;
                  break;
             
             case '7':
                  score+=7;
                  break;
             
             case '8':
                  score+=8;
                  break;
             
             case '9':
                  score+=9;
                  break;
                  
             case 't': case 'T':
                  score+=10;
                  break;
             
             case 'j': case 'J':
                  score+=10;
                  break;
                  
             case 'q': case 'Q':
                  score+=10;
                  break;
                  
             case 'k': case 'K':
                  score+=10;
                  break;
                  
             case 'a': case 'A':
                  score+=11;
                  ace++;
                  break;
         }
     }
     
     while(score>21&&ace!=0)
     {
      score-=10;
      ace--;
     }
     
     if(score>21)
     cout<<"Busted."<<endl;
     else
     cout<<score<<endl;
     cout<<"Repeat? (y/n):"<<endl;
     cin>>repeat;
    }
    while(repeat=='y');
    
    return 0;
}
