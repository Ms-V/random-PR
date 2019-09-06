#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define NAME_MAX 30
#define MAX_LOCAL 30

int random_times;


struct map{ 
    int map_id;
    char map_name[NAME_MAX];
    struct local
    {
        int local_id;
        char local_name[NAME_MAX];
        int max_player;
    }loacl_map[MAX_LOCAL];
};
char * random_local(int player_num,struct map * map_chose);
int du_check_int[4];

int game_times=0;
int enter_check(int);
int local_re_check(int ,int );


struct least_10s{
    int id;
    char mapname[NAME_MAX];
    int map_id;
    char localname[NAME_MAX];
    int local_id;
}least_10_r[10];
void least_10();

int main()
{
    struct map pubg[4] = {
        {1,"艾伦格",{{1,"G港上城",4},{2,"G港下城",4},{3,"钢塔！",2},{4,"P港",4},{5,"S城",4},{6,"R城",4},{7,"学校",4},{8,"学区房",4},{9,"P城",4},{10,"机场",4},{11,"Z城",2},{12,"靶场",2},{13,"K城",4},{14,"Y城",4},{15,"马蹄山",2},{16,"M城",4},{17,"L港",4},{18,"大电",4},{19,"小电",2},{20,"N港",4}}},
        {2,"米拉玛",{{1,"A城",3},{2,"EL",4},{3,"M城",4},{4,"V港",4},{5,"监狱",4},{6,"火车站",4},{7,"电厂",2},{8,"左月球坑",2},{9,"劈叉多",4},{10,"圣马丁",4},{11,"C城",4},{12,"狮城",4},{13,"墓地",3},{14,"月球坑",2},{15,"矿山",4},{16,"豪宅",4},{17,"水厂",3},{18,"TA",4},{19,"CDV",4},{20,"EA",4},{21,"TB",4},{22,"军事基地",4},{23,"I城",4},{24,"PP",4}}},
        {3,"萨  诺",{{1,"HA",4},{2,"CA",4},{3,"神庙",4},{4,"左盐场",2},{5,"NA K",4},{6,"Sahmee",4},{7,"Ban Tai",4},{8,"CC",4},{9,"Pai Nan",4},{10,"自闭城",4},{11,"专业打野",4},{12,"伐木场",4},{13,"Khao",4},{14,"度假村",4},{15,"矿场",3},{16,"Mongnai",2},{17,"CB",4},{18,"右盐场",2},{19,"Kampong",4},{20,"港口",2}}},
        {4,"维寒迪",{{1,"Pott",4},{2,"Krichas",4},{3,"Dobro Mesto",4},{4,"Vihar",4},{5,"Movatra",4},{6,"Sawmill",2},{7,"Milnar",4},{8,"恐龙公园",4},{9,"G城",4},{10,"Zabava",4},{11,"矿山",4},{12,"Mount K",3},{13,"Villa",4},{14,"Tovar",4},{15,"Abbey",4},{16,"酒庄",4},{17,"Volnova",4},{18,"城堡",4},{19,"Podvosto",4},{20,"火箭基地",4},{21,"Trevno",4},{22,"猪村",2},{23,"化工产",4},{24,"垃圾场",2},{25,"温泉",2},{26,"Cantra",4}}},
    };
    int player;
    int enter_cheack_main;
    int chose_map;
    for(int count_c = 0; count_c < 10;count_c++)
    {
        least_10_r[count_c].id = -1;
    }
    puts("几个人(输入1到4)?按0退出！！！！");
    while((player = getch())!='0')
    {
        system("cls");
        player = player - '0';
        enter_cheack_main=enter_check(player);
        if(enter_cheack_main==1)
        {   
            puts("选图！！！按0返回更改人数！！！");
            printf("1.%s\n",pubg[0].map_name);
            printf("2.%s\n",pubg[1].map_name);
            printf("3.%s\n",pubg[2].map_name);
            printf("4.%s\n",pubg[3].map_name);
            printf("当前游戏次数为：%d\n",game_times);
            least_10();
            while((chose_map=getch())!='0')
            {
                chose_map = chose_map - '0';
                enter_cheack_main=enter_check(chose_map);
                if(enter_cheack_main==1)
                {  
                    printf("就决定了！！！跳这里！！%s",random_local(player,&pubg[chose_map-1]));
                    game_times++;
                    Sleep(5000);
                    system("cls");
                    puts("选图！！！按0返回更改人数！！！");
                    printf("1.%s\n",pubg[0].map_name);
                    printf("2.%s\n",pubg[1].map_name);
                    printf("3.%s\n",pubg[2].map_name);
                    printf("4.%s\n",pubg[3].map_name);
                    printf("当前游戏次数为：%d\n",game_times);
                    least_10();
                }
                else
                {
                    puts("输入错误！！！！！一到四就行");
                    Sleep(5000);
                    system("cls");
                    puts("选图！！！按0返回更改人数！！！");
                    printf("1.%s\n",pubg[0].map_name);
                    printf("2.%s\n",pubg[1].map_name);
                    printf("3.%s\n",pubg[2].map_name);
                    printf("4.%s\n",pubg[3].map_name);
                    printf("当前游戏次数为：%d\n",game_times);
                    least_10();
                }
            }
            Sleep(5000);
            system("cls");
            puts("来吧重新输几个人！！！");
        }
        else
        {
            puts("输入错误！！！！！一到四就行");
            Sleep(5000);
            system("cls");
            puts("几个人(输入1到4)?按0退出！！！！");
        }
    }
}

