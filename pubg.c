#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
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

int main()
{
    struct map pubg[4] = {
        {1,"���׸�",{{1,"G���ϳ�",4},{2,"G���³�",4},{3,"������",2},{4,"P��",4},{5,"S��",4},{6,"R��",4},{7,"ѧУ",4},{8,"ѧ����",4},{9,"P��",4},{10,"����",4},{11,"Z��",2},{12,"�г�",2},{13,"K��",4},{14,"Y��",4},{15,"����ɽ",2},{16,"M��",4},{17,"L��",4},{18,"���",4},{19,"С��",2},{20,"N��",4}}},
        {2,"������",{{1,"A��",3},{2,"EL",4},{3,"M��",4},{4,"V��",4},{5,"����",4},{6,"��վ",4},{7,"�糧",2},{8,"�������",2},{9,"�����",4},{10,"ʥ��",4},{11,"C��",4},{12,"ʨ��",4},{13,"Ĺ��",3},{14,"�����",2},{15,"��ɽ",4},{16,"��լ",4},{17,"ˮ��",3},{18,"TA",4},{19,"CDV",4},{20,"EA",4},{21,"TB",4},{22,"���»���",4},{23,"I��",4},{24,"PP",4}}},
        {3,"��  ŵ",{{1,"HA",4},{2,"CA",4},{3,"����",4},{4,"���γ�",2},{5,"NA K",4},{6,"Sahmee",4},{7,"Ban Tai",4},{8,"CC",4},{9,"Pai Nan",4},{10,"�Աճ�",4},{11,"רҵ��Ұ",4},{12,"��ľ��",4},{13,"Khao",4},{14,"�ȼٴ�",4},{15,"��",3},{16,"Mongnai",2},{17,"CB",4},{18,"���γ�",2},{19,"Kampong",4},{20,"�ۿ�",2}}},
        {4,"ά����",{{1,"Pott",4},{2,"Krichas",4},{3,"Dobro Mesto",4},{4,"Vihar",4},{5,"Movatra",4},{6,"Sawmill",2},{7,"Milnar",4},{8,"������԰",4},{9,"G��",4},{10,"Zabava",4},{11,"��ɽ",4},{12,"Mount K",3},{13,"Villa",4},{14,"Tovar",4},{15,"Abbey",4},{16,"��ׯ",4},{17,"Volnova",4},{18,"�Ǳ�",4},{19,"Podvosto",4},{20,"�������",4},{21,"Trevno",4},{22,"���",2},{23,"������",4},{24,"������",2},{25,"��Ȫ",2},{26,"Cantra",4}}},
    };
    int player;
    int enter_cheack_main;
    int chose_map;
    puts("������(����1��4)?��0�˳���������");
    while((player = getch())!='0')
    {
        system("cls");
        player = player - '0';
        enter_cheack_main=enter_check(player);
        if(enter_cheack_main==1)
        {   
            puts("ѡͼ��������0���ظ�������������");
            printf("1.%s\n",pubg[0].map_name);
            printf("2.%s\n",pubg[1].map_name);
            printf("3.%s\n",pubg[2].map_name);
            printf("4.%s\n",pubg[3].map_name);
            printf("��ǰ��Ϸ����Ϊ��%d\n",game_times);
            while((chose_map=getch())!='0')
            {
                chose_map = chose_map - '0';
                enter_cheack_main=enter_check(chose_map);
                if(enter_cheack_main==1)
                {  
                    printf("�;����ˣ������������%s",random_local(player,&pubg[chose_map-1]));
                    game_times++;
                    Sleep(10000);
                    system("cls");
                    puts("ѡͼ��������0���ظ�������������");
                    printf("1.%s\n",pubg[0].map_name);
                    printf("2.%s\n",pubg[1].map_name);
                    printf("3.%s\n",pubg[2].map_name);
                    printf("4.%s\n",pubg[3].map_name);
                    printf("��ǰ��Ϸ����Ϊ��%d\n",game_times);
                }
                else
                {
                    puts("������󣡣�������һ���ľ���");
                    Sleep(1000);
                    system("cls");
                    puts("ѡͼ��������Q���ظ�������������");
                    printf("1.%s\n",pubg[0].map_name);
                    printf("2.%s\n",pubg[1].map_name);
                    printf("3.%s\n",pubg[2].map_name);
                    printf("4.%s\n",pubg[3].map_name);
                    printf("��ǰ��Ϸ����Ϊ��%d\n",game_times);
                }
            }
            Sleep(1000);
            system("cls");
            puts("���������伸���ˣ�����");
        }
        else
        {
            puts("������󣡣�������һ���ľ���");
            Sleep(1000);
            system("cls");
            puts("������(����1��4)?��Q�˳���������");
        }
    }
}

char * random_local(int player_num,struct map * map_chose)
{
    srand(time(0));
    int rand_num;
        do{
            rand_num=(int)rand() % MAX_LOCAL + 1;
        } while (map_chose->loacl_map[rand_num-1].max_player<player_num);
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

