//Header Files
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

//Structure For Team Match
struct detail
{
    char name[50];
    int Score;

}list[50];

//Structure for 1V1 Match
struct MatchScore{
    int Score1,Score2;
}list2[50];

//Function For Sorting and finding the difference
int qualitysort(int M)
{
    int difference[M],help[M];
    for(int i=0;i<M; i++)
    {
        difference[i]= abs(list2[i].Score1-list2[i].Score2);
    }
  for(int j=0;j<M;j++)
    {
        help[j]=difference[j];
    }
    // Sort 
    int Temp;
    for (int i = 0; i < M; ++i) 
    {
        for (int j = i + 1; j < M; ++j)
        {
            if (help[i] > help[j]) 
            {
                Temp =  help[i];
                help[i] = help[j];
                help[j] = Temp;
            }
        }
    }
    
// Printing Sorted Matches
    int index;
    for(int i=0;i<M;i++)
    {  
    
        for(int j=0;j<M;j++)
        {
            if(help[i]==difference[j])
            index = j+1;
        
        }
        cout<<"Match "<<index<<",";
    }
  
    cout<<"\n";


    return 0;
}

//Main
int main()
{
    int choice, Match;
    start:
    cout<<"\nPress 1 if the match is 1 vs 1  else press 2 if the match is a Team Match\n";
    cin>>choice;
    // User Input For 1V1 Match
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

    //User input for Team Match
    else if(choice ==2)
    {
        
    }

    //Else condition for Invalid Input
    else
    {
        cout<<" \nInvalid Choice :(";
        goto start;
    }
    
    
}
