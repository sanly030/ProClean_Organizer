// //
// // Created by hi on 1/30/2025.
// //
//
// #ifndef CREATEPKTLAYANAN_H
// #define CREATEPKTLAYANAN_H
//
// PktLayanan pkt;
// void CreatePktLayanan() {
//     char Opsi;
//     do {
//         blankScreen();
//         SetColorBlock(1, 7);
//         textBox2(31, 10, 139, 33);
//         PrintFile("..//Asset//TambahData.txt", 50, 11);
//
//         // Membaca daftar layanan
//         FILE *arsjly = fopen("../Database/Dat/JENISLAYANAN.dat", "rb");
//         if (arsjly == NULL) {
//             printf("File LAYANAN.dat tidak dapat dibuka.\n");
//             return;
//         }
//
//         jnslayanan jly[20];
//         int jumlahJnsLayanan = 0, i = 0;
//
//         textBox2(130, 17, 39, 18);
//         BoxBlock(131, 18, 38, 17);
//         SetColorBlock(7, 1);
//         gotoprinttext(137, 19, "D A F T A R  J N S  P A K E T ");
//
//         while (fread(&jly[i], sizeof(jly), 1, arsjly)) {
//             gotoxy(132, 20 + (i + 1));
//             printf("[ %d ] %s", jly[i].id_jnslayanan, jly[i].jenispaket);
//             i++;
//         }
//         fclose(arsjly);
//         jumlahJnsLayanan = i;
//
//         // Generate ID Jenis Layanan baru
//         int lastPktLayanan = 0;
//         FILE *arspkt = fopen("../Database/Dat/PAKET LAYANAN.dat", "rb");
//         while (fread(&pkt, sizeof(pkt), 1, arspkt)) {
//             if (pkt.id_pktLayanan >= lastPktLayanan) {
//                 lastPktLayanan = pkt.id_pktLayanan;
//             }
//         }
//         lastPktLayanan++;
//         fclose(arspkt);
//         pkt.id_pktLayanan = lastPktLayanan;
//
//         SetColorBlock(1, 7);
//         textBox2(41, 18, 72, 20);
//         BoxBlock(43, 19, 70, 18);
//         SetColorBlock(7, 1);
//
//         gotoxy(45, 20);
//         printf("I D  P A K E T  L A Y A N A N         : PKT%03d\n", pkt.id_pktLayanan);
//         gotoprinttext(45, 22, "I D  J E N I S  L A Y A N A N                  : JLY%03d\n", jly.id_jnslayanan );
//         gotoprinttext(45, 24, "N A M A  P A K E T                             : ");
//         gotoprinttext(45, 26, "J E N I S  P A K E T                           :    );
//
//         for ( i = 85; i <= 110 ; i++) {
//             gotoprintchar(i,23,196);
//         }
//         for ( i = 85; i <= 110 ; i++) {
//             gotoprintchar(i,25,196);
//         }
//         for ( i = 85; i <= 110 ; i++) {
//             gotoprintchar(i,27,196);
//         }
//
//
//
//
// }
// #endif //CREATEPKTLAYANAN_H
