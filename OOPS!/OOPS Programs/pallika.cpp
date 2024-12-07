#include<iostream>
using namespace std;
class Config
{
	static string default_lang;
	string lang;
	static int id;
	public:
		Config(){
		++id;
		lang=default_lang;
		cout<<endl;
	if(id>0)
		cout<<"As no any input for language, we set default for you, Thank You";}
		Config(string ll)
		{	++id;
			lang=ll;
			cout<<endl;
			cout<<"your selected option is "<<lang<<endl;
		}
		Config(Config &cc)
		{	++id;
			lang=cc.lang;
			cout<<"you clicked on default setting"<<endl;
		}
		static void display()
		{	cout<<endl;
			cout<<"The number of players joined the game: "<<id;
		}
};
string Config:: default_lang="Hindi";
int Config::id=-1;
int main()
{	
	 static Config for_all;//default setting
	 Config player1;
	 Config player2("Punjabi");
	 Config player3(for_all);
	 Config::display();
}