#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4
struct vandingMachine   //구조체 정의
{
    char szDrink[10];
    int nPrice;
    int nAmount;
};
int nSumMoney=0;//총 입금한 금액
void printMenu(struct vandingMachine *vandArray);//메뉴와 가격,개수를 보여주는 함수
void insertMoney(struct vandingMachine *vandArray); //돈을 투입 받는 함수
int SelectMenu(struct vandingMachine *vandArray);//메뉴를 선택 받는 함수
void outputMenu(struct vandingMachine *vandArray,int nSelectMenu);//메뉴를 출력 및 잔돈,남은 개수 계산하는 함수
int main()
{
    struct vandingMachine vandArray[SIZE]={{"latte",500,50},{"cocoa",600,50},{"milk",700,50},{"mocha",1000,50}};//메뉴 이름,가격,개수
    int nInsertMoney=0; //입금금액
    int nYesNo=0;   //추가 구매 유무
    int nSelectMenu=0;//메뉴 선택

    while(1)
    {
        //메뉴를 보여준다
        printMenu(vandArray);
        //금액 입력선택
MONEY:   insertMoney(vandArray);
        //메뉴 선택
        nSelectMenu=SelectMenu(vandArray);
        //자판기 출력기능
        outputMenu(vandArray,nSelectMenu);

        printf("\t계속 하시겠습니까(1)? 중단하시겠습니까(0)? ");
        scanf_s("%d",&nYesNo);
        if(nYesNo==0)
        {
            printf("\t감사합니다.반환금액은 %d원입니다.\n",nSumMoney);//잔액 반환
            nSumMoney=0;
            break;
        }
        else
        {
            goto MONEY;
        }
    }
    printf("\tgoodbye");
    return 0;
}
void printMenu(struct vandingMachine *vandArray)
{
    printf("\t****************************************\n");//각 음료 명 표시
    printf("\t***1.%2s**2.%2s***3.%2s**4.%2s***\n",vandArray[0].szDrink,vandArray[1].szDrink,vandArray[2].szDrink,vandArray[3].szDrink);
    printf("\t****************************************\n");//가격 표시
    printf("\t*****%4d원**%4d원***%5d원**%4d원***\n",vandArray[0].nPrice,vandArray[1].nPrice,vandArray[2].nPrice,vandArray[3].nPrice);
    printf("\t****************************************\n");//개수 표시
    printf("\t*****%4dea**%4dea**%4dea**%4dea*****\n",vandArray[0].nAmount,vandArray[1].nAmount,vandArray[2].nAmount,vandArray[3].nAmount);
    printf("\t****************************************\n");
    printf("\t****************************************\n");

    return ;
}
void insertMoney(struct vandingMachine *vandArray)
{
    int nInsertMoney=0;
    int nYesNo=0;

    while(1)
    {
        printf("\t***********현재금액:%6d원************\n",nSumMoney);
        printf("금액을 투입하시오(10원,50원,100원,1000원,5000원,10000원) ");    scanf_s("%d",&nInsertMoney);

        if(nInsertMoney>50000 )
        {
            printf("\t금액을 잘못 투입하셨습니다.\n");
            continue;
        }
        nSumMoney+=nInsertMoney;

        printf("\t 계속투입:(1) 취소:(0) ");//돈을 더 투입 할지를 선택
        scanf_s("%d",&nYesNo);
        if(nYesNo==0)
        {
            printf("\t***********현재금액:%6d원************\n",nSumMoney);//현재 금액을 표시
            break;
        }
    }
    return;
}
int SelectMenu(struct vandingMachine *vandArray)
{
    int nSelectMenu=0;

    while(1)
    {
        printf("\t메뉴를 선택하십시오 ");   scanf_s("%d",&nSelectMenu);
        if(nSelectMenu>4 || nSelectMenu<1)//메뉴 선택 1~4번
         {
            printf("\t 잘못 눌렀습니다. 다시 선택하시오 \n");
            continue;
        }
        else if(vandArray[nSelectMenu-1].nAmount<=0)//재고없음 출력 메시지
        {
            printf("\t재고가 부족합니다.다시 선택하십시오\n",vandArray[nSelectMenu-1].szDrink);
            continue ;
        }
        else
        {
            break;
        }
    }
    return nSelectMenu;
}
void outputMenu(struct vandingMachine *vandArray,int nSelectMenu)
{
    while(1)
    {
        int balance=vandArray[nSelectMenu-1].nPrice-nSumMoney;//모자른 돈 계산
        if(vandArray[nSelectMenu-1].nPrice>nSumMoney)
        {
            printf("\t%d원 금액이 부족합니다.금액을 투입하여 주십시오\n",balance);
            insertMoney(vandArray);
            continue ;
        }
        printf("\t        *     *         *    *          \n");
        printf("\t       *     *         *    *           \n");
        printf("\t        *     *         *    *          \n");
        printf("\t        *     *         *    *          \n");
        printf("\t       *     *         *    *           \n");
        printf("\t     *****************************      \n");
        printf("\t     *****************************      \n");
        printf("\t     **                         **      \n");
        printf("\t     **                         ******* \n");
        printf("\t      **   %s가 나왔습니다. ***    * \n",vandArray[nSelectMenu-1].szDrink);
        printf("\t       **                     ** *    * \n");
        printf("\t        **                   **  ****** \n");
        printf("\t         **                 **          \n");
        printf("\t          ***             ***           \n");
        printf("\t           ***           ***            \n");
        printf("\t            ***************             \n");
        printf("\t***********                 ************\n");
        printf("\t***********                 ************\n");
        nSumMoney=nSumMoney-vandArray[nSelectMenu-1].nPrice;//전체 금액에서 가격을 뺀 금액
        vandArray[nSelectMenu-1].nAmount=vandArray[nSelectMenu-1].nAmount-1;//전체 개수 차감
        Sleep(3000);
        system("cls");
        printMenu(vandArray);
        break;
    }
    return ;
}
