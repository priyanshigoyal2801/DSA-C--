#include <vector>
#include <iostream>

using namespace std;

void diagCreator(int n, int m){
    cout << "Enter the diagonal elements: ";
    vector <int> diagElements;
    int ele;
    for (int i=0; i< min(m,n);i++){
        cin>>ele;
        diagElements.push_back(ele);
    }
    cout << "The required diagonal matrix is: "<<endl ;
    for (int i=0; i< n;i++){
        for (int j=0; j< m;j++){
            if (i==j)
            cout << diagElements[i] << " ";
            else
            cout << "0 ";
            }
            cout << endl ;
            }
}

void TridiagCreator(int n, int m){
    cout << "Enter the diagonal elements";
    vector <int> diagElements;
    int ele;
    for (int i=0; i< min(m,n);i++){
        cin>>ele;
        diagElements.push_back(ele);
        }
        cout << "Enter the upper diagonal elements";
        vector <int> upperDiagElements;
        for (int i=0; i< min(m,n);i++){
            cin>>ele;
            upperDiagElements.push_back(ele);
            }
            cout << "Enter the lower diagonal elements";
            vector <int> lowerDiagElements;
            for (int i=0; i< min(m,n)-1;i++){ 
                cin>>ele;
                lowerDiagElements.push_back(ele);
                }
        cout << "The matrix is as follows: "<<endl;
        for (int i=0; i< n;i++){
            for (int j=0; j< m;j++){
                if (i==j)
                cout << diagElements[i] << " ";
                else if (i==j-1)
                cout << upperDiagElements[i] << " ";
                else if (i==j+1)
                cout << lowerDiagElements[i-1] << " ";
                else
                cout << "0 ";
                }
                cout << endl ;
                }
}

void LowertriangularMatrix(int n, int m){
    cout << "Enter the diagonal elements"<< endl;
    vector <int> diagElements, triElements;
    int ele;
    for (int i=0; i< min(m,n);i++){
        cin>>ele;
        diagElements.push_back(ele);
        }
    cout << "Enter the triangular elements in order: "<< endl;
    for (int i=0; i< n;i++){
            for (int j=0; j< m;j++){
                if (j<i){
                cin >> ele;
                triElements.push_back(ele);
            }}
    }

        cout << "The matrix is as follows: "<<endl;
        for (int i=0; i< n;i++){
            for (int j=0; j< m;j++){
                
                if (i==j)
                cout << diagElements[i] << " ";
                else if (j<i){
                if (i==n)
                cout << triElements[j+i] << " ";
                else
                cout << triElements[j+i-1] << " ";
                }
                else
                cout << "0 ";
            }   
            cout <<endl;
        }
}

void UppertriangularMatrix(int n, int m){
    cout << "Enter the diagonal elements"<< endl;
    vector <int> diagElements, triElements;
    int ele;
    for (int i=0; i< min(m,n);i++){
        cin>>ele;
        diagElements.push_back(ele);
        }
        cout << "Enter the triangular elements in order: "<< endl;
        for (int i=0; i< n;i++){
            for (int j=0; j< m;j++){
                if (j>i){
                    cin >> ele;
                    triElements.push_back(ele);
                }
            }
        }
        // for (int k=0; k<triElements.size();k++){
        //     cout << triElements[k] << " "; 
        // }
        cout << endl;
        cout << "The matrix is as follows: "<<endl;
        int p=0;
        for (int i=0; i< n;i++){
            for (int j=0; j<m;j++){
                
                if (i==j)
                cout << diagElements[i] << " ";
                else if (j>i)
                cout << triElements[p++] << " ";
                // {
                // if (i==0)
                // cout << triElements[j+i-1] << " ";
                // else
                // cout << triElements[j+i+i] << " ";
                // }
                else
                cout << "0 ";
            }   
            cout <<endl;
        }
}

void SymmetricMatrix(int n, int m){
    if (n!=m){
    cout << "It's not a square matrix!"<<endl;
    exit(0);
}
    cout << "Enter the diagonal elements: ";
    vector <int> diagElements, symElements;
    int ele;
    for (int i=0; i<min(m,n);i++){
        cin>>ele;
        diagElements.push_back(ele);
        }
        cout << "Enter the symmetric elements in order: "<< endl;
        for (int i=0; i< n;i++){
            for (int j=0; j< m;j++){
                if (j>i){
                    cin >> ele;
                    symElements.push_back(ele);
                }
            }
        }
                // for (int k=0; k<symElements.size();k++){
                //     cout << symElements[k] << " ";
                // }
                cout << endl;
                cout << "The matrix is as follows: "<<endl;
                int p=0,k=0;
                for (int i=0; i< n;i++){
                    for (int j=0; j<n;j++){
                        if (i==j)
                        cout << diagElements[j] << " ";
                        else if (j>i)
                        cout << symElements[p++] << " ";
                        else if (i>j)
                        cout << symElements[k++] << " ";
                        }
                        cout <<endl;
                }
}

int main()
{
    int n,m;
    cout << "Enter the no. of rows and columns: ";
    cin >>n >> m;
    cout << "What u wanna do?! :"<<endl;
    cout << "1. Create a matrix"<<endl;
    cout << "2. Create a tridiagonal matrix"<<endl;
    cout << "3. Lower Triangular Matrix"<<endl;
    cout << "4. Upper Triangular Matrix"<<endl;
    cout << "5. Symmetric Matrix"<<endl;
    cout << "6. Exit"<<endl;

    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        diagCreator(n,m);
        break;
    case 2:
        TridiagCreator(n,m);
        break;
    case 3:
        LowertriangularMatrix(n,m);
        break;
    case 4:
        UppertriangularMatrix(n,m);
        break;
    case 5:
        SymmetricMatrix(n,m);
        break;
    default:
        break;
    }
    
    return 0;
}
