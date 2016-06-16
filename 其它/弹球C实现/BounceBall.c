/*
 * ����curses�ⵯ����Ϸ������gcc xxx.c -lcurses
 */
#include <curses.h>
#include <sys/time.h>
#include <signal.h>
 
#define RIGHT COLS-1   /*�����ܵ���ĵ�ǰ��Ļ���ˮƽ��Χ*/
#define BOTTOM LINES-1 /*�����ܵ���ĵ�ǰ��Ļ���ֱ��Χ*/
#define BOARD_LENGTH   10  /*���峤��*/
#define LEFT 0  /*��ǰ��Ļ�������*/
#define TOP 0   /*��ǰ��Ļ�����ϱ�*/
char BALL= 'O';  /*�����״*/
char BLANK= ' ';  /*�������߹��Ĺ켣*/
 

int left_board; /*�����������*/
int right_board; /*�����Ҳ�����*/
int is_lose=0;


int hdir;   /*������ˮƽ�˶��ı���*/
int vdir;   /*������ֱ�˶��ı���*/
int pos_X;  /*��ĺ�����*/
int pos_Y;  /*���������*/
      
int delay=100;
void moveBall();
void init();
void control();

int main()
{
    //��ʼ�� curses
    initscr();
    crmode();  /*�ж�ģʽ*/
    noecho();  /*�رջ���*/
     
    move(6,28);
    attron(A_BOLD);
    addstr("Welcome to the BallGame!");
    move(8,20);
    attroff(A_BOLD);
    addstr("Help:");
    move(9,23);
    addstr("'N':Start a new game.");
    move(10,23);
    addstr("'Q':Quit game.");
    move(11,23);
    addstr("'KEY_LEFT' :Control baffle left  shift.");
    move(12,23);
    addstr("'KEY_RIGHT':Control baffle right shift.");
    move(13,23);
    addstr("'KEY_UP'   :Control of the ball speed.");
    move(14,23);
    addstr("'KEY_DOWN' :Control of the ball reducer.");
    int flag=1;
    char choice;
    move(16,24);
    addstr("Please choose your choice!(n/q):");
    refresh();
    choice=getch();
    while(flag){
        if(choice=='q'||choice=='Q'||choice=='n'||choice=='N')
             flag=0;
        else  choice=getch();
    }
    if(choice=='n'||choice=='N'){    /*��ʼ��Ϸ*/
        clear();
        move(10,25);
        addstr("BallGame will start! Are you read?");
        refresh();
        sleep(3);
        control();
    }
    else if(choice=='q'||choice=='Q'){   /*�˳���Ϸ*/
        clear();
        move(10,25);
        addstr("You quit the game successfully!");
        refresh();
        sleep(3);
        endwin();
    }
    endwin();  /*���� curses*/
    return 0;
}
 
void init(){
    int i,j;
    clear();
    if(start_color()==OK){  /*�ı���͵������ɫ*/
        attron(A_BOLD);  /*�򿪴���*/
        init_pair(1,COLOR_YELLOW,COLOR_BLACK);
        attron(COLOR_PAIR(1));
    }
    //��ʼ��
    pos_X =22;  /*���ʼ�ĺ�����*/
    pos_Y = BOTTOM-1;  /*���ʼ��������*/
    //��ʼ������˶�����,�����Ϸ��˶�
    hdir=1; 
    vdir=-1;
 
    //��ʼ����
    left_board=20;
    right_board=left_board+BOARD_LENGTH;
    for(i=left_board;i<=right_board;i++){  /*��ʾ����*/
        move(BOTTOM,i);
        addch('-');
    }
 
    //��ʼˢ��ʱ��
    signal(SIGALRM,moveBall);
    set_ticker(delay);
 
    keypad(stdscr,TRUE);  /*�� keypad ������Ӧ*/
    attroff(A_BLINK);     /*�ر� A_BLINK ����*/
     
    is_lose=0;
    move(pos_Y,pos_X);
    addch(BALL);
    move(LINES-1, COLS-1);
    refresh();
    usleep(100000);  /*˯��*/
    move(LINES-1,COLS-1);
    refresh();
}
 
