// head.hpp
#include<iostream>
#include<ctime>
#define LENGTH(x)(sizeof(x)/sizeof(x[0]))
#define RANDOM_VALUE(min,max)\
        ((double)(min+(int)(rand()*max-min+1.0)/(1.0+RAND_MAX))/(double)10)

class Mine_Sweeper{
        public:
                int mines;
                bool life;
                Mine_Sweeper();
                void displayStrblock();
                int aroundMinesCheckALL(int,int);
                void mineChecking(int,int);
        private:
                std::string block_str[10][10];
                int blocks[10][10];
};

