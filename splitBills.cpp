#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pengguna {
    private:
        string nama;

    public:
        Pengguna(string nama) {
            this->nama = nama;
        }

        string getNama() {
            return nama;
        }
};

class Item {
    private:
        string nama;
        int jumlah;
        int harga;

    public:
        Item(string nama, int jumlah, int harga) {
            this->nama = nama;
            this->jumlah = jumlah;
            this->harga = harga;
        }

        string getNama() {
            return nama;
        }

        int getJumlah() {
            return jumlah;
        }

        int getHarga() {
            return harga;
        }
};

class Transaksi {
    private:
        vector<Item> daftarItem;
        vector<Pengguna> daftarPengguna;
        vector<vector<int>> pembelian;

    public:
        void tambahPengguna(Pengguna pengguna) {
            daftarPengguna.push_back(pengguna);
            vector<int> itemPembelian(daftarItem.size(), 0);
            pembelian.push_back(itemPembelian);
        }

        void tambahItem(Item item) {
            daftarItem.push_back(item);
            for (int i = 0; i < pembelian.size(); i++) {
                pembelian[i].push_back(0);
            }
        }

        void beliItem(int idPengguna, int idItem, int jumlah) {
            pembelian[idPengguna][idItem] += jumlah;
        }

        void tampilkanTagihan() {
            int total = 0;
            for (int i = 0; i < daftarPengguna.size(); i++) {
                int tagihan = 0;
                cout << "Tagihan " << daftarPengguna[i].getNama() << ":" << endl;
                for (int j = 0; j < daftarItem.size(); j++) {
                    int pembelian = this->pembelian[i][j];
                    if (pembelian > 0) {
                        int harga = daftarItem[j].getHarga();
                        int subtotal = pembelian * harga;
                        tagihan += subtotal;
                        cout << "- " << daftarItem[j].getNama() << " (" << pembelian << " x " << harga << ") = " << subtotal << endl;
                    }
                }
                total += tagihan;
                cout << "Total tagihan " << daftarPengguna[i].getNama() << ": " << tagihan << endl << endl;
            }
            cout << "Total tagihan keseluruhan: " << total << endl;
        }
};

int main() {
    Transaksi transaksi;

    Pengguna pengguna1("Andi");
    Pengguna pengguna2("Budi");

    transaksi.tambahPengguna(pengguna1);
    transaksi.tambahPengguna(pengguna2);

    Item item1("Kopi", 2, 5000);
    Item item2("Roti", 3, 3000);
    Item item3("Sosis", 1, 15000);

    transaksi.tambahItem(item1);
    transaksi.tambahItem(item2);
    transaksi.tambahItem(item3);

    transaksi.beliItem(0, 0, 1);
    transaksi.beliItem(0, 2, 1);
    transaksi.beliItem(1, 1, 2);
    transaksi.beliItem(1, 2, 1);
    transaksi.beliItem(1, 0, 2);

    transaksi.tampilkanTagihan();

return 0;

}