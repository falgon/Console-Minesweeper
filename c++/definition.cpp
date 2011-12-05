// definition.cpp
#include"head.hpp"
#include<cstdlib>
#include<sstream>

Mine_Sweeper::Mine_Sweeper():mines(0)
{
        srand((unsigned int)time(NULL));

        for(int i=0; i<LENGTH(blocks); i++){
                for(int j=0; j<LENGTH(blocks[0]); j++){
                        if(RANDOM_VALUE(0,10) < 0.2){
                                blocks[i][j]=0x0f;
                                mines+=1;
                        }else{
                                blocks[i][j]=0;
                        }
                }
        }
        for(int i=0; i<LENGTH(block_str); i++){
                for(int j=0; j<LENGTH(block_str[0]); j++){
                        block_str[i][j]="¡";
                }
        }
}

void Mine_Sweeper::displayStrblock()
{
        for(int i=0; i<LENGTH(block_str); i++){
                for(int j=0; j<LENGTH(block_str[0]); j++){
                        if(!(block_str[i][j]=="¡"))
                                std::cout<<" "<<block_str[i][j];
                        else 
                                std::cout<<block_str[i][j];
                }
                std::cout<<":"<<i<<std::endl;
        }
}

int Mine_Sweeper::aroundMinesCheckALL(int i,int j)
{
        if(blocks[i][j]==0x0f){
                return 0x0f;
        }
        int ans=0;
        for(int n=-1; n<=1; n++)
                for(int m=-1; m<=1; m++){
                        //try{
                                if(blocks[i+n][j+m]==0x0f){
                                        ans+=1;
                                }
                                
                        //}
                        //catch(){}
                }
        return ans;
}

void Mine_Sweeper::mineChecking(int i,int j)
{
        if(aroundMinesCheckALL(i,j)==0x0f){
                std::cout<<"BOMB!"<<std::endl;
                std::cout<<"GAME OVER"<<std::endl;
                block_str[i][j]="*";
                life=true;
        }else{
                int str_n=aroundMinesCheckALL(i,j);
                std::ostringstream stream;
                stream<<str_n;
                block_str[i][j]=stream.str();
        }
}

