#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    // nurul silpia
    // n = nama
    // nis = nim
    // u = tanggal lahir
    // nr = current year
    // ns = umur
    // pia = jenis film
    // nrl = judul film
    // nurul = teater
    // np = jadwal penayangan
    // nur = jenis bangku
    // ul = harga jenis bangku
    // nl = pilihan bangku
    // nu = nomor bangku
    // rul = potongan harga
    // si = jumlah tiket
    // slp = harga tiket
    // sil = total bayar
    // silpi = kembalian
    // silpia = back to main program
    // ipi = diskon
    // ur = uang
    // ipiw = kembalian

    string silpia, n, np, nur, nrl, nurul, pia;
    int nis, u, nr, nu, nl[24], ns, ul, rul, si, slp, ipi, sil, silpi, ur, ipiw;

    time_t timestamp = time(NULL);
    struct tm datetime = *localtime(&timestamp);

START:
    cout << "DAFTAR PEMESANAN TIKET 12 \n ======================= \n";

    cout << "Nama Pemesan: ";
    getline(cin >> ws, n);

    cout << "Input tahun lahir: ";
    cin >> u;

    nr = datetime.tm_year + 1900;
    ns = nr - u;
    cout << "Usia: " << ns << "\n";

    cout << "\n 1. Anak-anak \n 2. Komedi Remaja \n 3. Dewasa \nPilih jenis film: (masukan angka) ";
    cin >> pia;

    cout << "\n 1. 10:00 \n 2. 13:20 \n 3. 18:20 \n 4. 21:20 \nPilih jam penayangan: (masukan angka) ";
    cin >> np;

    cout << "\n 1. VIP \n 2. Bisnis \n 3. Regular \nPilih jenis bangku: (masukan angka) ";
    cin >> nur;

    cout << "Jumlah tiket yang ingin dibeli: ";
    cin >> si;

    cout << "Masukan jumlah uang: Rp ";
    cin >> ur;

    for (int i = 0; i < si; i++)
    {
        cout << "Silahkan pilih nomor bangku ke-" << i + 1 << " (1-24): ";
        cin >> nl[i];

        if (nl[i] < 1 || nl[i] > 24)
        {
            cout << "--Nomor bangku tidak sesuai-- \n";
            i--;
        }
    }

    // kondisi bangku
    if (nur == "1")
    {
        nur = "VIP";
        ul = 20000;
    }
    else if (nur == "2")
    {
        nur = "Bisnis";
        ul = 10000;
    }
    else
    {
        nur = "Regular";
        ul = 0;
    }

    // kondisi jam tayang
    if (np == "1")
    {
        if (pia == "1")
        {
            slp = 25000;
            pia = "Anak-anak";
            np = "10:00";
            nrl = "Dora the Movie";
            nurul = "Teater 1";
        }
        else if (pia == "2")
        {
            slp = 35000;
            pia = "Komedi Remaja";
            np = "10:00";
            nrl = "SuperMan is Dad";
            nurul = "Teater 2";
        }
        else if (pia == "3")
        {
            slp = 40000;
            pia = "Dewasa";
            np = "10:00";
            nrl = "--Tidak Beroperasi--";
            nurul = "--Kosong--";
        }
    }
    else if (np == "2")
    {
        if (pia == "1")
        {
            pia = "Anak-anak";
            np = "13:20";
            nrl = "Naruto The Movie";
            nurul = "Teater 1";
        }
        else if (pia == "2")
        {
            slp = 35000;
            pia = "Komedi Remaja";
            np = "13:20";
            nrl = "Pocong Pink";
            nurul = "Teater 3";
        }
        else if (pia == "3")
        {
            slp = 40000;
            pia = "Dewasa";
            np = "13:20";
            nrl = "satu atap dua cinta";
            nurul = "Teater 3";
        }
    }
    else if (np == "3")
    {
        if (pia == "1")
        {
            pia = "Anak-anak";
            np = "18:20";
            nrl = "Doraemon The Movie";
            nurul = "Teater 1";
        }
        else if (pia == "2")
        {
            slp = 35000;
            pia = "Komedi Remaja";
            np = "18:20";
            nrl = "Tahu Bunting Cinta";
            nurul = "Teater 1";
        }
        else if (pia == "3")
        {
            slp = 40000;
            pia = "Dewasa";
            np = "18:20";
            nrl = "the rainBow";
            nurul = "Teater 2";
        }
    }
    else if (np == "4")
    {
        if (pia == "1")
        {
            pia = "Anak-anak";
            np = "21:20";
            nrl = "--Tidak Beroperasi--";
            nurul = "--Kosong--";
        }
        else if (pia == "2")
        {
            slp = 35000;
            pia = "Komedi Remaja";
            np = "21:20";
            nrl = "Horor Merah Jambu";
            nurul = "Teater 3";
        }
        else if (pia == "3")
        {
            slp = 40000;
            pia = "Dewasa";
            np = "21:20";
            nrl = "IronMan";
            nurul = "Teater 1";
        }
    }

    if (si >=3)
    {
        ipi = 5000;
    }

    // cout << "DISKONNNN = " << ipi << "\n";

    sil = (slp + ul) * si - ipi;

    if (ur > sil)
    {
        ipiw = ur - sil;
    }else
    {
        ipiw = 0;
    }
    

    cout << "\n============================== \n";
    cout << "Nama Pemesan   : " << n << "\n";
    cout << "Tahun Lahir    : " << u << "\n";
    cout << "Usia           : " << ns << "\n";
    cout << "Jenis Film     : " << pia << "\n";
    cout << "Jam Tayang     : " << np << "\n";
    cout << "Judul Film     : " << nrl << "\n";
    cout << "Teater         : " << nurul << "\n";
    cout << "Jenis bangku   : " << nur << "\n";
    cout << "Jumlah tiket   : " << si << "\n";
    cout << "Nomor bangku   : ";
    for (int i = 0; i < si; i++)
    {
        cout << nl[i] << (i < si - 1 ? ", " : "");
    }
    cout << "\nTotal bayar    : " << sil << "\n";
    cout << "Uang masuk     : " << ul << "\n";
    cout << "Uang kembalian : " << ipiw << "\n";
    cout << "\n============================== \n";

    // cout << "Pilih jenis bangku: (masukan angka)";
    // cin >> nur;

    // cout << "\nKembali ke program awal? (y/n) ";
    // cin >> silpia;

    // if (silpia == "y")
    // {
    //     goto START;
    // }
    // else if (silpia == "n")
    // {
    //     cout << "terimakasih ";
    // }

    return 0;
}