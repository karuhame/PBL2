#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()

#define cntBit __builtin_popcount
#define fi first
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

const int NN = 18;

class Gia_theo_gio{
private:
    int number = NN; // số lượng khung giờ
    int price[NN]; // giá theo khung giờ //
    int real_time[NN] = {5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};

public:
    Gia_theo_gio(const int a[]) {    // hàm khởi tạo
        for (int i = 0; i < NN; i++) {
            price[i] = a[i];
        }
    }


    Gia_theo_gio() {  // hàm khởi tạo
        for (int i = 0; i < NN; i++) {
            price[i] = 0;
        }
    }

    void showAll() {
        for (int i = 0; i < number; i++) {
            cout << "Khung gio " << i << ": " << real_time[i] << "h  "  << "  Gia thue san:   "
            << price[i] <<  endl;
        }
        cout <<endl << endl;
    }


    void showtime() {
        for (int i = 0; i < NN; i++) {
            cout << "Khung gio " << i << ": " << real_time[i] << "h" << endl;
        }
        cout <<endl << endl;
    }

    void update() {
        cout << "Xem lai tat ca khung gio   ->  Press 3" << endl;
        cout << "Update toan bo khung gio   ->  Press 2" << endl;
        cout << "Update 1 khung gio   ->  Press 1" << endl;
        cout << "Huy thao tac   ->  Press 0" << endl;

        int choose;
        cin >> choose;

        while (choose != 0) {
            if (choose == 3) {
                showAll();
            }

            if (choose == 1) {
                cout << "Chon khung gio: " << endl;
                int time_choose;
                cin >> time_choose;

                if (time_choose >= number) {
                    cout << "Warning:  INVALID time" << endl;
                    continue;
                }

                cout << "Thay doi gia tien: " << endl;
                int price_change;
                cin >> price_change;

                price[time_choose] = price[time_choose] + price_change;
            }

            if (choose == 2) {
                cout << "Thay doi gia tien: " << endl;
                int price_change;
                cin >> price_change;

                for (int i = 0; i < number; i++) {
                    price[i] = price[i] + price_change;
                }
            }

            // thao tac tiep theo
            cout << endl << endl;
            cout << "Xem lai tat ca khung gio   ->  Press 3" << endl;
            cout << "Update toan bo khung gio   ->  Press 2" << endl;
            cout << "Update 1 khung gio   ->  Press 1" << endl;
            cout << "Huy thao tac   ->  Press 0" << endl;

            cin >> choose;
            if(choose == 0) {
                ofstream outFile("output.txt");
                for (int i = 0; i < number; i++) {
                    outFile << price[i] << ' ';
                }
                outFile.close();
            }
            
        }
    }

    friend istream &operator >> (istream & inp, Gia_theo_gio &a) {
        for (int i = 0; i < a.number; i++) {
            cout << "Khung gio " << i << ": " << a.real_time[i] << "h  "  << "  Gia thue san la:   " << endl;
            inp >> a.price[i];
        }
        return inp;
    }


    friend ostream &operator << (ostream & out, Gia_theo_gio &a) {
        for (int i = 0; i < a.number; i++) {
            out << "Khung gio " << i << ": " << a.real_time[i] << "h  "  << "  Gia thue san:   "
            << a.price[i] <<  endl;
        }
        return out;
    }
};

int temp[NN];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ifstream inFile;
    inFile.open("output.txt");
    for (int i = 0; i < NN; i++) {
        inFile >> temp[i];
    }
    inFile.close();

    Gia_theo_gio ff(temp);
    ff.showAll();
    // ff.showtime();
    cout << endl << endl;
    ff.update();

    cout <<ff << endl;

    return 0;
}
