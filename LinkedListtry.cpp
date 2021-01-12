#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Carrick 100 -> Livia 90 -> Valencia 95

struct Node
{
    char name[255];
    int score;
    Node *next; //nunjuk node selanjutnya
} *head;
Node *tail; // global variabelnya , head dan tail
//head : nunjuk ke node pertama dalam linked list
//tail : nunjuk kode terakhir (node yang menunjuk null)

Node *createNode(const char *name, int score){
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->score=score;
    newNode->next = NULL; //biar ga nunjuk ke garbage value
    return newNode;
}


void pushhead(const char *name, int score){
    //1. buat dlu nodenya
    //2. cek kondisi
    //    jika gaada head, maka nodenya jadi head dan tail
    //    jika ada head, node akan jadi head baru dan node -> next = head lama
    Node *temp = createNode(name,score);

    if(!head){ //klo gaada head, maka node nya jadi head dan tail
        head = tail = temp;
    }else{
        temp->next = head; //node nunjuk ke head yg lama
        head = temp; // node jadi head baru

    }
}

void pushtail(const char *name, int score){
    //1. buat dlu nodenya
    //2. cek kondisi
    //    jika gaada head, maka nodenya jadi head dan tail
    //    jika ada head, node akan jadi head baru dan node -> next = head lama
    Node *temp = createNode(name,score);

    if(!head){ //klo gaada head, maka node nya jadi head dan tail
        head = tail = temp;
    }else{
        tail->next = temp; //node nunjuk ke head yg lama
        tail = temp; // node jadi head baru

    }
}



void popHead(){
    if(!head){ //jika tidak ada head
        return; // lgsg return
    }else if(head==tail){
        free(head);
        head = tail = NULL;
    }
    
    else{ // 53 (head -> 70 -> 40 -> 25)
        Node *temp = head->next; //53(head) ->70(temp) ->40 -> 25
        head->next = NULL; //53(head) -> NULL || 70(temp) ->40 -> 25
        free(head);
        head = temp; // 70 (head, temp) 40 -> 25
    }
    //karna temp itu local,
    // 70 (head) -> 40 -> 25
}

void popTail(){
    if(!head){ //jika tidak ada head
        return; // lgsg return
    }else if(head==tail){
        free(head);
        head = tail = NULL;
    }
    
    else{ // 53 (head -> 70 -> 40 -> 25)
        Node *temp = head; //53(head) ->70(temp) ->40 -> 25
        
        while (temp->next != tail)
        {
            temp=temp->next;
        }

        temp->next = NULL;
        free(tail);
        tail = temp;
        
    }
    //karna temp itu local,
    // 70 (head) -> 40 -> 25
}

void printList(){
    Node *curr = head;// 53(head) -> 70 (temp)-> 40 -> 25
        //head->next = NULL;// 53(head) -> NULL|| 70(temp) -> 40 -> 25
        while(curr){
            if(curr == head){
                printf("(tail)");
            }
            printf("%s %d ->",curr->name, curr->score);
            curr = curr-> next;
        }
        puts("NULL");
}
int main(){
    pushhead("ann", 100);
    pushtail("reret", 90);
    pushtail("annreret",95);
    printList();
    return 0;

}