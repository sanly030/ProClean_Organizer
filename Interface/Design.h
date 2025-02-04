#pragma once

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

// Deklarasi prosedur untuk menampilkan kursor
void showCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
//--------------------------------------untuk mengatur posisi--------------------------------/
void gotoxy(int x, int y) {
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//--------------------------------------Fullscreen Layar---------------------------------------/
void fullscreen(){
    keybd_event(VK_MENU,0x39,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x39,KEYEVENTF_KEYUP,0);

    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
}

//--------------------------------------Gotoprint Character------------------------------------/
void gotoprintchar(int x, int y, int dec){
    gotoxy(x,y);
    printf("%c",dec);
}

//--------------------------------------Gotoprint Text------------------------------------/
void gotoprinttext(int x, int y, char text[255]){
    gotoxy(x,y);
    printf("%s",text);
}

//---------------------------------------Untuk mewarnai huruf dan background---------------------/
void SetColorBlock(int foreground, int background) {
    int color = foreground + (background << 4);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

//----------------------------------------Menghapus semua block-----------------------------------/
void clearArea(int x, int y, int width, int height) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD topLeft = {(SHORT) x, (SHORT) y};
    DWORD written;

    for (int row = 0; row < height; ++row) {
        FillConsoleOutputCharacterA(console, ' ', width, topLeft, &written);
        topLeft.Y++;
    }
}

//-------------------------------------Mematikan scrollbar CMD----------------------------------------/
void disableScrollBar() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // Mendapatkan informasi tentang jendela console
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hOut, &csbi);

    // Menyusun atribut baru untuk mengunci scrollbar
    csbi.dwSize.Y = csbi.dwMaximumWindowSize.Y;

    // Menyetel ukuran jendela console
    SetConsoleScreenBufferSize(hOut, csbi.dwSize);

    // Menonaktifkan scrollbar
    SetConsoleMode(hOut, ENABLE_EXTENDED_FLAGS);
}

//--------------------------------------untuk mencetak file txt----------------------------------------/
void CetakFile(int x, int y, char filename[255]) {
    FILE *fp;
    char str[MAXCHAR];
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s", filename);
    }
    i = 0;
    while (fgets(str, MAXCHAR, fp) != NULL) {
        gotoxy(x, y + i);
        printf("%s", str);
        i++;
    }
    fclose(fp);
}

void BorderScreen(){
    int i;

    SetColorBlock(1,7);

    //pojok kanan atas/
    gotoprintchar(32,11,206);

    //atas tengah/
    for(i = 33; i < 170; i++){
        gotoprintchar(i,11,205);
    }

    //pojok kiri atas/
    gotoprintchar(170,11,206);

    //border samping kiri/
    for(i = 12; i < 43; i++){
        gotoprintchar(32,i,186);
    }

    //border samping kanan
    for(i = 12; i < 43; i++){
        gotoprintchar(170,i,186);
    }

    //pojok kiri bawah/
    gotoprintchar(32,42,206);

    //bawah tengah/
    for(i = 33; i < 170; i++){
        gotoprintchar(i,42,205);
    }
    //pojok kanan bawah/
    gotoprintchar(170,42,206);
}

// FONT
void setConsoleFont(int fontSizeX, int fontSizeY, const wchar_t* fontName) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);

    // Mendapatkan informasi font saat ini
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

    // Mengganti ukuran font
    fontInfo.dwFontSize.X = fontSizeX;
    fontInfo.dwFontSize.Y = fontSizeY;

    // Mengganti nama font
    wcscpy(fontInfo.FaceName, fontName);

    // Mengganti bentuk font
    SetCurrentConsoleFontEx(hConsole, FALSE,&fontInfo);
}

//UNTUK DESAIN TXT
void PrintFile(char file[], int x, int y){
    FILE *Text;
    char Data[200];
    if((Text=fopen(file, "r")) == NULL){
        system("cls");
    }
    while(fgets(Data, 200, Text))
    {
        gotoxy(x, y);
        printf("%s", Data);
        y++;
    }
    fclose(Text);
}

//LOADING
 void loading() {
    int x;
     gotoxy(80, 33  );
     printf("L O A D I N G . . . ");         //Loading

     for (x = 74; x <= 102; x++) {           //atas
         gotoxy(x, 35);
         printf("%c", 196);
     }
     for (x = 74; x <= 102; x++) {           //bawah
         gotoxy(x, 37);

         printf("%c", 196);
     }
     for (x = 74; x <= 102; x++) {           //isi
         Sleep(20);
         gotoxy(x, 36);
         printf("%c", 219);
     }
     gotoxy(73, 38);
     system("pause");
     // system("cls");

 }

//TAMPILAN AWAL
void logo()
{
    // hideCursor();
    ShowCursor(0);
    PrintFile("..//Asset//ProClean Organizer.txt",70 , 10);
    PrintFile("..//Asset//Bubble kiri.txt", 7, 4);
    PrintFile("..//Asset//Bubble kanan.txt", 133, 4);
    PrintFile("..//Asset//Orang Pegang Sapu Kiri.txt", 15, 20);
    PrintFile("..//Asset//OrangPegangSapu.txt", 125, 20);
    PrintFile("..//Asset//Atas kiri.txt", 3, 2);
    PrintFile("..//Asset//Atas kanan.txt", 156, 2);
    PrintFile("..//Asset//Bawah kiri.txt", 3, 38);
    PrintFile("..//Asset//Bawah kanan.txt", 156, 38);
    getch();
    loading();

}



