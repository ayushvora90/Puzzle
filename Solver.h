//
//  Solver.h
//  WaterPuzzle
//
//

#ifndef WaterPuzzle_Solver_h
#define WaterPuzzle_Solver_h
#include <iostream>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
#include "Config.h"
using namespace std;
/* Generalized Puzzle Solver Class
 */
template<typename T>
class Solver
{   private:
    Config<T>* initialConfig;
    public :
    /*
     *Default Constructor
     */
    Solver();
    /*
     *Parameterized  Constructor
     */
    Solver(Config<T>* initConfig){
        initialConfig = initConfig;
    }
    /*
     *Virtual Method to check IsGoal
     */
    virtual bool isGoal (Config<T>* a)=0;
    /*
     *Pure Virtual Method to getNextonfig
     */
    virtual list<Config<T>* >* getNextConfig(Config<T>* currentConfig)=0;
    /*
     *Solve Method which solves the puzzle  returns a path to the Goal
     */
    vector<Config<T>* >* solve() //return the path from start config to solution
    {
        Config<T>* solutionConfig;
        list<Config<T>* >* newConfigs;
        
        vector<Config<T>*>* actualConfigPath  = new vector<Config<T>*>;
        queue<Config<T>* > queueofElements;
        queueofElements.push(initialConfig);
        while(!queueofElements.empty() && ! isGoal(queueofElements.front())) //Check if front element is goal isGoal(queueofElements.front())
        {
            
            Config<T>* tempConfig = queueofElements.front();
            queueofElements.pop();
            newConfigs = getNextConfig(tempConfig);
            
            for(int index=0;!newConfigs->empty();index++)
            {   Config<T>* neigbour = newConfigs->front();
                
                newConfigs->pop_front();
                if( neigbour->getVisited()==false )  //not visited
                {
                    neigbour->setParent(tempConfig);
                    neigbour->setVisited(true);
                    queueofElements.push(neigbour);
                }
                
            }
        }
        if(!queueofElements.empty())//Solution Found
        {
            cout<<"Solution Found "<<endl;
            
            solutionConfig=queueofElements.front();
            while(solutionConfig->getParent()!=NULL)
            {
                actualConfigPath->push_back(solutionConfig);
                solutionConfig=solutionConfig->getParent();
            }
            actualConfigPath->push_back(solutionConfig);
        }
        else
        {
            cout<<"No solution found";
        }
        return actualConfigPath;
    }
    
};



#endif
