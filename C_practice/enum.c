#include <stdio.h>

enum ACMode {
    COOL,
    HEAT,
    FAN,
    DRY,
    Extra_Cool,
    NORMAL
};

void showACMode(enum ACMode mode) {
    switch (mode) {
        case COOL: printf("AC Mode: Cool\n"); break;
        case HEAT: printf("AC Mode: Heat\n"); break;
        case FAN:  printf("AC Mode: Fan\n"); break;
        case DRY:  printf("AC Mode: Dry\n"); break;
    }
}

int main(){
    int input;
    scanf("%d",&input);
    showACMode((enum ACMode)(input));
    printf("%zu\n",sizeof(enum ACMode));
    return 0;
}