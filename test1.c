#include "lxml.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "solver.h"

void grid(char* arr)
{
    int  r, c, i=0;
    int length = sizeof(arr)/sizeof(arr[0]);              
    for(r = 0; r < 9; r++)
    {
        /* Draw Top */
        for(c = 0; c < 9; c++)
            printf("+---");
        printf("+\n");

        /* Draw Middle */
        for(c = i; c < i+9; c++)
        {
            if(arr[c]=='0')
            {
                printf("|   ");
            }
            else{
                printf("| %c ", arr[c]);
            }
        }
        printf("|\n");
        i=i+9;

    }

    /* Draw Bottom */
    for(c = 0; c < 9; c++)
        printf("+---");
    printf("+\n\n\n");
}

int main()
{
    XMLDocument doc;
    FILE* fp;
    char ch,option;
    int choice;
    int i=0;
    char *arr = malloc(sizeof(char) * (81));
    char file[50];
    do{
        printf("1.New Game\n 2.Exit\n");
        scanf("%d",&choice);
        switch (choice) {
        case 1: {
            printf("Enter the file name:");
            scanf("%s",file);
            if (fp = fopen(file, "r")) 
            {
            
                if (XMLDocument_load(&doc,file)) {
                    XMLNode* str = XMLNode_child(doc.root, 0);

                    XMLNodeList* fields = XMLNode_children(str, "field");
                    for (int i = 0; i < fields->size; i++) {
                        XMLNode* field = XMLNodeList_at(fields, i);
                        XMLAttribute* type = XMLNode_attr(field, "type");
                        type->value = "";
                    }

                    XMLDocument_write(&doc, "out.txt", 4);
                    XMLDocument_free(&doc);
                    fclose(fp);
                }
                fp = fopen("out.txt","r");
                if (fp == NULL)
                {
                    printf("FIle is not available\n");
                }
                else
                {
                    while((ch = fgetc(fp)) != EOF)
                    {
                        if(ch == '-')
                        {
                            arr[i]='0';
                            i++;
                        }
                        else if (ch == ',' || ch == '\n')
                        {
                            continue;
                        }
                        else
                        {
                            arr[i]=ch;
                            i++;
                        }
                        if(i==81)
                        {
                            arr[81]='\0';
                        }
                        
                        
                    }
                }
                fclose(fp);
                /*    int length = sizeof(arr)/sizeof(arr[0]);         
                for (int i = 0; i < length; i++)
                {
                    printf("%c", arr[i]);     
                }
                printf("\n");*/
                printf("Your Sudoku Problem is:\n");
                grid(arr);
                graph_main(arr);
                free(arr);
                remove("out.txt");
                printf("Do you Want to a New Game ?\n");
            }
            else
            {
                printf("File doesn't exist\n");
            }
            break;
        }
        case 2: {
            break;
        }
        default:
            printf("wrong Input\n");
        }
    }while(choice!=2);
    
    

    return 0;
}