#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){

    if(argc != 3){
        printf("anda gagal login\n");
        printf("cara login : ./FileAplikasiProgramUtama username password");
    }

        FILE *fw= fopen("login.bin","wb");
        char login[30]= "syakir@Code";

        fwrite(login,sizeof(char),sizeof(login)/sizeof(char),fw);

        fclose(fw);

        char usernameinput[10], passwordinput[10];
        strcpy(usernameinput, argv[1]);
        strcpy(passwordinput, argv[2]);
        char username[20], password[20];

        FILE *fr= fopen("login.bin", "rb");

        if((fr)==NULL){
            printf("gagal membuka file");
            return EXIT_FAILURE;
        }

        char akun[20];
        fread(akun, sizeof(char), sizeof(akun)/sizeof(char), fr);
        
        fclose(fr);

        char *kalimat[3];
        int i = 0;

        kalimat[0] =strtok(akun, "@");
        while(kalimat[i++] != NULL){
            kalimat[i] = strtok(NULL, "@");
        }

        strcpy(username, kalimat[0]);
        strcpy(password, kalimat[1]);

    if((strcmp(usernameinput, username)==0)&&(strcmp(passwordinput, password)==0)){
        printf("anda berhasil login\n");
        printf("PROGRAM YANG GAME YANG MAU KITA BUAT YA GUYS");
    }else{
        printf("gagal login ke program, silahkah cek username dan password anda");
    }

    return 0;
}