void BoxBlock(int x, int y, int width, int height) {
    int i, j;
    for(i = 0; i <= height; i++) {
        for(j = 0; j < width; j++) {
            gotoxy(x + j, y + i);
            printf("%c", 219);
        }
    }
}


void textBox2(int x, int y, int width, int height) {
    int i, j;

    /* first Line */
    gotoxy(x, y);
    printf("%c", 201);
    for(i = 1; i <= width; i++) {
        printf("%c", 205);
    }
    printf("%c", 187);

    /* looping for height */
    for(i = 1; i <= height; i++) {
        gotoxy(x, y + i);
        printf("%c", 186);
        for(j = 1; j <= width; j++) {
            printf(" ");
        }
        gotoxy(x + width + 1, y + i);
        printf("%c", 186);
    }

    /* last line */
    printf("\n");
    gotoxy(x, y + height);
    printf("%c", 200);
    for(i = 1; i <= width; i++) {
        printf("%c", 205);
    }
    printf("%c", 188);
}

void blankScreen(){
    SetColorBlock(7,7);
    for(i = 10; i < 44; i++){
        for(j = 30; j < 173; j++){
            gotoprintchar(j,i,32);
        }
    }
}

//====== Garis kotak (Border) dengan karakter full blok ========
void borderFullBlock(int x, int y, int lebar, int tinggi) {
    // ========= garis atas
    for (int i = x; i < x + lebar; ++i) {
        gotoprintchar(i, y, 219);
    }

    // ========= Menggambar garis samping
    for (int j = y + 1; j < y + tinggi; ++j) {
        gotoprintchar(x, j, 219);
        gotoprintchar(x + lebar - 1, j, 219);
    }

    // ========= Menggambar garis bawah
    for (int i = x; i < x + lebar; ++i) {
        gotoprintchar(i, y + tinggi - 1,219);
    }
}

void garisFullBlokVertical(int x, int y, int tinggi) {
    for (int i = 0; i < tinggi; ++i) {
        gotoprintchar(x, y + i ,219);
    }
}

void garisFullBlokHorizontal(int x, int y, int lebar) {
    for (int i = 0; i < lebar; ++i) {
        gotoprintchar(x + i, y ,219);
    }
}

void borderAwal(){
    borderFullBlock(2,1,172,44);
}

void generateid(char Teks[4],int IDStruct){

    if(IDStruct < 10){
        printf("%s00%d", Teks, IDStruct);
    }
    else if(IDStruct < 100){
        printf("%s0%d", Teks, IDStruct);
    }
    else{
        printf("%s%d", Teks, IDStruct);
    }
}

void getallinput(char input[], int min, int max, int type)
{
    char inpkey;
    int i,n,x,m;
    n = 0;
    x=0;
    do
    {
        inpkey = getch(); // membaca masukan dari keyboard per-karakter //

//---- Menghapus Input ----//
//start//
        if(inpkey == '\b' && n != 0)
        {
            printf("\b \b");
            n--;
            input[n]='\0';
        }
//end//
        else if(isprint(inpkey)){ //karakter yang bisa di print
            if(n == max) {
                continue;
            }
            else{
                if(type == 3){ //isdigit = angka doang
                    if(isdigit(inpkey)) {
                        printf("%c", inpkey);
                        input[n]=inpkey;
                        n++;
                    }
                    else printf("\a"); //pemberitahuan suara tidak dapat di input (allert)
                }
                else if(type == 2){ //isalpha = alpabet dan spasi co : nama
                    if(isalpha(inpkey) || inpkey == ' ') {
                        printf("%c", inpkey);
                        input[n]=inpkey;
                        n++;
                    }
                    else printf("\a");
                }
                else { // inpkeyword //0= bebas
                    if(type == 1)
                    {
                        if (inpkey=='\r')
                        {
                            inpkey='\0';
                            break;
                        }
                        printf("%c", inpkey);
                        input[n]=inpkey;
//                        printf("*");
                        n++;
                    }


                    else
                    {
                        printf("%c", inpkey);
                        input[n]=inpkey;
                        n++;
                    }
                }
            }
        }
        else if(inpkey == 13)
        {
            if(n < min) {
                printf("\a");
                inpkey = 0;
            }
            else input[n]='\0';
        }
        //else if(current == 27) end();
    }
    while(inpkey != 13);
}

void getinput(char input[], int max, int type)
{
    getallinput(input, 1, max, type);
}


void frameLayout(int x, int y,int lebar, int tinggi, int dec){
    for(i = y; i < tinggi; i++){
        for(j = x; j < lebar; j++){
            gotoprintchar(j,i,dec);
        }
    }
}

