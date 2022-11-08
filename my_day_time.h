#pragma MY_DAY_TIME_H
#include<iostream>
#include<ctime>
using namespace std;
struct my_date_time{
    /*
        Read this:
            Cấu trúc được sử dụng riêng cho pbl2
            Các chức năng :
                + Nhập ngày giờ hiện tại (UTC+7) 
                + Trả về giá trị tọa độ bên trong lịch đặt sân
                + Từ giá trị tọa độ của lịch đặt sân và base, trả về thời gian thực
                + Base là tọa độ 0,0 mô tả 0 giờ ngày đầu tiên lịch được set
    */
    time_t real;
    int year, month, day,hour;
        /*
        tự đoán cái biến chỗ này :))
        có một lưu ý là khi thay đổi ngày giờ (biến year, month,day, hour) thì ngay sau đó
        phải gọi hàm reset_my
        */
    int utc=7;
    tm* inf;
    bool operator < (my_date_time a){
        return real<a.real;
    }
    my_date_time(){
        /*
        khởi tạo mặc định là thời gian hệ thống khi khởi tạo
        */
        real = time(0);
        reset_sys();
    }
    void reset_my(){
        /*
            sau khi cập nhật hour, day, month... thì gọi hàm này để lưu vào biến real
            mục đích là để còn thay đổi 
        */
        inf = localtime(&real);//mục đích là lấy utc của hệ thống
        inf->tm_hour=hour;
        inf->tm_mday=day;
        inf->tm_mon=month-1;
        inf->tm_year=year-1900;
        real = mktime(inf);// 
    }
    friend istream& operator >> (istream& in , my_date_time &a){
        in>>a.hour>>a.day>>a.month>>a.year;
        a.reset_my();
        return in;
    }
    friend ostream& operator << (ostream& out , my_date_time &a){
        out<<a.hour<<" "<<a.day<<" "<<a.month<<" "<<a.year;
        return out;
    }
    
    long long aday (){// lấy số ngày tính từ base sys
        return (real+utc*3600)/(3600*24);
    }
    void reset_sys(){
        /*
            sau khi cập nhật biến real (thời gian thực, định dạng của system) 
            thì cập nhật vào các giá trị hour,day,month...
        */
        inf = localtime(&real);
        hour =inf->tm_hour;
        day = inf->tm_mday;
        month=inf->tm_mon+1;
        year=inf->tm_year+1900;
    }
    friend my_date_time real_time(my_date_time base,pair<long long,long long> sys){
        // base là thời gian 0:00 ngày thứ 0
        base.real += (sys.first*24+sys.second)*3600;
        base.reset_sys();
        return base;
    }
    friend my_date_time real_time(my_date_time base,long long sys){
        base.real+= sys*3600;
        base.reset_sys();
        return base;
    }
};