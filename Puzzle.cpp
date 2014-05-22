/*
 * Puzzle.cpp
 *
 * Version:
 *     2
 *
 * Revisions:
 *     November 24th, 2013
 */

#include <iostream>
#include<fstream>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
#include "Config.h"
#include "Solver.h"
#include "Water.h"
#include "JumpPeg.h"
using namespace std;

int main()

{
    cout<<"This is the WaterJug problem\n"<<endl;
    vector<int> y(2,0);
    vector<vector<int> > x;
    vector<vector<int> > g;
    
    vector<Config<vector<vector<int> > > *>* actualPath = 0;
    
    int number = 0,target;
    int* capacity;
    fstream inout;
    ifstream in;
//    int ch;
    string tempnumber,tempCapacities,tempTarget;
//    cout<<"1. Input From File "<<endl;
//    cout<<"2. Input from Console"<<endl;
//    cin>>ch;
//    switch(ch)
//    {
//        case 1 :
//            
//            inout.open("//Users/ayushvora90/Desktop/JMK/WaterPuzzle/WaterPuzzle/input.txt",ios::in);
//            
//            if(inout.fail())
//            {
//                cout<<"File Not Found ";
//            }
//            while(!inout.eof())
//            {
//                inout>>number;
//                capacity = new int[number];
//                for(int i =0;i<number;i++)
//                    inout>>capacity[i];
//                inout>>target;
//            }
//            inout.close();
//            break;
//        case 2 :
    
            cout<<"Enter Number of Jugs "<<endl;
            cin>>number;
            capacity = new int[number];
            cout<<"Enter Capacity of Each Jug"<<endl;
            
            for(int i =0 ;i<number;i++) 
            { 
                cin>>capacity[i]; 
            } 
            cout<<"Enter target Capacity "<<endl; 
            cin>>target; 
//            break;
//    }
    
        
        for(int i =0;i<number;i++)
        {
            x.push_back(y);
        }
        for(int i=0;i<number;i++)
        {
            x.at(i).at(0)=capacity[i];
            x.at(i).at(1)=0;
        }
    
        for (int i=0; i<number; i++)
        {
            for(int j =0 ;j<2;j++)
            {
                cout<<(x.at(i)).at(j)<<" ";
                
            }
            
            cout<<endl;
        }
        
        Config<vector<vector<int> > >* h= new Config<vector<vector<int> > >(x);
        Water<vector<vector<int> > > m(h,target,number);
        
        
        int result = x.at(0).at(0);
        for(int i = 1; i < number; i++)
        {
            result = m.gcdR(result,x.at(i).at(0) );
        }
        if(target%result!=0)
        {
            cout<<"No Solution Exists"<<endl;
//            exit(0);
        }
        else
        {
            
            actualPath = m.solve();
            reverse(actualPath->begin(), actualPath->end());
            vector<Config<vector<vector<int> > > *>::iterator p;
            for (p = actualPath->begin(); p!=actualPath->end() ; p++) {
                g = (*p)->configuration;
                
                for (int i=0; i<number; i++)
                {
                    
                    cout<<(g.at(i)).at(1)<<" ";
                }
                cout<<endl;
            }
            /////Users/ayushvora90/Desktop/JMK/WaterPuzzle/WaterPuzzle/
            inout.open("//Users/ayushvora90/Desktop/JMK/WaterPuzzle/WaterPuzzle/output.txt",ios::out);
//            vector<Config<vector<vector<int> > > *>::iterator p;
            for (p = actualPath->begin(); p!=actualPath->end() ; p++)
            {
                g = (*p)->configuration;
                
                for (int i=0; i<number; i++)
                {
                    
                    inout<<(g.at(i)).at(1)<<" ";
                }
                inout<<endl;
            }
            
            inout.close();
        }
    
    ///Users/ayushvora90/Desktop/JMK/WaterPuzzle/WaterPuzzle/
    
    cout<<endl;
    cout<<"This is the JumpPeg problem"<<endl;
    
     vector<char> k(4,'+');
     vector<vector<char> > l;
     vector<vector<char> > n;
     for (int i=0; i<4; i++) {
     l.push_back(k);
     }
     l.at(0).at(1)='o';
     for (int i=0; i<4; i++) {
     for (int j=0; j<4; j++) {
     cout<<(l.at(i)).at(j)<<" ";
     }
     cout<<endl;
     }
     
     
     Config<vector<vector<char> > >* bd= new Config<vector<vector<char> > >(l);
     JumpPeg<vector<vector<char> > > z(bd);
     
     vector<Config<vector<vector<char> > > *>* actualPath2;
     actualPath2 = z.solve();
     reverse(actualPath2->begin(), actualPath2->end());
     vector<Config<vector<vector<char> > > *>::iterator ol;
     for (ol = actualPath2->begin(); ol!=actualPath2->end() ; ol++) {
     n = (*ol)->configuration;
     
     for (int i=0; i<4; i++) {
     for (int j=0; j<4; j++) {
     cout<<(n.at(i)).at(j)<<" ";
     }
     cout<<endl;
     }
     cout<<endl;
     }
    
     return 0;

}
