#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool FimdeJogo;
const int altura=20;
const int largura=20;

int cabecax, cabecay;
int frutax, frutay;
int pontos;
int rabicox[100], rabicoy[100], nrabico;

enum eDirection{ STOP=0, UP, DOWN, LEFT, RIGHT};
eDirection dir;


void Setup(){
    FimdeJogo=false;

    dir=STOP;

    cabecax=largura/2;
    cabecay=altura/2;

    frutax=rand() %largura;
    frutay=rand() %altura;
}
void Empate(){

    system("cls");

    for(int i=0; i<largura; i++){
        cout<<"#";
    }cout<<endl;

    for(int i=0; i<altura; i++){
        for(int j=0; j<largura; j++){
            if(j==0 || j==largura-1){
                cout<<"#";
            }else if(i==cabecay && j==cabecax){
                cout<<"O";
            }else if(i==frutay && j==frutax){
                cout<<"+";
            }else{

                bool print=false;

                for(int k=0; k<nrabico; k++){
                    if(i==rabicoy[k] && j==rabicox[k]){
                        cout<<"O";
                        print=true;
                    }
                }if(!print){cout<<" ";}
            }
        }cout<<endl;
    }

    for(int i=0; i<largura; i++){
        cout<<"#";
    }cout<<endl;
    cout<<endl;
    cout<<"Pontuacao: "<<pontos<<endl;
}
void Input(){
    if(_kbhit()){
        switch(_getch()){
        case 'w':
            dir=UP;
            break;
        case 's':
            dir=DOWN;
            break;
        case 'a':
            dir=LEFT;
            break;
        case 'd':
            dir=RIGHT;
            break;
        default:
            break;
        }
    }
}
void Logica(){

    int antx=rabicox[0];
    int anty=rabicoy[0];
    rabicox[0]=cabecax;
    rabicoy[0]=cabecay;
    int ant2x, ant2y;

    for(int i=1; i<nrabico; i++){
        ant2x=rabicox[i];
        ant2y=rabicoy[i];
        rabicox[i]=antx;
        rabicoy[i]=anty;
        antx=ant2x;
        anty=ant2y;
    }

    switch(dir){
        case UP:
            cabecay--;
            break;
        case DOWN:
            cabecay++;
            break;
        case LEFT:
            cabecax--;
            break;
        case RIGHT:
            cabecax++;
            break;
        default:
            break;
    }
    if(cabecax<0 || cabecax>largura || cabecay<0 || cabecay>altura){
        FimdeJogo=true;
    }

    for(int i=0;i<nrabico;i++){
        if(cabecax==rabicox[i] && cabecay==rabicoy[i]){
            FimdeJogo=true;
        }
    }

    if(cabecax==frutax && cabecay==frutay){
        pontos+=10;
        frutax=rand() %largura;
        frutay=rand() %altura;
        nrabico++;
    }
}

int main(){

    char JogarNovamente;

    do{

        Setup();
        while(!FimdeJogo){
            Empate();
            Input();
            Logica();
            Sleep(80);

        }

        system("cls");
        cout<<"Fim de Jogo, deseja jogar novamente? (s/n)";
        cin>>JogarNovamente;
    }while(JogarNovamente='s' || JogarNovamente=='S');

    return 0;
}

