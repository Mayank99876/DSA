// Online C++ compiler to run C++ program online
#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;

double calculateDistance(double,double,double,double);
double calculateCircleArea(double,double,double,double);
int amount(int,int);

int main(){
    int x1,x2,x3,y1,y2,y3,A1,A2,ans;
    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>x3>>y3;
    A1 = calculateCircleArea(x1,y1,x2,y2);
    A2 = calculateCircleArea(x1,y1,x3,y3); 
    // cout<<"A1 is "<<A1<<endl;
    // cout<<"A2 is "<<A2<<endl;
    ans = amount(A1,A2);
    if(A1 == A2){
        cout<<"-1";
    }
    else if(A1>A2){
        cout<<"Shiva  "<<ans;
    }
    else{
        cout<<"Krishna  "<<ans;
    }

return 0;
}

double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to calculate the area of a circle given center coordinates and a point on the circumference
double calculateCircleArea(double centerX, double centerY, double pointX, double pointY) {
    int radius = calculateDistance(centerX, centerY, pointX, pointY) +1;
    return M_PI * pow(radius, 2);
}

int amount(int A1, int A2){
    int A3 = A1 - A2;
    int ans = abs(A3);
    int sqrt1 = sqrt(ans) +1;
    int pow1 = pow(sqrt1,2);
    return abs(pow1-ans)*20;
}