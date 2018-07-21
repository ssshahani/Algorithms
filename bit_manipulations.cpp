#include <iostream>

using namespace std;
bool getBit(int &num, int pos){
    bool bit = num & (1<<pos);
    return bit;
}
// OR operation is done because 0 | 1 or 1 | 0 or 1 | 1  =  1;
void setBit(int &num, int pos){
    num = num | (1<<pos);
}
// if Bit is 1 it turns it off to 0
void unsetBit(int&num, int pos){
    num = num & (~(1<<pos));
}


//Toggle: Switchs on(1) if off(0) or switches off(0) if on(1). XOR has nice properties
void toggleBit(int &num, int pos){
    num = num ^ (1<<pos);
}

int determinePowerOfTwo(int &num){
    /*num = num << 30;
    if(num == 0)
        return true;
    return false;*/
    int count = 0;
    while(num)
    {
        num >>= 1;
        count += (num & 1);
    }
    return count;
}

int countSetBits(int &num){
    
}
int main(){
    //GetBit
    int num = 6;
    int pos = 0;
    int bit = getBit(num, pos);
    cout << "Bit at position " <<pos<<" is "<<bit<< endl;
    //Set
    setBit(num, pos);
    cout<<"Number after setting bit is "<<num<<endl;
    
    //Unset   
    pos = 1;
    unsetBit(num, pos);
    cout<<"Number after un-setting bit at position "<<pos<<" is "<<num<<endl;
    
    // Since num changed to 5 (101), after toggling it changes to 7
    toggleBit(num, pos);   
    cout<<"After toggling bit position "<<pos<<" number becomes  "<<num<<endl;
    
    // Power of 2
    num = 32;
    int count = determinePowerOfTwo(num);
    string str;
    str = (count != 1) ? "the given number is NOT a power of 2" : " The given number is a power of 2";
    cout << str <<endl;
    
    return 0;
}