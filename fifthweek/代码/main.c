#include "BiTree.c"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    BiTree T = NULL;
    int ans = 0;
    char *definition = (char*)malloc(sizeof(char));
    printf("请按先序遍历方式输入前缀表达式，进行计算：\n");
    printf("注意：输入的数字范围为0-9，以#结束，并且输入的计算符号为以下四种 + - * /\n");
    InitBiTree(&T);
    scanf("%s",definition);
    CreateBiTree(&T,definition);
    PreOrderTraverse(T,T->data);
    Value(T,&ans);
    printf("%d",ans);

    return 0;
}