void frameDetailData(int x, int y) {
    hideCursor();
        SetColorBlock(1,7);
        for(i = y; i < 22+ y; i++){
            for(j = x; j < 127; j++){
                gotoprintchar(j,i,32);
            }
        }
        SetColorBlock(7,1);
        /*border frame atas bawah*/
        for(i = 17; i < 18; i++){
            for(j = x - 2; j < 98; j++){
                gotoprintchar(j,i,177);
            }
        }

        for(i = 38 ;i < 39; i++){
            for(j = x - 2; j < 98; j++){
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


void getnum(int *nilai, int max)
{
    char input[max];
    getinput(input, max, 3);
    *nilai = atoi(input);
}

void clearTengah() {
    SetColorBlock(7,7);
    frameLayout(31,17,130,40,32);
}

void blankScreenLogin() {
    SetColorBlock(7,7);
    for(i = 2; i < 43; i++){
        for(j = 3; j < 173; j++){
            gotoprintchar(j,i,32);
        }
    }
}

void getRp(float *nilai, int min, int max, int x, int y) //input rupiah
{
    char input[255];
    char inpkey;
    int i,n,m;
    n = 0;
    do
    {
        inpkey = getch(); // membaca masukan dari keyboard per-karakter //
        if(inpkey == '\b' && n != 0) /* Hapus karakter */
        {
            n--;
            input[n]='\0';

            m = n % 3;
            if((n-m) % 3 == 0 || n == m)
            {
                printf("\b \b");
                printf("\b \b");
            }
            else
            {
                printf("\b \b");
            }

            gotoxy(x, y);		/* Cetak ulang sesuai format */
            for(i = 0; i < n; i++)
            {
                if((i+1) == m || (i+1-m) % 3 == 0)
                {
                    printf("%c", input[i]);
                    if(i != (n-1))
                    {
                        printf(".");
                    }
                }
                else
                {
                    printf("%c", input[i]);
                }
            }
        }
        else if(isprint(inpkey))      /* Karakter yang bisa di print */
        {
            if(n == max)
            {
                continue;
            }
            else
            {
                if(isdigit(inpkey))   /* Print angka */
                {
                    gotoxy(x, y);
                    input[n]=inpkey;
                    n++;
                    m = n % 3;
                    for(i = 0; i < n; i++)  /* Cetak ulang sesuai format */
                    {
                        if((i+1) == m || (i+1-m) % 3 == 0)
                        {
                            printf("%c", input[i]);
                            if(i != (n-1))
                            {
                                printf(".");
                            }
                        }
                        else
                        {
                            printf("%c", input[i]);
                        }
                    }
                }
                else printf("\a"); /* Pemberitahuan suara tidak dapat di input (alert) */
            }
        }
        else if(inpkey == 13)	/* Jika menekan enter sebelum mengisi karakter akan muncul suara tidak dapat diinput (alert) */
        {
            if(n < min)
            {
                printf("\a");
                inpkey = 0;
            }
            else input[n]='\0';
        }
    }
    while(inpkey != 13);

    *nilai = atoi(input);   /* Memasukkan nilai input (char) ke nilai (int) */
}

void DashboardCRUD(){
    SetColorBlock(9,9);
    frameLayout(130,9,170,42,32);
    SetColorBlock(1,15);
    frameLayout(130,9,131,42,223);
    frameLayout(130,9,170,10,223);
    frameLayout(169,9,170,42,223);
    frameLayout(130,41,170,42,220);
}

void menuLaporanManajer(){
    SetColorBlock(7,9);
    //DrawFile(65,19,"../Desaintxt/Dashboard/menuLaporan.txt");
    gotoprinttext(82,25,"B U L A N A N");
    gotoprinttext(82,28,"T A H U N A N");
    gotoprinttext(82,31,"K E M B A L I");
}

void menuBackLihat(int y){
    gotoprinttext(153,y," L I H A T   \n");
    gotoprinttext(134,y," K E M B A L I");
}

void BorderSwitchRole(int x, int y, int lebar){
    /*untuk kiri atas*/
    gotoxy(x,y);printf("%c", 201);
    int a;
    a = x + 1;
    for(i = 0; i < lebar; i++){
        gotoxy(a,y);printf("%c",205); /*untuk asci tepi atas =*/
        a++;
    }
    /*untuk kanan atas*/
    gotoxy(a,y);printf("%c", 187);

    gotoxy(x,y+1);printf("%c",186);/*untuk ascii tepi sama dengan miring kiri tengah*/

    gotoxy(a,y+1);printf("%c",186);/*untuk ascii tepi sama dengan miring kanan tengah */

    gotoxy(x,y+2);printf("%c",200);/*untuk sudut kiri bawah*/
    a = x + 1;
    for(i = 0; i < lebar; i++){
        gotoxy(a,y+2);printf("%c",205);/*untuk tepi bawah =*/
        a++;
    }
    gotoxy(a,y+2);printf("%c",188);/*untuk sudut kanan bawah*/
}

void BorderSwitchRoleDashboard(int x, int y, int lebar,int tinggi){
    gotoxy(x,y);printf("%c", 201);
    int a;
    a = x + 1;
    for(i = 0; i < lebar; i++){
        gotoxy(a,y);printf("%c",205); /*untuk asci tepi atas =*/
        a++;
    }
    /*untuk kanan atas*/
    gotoxy(a,y);printf("%c", 187);
    int b = y + 1;
    for(i = 0; i < 2; i++) {
        gotoxy(x, b);
        printf("%c", 186);/*untuk ascii tepi sama dengan miring kiri tengah*/
        b++;
    }
    b = y + 1;
    for(i = 0; i < 2; i++) {
        gotoxy(a, b);
        printf("%c", 186);/*untuk ascii tepi sama dengan miring kiri tengah*/
        b++;
    }
    gotoxy(x,b);printf("%c",200);/*untuk sudut kiri bawah*/
    a = x + 1;
    for(i = 0; i < lebar; i++){
        gotoxy(a,b);printf("%c",205);/*untuk tepi bawah =*/
        a++;
    }
    gotoxy(a,b);printf("%c",188);/*untuk sudut kanan bawah*/
}

void SpecialkeyLaporanManajer(int x, int y, int lebar,int tinggi, int *output) {
    //Declaration
    int count = 1;
    char ch;

    //Algorithm
//    BorderSwitchRole(x, y, lebar);
    menuLaporanManajer();
    if(count == 1){
        SetColorBlock(0,9);
        gotoprinttext(82,25,"B U L A N A N");
    }
    while (1) {
        ch = getch();
        if (ch == ENTER || ch == TAB) {
            switch (count) {
                case 1 :
                    Beep(3000, 100);
                    *output = count;
                    break;

                case 2 :
                    Beep(3000, 100);
                    *output = count;
                    break;

                case 3 :
                    Beep(3000, 100);
                    *output = count;
                    break;
            }
            break;
        } else if (ch == UP_KEY) {
            if (count > 1) {
                Beep(700, 120);
//                clearArea(x, y, lebar + 2, tinggi);
                y -= 3;  // Geser ke atas sebanyak 4 unit
                SetColorBlock(7,9);
//               BorderSwitchRole(x, y, lebar);
                menuLaporanManajer();
                count--;
            }
            if(count == 1){
                SetColorBlock(0,9);
                gotoprinttext(82,25,"B U L A N A N");
            } else if(count == 2){
                SetColorBlock(0,9);
                gotoprinttext(82,28,"T A H U N A N");
            } else if(count==3){
                SetColorBlock(0,9);
                gotoprinttext(82,31,"K E M B A L I");
            }
        } else if (ch == DOWN_KEY) {
            if (count < 3) {
                Beep(700, 120);
//                clearArea(x, y, lebar + 2, tinggi);
                y += 3;  // Geser ke bawah sebanyak 4 unit
//                BorderSwitchRole(x, y, lebar);
                SetColorBlock(7,9);
                menuLaporanManajer();
                count++;
            }
            if(count == 1){
                SetColorBlock(0,9);
                gotoprinttext(82,25,"B U L A N A N");
            } else if(count == 2){
                SetColorBlock(0,9);
                gotoprinttext(82,28,"T A H U N A N");
            } else if(count==3){
                SetColorBlock(0,9);
                gotoprinttext(82,31,"K E M B A L I");
            }
        }
    }
}


void SpecialKeyCariDataLaporan(int x, int y, int lebar,int tinggi,int *output) {
    int count = 1;
    char ch;
    //Algorithm
    SetColorBlock(7, 9);
    BorderSwitchRole(x, y, lebar);
    menuBackLihat(y+1);
    while (1) {
        ch = getch();
        if (ch == ENTER || ch == TAB) {
            switch (count) {
                case 1 :
                    Beep(3000, 100);
                    *output = count;
                    break;

                case 2 :
                    Beep(3000, 100);
                    *output = count;
                    break;
            }
            break;
        } else if (ch == RIGHT_KEY) {
            if (count > 1) {
                Beep(1000, 100);
                clearArea(x, y, lebar+2,tinggi);
                x += 17;
                BorderSwitchRole(x, y, lebar);
                menuBackLihat(y+1);
                count--;
            }
        } else if (ch == LEFT_KEY) {
            if (count < 2) {
                Beep(1000, 100);
                clearArea(x, y, lebar+2, tinggi);
                x -= 17;
                BorderSwitchRole(x,y,lebar);
                menuBackLihat(y+1);
                count++;
            }
        }
    }
}


void frameTransaksi(int x, int y){
    SetColorBlock(9,9);
    for(i = 15; i < 41; i++){  // Ubah batas atas dari 10 ke 15 (+5), bawah dari 43 ke 41 (-2)
        for(j = 37; j < 116; j++){
            gotoprintchar(j,i,32);
        }
    }
    SetColorBlock(7,7);
    gotoprintchar(37,15,219);
    gotoprintchar(38,15,219);
    gotoprintchar(37,16,219);

    gotoprintchar(37,40,219);
    gotoprintchar(38,40,219);
    gotoprintchar(37,39,219);

    gotoprintchar(114,15,219);
    gotoprintchar(115,15,219);
    gotoprintchar(115,16,219);

    gotoprintchar(114,41,219);  // Ubah dari 43 ke 41 (-2)
    gotoprintchar(115,41,219);
    gotoprintchar(115,40,219);

    SetColorBlock(7,9);
    gotoprintchar(40,15,201);
    for(i=41; i <= 111;i++){
        gotoprintchar(i,15,205);
    }
    gotoprintchar(112,15,187);

    gotoprintchar(40,16,188);
    gotoprintchar(39,16,201);
    gotoprintchar(39,17,188);
    gotoprintchar(38,17,201);

    for(i = 18; i <=38; i++){  // Ubah batas atas dari 13 ke 18 (+5), bawah dari 40 ke 38 (-2)
        gotoprintchar(38,i,186);
    }

    gotoprintchar(38,39,200);
    gotoprintchar(39,39,187);
    gotoprintchar(39,40,200);
    gotoprintchar(40,40,187);

    gotoprintchar(40,41,200);
    for(i=41; i <= 111;i++){
        gotoprintchar(i,41,205);  // Ubah dari 43 ke 41 (-2)
    }
    gotoprintchar(112,41,188);
    gotoprintchar(112,40,201);
    gotoprintchar(113,40,188);
    gotoprintchar(113,39,201);
    gotoprintchar(114,39,188);

    gotoprintchar(112,15,187);
    gotoprintchar(112,16,200);
    gotoprintchar(113,16,187);
    gotoprintchar(113,17,200);
    gotoprintchar(114,17,187);

    for(i = 18; i <=38; i++){  // Ubah batas atas dari 13 ke 18 (+5), bawah dari 40 ke 38 (-2)
        gotoprintchar(114,i,186);
    }
    SetColorBlock(7,9);
}



void BlankDesain(){
    SetColorBlock(7,7);
    for(i = 16; i < 34; i++){
        for(j = 130; j < 167; j++){
            gotoprintchar(j,i,32);
        }
    }
}

void BlankDashboard(){
    SetColorBlock(7,7);
    for(i = 9; i < 42; i++){
        for(j = 34; j < 170; j++){
            gotoprintchar(j,i,32);
        }
    }
}

void boxSearch(){
    SetColorBlock(1,7);
    gotoprintchar(136,9,201);
    for(i = 137; i <= 164;i++){
        gotoprintchar(i,9,205);
    }
    gotoprintchar(165,9,187);
    gotoprintchar(136,10,186);
    gotoprintchar(165,10,186);
    gotoprintchar(136,11,200);
    for(i = 137; i <= 164;i++){
        gotoprintchar(i,11,205);
    }
    gotoprintchar(165,11,188);
}

void tampilanDetailTableTransaksiPembersihanRumah(){
    SetColorBlock(1,7);
    /*border atas*/
    for(i = 12; i <= 12;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut kiri atas*/
    gotoprintchar(36,12,206);
    /*border sudut kanan atas*/
    gotoprintchar(167,12,206);
    /*border vertikal kebawah kiri*/
    for(i = 13; i <= 38;i++){
        gotoprintchar(36,i,186);
    }
    /*border vertikal kebawah kanan*/
    for(i = 13; i <= 38;i++){
        gotoprintchar(167,i,186);
    }
    /*border sudut bawah kiri*/
    gotoprintchar(36,38,206);
    for(i = 38; i <= 38;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut bawah kanan*/
    gotoprintchar(167,38,206);

    SetColorBlock(7,1);
    for(i = 13; i <= 15;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,32);
        }
    }
    gotoprinttext(38,14,"NO.");
    gotoprinttext(43,14,"ID TRANSAKSI");
    gotoprinttext(57,14,"ID PELANGGAN");
    gotoprinttext(69,14,"ID JENIS LAYANAN");
    gotoprinttext(100,14,"ID PROMO");
    gotoprinttext(123,14,"TOTAL HARGA");
}

void tampilanDetailTableTransaksiPembersihanKendaraan(){
    SetColorBlock(1,7);
    /*border atas*/
    for(i = 12; i <= 12;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut kiri atas*/
    gotoprintchar(36,12,206);
    /*border sudut kanan atas*/
    gotoprintchar(167,12,206);
    /*border vertikal kebawah kiri*/
    for(i = 13; i <= 38;i++){
        gotoprintchar(36,i,186);
    }
    /*border vertikal kebawah kanan*/
    for(i = 13; i <= 38;i++){
        gotoprintchar(167,i,186);
    }
    /*border sudut bawah kiri*/
    gotoprintchar(36,38,206);
    for(i = 38; i <= 38;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut bawah kanan*/
    gotoprintchar(167,38,206);

    SetColorBlock(7,1);
    for(i = 13; i <= 15;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,32);
        }
    }
    gotoprinttext(38,14,"NO.");
    gotoprinttext(43,14,"ID TRANSAKSI");
    gotoprinttext(57,14,"ID PELANGGAN");
    gotoprinttext(69,14,"ID JENIS LAYANAN");
    gotoprinttext(100,14,"ID JENIS KENDARAAN");
    gotoprinttext(125,14,"ID PROMO");
    gotoprinttext(135,14,"TOTAL HARGA");
}

void blankTable(){
    int u;
    SetColorBlock(7,7);
    for(u = 13; u <38; u++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,u,32);
        }
    }
}

void moreTable(int a){
    SetColorBlock(1,7);
    gotoxy(80,40);printf("Klik apa saja untuk melihat data selanjutnya...");
    getch();
    blankTable();
    y = a;
}

void rupiah(int number,char output[80]){
    if(number < 1000) sprintf(output, "Rp. %d", number);
    else if(number < 1000000) sprintf(output, "Rp. %d.%03d", number/1000, number%1000);
    else if(number < 1000000000) sprintf(output, "Rp. %d.%03d.%03d", number/1000000, (number%1000000)/1000, number%1000);
    else sprintf(output, "Rp. %d.%03d.%03d.%03d", number/1000000000, (number%1000000000)/1000, (number%1000000)/1000, number%1000);
}

void batasTable(){
    if (i == 25) {
        moreTable(12);
    }
    if (i == 50) {
        moreTable(12);
    }
    if (i == 75) {
        moreTable(12);
    }
    if (i == 100) {
        moreTable(12);
    }
    if (i == 125) {
        moreTable(12);
    }
    if (i == 150) {
        moreTable(12);
    }
    if (i == 175) {
        moreTable(12);
    }if (i == 200) {
        moreTable(12);
    }if (i == 225) {
        moreTable(12);
    }if (i == 250) {
        moreTable(12);
    }if (i == 275) {
        moreTable(12);
    }if (i == 300) {
        moreTable(12);
    }if (i == 325) {
        moreTable(12);
    }if (i == 350) {
        moreTable(12);
    }if (i == 375) {
        moreTable(12);
    }if (i == 400) {
        moreTable(12);
    }if (i == 425) {
        moreTable(12);
    }if (i == 450) {
        moreTable(12);
    }
    if (i == 475) {
        moreTable(12);
    }if (i == 500) {
        moreTable(12);
    }if (i == 525) {
        moreTable(12);
    }if (i == 550) {
        moreTable(12);
    }if (i == 575) {
        moreTable(12);
    }if (i == 600) {
        moreTable(12);
    }if (i == 625) {
        moreTable(12);
    }if (i == 650) {
        moreTable(12);
    }if (i == 675) {
        moreTable(12);
    }if (i == 700) {
        moreTable(12);
    }if (i == 725) {
        moreTable(12);
    }if (i == 750) {
        moreTable(12);
    }if (i == 775) {
        moreTable(12);
    }if (i == 800) {
        moreTable(12);
    }if (i == 825) {
        moreTable(12);
    }if (i == 850) {
        moreTable(12);
    }if (i == 875) {
        moreTable(12);
    }if (i == 900) {
        moreTable(12);
    }if (i == 925) {
        moreTable(12);
    }if (i == 950) {
        moreTable(12);
    }if (i == 975) {
        moreTable(12);
    }if (i == 1000) {
        moreTable(12);
    }if (i == 1025) {
        moreTable(12);
    }if (i == 1050) {
        moreTable(12);
    }if (i == 1075) {
        moreTable(12);
    }if (i == 1100) {
        moreTable(12);
    }if (i == 1125) {
        moreTable(12);
    }if (i == 1150) {
        moreTable(12);
    }if (i == 1175) {
        moreTable(12);
    }if (i == 1200) {
        moreTable(12);
    }if (i == 1225) {
        moreTable(12);
    }if (i == 1250) {
        moreTable(12);
    }if (i == 1275) {
        moreTable(12);
    }if (i == 1300) {
        moreTable(12);
    }if (i == 1325) {
        moreTable(12);
    }if (i == 1350) {
        moreTable(12);
    }if (i == 1375) {
        moreTable(12);
    }if (i == 1400) {
        moreTable(12);
    }if (i == 1425) {
        moreTable(12);
    }if (i == 1450) {
        moreTable(12);
    }if (i == 1475) {
        moreTable(12);
    }if (i == 1500) {
        moreTable(12);
    }
}

void menuLihatorBack(int x, int y,int jarak){
    gotoprinttext(x,y,"LIHAT DETAIL\n");
    gotoprinttext(x-jarak,y,"KEMBALI");
}

void SpecialKeyCariorBackDashboard(int x, int y,int jarak,int fore,int back,int *output) {
    hideCursor();
    int count = 1;
    char ch;
    //Algorithm
    SetColorBlock(fore, back);
    menuLihatorBack(x,y,jarak);
    if(count == 1){
        SetColorBlock(0,back);
        gotoprinttext(x,y,"LIHAT DETAIL");
    }

    while (1) {
        ch = getch();
        if (ch == ENTER || ch == TAB) {
            switch (count) {
                case 1 :
                    Beep(1000, 120);
                *output = count;
                break;

                case 2 :
                    Beep(1000, 120);
                *output = count;
                break;
            }
            break;
        } else if (ch == RIGHT_KEY) {
            if (count > 1) {
                Beep(700, 120);
                SetColorBlock(fore, back);
                menuLihatorBack(x,y,jarak);
                count--;
                if(count == 1){
                    SetColorBlock(0,back);
                    gotoprinttext(x,y,"LIHAT DETAIL");
                } else if(count == 2){
                    SetColorBlock(0,back);
                    gotoprinttext(x-jarak,y,"KEMBALI");
                }
            }
        } else if (ch == LEFT_KEY) {
            if (count < 2) {
                Beep(700, 120);
                SetColorBlock(fore, back);
                menuLihatorBack(x,y,jarak);
                count++;
                if(count == 1){
                    SetColorBlock(0,back);
                    gotoprinttext(x,y,"LIHAT DETAIL");
                } else if(count == 2){
                    SetColorBlock(0,back);
                    gotoprinttext(x-jarak,y,"KEMBALI");
                }
            }
        }
    }
}

void tampilanTableTransaksiPembersihanRumah(){
    SetColorBlock(1,7);
    /*border atas*/
    for(i = 12; i <= 12;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut kiri atas*/
    gotoprintchar(36,12,206);
    /*border sudut kanan atas*/
    gotoprintchar(167,12,206);
    /*border vertikal kebawah kiri*/
    for(i = 13; i <= 38;i++){
        gotoprintchar(36,i,186);
    }
    /*border vertikal kebawah kanan*/
    for(i = 13; i <= 38;i++){
        gotoprintchar(167,i,186);
    }
    /*border sudut bawah kiri*/
    gotoprintchar(36,38,206);
    for(i = 38; i <= 38;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut bawah kanan*/
    gotoprintchar(167,38,206);

    SetColorBlock(7,1);
    for(i = 13; i <= 15;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,32);
        }
    }
    gotoprinttext(38,14,"NO.");
    gotoprinttext(43,14,"ID TRANSAKSI");
    gotoprinttext(57,14,"ID PELANGGAN");
    gotoprinttext(69,14,"ID JENIS LAYANAN");
    gotoprinttext(100,14,"ID PROMO");
    gotoprinttext(123,14,"TOTAL HARGA");
}

void tampilanTableTransaksiPembersihanKendaraan(){
    SetColorBlock(1,7);
    /*border atas*/
    for(i = 12; i <= 12;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut kiri atas*/
    gotoprintchar(36,12,206);
    /*border sudut kanan atas*/
    gotoprintchar(167,12,206);
    /*border vertikal kebawah kiri*/
    for(i = 13; i <= 38;i++){
        gotoprintchar(36,i,186);
    }
    /*border vertikal kebawah kanan*/
    for(i = 13; i <= 38;i++){
        gotoprintchar(167,i,186);
    }
    /*border sudut bawah kiri*/
    gotoprintchar(36,38,206);
    for(i = 38; i <= 38;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,205);
        }
    }
    /*border sudut bawah kanan*/
    gotoprintchar(167,38,206);

    SetColorBlock(7,1);
    for(i = 13; i <= 15;i++){
        for(j = 37; j < 167; j++){
            gotoprintchar(j,i,32);
        }
    }
    gotoprinttext(38,14,"NO.");
    gotoprinttext(43,14,"ID TRANSAKSI");
    gotoprinttext(57,14,"ID PELANGGAN");
    gotoprinttext(75,14,"ID JENIS LAYANAN");
    gotoprinttext(95,14,"ID JENIS KENDARAAN");
    gotoprinttext(115,14,"ID PROMO");
    gotoprinttext(135,14,"TOTAL HARGA");
}


