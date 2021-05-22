#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){

    char username[20], password[20];

    if((argc==2)&&((strcmp(argv[1],"SignUp"))==0)){
        
        FILE *fw= fopen("login.bin","wb");
            char login[30];
            printf("====Daftarkan Akun Anda====\n");
            printf("cara memasukkan usernamne dan password : 'username@password'\n");
            printf("masukkan username dan password :");
            scanf(" %[^\n]", login);

            fwrite(login,sizeof(char),sizeof(login)/sizeof(char),fw);

            fclose(fw);
            printf("cara login : ./FileAplikasiProgramUtama username password");
    }if((argc==2)&&((strcmp(argv[1],"SignUp")) != 0)){
        printf("\nDaftarkan username dan password anda jika belum punya akun\n");
        printf("cara daftar akun : ./FileAplikasiProgramUtama SignUp\n");
    }

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

    if((argc==3)&&((((strcmp(argv[1], username))==0))&&((strcmp(argv[2], password))==0))){//ketika berhasil login
        printf("anda berhasil login\n");
        printf("====selamat datang di game who want to be a milioner====\n");
        printf("isi program kita disini ya gengs");
    }if((argc==3)&&((((strcmp(argv[1], username)) != 0))||((strcmp(argv[2], password)) != 0))){// ga berhasil login
        printf("anda gagal login, silahkan cek username dan password anda!\n");
        printf("cara login : ./FileAplikasiProgramUtama username password");
    }



    return 0;
}
