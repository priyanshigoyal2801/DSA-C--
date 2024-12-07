////#include<iostream>
////#include<string>
////using namespace std;
////class config{
////	 string lang;
////	 static string default_lang;
////	public:
////		static int cnt;
////		config(){
////			lang=default_lang;
////			cout<<"default language is "<<lang<<endl;
////		}
////		config(string s)
////		{
////			lang=s;
////			cout<<"language confirmed "<<lang<<endl;
////			config::cnt+=1;
////		}
////		config( config &s){
////			lang=s.lang;
////			config::cnt+=1;
////			cout<<"copied default lang";
////		}
////		static void player_count(){
////			cout<<"active players "<<cnt;
////		
////}
////};
////int config::cnt;
////string config::default_lang="eng";
////int main(){
////	config l0;
////	config l1("hindi");
////	 static config l3;
////	config l2(l3);
////	config::player_count();
////	
////}
//#include <iostream>
//using namespace std;
//class a{
//	protected:
//		int i;
//		public:
//			a(int x)
//			{
//			i=x;
//			}
//			
//};
//class b:public a{
//	int j;
//	public:
//		b(int x,int y):a(x){
//			j=y;
//		}
//		friend void show();
//};
//void show(){
//	b B(3,4);
//	cout<<B.i<<endl<<B.j;
//}
//int main(){
//	show();
//}

#include<iostream>
using namespace std;
class Base {
public:
int value;
Base(int v) : value(v) {}
void show() { cout << "Base value: " << value << endl; }
};
class Derived1 : public Base {
public:
Derived1(int v) : Base(v) {}
};
class Derived2 : public Base {
public:
Derived2(int v) : Base(v) {}
};
class Final : public Derived1, public Derived2 {
public:
Final(int v): Derived1(v), Derived2(v) {}
void show() {
Derived1 :: show();
}
};
int main() {
Final obj(6);
obj.show();
return 0;
}
