#include "BiTree.c"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    BiTree T = NULL;
    int ans = 0;
    char *definition = (char*)malloc(sizeof(char));
    printf("�밴���������ʽ����ǰ׺���ʽ�����м��㣺\n");
    printf("ע�⣺��������ַ�ΧΪ0-9����#��������������ļ������Ϊ�������� + - * /\n");
    InitBiTree(&T);
    scanf("%s",definition);
    CreateBiTree(&T,definition);
    PreOrderTraverse(T,T->data);
    Value(T,&ans);
    printf("%d",ans);

    return 0;
}
