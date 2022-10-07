#include <iostream>
using namespace std;


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
	friend ostream &operator <<(ostream &out, const struct TimeDay &v)

        //Cap nhat ngay vao danh sach tuan
        void tao(){
            week[thu] = ngay;
        }

        //dat san
        void datSan(struct timeDay* t, int x){
            t.daCoc[x] = 1;
        }


};   

ostream &operator <<(ostream &out, const struct timeDay &v){
    out<<"Ho va ten:"<< thongtin.hoten <<endl;
    out<<cout<<" SDT:"<< thongtin.sdt<<endl;
    return out;
}
