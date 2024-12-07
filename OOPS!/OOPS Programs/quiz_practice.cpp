// // // // // #include<iostream>
// // // // // using namespace std;
// // // // // namespace A{
// // // // // int a=20;
// // // // // }
// // // // // namespace B
// // // // // {
// // // // // int a=27;
// // // // // }
// // // // // using namespace A;
// // // // // using namespace B;
// // // // // int main()
// // // // // {

// // // // // cout << a << " ";
// // // // // // using namespace B;
// // // // // // cout << a;
// // // // // return 0;
    
// // // // // }

// // // // #include <iostream>
// // // // using namespace std;
// // // // int fish = 5;
// // // // class dish
// // // // {
// // // // public:
// // // // static int fish;
// // // // };
// // // // int dish :: fish = 50;
// // // // int main()
// // // // {
// // // // int fish = 0;
// // // // cout << fish << " ";
// // // // cout << :: fish <<" ";
// // // // cout << dish :: fish << " " ;
// // // // return 0;
// // // // }

// // // #include <iostream>
// // // float operate (float a, float b)
// // // {
// // // return (a / b);
// // // }
// // // int main()
// // // {
// // // std :: cout << operate (4.5,0.5);
// // // return 0;
// // // }

// #include <iostream>
// float operate (float a, float b)
// {
// return (a / b);
// }
// int operate(int a, int b)
// {
// return a+b;
// }
// int main()
// {
// std :: cout << operate (8.5,2);
// return 0;
// }

// // #include <iostream>
// // float operate (float a, float b)
// // {
// // return (a / b);
// // }
// // int operate(int a, int b)
// // {
// // return a+b;
// // }
// // int main()
// // {
// // std :: cout << operate (11.5,4);
// // return 0;}

#include <iostream>
float operate (float a, int b)
{
return (a / b);
}
int operate(int a, int b)
{
return a+b;
}
int main()
{
std :: cout << operate (8.5,2);
return 0;}