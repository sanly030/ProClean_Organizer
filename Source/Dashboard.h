

void Dashboard() {
    system("color 71");

    PrintFile("..//Asset//Admin.txt", 7, 2);
    borderAwal();
    garisFullBlokVertical(47,2,42);
    garisFullBlokHorizontal(3,9,171);


    int opsi;
    gotoprinttext(18,12,"1. D A T A ");
    gotoprinttext(15,14,"  P E T U G A S");
    gotoprinttext(17,16,"2. J E N I S");
    gotoprinttext(15,18,"  P E T U G A S");
    gotoprinttext(18,20,"3. D A T A ");
    gotoprinttext(15,22,"  P E T U G A S");
    gotoprinttext(13,26,"P I L I H  M E N U : ");
    gotoxy(34,26);
    scanf("%d",&opsi);
    gotoprinttext(20,40,"K E L U A R ");

    switch (opsi) {
        case 1:
            MenuAdmin();break;
        case 2:
            MenuJenisPetugas();break;
    }
}