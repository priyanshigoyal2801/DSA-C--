#include <iostream>
using namespace std;
class A{
int p;
int p1;
public:
void set_data(){
    cin>>p;
    cin>>p1;
}
void update_data( A a[]){
    
this->p=a[0].p+1;
}
void display(A a[]){
    for(int i=0;i<5;i++){
    cout<<a[i].p;}
}
};
int main(){
        A *p=new A[5];
        p[0].set_data();
        for(int i=0; i<5; i++){
        p[i].update_data(p);
        }for(int i=0; i<5; i++){
        p->display(p);
        p++;
        }

        

}