// main.cpp
#include"head.hpp"
#include<iomanip>

int main()
{
        using namespace std;

        int key[2];
        Mine_Sweeper obj;
        obj.displayStrblock();
        while(!obj.life){
                cout<<"�c�蔚�e�� :"<<obj.mines<<endl;
                cout<<"���W���w�� �c [Space] �� >>";
                cin>>setw(1)>>key[0];
                cin>>setw(1)>>key[1];
                obj.mineChecking(key[0],key[1]);
                obj.displayStrblock();
        }
}

