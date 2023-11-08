#include <iostream>

using namespace std;

int main()
{
    int defaultNoRek = 123456, defaultNoRekA = 22222, defaultNoRekB = 33333, defaultPin = 1234, pin = 0, noRek = 0;
    int saldo = 100, nominal = 0, pecahan, pecahan50 = 50, pecahan100 = 100;
    int ulang = 0;
    int menuPilih = 0, pilih;
    // USER memesukan pin
    cout << "ATM SEDERHANA\n";
    while (ulang < 3)
    {
        cout << "Masukan No rekening anda : ";
        cin >> noRek;
        cout << "Masukan No pin anda : ";
        cin >> pin;
        // USER masuk dalam menu
        if (noRek == defaultNoRek && pin == defaultPin)
        {
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
                switch (pilih)
                {
                    // Menu Transfer
                case 1:
                    cout << "Menu Transfer\n";
                    // while ()
                    // {
                    cout << "Masukkan No rekening tujuan: ";
                    cin >> noRek;
                    if (noRek == defaultNoRekA || noRek == defaultNoRekB)
                    {
                        cout << "Masukkan Nominal : ";
                        cin >> nominal;
                        if (saldo >= nominal)
                        {
                            cout << "NO rekening tujuan : " << noRek << endl;
                            cout << "Nominal uang : " << nominal << endl;
                            while (menuPilih < 3)
                            {
                                cout << "Masukkan Pin untuk konfirmasi:";
                                cin >> pin;
                                if (pin == defaultPin)
                                {
                                    saldo = saldo - nominal;
                                    cout << "Transaksi Berhasil\n";
                                    cout << "Saldo tersisa : " << saldo << endl;
                                    cout << "Apakah anda ingin melakukan transaksi lainnya ?\n(Ketik 1 untuk iya / ketik 0 untuk tidak)";
                                    cin >> pilih;
                                    if (pilih != 0)
                                    {
                                    }
                                }
                                else
                                {
                                    cout << "PIN SALAH!\n";
                                    menuPilih++;
                                    if (menuPilih == 3)
                                    {
                                        ulang = 3;
                                        pilih = 0;
                                        cout << "ATM terblokir" << endl;
                                    }
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
                        }
                    }
                    else
                    {
                        cout << "No rekening tujuan tidak ditemukan" << endl;
                    }
                    // }
                    break;
                    // case 2:
                    //     cout << "Menu Tarik Tunai" <<endl;
                    //     cout << "Pilih pecahan yang akan di ambil : ";
                    //     cin >> pecahan;
                    //     switch (pecahan)
                    //     {
                    //     case 50:

                    //         break;

                    //     default:
                    //         break;
                    //     }
                    //     break;

                case 0:
                    cout << "Exit";
                    ulang = 3;
                    break;

                default:
                    ulang = 3;
                    break;
                }
            }
        }
        else
        {
            cout << "PIN yang anda masukkan salah \n";
            ulang = ulang + 1;
            if (ulang == 3)
            {
                cout << "ATM Anda terblokir\n";
            }
        }
    }
    cout << "Program Selesai";
    return 0;
}