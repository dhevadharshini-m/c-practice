#include<stdio.h>
#include<string.h>

struct structure
{
    char ssid_name[20];
    double signal_strength;
    char password[20];
    float freq;
    int available;
};

int main(){
    struct structure goat;
    strcpy(goat.ssid_name,"SECE");
    strcpy(goat.password ,"Dheva");
    goat.signal_strength = 7.8;
    goat.freq = 2.4;
    goat.available = 1;

    FILE* fp;

    fp = fopen("wifi","w");

    fprintf(fp,"ssid_name: %s \nsignal_strength : %.1f \nPassword : %s \nAvailable : %d \nFrequency : %.1f",goat.ssid_name,goat.signal_strength,goat.password,goat.available,goat.freq);
    fclose(fp);
    return 0;
}
