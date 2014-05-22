//
//  Config.h
//  WaterPuzzle
//
//  Created by Ayush Vora on 5/16/14.
//  Copyright (c) 2014 Ayush Vora. All rights reserved.
//

#ifndef __WaterPuzzle__Config__
#define __WaterPuzzle__Config__

#include <iostream>
/*
 * This is a generalized class for storing configurations.
 */
template<typename T>
class Config
{
public:
    T configuration;
    bool visited ;  //visited flag for each config
    Config<T>* parent;
    /*
     *Default Constructor
     */
    Config<T>(){
        
    }
    /*
     *Parameterized Constructor
     */
    Config<T>(T config){
        configuration = config;
        visited = false;
        parent = NULL;
    }
    /*
     * This method returns whether this configuration has been visited or not.
     */
    
    bool getVisited(){
        return visited;
    }
    /*
     * Returns the parent configuration.
     */
    
    Config<T>* getParent(){
        return parent;
    }
    /*
     * Sets whether the configuration was visited.
     */
    
    void setVisited(bool vis){
        visited = vis;
    }
    /*
     * Sets a parent configuration for the current current configuration.
     */
    
    void setParent(Config<T>* par){
        parent = par;
    }
};

#endif /* defined(__WaterPuzzle__Config__) */
