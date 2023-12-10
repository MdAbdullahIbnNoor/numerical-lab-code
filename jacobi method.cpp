
#include <bits/stdc++.h>
using namespace std;
float arr[3][4];

void Interchange(int a,int b){
    float temp;
    for(int i=0; i<4; i++){
        temp=arr[a][i];
        arr[a][i]=arr[b][i];
        arr[b][i]=temp;
    }
}

int Find_Max(int a){
    if(fabs(arr[a][0])>=fabs(arr[a][2])+fabs(arr[a][1])){
        return 0;
    }
    if(fabs(arr[a][1])>=fabs(arr[a][0])+fabs(arr[a][2])){
        return 1;
    }
    else{
        return 2;
    }
}

void Re_arrange(){
    for(int i=0; i<3; i++){
        if(Find_Max(i)!=i){
            Interchange(Find_Max(i),i);
        }
    }
}

int main() {
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cin>>arr[i][j];
        }
    }
    Re_arrange();
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<setprecision(6)<<fixed;
int step=0;
    float x1=0,y1=0,z1=0,x,y,z,Error,Tol=.000001;
    do{
        step++;
        x=(-arr[0][1]*y1-arr[0][2]*z1+arr[0][3])/arr[0][0];
        y=(-arr[1][0]*x1-arr[1][2]*z1+arr[1][3])/arr[1][1];
        z=(-arr[2][0]*x1-arr[2][1]*y1+arr[2][3])/arr[2][2];
        cout<<step<<"    "<<x1<<"    "<<y1<<"    "<<z1<< endl;
        Error= fabs(x-x1);
        if(fabs(y-y1)>Error)
            Error= fabs(y-y1);
        if(fabs(z-z1)>Error)
            Error= fabs(z-z1);
        x1=x;
        y1=y;
        z1=z;
    }
    while(Error>Tol);

    cout<<"x : "<<x<<endl
       <<"y : "<<y<<endl
       <<"z : "<<z<<endl;


    return 0;
}


/*
5 3 20 14
20 5 3 15
5 20 3 13*/
