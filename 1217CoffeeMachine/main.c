#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4
struct vandingMachine   //����ü ����
{
    char szDrink[10];
    int nPrice;
    int nAmount;
};
int nSumMoney=0;//�� �Ա��� �ݾ�
void printMenu(struct vandingMachine *vandArray);//�޴��� ����,������ �����ִ� �Լ�
void insertMoney(struct vandingMachine *vandArray); //���� ���� �޴� �Լ�
int SelectMenu(struct vandingMachine *vandArray);//�޴��� ���� �޴� �Լ�
void outputMenu(struct vandingMachine *vandArray,int nSelectMenu);//�޴��� ��� �� �ܵ�,���� ���� ����ϴ� �Լ�
int main()
{
    struct vandingMachine vandArray[SIZE]={{"latte",500,50},{"cocoa",600,50},{"milk",700,50},{"mocha",1000,50}};//�޴� �̸�,����,����
    int nInsertMoney=0; //�Աݱݾ�
    int nYesNo=0;   //�߰� ���� ����
    int nSelectMenu=0;//�޴� ����

    while(1)
    {
        //�޴��� �����ش�
        printMenu(vandArray);
        //�ݾ� �Է¼���
MONEY:   insertMoney(vandArray);
        //�޴� ����
        nSelectMenu=SelectMenu(vandArray);
        //���Ǳ� ��±��
        outputMenu(vandArray,nSelectMenu);

        printf("\t��� �Ͻðڽ��ϱ�(1)? �ߴ��Ͻðڽ��ϱ�(0)? ");
        scanf_s("%d",&nYesNo);
        if(nYesNo==0)
        {
            printf("\t�����մϴ�.��ȯ�ݾ��� %d���Դϴ�.\n",nSumMoney);//�ܾ� ��ȯ
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
    printf("\t****************************************\n");//�� ���� �� ǥ��
    printf("\t***1.%2s**2.%2s***3.%2s**4.%2s***\n",vandArray[0].szDrink,vandArray[1].szDrink,vandArray[2].szDrink,vandArray[3].szDrink);
    printf("\t****************************************\n");//���� ǥ��
    printf("\t*****%4d��**%4d��***%5d��**%4d��***\n",vandArray[0].nPrice,vandArray[1].nPrice,vandArray[2].nPrice,vandArray[3].nPrice);
    printf("\t****************************************\n");//���� ǥ��
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
        printf("\t***********����ݾ�:%6d��************\n",nSumMoney);
        printf("�ݾ��� �����Ͻÿ�(10��,50��,100��,1000��,5000��,10000��) ");    scanf_s("%d",&nInsertMoney);

        if(nInsertMoney>50000 )
        {
            printf("\t�ݾ��� �߸� �����ϼ̽��ϴ�.\n");
            continue;
        }
        nSumMoney+=nInsertMoney;

        printf("\t �������:(1) ���:(0) ");//���� �� ���� ������ ����
        scanf_s("%d",&nYesNo);
        if(nYesNo==0)
        {
            printf("\t***********����ݾ�:%6d��************\n",nSumMoney);//���� �ݾ��� ǥ��
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
        printf("\t�޴��� �����Ͻʽÿ� ");   scanf_s("%d",&nSelectMenu);
        if(nSelectMenu>4 || nSelectMenu<1)//�޴� ���� 1~4��
         {
            printf("\t �߸� �������ϴ�. �ٽ� �����Ͻÿ� \n");
            continue;
        }
        else if(vandArray[nSelectMenu-1].nAmount<=0)//������ ��� �޽���
        {
            printf("\t��� �����մϴ�.�ٽ� �����Ͻʽÿ�\n",vandArray[nSelectMenu-1].szDrink);
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
        int balance=vandArray[nSelectMenu-1].nPrice-nSumMoney;//���ڸ� �� ���
        if(vandArray[nSelectMenu-1].nPrice>nSumMoney)
        {
            printf("\t%d�� �ݾ��� �����մϴ�.�ݾ��� �����Ͽ� �ֽʽÿ�\n",balance);
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
        printf("\t      **   %s�� ���Խ��ϴ�. ***    * \n",vandArray[nSelectMenu-1].szDrink);
        printf("\t       **                     ** *    * \n");
        printf("\t        **                   **  ****** \n");
        printf("\t         **                 **          \n");
        printf("\t          ***             ***           \n");
        printf("\t           ***           ***            \n");
        printf("\t            ***************             \n");
        printf("\t***********                 ************\n");
        printf("\t***********                 ************\n");
        nSumMoney=nSumMoney-vandArray[nSelectMenu-1].nPrice;//��ü �ݾ׿��� ������ �� �ݾ�
        vandArray[nSelectMenu-1].nAmount=vandArray[nSelectMenu-1].nAmount-1;//��ü ���� ����
        Sleep(3000);
        system("cls");
        printMenu(vandArray);
        break;
    }
    return ;
}