void moveBall(){
    if(is_lose) return;
    signal(SIGALRM,moveBall);
    move(pos_Y,pos_X);
    addch(BLANK);
    pos_X += hdir;
    pos_Y += vdir;
    //�ı���ķ���ʱ
    if(pos_X >= RIGHT) { /*�������������ұ߱�Եʱ���򷴵������˶�*/
        hdir = -1;
        beep();   /*��ײǽʱ����������*/
    }
    if(pos_X <= LEFT)  { /*��������������߱�Եʱ���򷴵������˶�*/
        hdir = 1;
        beep();  /*��ײǽʱ����������*/
    }
    if(pos_Y <= TOP)   { /*������������ڶ�����Եʱ���򷴵������˶�*/
        vdir = 1;
        beep();  /*��ײǽʱ����������*/
    }
 
    //�����ڵײ���ʱ����ж���Ĵ���
    if(pos_Y >= BOTTOM-1){
        if(pos_X>=left_board&&pos_X<=right_board)  /*���ڵ��崦*/
            vdir=-1;
        else{    /*���ڵ��崦*/
            is_lose=1;
            move(pos_Y,pos_X);
            addch(BALL);
            move(LINES-1, COLS-1);
            refresh();
            usleep(delay*1000);  /*˯��*/
            move(pos_Y,pos_X);
            addch(BLANK);
            pos_X += hdir;
            pos_Y += vdir;
            move(pos_Y,pos_X);
            addch(BALL);
            move(LINES-1, COLS-1);
            refresh();
        }
    }
    //���ı���ķ���ʱ
    move(pos_Y,pos_X);
    addch(BALL);
    move(LINES-1, COLS-1);
    refresh();
}
void control(){
    init();
    int cmd;
    while (1)
    {     
        if(!is_lose){
            cmd=getch();
            if(cmd=='q'||cmd=='Q'||cmd==27) break;  //ǿ���˳���Ϸ
            //��������
            if(cmd==KEY_LEFT){
                if(left_board>0){
                    move(BOTTOM,right_board);
                    addch(' ');
                    right_board--;
                    left_board--;                     
                    move(BOTTOM,left_board);
                    addch('-');
                    move(BOTTOM,RIGHT);
                    refresh();
                }
            }     
            //��������
            else if(cmd==KEY_RIGHT){
                if(right_board<RIGHT){
                    move(BOTTOM,left_board);
                    addch(' ');
                    right_board++;
                    left_board++;
                    move(BOTTOM,right_board);
                    addch('-');
                    move(BOTTOM,RIGHT);
                    refresh();
                }
            }
            //�������
            else if(cmd==KEY_UP){   
                delay/=2;     
                set_ticker(delay);
            }
            //�������
            else if(cmd==KEY_DOWN){  
                delay*=2;
                set_ticker(delay);
            }
         
        }
        else{
            //������Ĵ���
            int flag=1;
            char choice;
            move(8,15);
            addstr("Game Over!try again?(y/n):");
            refresh();
            choice=getch();
 
            while(flag){
                if(choice=='y'||choice=='Y'||choice=='n'||choice=='N')
                     flag=0;
                else  choice=getch();
            }
            if(choice=='y'||choice=='Y'){  /*��Ϸ���¿�ʼ*/
                    delay=100; /*�ָ���ĳ�ʼ�ٶ�*/
                    init();
                    continue;
            }
            else if(choice=='n'||choice=='N'){   /*������Ϸ*/
                    break;
            }
        }
    }
}
//���ö�ʱ��
int set_ticker(int n_msecs){
    struct itimerval new_timeset;     
    long n_sec,n_usecs;
    n_sec=n_msecs/1000;
    n_usecs=(n_msecs%1000)*1000L;
    new_timeset.it_interval.tv_sec=n_sec;
    new_timeset.it_interval.tv_usec=n_usecs;
    new_timeset.it_value.tv_sec=n_sec;
    new_timeset.it_value.tv_usec=n_usecs;
    return setitimer(ITIMER_REAL,&new_timeset,NULL); 
}
