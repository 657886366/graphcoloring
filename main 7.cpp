//
//  main.cpp
//  Project
//
//  Created by Conghui Deng on 5/2/20.
//  Copyright © 2020 Conghui Deng. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;
int numNodes;
int currentColor;
int * ColorList;
int ** Glist;
int whichMethod;
class GraphColor{
public:
    int *colorNode;
    void Method1(ifstream &in, ofstream &out, ofstream &out2){
        createDataList(in);
        colorNode=new int[numNodes+1];
        colorNode[1]=1;  // color node 1 with 1st color;
        int newNode=2;   //start with node 2
        int newColor=1;
        bool check=true;
        
        
        while(newNode<numNodes+1){
            for(int i=1;i<numNodes+1;i++){
                newColor=ColorList[i];
                
                check=true;
                
            for(int j=1;j<numNodes+1;j++){
                    if(Glist[newNode][j]==1 && newColor==colorNode[j]){
                        check=false;
                        break;
                    }
            }
                    if(check){
                        colorNode[newNode]=newColor;
                        break;
                    }
                    
            }
            
                 newNode++;
        
    }
        printNode(out);
        dataStructure(out2);
    }
    
    void Method2(ifstream &in,ofstream &out, ofstream &out2){
        createDataList(in);
        colorNode=new int[numNodes+1];
        colorNode[1]=1;
        int *UsedColorList=new int[numNodes+1];
          UsedColorList[1]=1;
          int newNode=2;
          bool check=true;
          int z=1;
          int newUsedColor=0;
        
        while(newNode<numNodes+1){
            
                    for(int i=1;i<z+1;i++){
                        
                        newUsedColor=UsedColorList[i];
                         check=true;
                        
                        for(int j=1;j<numNodes+1;j++){
                            
                            
                         if(Glist[newNode][j]==1 && newUsedColor==colorNode[j]){
                           check=false;
                           break;
                       }
                      }
                        if(check){
                         colorNode[newNode]=i;
                         break;
                       }
                    }
                    if(!check){
                        z++;
                        UsedColorList[z]=ColorList[z];
                        colorNode[newNode]=UsedColorList[z];
                        
                    }
                newNode++;
        }
            printNode(out);
        dataStructure(out2);
        
    }
    
    void createDataList(ifstream &in){
        int x;
        int y;
        while(in>>x>>y){
            Glist[x][y]=1;
            Glist[y][x]=1;
           // cout<<Glist[x][y];
        }
    }
    
    void printNode(ofstream &out){
        out<<"Using Method "<<whichMethod<<": "<<endl;
        out<<numNodes<<endl;
        for(int i=1;i<numNodes+1;i++){
            out<<i<<"  "<<colorNode[i]<<endl;
        }
    }
    
    void dataStructure(ofstream &out){
        out<<"Data Structure :"<<endl;
        for(int i=1;i<numNodes+1;i++){
            out<<"Node: "<<i<<"  Color: "<<colorNode[i]<<"  Neightbor Node: ";
            for(int j=1;j<numNodes+1;j++){
                if(Glist[i][j]==1)
                    out<<j<<" ";
                
            }
            out<<endl;
        }
        
    }
};

int main(int argc, const char *argv[]){
    ifstream inFile(argv[1]);
    whichMethod=stoi(argv[2]);
    ofstream outFile1(argv[3]);
    ofstream outFile2(argv[4]);
//    ofstream outFile3(argv[5]);
    
    inFile>>numNodes;
    
    GraphColor *gc=new GraphColor();
    currentColor=0;
    
    Glist=new int*[numNodes+1];
          for(int i=0;i<numNodes+1;i++)
              Glist[i]=new int[numNodes+1];
    
    for(int i=1;i<numNodes+1;i++)
        for(int j=1;j<numNodes+1;j++)
            Glist[i][j]=0;
    
    ColorList=new int[numNodes+1];
    for(int i=1;i<numNodes;i++){
        ColorList[i]=i;
    }
    
    switch (whichMethod){
        case 1:
            gc->Method1(inFile,outFile1,outFile2);
            break;
        case 2:
            gc->Method2(inFile,outFile1,outFile2);
            break;
        
        default: outFile1<<"Input data error!";
            break;
    }
        
}

