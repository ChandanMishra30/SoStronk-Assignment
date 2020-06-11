//Header Files
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

//Structure for 1V1 Match
struct MatchScore{
    int Score1,Score2;
    int MatchNo;
    int difference; 
    }list2[50];

//Function for sorting of Matches for 1V1 Match
int qualitysort(int M)
{
    // Sort 
    MatchScore Temp;
    for (int i = 0; i < M; ++i) 
    {
        for (int j = i + 1; j < M; ++j)
        {
            if (list2[i].difference > list2[j].difference) 
            {
                Temp =  list2[i];
                list2[i] = list2[j];
                list2[j] = Temp;
            }
        }
    }
    //Printing Sorted Matches
    for(int i=0;i<M;i++)
    {
        cout<<"Match"<<list2[i].MatchNo<<",";
    }
    cout<<"\n";
    return 0;
}

//Main 
int main()
{
    int Match,Player,No_Player;
    start:
    // Input For 1V1 Match
   
        cout<<"Enter Number Of Matches: ";
        cin>>Match;
        cout<<"Enter Score of 1 v 1 Match:\n";
        for(int i=0; i<Match; i++)
        {
             cout<<"Match "<< i+1<<" : ";
            cout<<"\n\tPlayer 1 : ";
            cin>>list2[i].Score1;
            cout<<"\n\tPlayer 2 : ";
            cin>>list2[i].Score2;
            list2[i].MatchNo=i+1;
            list2[i].difference= abs(list2[i].Score1-list2[i].Score2);
        }

    // Sorting of 1V1 Match
        cout<<"\nSorted order of Matches would be\n";
        qualitysort(Match);
   return 0; 
}
