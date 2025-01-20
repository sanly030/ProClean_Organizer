void Dashboard() {
    system("color 71");
    PrintFile("..//Asset//ProCleanV2.txt",40 , 0);
    // PrintFile("..//Asset//Admin.txt", 7, 2);
    borderAwal();
    garisFullBlokVertical(29,2,42);
    garisFullBlokHorizontal(3,9,171);


    int opsi;
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
    gotoprinttext(6,24,"P I L I H  M E N U : ");
    gotoprinttext(10,35,"K E L U A R ");
    gotoxy(27,24);
    scanf("%d",&opsi);


    switch (opsi) {
        case 1:
            MenuJenisPetugas();break;
        case 2:
            DashboardMenuAdmin();break;
    }
}