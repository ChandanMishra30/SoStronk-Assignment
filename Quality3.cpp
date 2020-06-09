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
    int MatchNo;
    int difference; 
    }list2[50];

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
    //  
    for(int i=0;i<M;i++)
    {
        cout<<"Match :"<<list2[i].MatchNo<<",";
    }
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
            list2[i].MatchNo=i+1;
            list2[i].difference= abs(list2[i].Score1-list2[i].Score2);
        }
        cout<<"\nSorted order of Matches would be\n";
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
