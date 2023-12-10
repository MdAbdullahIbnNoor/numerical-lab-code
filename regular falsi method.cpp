//Regula Falsi method
#include<bits/stdc++.h>
#define f(x) x*x*x-2*x-5
using namespace std;
int main()
{
	 float a, b, x, f0, f1, f, e;
	 int step = 1;
    // cout<< setprecision(6)<< fixed;
	// up:
	 cout<<"Enter first guess: ";
     cin>>a;
     cout<<"Enter second guess: ";
     cin>>b;
     cout<<"Enter tolerable error: ";
     cin>>e;
	 f0 = f(a);
	 f1 = f(b);
	 if( f0 * f1 > 0.0)
	 {
		  cout<<"Incorrect Initial Guesses."<< endl;
		 // goto up;
	 }
     cout<< endl<<"*******************"<< endl;
	 cout<<"False Position Method"<< endl;
	 cout<<"*******************"<< endl;
	 do
	 {
		  x = a - (a-b) * f0/ (f0-f1);
		  f = f(x);
		  cout<<"Iteration-"<< step<<":\t x = "<<  x<<" and f(x) = "<< f(x)<< endl;
		  if( f0 * f < 0)
		  {
			   b = x;
			   f1 = f;
		  }
		  else
		  {
			   a = x;
			   f0 = f;
		  }
		  step = step + 1;
	 }while(fabs(f)>e);
	 cout<< endl<<"Root is: "<< x<< endl;
	 return 0;}
