void Dashboard() {
    system("color 71");

    PrintFile("..//Asset//Admin.txt", 7, 2);
    borderAwal();
    garisFullBlokVertical(49,2,42);
    garisFullBlokHorizontal(3,9,171);


    int opsi;
    gotoprinttext(21,12,"D A T A ");
    gotoprinttext(18,14,"P E T U G A S");
    gotoxy(7, 15);
    printf("2. C R U D  J E N I S  P E T U G A S");
    gotoxy(7, 16);
    printf("3. C R U D  P E L A N G G A N");
    gotoxy(7, 18);
    printf("P I L I H  M E N U : ");
    gotoxy(29,18);
    scanf("%d",&opsi);
    switch (opsi) {
        case 1:
            clearArea(3,9,46,43);

        break;

    }
}