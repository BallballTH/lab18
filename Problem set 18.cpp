#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Rect{
    double x,y,w,h;
};

Rect MergedRect(Rect &r1,Rect &r2){
    double w = max(r1.x+r1.w,r2.x+r2.w)-min(r1.x,r2.x);
	double h = max(r1.y,r2.y) - min(r1.y-r1.h,r2.y-r2.h);
    double x = max(r1.x+r1.w,r2.x+r2.w)-w;
	double y = max(r1.y,r2.y);
	if(min(w,h)>0) return {x,y,w,h};
	else return {0,0,0,0};
}

int main(){
    Rect rect1,rect2,Mergedrect;
    cout <<  "Please input Rect 1 (x y w h) : ";
    cin >> rect1.x >> rect1.y >> rect1.w >> rect1.h;
    cout <<  "Please input Rect 2 (x y w h) : ";
    cin >> rect2.x >> rect2.y >> rect2.w >> rect2.h;  
    Mergedrect = MergedRect(rect1,rect2);
    cout << "Merged Rect = " << Mergedrect.x << " " << Mergedrect.y << " " << Mergedrect.w << " " << Mergedrect.h << endl;
}