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

void frameTransaksi(int x, int y){
    SetColorBlock(9,9);
    for(i = 10; i < 43; i++){  // Ubah batas bawah dari 42 ke 43 (+1)
        for(j = 37; j < 116; j++){
            gotoprintchar(j,i,32);
        }
    }
    SetColorBlock(7,7);
    gotoprintchar(37,10,219);
    gotoprintchar(38,10,219);
    gotoprintchar(37,11,219);

    gotoprintchar(37,42,219);
    gotoprintchar(38,42,219);
    gotoprintchar(37,41,219);

    gotoprintchar(114,10,219);
    gotoprintchar(115,10,219);
    gotoprintchar(115,11,219);

    gotoprintchar(114,43,219);  // Ubah dari 42 ke 43 (+1)
    gotoprintchar(115,43,219);
    gotoprintchar(115,42,219);

    SetColorBlock(7,9);
    gotoprintchar(40,10,201);
    for(i=41; i <= 111;i++){
        gotoprintchar(i,10,205);
    }
    gotoprintchar(112,10,187);

    gotoprintchar(40,11,188);
    gotoprintchar(39,11,201);
    gotoprintchar(39,12,188);
    gotoprintchar(38,12,201);

    for(i = 13; i <=40; i++){  // Ubah batas bawah dari 39 ke 40 (+1)
        gotoprintchar(38,i,186);
    }

    gotoprintchar(38,41,200);
    gotoprintchar(39,41,187);
    gotoprintchar(39,42,200);
    gotoprintchar(40,42,187);

    gotoprintchar(40,43,200);
    for(i=41; i <= 111;i++){
        gotoprintchar(i,43,205);  // Ubah dari 42 ke 43 (+1)
    }
    gotoprintchar(112,43,188);
    gotoprintchar(112,42,201);
    gotoprintchar(113,42,188);
    gotoprintchar(113,41,201);
    gotoprintchar(114,41,188);

    gotoprintchar(112,10,187);
    gotoprintchar(112,11,200);
    gotoprintchar(113,11,187);
    gotoprintchar(113,12,200);
    gotoprintchar(114,12,187);

    for(i = 13; i <=40; i++){  // Ubah batas bawah dari 39 ke 40 (+1)
        gotoprintchar(114,i,186);
    }
    SetColorBlock(7,9);
}


