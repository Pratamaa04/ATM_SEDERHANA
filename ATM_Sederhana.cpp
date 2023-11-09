#include <iostream>

using namespace std;

int main()
{
    int defaultNoRek = 123456, defaultNoRekA = 22222, defaultNoRekB = 33333, defaultPin = 1234, pin = 0, noRek = 0;
    int saldo = 100, saldo50, saldo100, nominal = 0, pecahan, pecahan50 = 50, pecahan100 = 100;
    int ulang = 0, ulangNorek = 0, konfirmasi = 0;
    int menuPilih = 0, pilih;
    // USER memesukan pin
    cout << "ATM SEDERHANA\n";
    // Pengulangan Sementar hanya untuk pin jika salah atau benar ATM terblokir (Mungkin bisa ditambah no rek)
    while (ulang < 3)
    {
        cout << "Masukan No rekening anda : ";
        cin >> noRek;
        cout << "Masukan No pin anda : ";
        cin >> pin;
        // USER masuk dalam menu
        if (noRek == defaultNoRek && pin == defaultPin)
        {
            // pengulangan untuk menu
            while (pilih != 0)
            {
                cout << "Pilih Transaksi \n";
                cout << "1. Transfer uang \n";
                cout << "2. Tarik tunai \n";
                cout << "3. Info saldo \n";
                cout << "4. Setor tunai \n";
                cout << "5. Pembayaran virtual account \n";
                cout << "0. Exit\n";
                cout << "Masukan pilihan anda :";
                cin >> pilih;
                ulangNorek = 0;
                switch (pilih)
                {
                    // Menu Transfer
                case 1:
                    cout << "Menu Transfer\n";
                    // Pengulangan no rek tujuan
                    while (ulangNorek == 0)
                    {
                        // User input no rek tujuan
                        cout << "Masukkan No rekening tujuan: ";
                        cin >> noRek;
                        // pengkondisian jika no rek tidak terdaftar
                        if (noRek == defaultNoRekA || noRek == defaultNoRekB)
                        {
                            // User input nominal
                            cout << "Masukkan Nominal : ";
                            cin >> nominal;
                            // pengkondisian jika saldo lebih atau kurang
                            if (saldo >= nominal)
                            {
                                // Konfirmasi jika inputan user benar
                                cout << "NO rekening tujuan : " << noRek << endl;
                                cout << "Nominal uang : " << nominal << endl;
                                cout << "Apakah yang anda masukkan sudah benar !\n(Ketik 1 untuk IYA & ketik 0 untuk TIDAK) :";
                                cin >> konfirmasi;
                                if (konfirmasi != 0)
                                {
                                    // Pengulangan jika pin salah atm terblokir
                                    menuPilih = 0;
                                    while (menuPilih < 3)
                                    {
                                        // Konfirmasi pin jika inputan sudah benar
                                        cout << "Masukkan Pin untuk konfirmasi:";
                                        cin >> pin;
                                        // pekondisian untuk pin salah atau benar
                                        if (pin == defaultPin)
                                        {
                                            // progress pengurangan saldo
                                            saldo = saldo - nominal;
                                            cout << "Transaksi Berhasil\n";
                                            cout << "Saldo tersisa : " << saldo << endl;
                                            // jika ingin melakukan transaksi lainnya
                                            cout << "Apakah anda ingin melakukan transaksi lainnya ?\n(Ketik 1 untuk iya / ketik 0 untuk tidak)";
                                            cin >> pilih;
                                            if (pilih != 0)
                                            {
                                                menuPilih = 3;
                                                ulangNorek = 1;
                                            }
                                            else
                                            {
                                                ulangNorek = 1;
                                                menuPilih = 3;
                                                ulang = 3;
                                            }
                                        }
                                        // pengkondisian jika pin
                                        else
                                        {
                                            cout << "PIN SALAH!\n";
                                            menuPilih++;
                                            if (menuPilih == 3)
                                            {
                                                ulangNorek = 1;
                                                ulang = 3;
                                                pilih = 0;
                                                cout << "ATM terblokir" << endl;
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    cout << "Apakah ingin mengubah tujuan no rekening dan nominal ?\n (ketik 1 untuk IYA dan ketik 0 untuk kembali ke menu)";
                                    cin >> konfirmasi;
                                    if (konfirmasi != 0)
                                    {
                                        ulangNorek = 0;
                                    }
                                    else
                                    {
                                        ulangNorek = 1;
                                    }
                                }
                            }
                            else
                            {
                                cout << "Saldo Anda Kurang \n";
                                cout << "Apakah anda ingin melakukan transaksi lainnya ?\n(Ketik 1 untuk iya / ketik 0 untuk tidak)";
                                cin >> pilih;
                                if (pilih == 0)
                                {
                                    ulang = 3;
                                }
                                else
                                {
                                    ulangNorek = 1;
                                }
                            }
                        }
                        // jika no rekening tujuan tidak ditemukan
                        else
                        {
                            cout << "No rekening tujuan tidak ditemukan" << endl;
                            cout << "Apakah anda ingin mengisi ulang no rekening tujuan \n (ketik 1 untuk kembali ke menu / ketik 0 untuk mengisi ulang)";
                            cin >> ulangNorek;
                        }
                    }
                    break;

                // menu tarik tunai
                case 2:
                    cout << "Menu Tarik tunai" << endl;

                    break;

                case 0:
                    cout << "Exit";
                    ulang = 3;
                    break;

                default:
                    pilih = 0;
                    ulang = 3;
                    break;
                }
            }
        }
        else
        {
            cout << "PIN yang anda masukkan salah \n";
            ulang++;
            if (ulang == 3)
            {
                cout << "ATM Anda terblokir\n";
            }
        }
    }
    cout << "Program Selesai";
    return 0;
}