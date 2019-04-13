#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
const int direction[6][3] = { {1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };
const int xMax = 20;
const int yMax = 20;
const int zMax = 20;

int theBox[xMax+3][yMax+3][zMax+3];
struct node
{
  int x,y,z,direc;
};
int cases=0;//当前第几个
int xIn,yIn,zIn,xOut,yOut,zOut,num;
char diec,xyz;
bool finded;
node Max,inflow,outflow;//记录立体最大值 输入节点 输出节点

bool init()
{
    cin>>Max.x;
    if(Max.x == 0)
    {
        return false;
    }
    cin>>Max.y>>Max.z>>inflow.x>>inflow.y>>inflow.z>>diec>>xyz;
    if(xyz=='x')
    {
        inflow.direc = 0;
    }
    else if(xyz=='y')
    {
        inflow.direc = 2;
    }
    else
    {
        inflow.direc = 4;
    }
    if(diec=='-')
    {
        inflow.direc++;
    }
    cin>>outflow.x>>outflow.y>>outflow.z>>diec>>xyz;
    if(xyz=='x')
    {
        outflow.direc = 0;
    }
    else if(xyz=='y')
    {
        outflow.direc = 2;
    }
    else
    {
        outflow.direc = 4;
    }
    if(diec=='-')
    {
        outflow.direc++;
    }
    inflow.x -=direction[inflow.direc][0];
    inflow.y -=direction[inflow.direc][1];
    inflow.z -=direction[inflow.direc][2];
    return 1;
}

int add(node now)
{
    if(now.x<1 || now.y<1 || now.z<1 || now.x>Max.x || now.y>Max.y || now.z>Max.z)
    {
        return 1;
    }

    theBox[now.x][now.y][now.z]++;

    if(theBox[now.x][now.y][now.z]>1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void del(node now)
{
    if(now.x<1 || now.y<1 || now.z<1 || now.x>Max.x || now.y>Max.y || now.z>Max.z)
    {
        return ;
    }
    theBox[now.x][now.y][now.z]--;
}
void search(node now,int deep)
{
    if(deep>num)
    {
        return;
    }
    if(now.x==outflow.x && now.y==outflow.y && now.z==outflow.z && now.direc == outflow.direc)
    {
        finded = true;
        num = deep;
        return;
    }

    node n1,n2,n3,n4;

    n1.x=now.x+direction[now.direc][0];
    n1.y=now.y+direction[now.direc][1];
    n1.z=now.z+direction[now.direc][2];
    n2.x=n1.x+direction[now.direc][0];
    n2.y=n1.y+direction[now.direc][1];
    n2.z=n1.z+direction[now.direc][2];

    for(int i=0;i<6;i++)
    {
        if(i/2 != now.direc/2)
        {
            n3.x=n2.x+direction[i][0];
            n3.y=n2.y+direction[i][1];
            n3.z=n2.z+direction[i][2];
            n4.x=n3.x+direction[i][0];
            n4.y=n3.y+direction[i][1];
            n4.z=n3.z+direction[i][2];
            n4.direc = i;

            if(add(n1)+add(n2)+add(n3)+add(n4)==0)
            {
                search(n4,deep+1);
            }
            del(n1);del(n2);del(n3);del(n4);
        }
    }

    n1.x=now.x+direction[now.direc][0];
    n1.y=now.y+direction[now.direc][1];
    n1.z=now.z+direction[now.direc][2];
    n2.x=n1.x+direction[now.direc][0];
    n2.y=n1.y+direction[now.direc][1];
    n2.z=n1.z+direction[now.direc][2];
    n3.x=n2.x+direction[now.direc][0];
    n3.y=n2.y+direction[now.direc][1];
    n3.z=n2.z+direction[now.direc][2];

    for(int i=0;i<6;i++)
    {
        if(i/2 != now.direc/2)
        {
            n4.x=n3.x+direction[i][0];
            n4.y=n3.y+direction[i][1];
            n4.z=n3.z+direction[i][2];
            n4.direc = i;

            if(add(n1)+add(n2)+add(n3)+add(n4)==0)
            {
                search(n4,deep+1);
            }
            del(n1);del(n2);del(n3);del(n4);
        }
    }

}
int main()
{

    while(init())
    {
        memset(theBox,0,sizeof(theBox));
        /*
        cout<<Max.x<<" "<<Max.y<<" "<<Max.z<<" "<<inflow.x<<" "<<inflow.y<<" "<<inflow.z<<" "
        <<inflow.direc<<" "<<outflow.x<<" "<<outflow.y<<" "<<outflow.z<<" "<<outflow.direc<<endl;
        */
        num = 6;
        finded = false;
        search(inflow,0);
        cout<<"Case "<<++cases<<": ";
        if(finded)
        {
            cout<<num<<endl;
        }
        else
        {
            cout<<"Impossible"<<endl;
        }
    }
    return 0;
}
