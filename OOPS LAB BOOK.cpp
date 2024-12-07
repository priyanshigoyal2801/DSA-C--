#include<iostream>
#include<string>
using namespace std;
class Book{
int ISBN;
string title;
string author;
int price;
int quantity;
public:
Book(int isbn, string t, string a, int p, int q){
	ISBN=isbn;
	title=t;
	author=a;
	price=p;
	quantity=q;
	
}
	void display_Book(){
		cout<<"ISBN: "<<ISBN<<endl<<"title:"<<title<<endl<<"author: "<<author<<endl<<"price:"<<price<<endl<<"quantity:"<<quantity<<endl;
	}
	friend void sell( Book &b1, Book &b2);
	~Book(){
		cout<<"book removed from inventory titled "<<title<<endl;
	}
};
	void sell( Book &b1, Book &b2){
		if(b1.quantity>10){
			b1.quantity-=1;
			b2.quantity+=1;
			cout<<"sale successful";
		}
		else{
			cout<<"insufficient copies";
		}
	}
	

int main(){
	Book b[5]={Book(1,"a","aa",1,10), Book(2,"b","bb",2,20),Book(3,"c","cc",3,30),Book(4,"d","dd",4,40),Book(5,"e","ee",5,50)};
	
	cout<<"details before sales";
	for(int i=0;i<5;i++){
		b[i].display_Book();
	}
	sell(b[1],b[2]);
	cout<<"details after sales";
	b[1].display_Book();
	b[2].display_Book();
}
