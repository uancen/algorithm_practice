#include <cstdio>

int main()
{
    double a = 86*3+92*0.5+90*1.5+93*5.0+86*3.0+90*0.5+85*3.0+94*0.5+93*4.0+90*0.5+97*2.5
                +93*2.0+91*3.0+94*3.0+85*2.5+89*3.0+92*0.5+85*3.0+94*3.0+92*0.5+90*3.0+83*4.0+90*3.0+93*2.5;
    double c = 4*(3+0.5+1.5+5+3+0.5+3+0.5+4+0.5+2.5+2+3+3+2.5+3+0.5+3+3+0.5+3+3+2.5)+3.8*4;
    double b =    3+0.5+1.5+5+3+0.5+3+0.5+4+0.5+2.5+2+3+3+2.5+3+0.5+3+3+0.5+3+4+3+2.5;
    printf("%f",c/b);
}