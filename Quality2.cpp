#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

struct detail
{
    char name[50];
    int Score;
}list[50];

struct MatchScore{
    int Score1,Score2;
}list2[50];

int qualitysort(int M)
{
    int difference[M];
    for(int i=0;i<M; i++)
    {
        difference[i]= abs(list2[i].Score1-list2[i].Score2);
    }
   int index,k;
   int N=M;
   for(int i=M-1; i>=0;i--)
   {
       int min=difference[N-1];
       for(int j=N-1;j>=0;j--)
       {
           if(difference[j]<=min)
            {
               min = difference[j];
               index=j+1;
               k=index;
            }
       }
       for(int i=k-1;i<N;i++)
       {
           difference[i]=difference[i+1];
       }
       cout<<"Match "<<index<<",";
       N=N-1;
       
   }
    cout<<"\n";


    return 0;
}
int main()
{
    int choice, Match;
    start:
    cout<<"\nPress 1 if the match is 1 vs 1  else press 2 if the match is a Team Match\n";
    cin>>choice;
    if(choice ==1)
    {
        cout<<"Enter Number Of Matches: ";
        cin>>Match;
        cout<<"Enter Score of 1 v 1 Match:\n";
        for(int i=0; i<Match; i++)
        {
            cout<<"Match "<< i+1<<" : ";
            cin>>list2[i].Score1>>list2[i].Score2;
        }
        cout<<"\nSorted order of here would be\n";
        qualitysort(Match);
    }
    else if(choice ==2)
    {
        
    }
    else
    {
        cout<<" \nInvalid Choice :(";
        goto start;
    }
    
    
}
