#ifndef LIB_H
#define LIB_H

void seluruhjenispetugas(); // Deklarasi fungsi
void seluruhDataPetugas();  // Deklarasi fungsi


void seluruhpetugas() {
    SetColorBlock(1,7);
    gotoprinttext(55,19,"D E T A I L  D A T A");
    gotoprinttext(43,22,"ID PETUGAS          :");
    gotoprinttext(43,24,"NAMA                :");
    gotoprinttext(43,26,"TANGGAL LAHIR       :");
    gotoprinttext(43,28,"NO TELP             :");
    gotoprinttext(43,30,"STATUS              :");
    gotoprinttext(43,32,"USERNAME            :");
    gotoprinttext(43,34,"PASSWORD            :");

}

void seluruhjenispetugas() {
    SetColorBlock(1,7);
    gotoprinttext(55,19,"D E T A I L  D A T A");
    gotoprinttext(43,25,"ID PETUGAS          :");
    gotoprinttext(43,27,"NAMA JABATAN        :");
    gotoprinttext(43,29,"DESKRIPSI           :");
}

void seluruhLayanan() {
    SetColorBlock(1,7);
    gotoprinttext(55,22,"D E T A I L  D A T A");
    gotoprinttext(43,25,"ID LAYANAN          :");
    gotoprinttext(43,27,"JENIS LAYANAN       :");
}

void seluruhJnsLayanan() {
    SetColorBlock(1,7);
    gotoprinttext(55,22,"D E T A I L  D A T A");
    gotoprinttext(43,25,"ID LAYANAN          :");
    gotoprinttext(43,27,"JENIS PAKET         :");
    gotoprinttext(43,29,"HARGA               :");
    gotoprinttext(43,31,"DURASI              :");
    gotoprinttext(43,33,"STATUS              :");

}

void seluruhPromo() {
    SetColorBlock(1,7);
    gotoprinttext(55,21,"D E T A I L  D A T A");
    gotoprinttext(43,23,"ID PROMO            :");
    gotoprinttext(43,25,"NAMA PROMO          :");
    gotoprinttext(43,27,"POTONGAN            :");
    gotoprinttext(43,29,"TANGGAL MULAI       :");
    gotoprinttext(43,31,"TANGGAL SELESAI     :");
}

void seluruhPelanggan() {
    SetColorBlock(1,7);
    gotoprinttext(55,20,"D E T A I L  D A T A");
    gotoprinttext(43,23,"ID PELANGGAN        :");
    gotoprinttext(43,25,"NAMA PELANGGAN      :");
    gotoprinttext(43,27,"ALAMAT              :");
    gotoprinttext(43,29,"NO TELP             :");
    gotoprinttext(43,31,"JENIS KELAMIN       :");
}

void seluruhKendaraan() {
    SetColorBlock(1,7);
    gotoprinttext(55,20,"D E T A I L  D A T A");
    gotoprinttext(43,23,"ID PELANGGAN        :");
    gotoprinttext(43,25,"JENIS KENDARAAN     :");
}

void seluruhPembayaran() {
    SetColorBlock(1,7);
    gotoprinttext(55,20,"D E T A I L  D A T A");
    gotoprinttext(43,23,"ID PEMBAYARAN       :");
    gotoprinttext(43,25,"NAMA PEMBAYARAN     :");
}

void Tanggal()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char *wday[] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};

    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    gotoxy(149,4);printf("Waktu Masuk: %02d:%02d:%02d\n",timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);


    gotoxy(151, 5); printf("%s,%02d-%02d-%d", wday[tm.tm_wday],tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900);
}

#endif