
struct info{
    char hoten[20];
    char sdt[10];
    
};

struct TimeDay{
    //5h - 20h
    int daCoc[17] = {};
};

enum DaysOfWeek
{
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY
};


struct TimeDay week[8];

class calendar{
    private:
        int thu;
        struct info thongtin;
        struct TimeDay ngay;
    
    public:

        // Them chuc nang thoi gian    
        void hienThiThongTin(){
            cout<< "Ho va ten:"<< thongtin.hoten<< endl;
            cout<<" SDT:"<< thongtin.sdt<<endl;
        //...
        }

        //Cap nhat ngay vao danh sach tuan
        void tao(){
            week[thu] = day;
        }

        //dat san
        void datSan(struct timeDay t, int x){
            t.daCoc[x] = 1;
        }

}
