#include <iostream>
#include <stdio.h>

using namespace std;

float yIn(float x[],  float w_new[]){
    float result = 0;
    for(int i = 0; i < 4; i++){
        result += x[i] * w_new[i];
    }
    return result;
}
float Dw(float a, float t_yin,float xi){
    return a*t_yin*xi;
}

int main()
{
    float x[4][4]={1,1,1,1,-1,1,-1,-1,1,1,1,-1,1,-1,-1,1}, Yin[4], t_yin[4], w_new[5][4]={0,0,0,0}, dw[4][4], t[4]={1,1,-1,-1}, a = 0.5;

    for(int i = 0; i < 4; i++){
        if(i == 0){
            Yin[i] = yIn(x[i], w_new[i]);
            t_yin[i] = t[i] - Yin[i];
            for(int j = 0; j < 4; j++){
                dw[i][j] = Dw(a, t_yin[i], x[i][j]);
                w_new[i + 1][j] = w_new[i][j] + (a * t_yin[i]);
            }
        }else{
            Yin[i] = yIn(x[i], w_new[i]);
            t_yin[i] = t[i] - Yin[i];
            for(int j = 0; j < 4; j++){
                dw[i][j] = Dw(a, t_yin[i], x[i][j]);
                w_new[i + 1][j] = w_new[i][j] + dw[i][j];
            }
        }
    }
    cout<<"x1\tx2\tx3\tx4\tt\tYin\tt-Yin\tdw1\tdw2\tdw3\tdw4\tw1\tw2\tw3\tw4\n";
    for(int i = 0; i < 4; i++){
        for(int j=0;j<4;j++){
            printf("%.2f\t",x[i][j]);
        }
        printf("%.2f\t%.2f\t%.2f\t",t[i],Yin[i],t_yin[i]);
        for(int j=0;j<4;j++){
            printf("%.2f\t",dw[i][j]);
        }
        for(int j=0;j<4;j++){
            printf("%.2f\t",w_new[i+1][j]);
        }
        cout<<"\n";
    }
    return 0;
}
