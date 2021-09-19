#include <stdio.h>
#include <stdlib.h>

//enum state {isInt, isChar, isString};

struct Element{
    // Значение элемента множества
    union {
        int ival;
        float fval;
        char cval;
        char *string;      // Пусть максимальная длина слова будет 10
    } value;

    enum {isInt, isChar, isString} type;
    //enum state type;

    struct Element *previous;

};

struct Element *addElem(){
    int chs;
    printf("Which type:\n1-int\n2-string\n3-char\n");
    scanf("%d", &chs);
    switch(chs){

    // Числовой тип
    case 1:{
        struct Element s1;
        struct Element *elem = &s1;
        int num;
        while(1){
            char num_str[256];
            scanf("%s", num_str);
            if(isDigit(num_str) == 1){
                num = atoi(num_str);
                break;
            }
            else{
                printf("Input error\n");
                continue;
            }
        }
        (*elem).type = isInt;
        elem->value.ival = num;
        return elem;
        break;
    }
    case 2:{
        struct Element s1;
        struct Element *elem = &s1;
        char word[10];
        scanf("%s", word);
        // Как обратиться к перечислению?
        (*elem).type = isString;
        elem->value.string = word;
        return elem;
        break;
    }
    case 3:{
        struct Element s1;
        struct Element *elem = &s1;
        char symbol;
        char word[10];
        scanf("%s", word);
        symbol = word[0];
        (*elem).type = isChar;
        elem->value.cval = symbol;
        return elem;
        break;
    }
    // Сделать еще для float
    }
    return NULL;
};


/* Проверка строки на число */
int isDigit(char *word){
    char nums[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for(int i = 0; word[i]!='\0'; i++){
        int temp = 0;
        for(int j = 0; j < 10; j++){
            if(word[i] == nums[j])
                temp = 1;
        }
        if(temp == 0)
            return 0;
    }
    return 1;
}

struct Stack{
    int size;
    int tos;
    struct Element *top;
};

/* Описание функций для стека */
void push(struct Stack *stck, struct Element *el){
    if(stck->top == NULL){
        stck->top = el;
        stck->tos++;
    }else{
        if(isFull(stck))
            return;
        el->previous = stck->top;
        stck->top = el;
    }
    stck->tos++;
}

int isFull(struct Stack *stck){
    if(stck->tos >= stck->size){
        printf("Stack is full");
        return 1;
    }
    return 0;
}

int isEmpty(struct Stack *stck){
    if(stck->tos <= 0){
        printf("Stack is empty\n");
        return 1;
    }
    return 0;
}

struct Element *pop(struct Stack *stck){
    if(stck->tos <= 0){
        printf("Stack is empty\n");
        return NULL;
    }
    else{
        struct Element *el = stck->top;
        stck->top = stck->top->previous;
        (*stck).tos--;
        printf("%d", stck->tos);
        return el;
    }
};

void ShowElem(struct Element *elem){
    struct Element s1 = *elem;
    printf("e");

}



int main(){
    // Создание первого множества
    //printf("Enter size of first Set: ");
    int size1 = 3;
    struct Stack stck1;        // Пусть у первого множества будет размер 3
    stck1.size = size1;
    stck1.tos = 0;
    struct Stack *stck_ptr = &stck1;
    isEmpty(stck_ptr);
    for(int i = 0; i < size1; i++){
        struct Element *el1 = addElem();
        push(stck_ptr, el1);
    }
    printf("Get the Elem\n");
    struct Element *elo = pop(stck_ptr);
    int a = (*elo).value.ival;
    printf("%d", a);
    printf("\n");
    pop(stck_ptr);


    return 0;
}