void uangLaporan(int number,char output[80]){
    if(number < 1000) sprintf(output, "%d", number);
    else if(number < 1000000) sprintf(output, "%d.%03d", number/1000, number%1000);
    else if(number < 1000000000) sprintf(output, "%d.%03d.%03d", number/1000000, (number%1000000)/1000, number%1000);
    else sprintf(output, "%d.%03d.%03d.%03d", number/1000000000, (number%1000000000)/1000, (number%1000000)/1000, number%1000);
}

void aturkanankekiri(char kata[],int a, int b){
    // Kata yang akan dicetak
    int panjang = strlen(kata);

    // Tentukan posisi awal cetakan
    x = a - panjang; // Kolom 80 sebagai batas, kurangi panjang kata
    y = b; // Baris 10, bisa disesuaikan dengan tinggi layar

    // Cetak kata dari kanan ke kiri
    gotoxy(x, y);
    printf("%s", kata);
    printf("\n");
}

void menuYesorNo(int x, int y,int jarak){
    gotoprinttext(x,y,"    Y A\n");
    gotoprinttext(x-jarak,y,"T I D A K");
}

void SpecialKeyYesorNoDashboard(int x, int y,int jarak,int fore,int back,int *output) {
    hideCursor();
    int count = 1;
    char ch;
    //Algorithm
    SetColorBlock(fore, back);
    menuYesorNo(x,y,jarak);
    if(count == 1){
        SetColorBlock(0,back);
        gotoprinttext(x,y,"    Y A");
    }

    while (1) {
        ch = getch();
        if (ch == ENTER || ch == TAB) {
            switch (count) {
                case 1 :
                    Beep(1000, 120);
                *output = count;
                break;

                case 2 :
                    Beep(1000, 120);
                *output = count;
                break;
            }
            break;
        } else if (ch == RIGHT_KEY) {
            if (count > 1) {
                Beep(700, 120);
                SetColorBlock(fore, back);
                menuYesorNo(x,y,jarak);
                count--;
                if(count == 1){
                    SetColorBlock(0,back);
                    gotoprinttext(x,y,"    Y A");
                } else if(count == 2){
                    SetColorBlock(0,back);
                    gotoprinttext(x-jarak,y,"T I D A K");
                }
            }
        } else if (ch == LEFT_KEY) {
            if (count < 2) {
                Beep(700, 120);
                SetColorBlock(fore, back);
                menuYesorNo(x,y,jarak);
                count++;
                if(count == 1){
                    SetColorBlock(0,back);
                    gotoprinttext(x,y,"    Y A");
                } else if(count == 2){
                    SetColorBlock(0,back);
                    gotoprinttext(x-jarak,y,"T I D A K");
                }
            }
        }
    }
}

