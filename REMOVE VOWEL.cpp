#include<iostream>
#include<string>
using namespace std;
int main(){
string s;
cout<<"enter string in lowercase";
getline(cin,s);
int n=s.length();
string result;
for(int i=0; i<n; ++i){
	char c=s[i];
	if(c != 'a' && c != 'e'&&c !=' i'&&c != 'o'&&c != 'u'){
		result+=c;
	}
}
cout<<endl<<result;
}

//#include<iostream>
//#include<string>
//using namespace std;
//
//int main() {
//    string s;
//    cout << "Enter string in lowercase: ";
//    getline(cin, s);
//
//    int n = s.length();
//    string result;
//
//    for(int i = 0; i < n; i++) {
//        char c = s[i];
//        // Correct condition to exclude vowels
//        if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
//            result += c;
//        }
//    }
//
//    cout << "String after deleting vowels: " << result << endl;
//
//    return 0;
//}

