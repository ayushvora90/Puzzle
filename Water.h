//
//  Water.h
//  WaterPuzzle
//
//

#ifndef WaterPuzzle_Water_h
#define WaterPuzzle_Water_h
#include "Solver.h"
/*Water Class */
template<typename T>
class Water : public Solver<T>
{
    private :
    int targetCapacity;
    int numberOfJugs;
    public :
    Water<T>();
    Water<T>(Config<T> *initConfig,int target,int number):Solver<T>(initConfig)
    {
        numberOfJugs=number;
        targetCapacity=target;
        
        
    }
    bool isGoal(Config<T> *a)
    {
        for (int i=0; i<numberOfJugs; i++)
        {
            if(a->configuration.at(i).at(1)==targetCapacity) //Check if equal to target
                return true;
            
        }
        
        return false;
        
    }
    int gcdR(int num1,int num2)
    {
        if (num1==0 || num2==0)
			return (num1+num2);
		else
			return gcdR(num2,num1%num2);
        
    }
    
    
    list <Config<T>* >* getNextConfig(Config<T>* currentConfig)
    {
        
        list <Config<T>*>* listOfGeneratedConfigsPointer = new list<Config<T>*>;
        for(int i=0;i<numberOfJugs;i++)   //Total Number of Cups..If either empty then fill and push
        {
            //Config<vector<vector<int> > >* tempConfig = new Config<vector<vector<int> > >(currentConfig->configuration);
            if(currentConfig->configuration.at(i).at(1)==0) //Empty
            {
                Config<vector<vector<int> > >* tempConfig = new Config<vector<vector<int> > >(currentConfig->configuration);
                tempConfig->configuration.at(i).at(1)=tempConfig->configuration.at(i).at(0);
                listOfGeneratedConfigsPointer->push_back(tempConfig);
                
            }
            
        }
        for(int i=0;i<numberOfJugs;i++)   //if either full,empty and push
        {
            if(currentConfig->configuration.at(i).at(1)==currentConfig->configuration.at(i).at(0)) //Empty
            {
                Config<vector<vector<int> > >* tempConfig = new Config<vector<vector<int> > >(currentConfig->configuration);
                tempConfig->configuration.at(i).at(1)=0;
                listOfGeneratedConfigsPointer->push_back(tempConfig);
                
            }
            
        }
        for(int i=0;i<numberOfJugs;i++) //Till one is full
        {
            for(int j =0 ;j<numberOfJugs;j++)
            {
                if(i!=j)
                {
                    int temp =currentConfig->configuration.at(i).at(0)-currentConfig->configuration.at(i).at(1);
                    if(temp>0 && currentConfig->configuration.at(j).at(1)>=temp)
                    {
                        Config<vector<vector<int> > >* tempConfig = new Config<vector<vector<int> > >(currentConfig->configuration);
                        
                        
                        tempConfig->configuration.at(i).at(1)=tempConfig->configuration.at(i).at(1)+temp;
                        tempConfig->configuration.at(j).at(1)=tempConfig->configuration.at(j).at(1)-temp;
                        listOfGeneratedConfigsPointer->push_back(tempConfig);
                        
                    }
                    
                }
                
            }
        }
        
        for(int i=0;i<numberOfJugs;i++) //Till one is empty
        {
            for(int j =0 ;j<numberOfJugs;j++)
            {
                
                if(i!=j)
                {
                    int temp =currentConfig->configuration.at(i).at(1)+currentConfig->configuration.at(j).at(1);
                    
                    Config<vector<vector<int> > >* tempConfig = new Config<vector<vector<int> > >(currentConfig->configuration);
                    if(temp<=currentConfig->configuration.at(j).at(0))
                    {
                        tempConfig->configuration.at(i).at(1)=0;//empty
                        tempConfig->configuration.at(j).at(1)=temp;
                        listOfGeneratedConfigsPointer->push_back(tempConfig);
                        
                        
                        
                    }
                    
                }
                
                
                
            }
        }
        
        
        return listOfGeneratedConfigsPointer;
    }
    
};


#endif