void bulan(){
    gotoprinttext(48,23,"Januari");
    gotoprinttext(48,24,"Februari");
    gotoprinttext(48,25,"Maret");
    gotoprinttext(48,26,"April");
    gotoprinttext(48,27,"Mei");
    gotoprinttext(48,28,"Juni");
    gotoprinttext(48,29,"Juli");
    gotoprinttext(48,30,"Agustus");
    gotoprinttext(48,31,"September");
    gotoprinttext(48,32,"Oktober");
    gotoprinttext(48,33,"November");
    gotoprinttext(48,34,"Desember");

}

void borderInput(int x, int y, int lebar){
    /*sudut kiri atas*/
    gotoprintchar(x,y,201);

    /*tepi atas*/
    int a = x +1;
    for(i = 0; i < lebar;i++){
        gotoprintchar(a,y,205);
        a++;
    }
    /*sudut kanan atas*/
    gotoprintchar(a,y,187);

    /*untuk tepi kiri tengah*/
    gotoprintchar(x,y+1,186);
    /*untuk tepi kanan tengah*/
    gotoprintchar(a,y+1,186);

    /*sudut kiri bawah*/
    gotoprintchar(x,y+2,200);

    /*tepi bawah*/
    a = x +1;
    for(i = 0; i < lebar;i++){
        gotoprintchar(a,y+2,205);
        a++;
    }

    /*sudut kanan bawah*/
    gotoprintchar(a,y + 2,188);

}

