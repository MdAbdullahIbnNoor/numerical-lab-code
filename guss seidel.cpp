#include <bits/stdc++.h>
using namespace std;
float coeff[3][4];

void change(int a,int b){
    float temp;
    for(int i=0; i<4; i++){
        temp=coeff[a][i];
        coeff[a][i]=coeff[b][i];
        coeff[b][i]=temp;
    }
}

int find_big(int a){
    if(fabs(coeff[a][0])>=fabs(coeff[a][2])+fabs(coeff[a][1])){
        return 0;
    }
    if(fabs(coeff[a][1])>=fabs(coeff[a][0])+fabs(coeff[a][2])){
        return 1;
    }
    else{
        return 2;
    }
}

void rearrange(){
    for(int i=0; i<3; i++){
        if(find_big(i)!=i){
            change(find_big(i),i);
        }
    }
}

int main() {
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cin>>coeff[i][j];
        }
    }
    rearrange();
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<coeff[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<setprecision(6)<<fixed;
    int step=0;
    float x1=0,y1=0,z1=0,x,y,z,error,tolerance=.000001;
    do{
        step++;
        x=(-coeff[0][1]*y1-coeff[0][2]*z1+coeff[0][3])/coeff[0][0];
        y=(-coeff[1][0]*x-coeff[1][2]*z1+coeff[1][3])/coeff[1][1];
        z=(-coeff[2][0]*x-coeff[2][1]*y+coeff[2][3])/coeff[2][2];
        cout<<step<<"    "<<x1<<"    "<<y1<<"    "<<z1<< endl;
        error= fabs(x-x1);
        if(fabs(y-y1)>error)
            error= fabs(y-y1);
        if(fabs(z-z1)>error)
            error= fabs(z-z1);
        x1=x;
        y1=y;
        z1=z;
    }
    while(error>tolerance);

    cout<<"x : "<<x<<endl
        <<"y : "<<y<<endl
        <<"z : "<<z<<endl;


    return 0;
}


/*
5 3 20 14
20 5 3 15
5 20 3 13
 */
