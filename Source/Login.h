void HalLogin();
void Username(char username[]);
void Password(char password[]);
void Dashboard();

int i, x, y;

void frame(int x, int y){
    SetColorBlock(1,7);
    for(i = y; i < 22 + y; i++){
        for(j = x; j < 127; j++){
            gotoprintchar(j,i,32);
        }
    }
    SetColorBlock(7,1);
    /*border frame atas bawah*/
    for(i = 20; i < 21; i++){
        for(j = x - 2; j < 120; j++){
            gotoprintchar(j,i,177);
        }
    }

    for(i = 41; i < 42; i++){
        for(j = x - 2; j < 120; j++){
            gotoprintchar(j,i,177);
        }
    }

    SetColorBlock(1,7);
    /*border frame tengah kanan kiri*/
    for(i = y + 1; i < y + 21; i++){
        gotoprintchar(x - 1,i,186);
    }

    for(i = y + 1; i < y + 21; i++){
        gotoprintchar(x+60,i,186);
    }
}

void HalLogin() {
    // ShowCursor(10);
    system("color 71");
    borderAwal();
    // PrintFile("..//Asset/ProCleanOrganizer.txt", 83, 15);
    PrintFile("..//Asset/Atas Kiri.txt", 3, 2);
    PrintFile("..//Asset/Atas Kanan.txt", 156, 2);
    PrintFile("..//Asset/Bawah kiri.txt", 3, 38);
    PrintFile("..//Asset/Bawah kanan.txt", 156, 38);
    PrintFile("..//Asset/Welcome.txt", 35, 5);

    frame(58,20);
    PrintFile("..//Asset/Login.txt", 75, 22);


    //kotak username
    gotoxy(80, 34);
    printf("%c", 192);      //kiri bawah
    gotoxy(80, 32);
    printf("%c", 218);      //kiri atas
    gotoxy(106, 32);
    printf("%c", 191);      //kanan atas
    gotoxy(106, 34);
    printf("%c", 217);      //kanan bawah
    gotoxy(80, 33);
    printf("%c", 179);      //kiri tengah
    gotoxy(106, 33);
    printf("%c", 179);      //kanan tengah
    for (x = 81;x <= 105; x++) {    //atas
        gotoxy(x,32);
        printf("%c", 196);
    }
    for (x = 81;x <= 105; x++) {    //bawah
        gotoxy(x,34);
        printf("%c", 196);
    }

    //kotak password
    gotoxy(80, 37);
    printf("%c", 192);      //kiri bawah
    gotoxy(80, 35);
    printf("%c", 218);      //kiri atas
    gotoxy(106, 35);
    printf("%c", 191);      //kanan atas
    gotoxy(106, 37);
    printf("%c", 217);      //kanan bawah
    gotoxy(80, 36);
    printf("%c", 179);  //kiri tengah
    gotoxy(106, 36);
    printf("%c", 179);  //kanan tengah
    for (x = 81;x <= 105; x++) {    //atas
        gotoxy(x,35);
        printf("%c", 196);
    }
    for (x = 81;x <= 105; x++) {    //bawah
        gotoxy(x,37);
        printf("%c", 196);
    }
    gotoxy(70, 33);
    printf("Username: ");
    gotoxy(70, 36);
    printf("Password: ");
    gotoxy(81, 33);
    Username(adm.username);
    gotoxy(81, 36);
    Password(adm.password);
    if((strcmp(adm.username, "Admin")== 0) && (strcmp(adm.password, "Admin") == 0)) {
        MessageBox(NULL, "Welcome To Admin", "Notification", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        system("cls");
        Dashboard();
    }else {
        MessageBox(NULL, "Masukan Username dan Password Dengan Benar!!!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
         clearArea(96,35,8,1);
         clearArea(96,38,8,1);
        // exit(0);
        HalLogin();

    }
}

    //Input username serta validasinya
    void Username(char username[]){
        fflush(stdin);
        int i = 0;
        char ch;
        while (1){
            ch = getch();
            if (ch == -32 || ch == 224) {
                getch();
                continue;
            }
            if (ch == BACKSPACE){
                if (i > 0){
                    printf("\b \b");
                    i--;
                }
            }
            else if (ch == ENTER){
                break;
            }
            else if (i < 8 && ch != SPACE && ch != TAB && (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')){
                username[i] = ch;
                printf("%c", username[i]);
                i++;
            }
        }
        username[i] = '\0';
    }

    //Input password serta validasinya
    void Password(char password[]){
        fflush(stdin);
        int i = 0;
        char ch;
        while(1){
            ch = getch();
            if (ch == -32 || ch == 224) {
                getch();
                continue;
            }
            if(ch == BACKSPACE){
                if(i > 0){
                    printf("\b \b");
                    i--;
                }
            }
            else if(ch == ENTER){
                break;
            }
            else if(i < 8 && ch != SPACE && ch != TAB && (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')){
                password[i] = ch;
                printf("*");
                i++;
            }
        }
        password[i] = '\0';
    }