void kertas(int x,int y){
    SetColorBlock(15,15);
    for(i = 10; i <= 40;i++){
        for(j = 36; j <= 127; j++){
            gotoprintchar(j,i,219);
        }
    }
    SetColorBlock(1,15);
    //DrawFile(x,y,namaFile);
    SetColorBlock(1,15);
    frameLayout(36,10,37,40,223);
    frameLayout(36,10,128,11,223);
    frameLayout(127,10,128,40,223);
    frameLayout(36,40,128,41,220);
}

void lembarLaporanBulanan(){
    SetColorBlock(1,15);
    kertas(50,12);
    gotoprinttext(58,18,"UNTUK PERIODE BULAN  TAHUN ");
    SetColorBlock(7,9);
    //DrawFile(132,13,"../Desaintxt/Dashboard/cariLaporan.txt");
    gotoprinttext(133,23,"Bulan");
    borderInput(133,24,32);
    gotoprinttext(133,27,"Tahun");
    borderInput(133,28,32);
    for(j = 20; j <= 22; j++) {
        for (i = 42; i < 120; i++) {
            gotoprintchar(i, j, 32);
        }
    }
    for(i = 23; i< 35;i++){
        gotoprintchar(42,i,32);
    }
    for(i = 42; i< 120;i++){
        gotoprintchar(i,35,32);
    }
    for(i = 23; i< 35;i++){
        gotoprintchar(46,i,32);
    }
    for(i = 23; i< 35;i++){
        gotoprintchar(100,i,32);
    }
    for(i = 23; i< 35;i++){
        gotoprintchar(119,i,32);
    }
    for(i=23; i < 35;i++){
        SetColorBlock(9,15);
        gotoprinttext(102,i,"Rp.");
    }
    for(i = 1; i <=9; i++){
        gotoxy(44,22+i);
        printf("%d.",i);
    }
    for(i = 10; i <=12; i++){
        gotoxy(43,22+i);
        printf("%d.",i);
    }
    SetColorBlock(15,9);
    for(i = 101; i < 117; i++){
        gotoprintchar(i,35,196);
    }
    gotoprinttext(118,35,"+");
    SetColorBlock(9,15);
    gotoprinttext(82,37,"TOTAL KESELURUHAN : Rp.");
    SetColorBlock(15,9);
    gotoprinttext(43,21,"NO.");
    gotoprinttext(67,21,"ID TRANSAKSI");
    gotoprinttext(102,21,"TOTAL PENDAPATAN");
}

