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

//Structure for Team Match
struct detail
{
    char name[50];
    int Score;
}list[50];

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
        cout<<"Match :"<<list2[i].MatchNo<<",";
    }
    return 0;
}

//Function for sorting of Matches 0f Team Match
int qualitysortTM(int p,int np)
{
      
}

//Main 
int main()
{
    int choice, Match,Player,No_Player;
    start:
    cout<<"\nPress 1 if the match is 1 vs 1  else press 2 if the match is a Team Match\n";
    cin>>choice;

    // Input For 1V1 Match
    if(choice ==1)
    {
        cout<<"Enter Number Of Matches: ";
        cin>>Match;
        cout<<"Enter Score of 1 v 1 Match:\n";
        for(int i=0; i<Match; i++)
        {
             cout<<"Match "<< i+1<<" : ";
            cout<<"\n           Player 1 : ";
            cin>>list2[i].Score1;
            cout<<"\n           Player 2 : ";
            cin>>list2[i].Score2;
            list2[i].MatchNo=i+1;
            list2[i].difference= abs(list2[i].Score1-list2[i].Score2);
        }

    // Sorting of 1V1 Match
        cout<<"\nSorted order of Matches would be\n";
        qualitysort(Match);
    }

    //Input For Team Match
    else if(choice ==2)
    {
        cout<<"\nEnter Number of players:";
        cin>>Player;
        cout<<"Enter Number Of player in each Team: ";
        cin>>No_Player;
        if(Player%No_Player == 0)
        {
            cout<<"\nEnter Name and Score of each player:";
            for(int i=0;i<Player;i++)
            {
               cin>>list[i].name;
               cin>>list[i].Score;
            } 
            //sorting of Team match
            qualitysortTM(Player,No_Player);

        }
        else
        {
            cout<<"Team cannot be formed:";
            return -1;
        }
    }

    //If Invalid Input
    else
    {
        cout<<" \nInvalid Choice :(";
        goto start;
    }
    
   return 0; 
}
