#include<stdio.h>
#include<string.h>
#include<float.h>
struct structure
{
    char ssid_name[20];
    double signal_strength;
    char password[20];
    float freq;
    int available;
};

FILE *fptr;
struct structure wifi;


size_t getsize(){
    fseek(fptr,0,SEEK_END);
    long filesize= ftell(fptr);
    rewind(fptr);

    size_t size= filesize/sizeof(struct structure);
    printf("Size of data : %zu\n",size);
    return size;
}

void addwifi(){
    
    printf("Enter the name : ");
    scanf("%s",wifi.ssid_name);
    printf("Enter password : ");
    scanf("%s",wifi.password);
    printf("Enter the frequency : ");
    scanf("%f",&wifi.freq);
    printf("Enter the signal strength : ");
    scanf("%lf",&wifi.signal_strength);
    wifi.available=1;

    fptr=fopen("wifi_details.dat","ab");
    if(!fptr){
        printf("Error in opening the file\n");
    }
    fwrite(&wifi,sizeof(struct structure),1,fptr);
    fclose(fptr);
}

//than deleting we can also make available value as 0
void deletewifi(){
    char target[20];
    printf("Enter the name of wifi to delete : ");
    scanf("%s",target);

    fptr= fopen("wifi_details.dat","rb");
    FILE *temp= fopen("temp.dat","wb");

    while(fread(&wifi,sizeof(struct structure),1,fptr)){
        if(strcmp(wifi.ssid_name,target)!=0){
            fwrite(&wifi,sizeof(struct structure),1,temp);
        }
    }
    fclose(fptr);
    fclose(temp);

    remove("wifi_details.dat");
    rename("temp.dat","wifi_details.dat");
    printf("deleted the wifi details of %s successfully\n",target);
}

void printwifi(){
    fptr=fopen("wifi_details.dat","rb");
    size_t length= getsize();
    for(size_t i=0;i<length;i++){
        fread(&wifi,sizeof(struct structure),1,fptr);
        printf("ssid_name: %s signal_strength: %.2f password: %s freq: %f available: %d\n",wifi.ssid_name,wifi.signal_strength,wifi.password,wifi.freq,wifi.available);
    
    }
}

void getbestwifi(){
    fptr=fopen("wifi_details.dat","rb");
    size_t length= getsize();
    double temp=DBL_MIN;
    char bestwifi[20];
    for(size_t i=0;i<length;i++){
        fread(&wifi,sizeof(struct structure),1,fptr);
        if(wifi.available && wifi.signal_strength>temp){
            temp=wifi.signal_strength;
            strcpy(bestwifi,wifi.ssid_name);
        }    
    }
    printf("Best wifi name is %s\n",bestwifi);
}

int main(){
    while(1){
        int option;
        printf("Enter the correct option\n1 - to add wifi\n2 - to delete wifi\n3 - to get best wifi\n4 - print all available wifi\n");
        scanf("%d",&option);

        switch(option){
            case 1:
                addwifi();
                break;
            case 2:
                deletewifi();
                break;
            case 3:
                getbestwifi();
                break;
            case 4:
                printwifi();
                break;
            default:
                printf("Invalid option\n");
                return 0;
        }
    }
    
}


// strcpy(goat.ssid_name,"SECE");
//     strcpy(goat.password ,"Dheva");
//     goat.signal_strength = 7.8;
//     goat.freq = 2.4;
//     goat.available = 1;

//     FILE* fp;

//     fp = fopen("wifi","w");

//     fprintf(fp,"ssid_name: %s \nsignal_strength : %.1f \nPassword : %s \nAvailable : %d \nFrequency : %.1f",goat.ssid_name,goat.signal_strength,goat.password,goat.available,goat.freq);
//     fclose(fp);