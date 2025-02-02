

void Dashboard() {
    system("color 71");
    PrintFile("..//Asset//ikonsapu.txt",90, 12);
    PrintFile("..//Asset//HelloAdmin!.txt",50, 20);
    PrintFile("..//Asset//ProCleanV2.txt",43, 0);
    // PrintFile("..//Asset//Admin.txt", 7, 2);
    borderAwal();
    garisFullBlokVertical(29,2,42);
    garisFullBlokHorizontal(3,9,171);
    garisFullBlokVertical(146,2,8);

    gotoprinttext(7,4,"M E N U  A D M I N");
    gotoprinttext(7,5," P R O C L E A N");
    gotoprinttext(7,6,"O R G A N I Z E R");
    gotoprinttext(9,11,"P R O F I L E ");
    gotoprinttext(9,12,"  A D M I N ");
    gotoprinttext(9,14,"  J E N I S ");
    gotoprinttext(9,15,"P E T U G A S ");
    gotoprinttext(9,17,"   D A T A ");
    gotoprinttext(9,18,"P E T U G A S ");
    gotoprinttext(9,20,"   D A T A ");
    gotoprinttext(9,21,"L A Y A N A N ");
    gotoprinttext(9,23,"J E N I S  ");
    gotoprinttext(9,24,"L A Y A N A N");
    gotoprinttext(9,26,"P A K E T  ");
    gotoprinttext(9,27,"L A Y A N A N");
    gotoprinttext(9,28,"M E N U");
    gotoprinttext(9,29,"P E L A N G G A N");
    gotoprinttext(9,30,"M E N U");
    gotoprinttext(9,31,"P E M B A Y A R A N");


    textBox2(3,39,24,2);
    gotoprinttext(5,40,"P I L I H  M E N U :[ ]");

    gotoprinttext(10,35,"K E L U A R ");
    gotoxy(26,40);
    getnum(&opsi,2);

    switch (opsi) {
        case 1:blankScreen();MenuJenisPetugas();break;
        case 2:blankScreen();MenuPetugas();break;
        case 3:blankScreen();MenuLayanan();break;
        case 4:blankScreen();MenuJnsLayanan();break;
        case 5:blankScreen();MenuPromo();break;
        case 6:blankScreen();MenuPelanggan();break;
        case 7:blankScreen();MenuPembayaran();break;
        case 8:blankScreen();MenuJenisKendaraan();break;
        case 9:blankScreen();createTransaksiRumah();break;
        case 10:blankScreen();createTransaksiKendaraan();break;
        // case 5:blankScreen();MenuPktLayanan();break;
    }
}
