#include<iostream>
using namespace std;
class Distance{ 
private: int metre;
public: 
Distance( float m) { 
    metre=m; 
}
void show(){
    cout<<metre;
}
};
int main(){
float d=100;
Distance d1=d;
d1.show();
}