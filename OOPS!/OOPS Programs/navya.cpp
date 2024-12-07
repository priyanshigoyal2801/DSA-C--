//operator overloading
//lab assignment 7 question 3 
#include<iostream>
using namespace std;
class dist{
    int feet,inches;
    
    public:
    dist(int f,int i){
        feet=f;
        inches=i;
    }
    
    void display()const{
        cout<<"feet is "<<feet<<" and inches is "<<inches<<endl;
    }
    
    dist operator-(){
        feet=-feet;
        inches=-inches;
        return dist(feet,inches);
    }
};

int main(){
    dist d(4,9);
    d.display();
    dist d3= -d;
    d3.display();
    return 0;
}