void lembarLaporanTahunan(){
    SetColorBlock(1,15);
    kertas(50,12);
    gotoprinttext(58,18,"U N T U K  P E R I O D E  T A H U N");
    SetColorBlock(7,9);
    //DrawFile(132,13,"../Desaintxt/Dashboard/cariLaporan.txt");
    gotoprinttext(133,25,"Tahun");
    borderInput(133,26,32);
    for(j = 20; j <= 22; j++) {
        for (i = 42; i < 120; i++) {
            gotoprintchar(i, j, 32);
        }
    }
    for(i = 23; i< 35;i++){
        gotoprintchar(42,i,32);
    }
    for(i = 42; i< 120;i++){
        gotoprintchar(i,35,32);
    }
    for(i = 23; i< 35;i++){
        gotoprintchar(46,i,32);
    }
    for(i = 23; i< 35;i++){
        gotoprintchar(100,i,32);
    }
    for(i = 23; i< 35;i++){
        gotoprintchar(119,i,32);
    }
    for(i=23; i < 35;i++){
        SetColorBlock(9,15);
        gotoprinttext(102,i,"Rp.");
    }
    for(i = 1; i <=9; i++){
        gotoxy(44,22+i);
        printf("%d.",i);
    }
    for(i = 10; i <=12; i++){
        gotoxy(43,22+i);
        printf("%d.",i);
    }
    SetColorBlock(15,9);
    for(i = 101; i < 117; i++){
        gotoprintchar(i,35,196);
    }
    gotoprinttext(118,35,"+");
    SetColorBlock(9,15);
    bulan();
    gotoprinttext(82,37,"TOTAL KESELURUHAN : Rp.");
    SetColorBlock(15,9);
    gotoprinttext(43,21,"NO.");
    gotoprinttext(72,21,"BULAN");
    gotoprinttext(102,21,"TOTAL PENDAPATAN");
}