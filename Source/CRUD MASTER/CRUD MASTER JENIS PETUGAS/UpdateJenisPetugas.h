//
// Created by hi on 1/12/2025.
//

#ifndef UPDATEJENISPETUGAS_H
#define UPDATEJENISPETUGAS_H


void TextBoxUpdateJenisPetugas(id_petugas);

//Fungsi Ubah Data Jenis Petugas
void UpdateJenisPetugas() {
    SetColorBlock(1,7);


    ReadUpdateJenisPetugas();


    // if (found) {
    //     gotoprinttext(65,30,"Data petugas berhasil diubah.\n");
    // } else {
    //     gotoxy(65,30);
    //
    //     printf("Data dengan ID Petugas JGS00%d tidak ditemukan.\n", id_petugas);
    // }
    getch();
    MenuJenisPetugas();
}


void TextBoxUpdateJenisPetugas(id_petugas) {
    textBox2(130,17,39,25);
    gotoprinttext(141,28,"U P D A T E  D A T A");
    gotoprinttext(134,30,"Masukkan ID Jenis : JPS00 ");
    gotoxy(159,30);
    getnum(&id_petugas,3);
}


#endif //UPDATEJENISPETUGAS_H
