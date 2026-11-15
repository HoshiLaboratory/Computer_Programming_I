#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


#define board_size 20
#define プレイヤー 1
#define 敵 2
#define 空白 0

int board[board_size][board_size];
int Time = 0;

void Start(void){
    for(int i=0;i<board_size;i++){
        for(int j=0;j<board_size;j++){
            board[i][j]=空白;
        }
    }
        printf("初期化完了(%dx%d)\n",board_size,board_size);
}

void Printboard(void){
    printf("   ");
    for(int i=0;i<board_size;i++){
        if(i<9){
            printf("%2d",i + 1);
        }
        else{
            printf("%2d",((i + 1)/10)%10);
        }
    }
    if(board_size>10){
        printf("\n");
        printf("   ");
        for(int i=0;i<board_size;i++){
            if(i<9){
                printf("  ");
            }
            else{
                printf("%2d",(i + 1)%10);
            }
        }
    }
    printf("\n\n");
    for(int i=0;i<board_size;i++){
        printf("%2d ",i + 1);
    for(int j=0;j<board_size;j++){
        switch(board[i][j]){
            case 空白:
                printf(" +");
                break;
            case プレイヤー:
                printf(" ●");
                break;
            case 敵:
                printf(" ○");
        
            }
        }
        printf("\n");
    }
}

void Player(int *Lx,int *Ly){
    int x,y;
    while(1){
        printf("\n置く位置を入力： x   y\n");
        if (scanf("%d %d", &x, &y) != 2)
        {
            printf("数値を2つ入力してください\n");
            while(getchar() != '\n');
            continue;
        }
        if(x<=0||x>=board_size + 1||y<=0||y>=board_size + 1){
            printf("範囲外\n");
            continue;
        }
        if(board[y - 1][x - 1] != 空白){
            printf("既に置かれています\n");
            continue;
        }
        board[y-1][x-1] = プレイヤー;
        *Lx = x-1;
        *Ly = y-1;
        break;
    }
}

bool is_stone_judge(int x,int y){
    return (x>=0&&x<board_size&&y>=0&&y<board_size);
}

bool Win(int x,int y,int Turn){
    int dx[4] = {0,1,1,-1};
    int dy[4] = {1,0,1,1};
    for(int i=0;i<4;i++){
        int count = 1;
        int nx = x + dx[i];
        int ny = y + dy[i];
        while(is_stone_judge(nx,ny)&&board[ny][nx]==Turn){
            count++;
            nx += dx[i];
            ny += dy[i];
        }
        nx = x - dx[i];
        ny = y - dy[i];
        while(is_stone_judge(nx,ny)&&board[ny][nx]==Turn){
            count++;
            nx -= dx[i];
            ny -= dy[i];
        }
        if(count>=5){
            return true;
        }
    }
    return false;
}   

bool is_Full(void){
    for(int i=0;i<board_size;i++){
        for(int j=0;j<board_size;j++){
            if(board[i][j]==空白){
                return false;
            }
        }
    }
    return true;
}

bool check(int x,int y,int Turn,int required_count){

    
    int dx[4] = {0,1,1,-1};
    int dy[4] = {1,0,1,1};
    for(int i=0;i<4;i++){
        int count = 1;
        int nx = x + dx[i];
        int ny = y + dy[i]; 
        while(is_stone_judge(nx,ny)&&board[ny][nx]==Turn){
            count++;
            nx += dx[i];
            ny += dy[i];
        }
        nx = x - dx[i];
        ny = y - dy[i];
        while(is_stone_judge(nx,ny)&&board[ny][nx]==Turn){
            count++;
            nx -= dx[i];
            ny -= dy[i];
        }
        if(count>=required_count){
            return true;
        }
    }
    return false;
}

void Enemy(int *Lx,int *Ly){

    for(int i=0;i<board_size;i++){
        for(int j=0;j<board_size;j++){
            if(board[i][j]==空白&&check(j,i,敵,5)){
                board[i][j]=敵;
                *Lx = j;
                *Ly = i;
                return;
            }
        }
    }

    for(int i=0;i<board_size;i++){
        for(int j=0;j<board_size;j++){
            if(board[i][j]==空白&&check(j,i,プレイヤー,5)){
                board[i][j]=敵;
                *Lx = j;
                *Ly = i;
                return;
            }
        }
    }
    for(int i=0;i<board_size;i++){
        for(int j=0;j<board_size;j++){
            if(board[i][j]==空白&&check(j,i,敵,4)){
                board[i][j]=敵;
                *Lx = j;
                *Ly = i;
                return;
            }
        }
    }

    for(int i=0;i<board_size;i++){
        for(int j=0;j<board_size;j++){
            if(board[i][j]==空白&&check(j,i,プレイヤー,4)){
                board[i][j]=敵;
                *Lx = j;
                *Ly = i;
                return;
            }
        }
    }

    for(int i=0;i<board_size;i++){
        for(int j=0;j<board_size;j++){
            if(board[i][j]==空白&&check(j,i,敵,3)){
                board[i][j]=敵;
                *Lx = j;
                *Ly = i;
                return;
            }
    }
}
        for(int i=0;i<board_size;i++){
        for(int j=0;j<board_size;j++){
            if(board[i][j]==空白&&check(j,i,敵,2)){
                board[i][j]=敵;
                *Lx = j;
                *Ly = i;
                return;
            }
    }
}



    while(1){
        int x = rand()%board_size;
        int y = rand()%board_size;
        if(board[y][x]==空白){
            board[y][x]=敵;
            *Lx = x;
            *Ly = y;
            return;
        }
    }
    
}

int main(){
    int Lx,Ly;

    Start();
    while(1){
    Printboard();
    Player(&Lx,&Ly);

    if(Win(Lx,Ly,プレイヤー)){
        Printboard();
        printf("勝利\n");
        break;
    }

    if(is_Full()){
        Printboard();
        printf("引き分け\n");
        break;
    }
    if(Time == 0){
    Time = 1;
    if(is_stone_judge(Ly, Lx + 1)){
    board[Ly][Lx+1]=敵;
    }
    else{
    board[Ly][Lx-1]=敵;
    }
    }
    else{
    Enemy(&Lx,&Ly);
    }
    if(Win(Lx,Ly,敵)){
        Printboard();
        printf("敗北\n");
        break;
    }

    if(is_Full()){
        Printboard();
        printf("引き分け\n");
        break;
    }
    }

    return 0;
}