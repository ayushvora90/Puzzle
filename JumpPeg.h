//
//  JumpPeg.h
//  WaterPuzzle
//
//

#ifndef WaterPuzzle_JumpPeg_h
#define WaterPuzzle_JumpPeg_h
#include "Solver.h"
/*JumpPeg Class */
template<typename T>
class JumpPeg : public Solver<T>
{
    
public:
    int numberOfHoles,i,j;
    /*
     *Default Constructor
     */
    JumpPeg<T>();
    /*
     *Parameterized Constructor
     */
    JumpPeg <T> (Config<T> *initConfig):Solver<T>(initConfig)
    {
        i=0;
        j=1;
    }
    /*
     *Overriding the IsGoal Function Checks if number of pegs is 1
     */
    bool isGoal (Config<T>* a)
    {
        numberOfHoles = 0;
        for (int i=0; i<4; i++)
        {
            for (int j=0; j<4; j++)
            {
                if((a->configuration.at(i)).at(j)=='o')
                    numberOfHoles++;
            }
        }
        if(numberOfHoles==15)
            return true;
        else
            return false;
    }
    /*
     *Generates a list of neigbouring configurations
     */
    list <Config<T>* >* getNextConfig(Config<T>* currentConfig)
    {
        list <Config<T>*>* listOfGeneratedConfigsPointer = new list<Config<T>*>;
        
        for (int i=0; i<4; i++)
        {
            for (int j=0; j<4; j++)
            {
                if((currentConfig->configuration.at(i)).at(j)=='o')
                {
                    
                    
                    nextMove(i,j,currentConfig,listOfGeneratedConfigsPointer);
                    
                }
            }
        }
        
        return listOfGeneratedConfigsPointer;
    }
    /*
     * Condition to check possibility of multiple moves
     */
    bool condition(int i,int j ,Config<vector<vector<char> > >* currentConfig)
    {
        if((i>=0 && i<2 && j>=0 && j<4 && currentConfig->configuration.at(i+1).at(j)=='+' && currentConfig->configuration.at(i+2).at(j)=='o')||(i>=0 && i<2 && j>=0 && j<4 && currentConfig->configuration.at(i+1).at(j)=='+' && currentConfig->configuration.at(i+2).at(j)=='o')||(i>=0 && i<4 && j>=2 && j<4 && currentConfig->configuration.at(i).at(j-1)=='+' && currentConfig->configuration.at(i).at(j-2)=='o')||(i>=0 && i<4 && j>=0 && j<2 && currentConfig->configuration.at(i).at(j+1)=='+' && currentConfig->configuration.at(i).at(j+2)=='o'))
        {
            return true;
        }
        else
            return false ;
        
    }
    /*
     *Generates the next move for CurrentConfig
     */
    void nextMove (int i,int j ,Config<vector<vector<char> > >* currentConfig, list<Config<vector<vector<char> > >* >* listOfGeneratedConfigsPointer )
    {
        Config<vector<vector<char> > >* tempConfig = new Config<vector<vector<char> > >(currentConfig->configuration);
        Config<vector<vector<char> > >* tempConfig2 = new Config<vector<vector<char> > >(currentConfig->configuration);
        Config<vector<vector<char> > >* tempConfig3 = new Config<vector<vector<char> > >(currentConfig->configuration);
        Config<vector<vector<char> > >* tempConfig4 = new Config<vector<vector<char> > >(currentConfig->configuration);
        
        //Down
        if(i>=0 && i<2 && j>=0 && j<4 && currentConfig->configuration.at(i+1).at(j)=='+' && currentConfig->configuration.at(i+2).at(j)=='+')
        {
            
            tempConfig->configuration.at(i+1).at(j)='o';
            tempConfig->configuration.at(i+2).at(j)='o';
            tempConfig->configuration.at(i).at(j)='+';
            listOfGeneratedConfigsPointer->push_back(tempConfig);
            if(condition(i,j, tempConfig)){
                Config<vector<vector<char> > >* tempConfig5 = new Config<vector<vector<char> > >(nMove(i,j,tempConfig));
                listOfGeneratedConfigsPointer->push_back(tempConfig5);
            }
            
        }
        //Up
        
        
        if(i>=2 && i<4 && j>=0 && j<4 && currentConfig->configuration.at(i-1).at(j)=='+' && currentConfig->configuration.at(i-2).at(j)=='+')
        {
            
            tempConfig2->configuration.at(i-1).at(j)='o';
            tempConfig2->configuration.at(i-2).at(j)='o';
            tempConfig2->configuration.at(i).at(j)='+';
            listOfGeneratedConfigsPointer->push_back(tempConfig2);
            if(condition(i, j, tempConfig2)){
                Config<vector<vector<char> > >* tempConfig6 = new Config<vector<vector<char> > >(nMove(i,j,tempConfig2));
                listOfGeneratedConfigsPointer->push_back(tempConfig6);
                
            }
            
        }
        //Left
        if(i>=0 && i<4 && j>=2 && j<4 && currentConfig->configuration.at(i).at(j-1)=='+' && currentConfig->configuration.at(i).at(j-2)=='+')
        {
            
            tempConfig3->configuration.at(i).at(j-1)='o';
            tempConfig3->configuration.at(i).at(j-2)='o';
            tempConfig3->configuration.at(i).at(j)='+';
            listOfGeneratedConfigsPointer->push_back(tempConfig3);
            if(condition(i, j, tempConfig3)){
                Config<vector<vector<char> > >* tempConfig7 = new Config<vector<vector<char> > >(nMove(i,j,tempConfig3));
                listOfGeneratedConfigsPointer->push_back(tempConfig7);
            }
            
        }
        //Right
        if(i>=0 && i<4 && j>=0 && j<2 && currentConfig->configuration.at(i).at(j+1)=='+' && currentConfig->configuration.at(i).at(j+2)=='+')
        {
            tempConfig4->configuration.at(i).at(j+1)='o';
            tempConfig4->configuration.at(i).at(j+2)='o';
            tempConfig4->configuration.at(i).at(j)='+';
            listOfGeneratedConfigsPointer->push_back(tempConfig4);
            if(condition(i, j, tempConfig4)){
                Config<vector<vector<char> > >* tempConfig8 = new Config<vector<vector<char> > >(nMove(i,j,tempConfig4));
                listOfGeneratedConfigsPointer->push_back(tempConfig8);
            }
            
        }
        return ;
    }
    /*
     * Finds multiple moves.
     */
    T nMove (int i,int j ,Config<vector<vector<char> > >* currentConfig ){
        //Down
        if(i>=0 && i<2 && j>=0 && j<4 && currentConfig->configuration.at(i+1).at(j)=='+' && currentConfig->configuration.at(i+2).at(j)=='o'){
            currentConfig->configuration.at(i).at(j)='o';
            currentConfig->configuration.at(i+1).at(j)='o';
            currentConfig->configuration.at(i+2).at(j)='+';
            nMove(i+2, j, currentConfig);
        }
        //Up
        if(i>=2 && i<4 && j>=0 && j<4 && currentConfig->configuration.at(i-1).at(j)=='+' && currentConfig->configuration.at(i-2).at(j)=='o')
        {
            currentConfig->configuration.at(i).at(j)='o';
            currentConfig->configuration.at(i-1).at(j)='o';
            currentConfig->configuration.at(i-2).at(j)='+';
            nMove(i-2, j, currentConfig);
            
        }
        //Left
        if(i>=0 && i<4 && j>=2 && j<4 && currentConfig->configuration.at(i).at(j-1)=='+' && currentConfig->configuration.at(i).at(j-2)=='o')
        {
            currentConfig->configuration.at(i).at(j)='o';
            currentConfig->configuration.at(i).at(j-1)='o';
            currentConfig->configuration.at(i).at(j-2)='+';
            nMove(i, j-2, currentConfig);
        }
        //Right
        if(i>=0 && i<4 && j>=0 && j<2 && currentConfig->configuration.at(i).at(j+1)=='+' && currentConfig->configuration.at(i).at(j+2)=='o')
        {
            currentConfig->configuration.at(i).at(j)='o';
            currentConfig->configuration.at(i).at(j+1)='o';
            currentConfig->configuration.at(i).at(j+2)='+';
            nMove(i, j+2, currentConfig);
        }
        return currentConfig->configuration;
        
        
    }
    
};



#endif
