#include <iostream>

using namespace std;

int main()
{
    long dec = 0;
    cin>>dec;
    int divid = dec;
    string hex = "";
    string hexNum = "";
    while(true){
            switch(divid%16){
                case 0: hexNum="0";break;
                case 1: hexNum="1";break;
                case 2: hexNum="2";break;
                case 3: hexNum="3";break;
                case 4: hexNum="4";break;
                case 5: hexNum="5";break;
                case 6: hexNum="6";break;
                case 7: hexNum="7";break;
                case 8: hexNum="8";break;
                case 9: hexNum="9";break;
                case 10: hexNum="A";break;
                case 11: hexNum="B";break;
                case 12: hexNum="C";break;
                case 13: hexNum="D";break;
                case 14: hexNum="E";break;
                case 15: hexNum="F";break;
            }
        hex.append(hexNum);
        divid = divid/16;
        if(divid == 0){
            break;
        }
    }
    for(int i=(int)hex.length()-1;i>=0;i--){
        cout<<hex[i];
    }
    cout<<endl;
    return 0;
}