char * random_local(int player_num,struct map * map_chose)
{
    srand(time(0));
    int rand_num;
    do{
        rand_num=(int)rand() % MAX_LOCAL + 1;
    } while (map_chose->loacl_map[rand_num-1].max_player<player_num||(local_re_check(map_chose->map_id,map_chose->loacl_map[rand_num-1].local_id))==0);
    for (int count = 0; count < 10;count++)
    {
        if(least_10_r[count].id==-1)
        {
            memcpy(least_10_r[count].localname,map_chose->loacl_map[rand_num - 1].local_name,sizeof(char)*NAME_MAX);
            least_10_r[count].id = count;
            memcpy(least_10_r[count].mapname,map_chose->map_name,sizeof(char)*NAME_MAX);
            least_10_r[count].local_id = map_chose->loacl_map[rand_num - 1].local_id;
            least_10_r[count].map_id = map_chose->map_id;
            return map_chose->loacl_map[rand_num-1].local_name;
        }
    }
    for (int recount = 9; recount  >0;recount--)
    {
        memcpy(least_10_r[recount].localname,least_10_r[recount-1].localname,sizeof(char)*NAME_MAX);
        memcpy(least_10_r[recount].mapname,least_10_r[recount-1].mapname,sizeof(char)*NAME_MAX);
        least_10_r[recount].local_id = least_10_r[recount - 1].local_id;
        least_10_r[recount].map_id = least_10_r[recount - 1].map_id;
    }
    memcpy(least_10_r[0].localname,map_chose->loacl_map[rand_num - 1].local_name,sizeof(char)*NAME_MAX);
    memcpy(least_10_r[0].mapname,map_chose->map_name,sizeof(char)*NAME_MAX);
    least_10_r[0].local_id = map_chose->loacl_map[rand_num - 1].local_id;
    least_10_r[0].map_id = map_chose->map_id;
    return map_chose->loacl_map[rand_num-1].local_name;
}

int enter_check(int enter)
{
    if(enter<1)
    {
        return 0;
    }
    else if(enter>4)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void least_10()
{
    puts("");
    puts("近10次跳伞记录");
    for (int count = 0; count < 10;count++)
    {
        if(least_10_r[count].id==-1)
            break;
        else
            printf("%d. %s的%s\n",least_10_r[count].id+1,least_10_r[count].mapname,least_10_r[count].localname);
    }
    puts("");
}

int local_re_check(int map_in,int local_in)//1为返回退出，表示没有一样的
{
    int total_local=0;
    for (int count_local = 0; count_local < 5;count_local++)
    {
        if(least_10_r[count_local].id==-1)
        {
            if(count_local==0)
            {
                return 1;
            }
            else
            {
                break;
            }
        }
        else
        {
            total_local++;
        }
    }
    for (int count_check = 0; count_check < total_local;count_check++)
    {
        if(least_10_r[count_check].local_id==local_in&&least_10_r[count_check].map_id==map_in)
        {
            return 0;
        }
    }
    return 1;
}