#pragma DB_LINK_LIST_H
#include<bits/stdc++.h>
using namespace std;

template <class T>
struct node{
    T data;
    node* next;
    node* prev;
    friend istream& operator >> (istream& in, node& a){
        in>>a.data;
        return in;
    }
    friend ostream& operator << (ostream& out, node& a){
        out<<a.data;
        return out;
    }
};

template <class T>
class listt{
    private:
        node<T>* it_f;
        node<T>* it_l;
        int size;
    public:
        listt():it_f(NULL),it_l(NULL),size(0){

        }
        listt(listt& a):it_f(NULL),it_l(NULL),size(0){
            // chỗ này học được bai học là, cái này bắt buộc
            for (auto it = a.begin(); it != a.end(); it=it->next){
                push_back(it->data);
            }
        }
        listt& operator = (listt a){
            while(pop_back());
            for (node<T>* it = a.begin(); it != a.end(); it=it->next){
                push_back(it->data);
            }
            return *this;
        }
        bool empty(){
            if (it_f == NULL) return 1;
            return 0;
        }
        void push_back(T a){
            if (empty()){
                node<T>* x = new node<T>;
                x->data = a;
                it_l = x;
                it_f = x;
                x->next = NULL;
                x->prev = NULL;
                size=1;
                return;
            }
            node<T>* x = new node<T>;
            x->data = a;
            x->prev = it_l;
            x->next = NULL;
            it_l->next = x;
            it_l = x;
            size++;
        }
        bool pop_back(){
            if(empty()) return 0;
            auto it = it_l;
            if (it_l == it_f) {
                it_f = NULL;
                it_l = NULL;
                delete it;
                return 1;
            }
            else {
                it_l = it_l->prev;
                it_l->next=NULL;
            }
            size--;
            delete it;
            return 1;
        }
        bool pop_front(){
            if(empty()) return 0;
            auto it = it_f;
            if (it_l == it_f) {
                it_f = NULL;
                it_l = NULL;
            }
            else {
                it_f = it_f->next;
                it_l->prev=NULL;
            }
            size--;
            delete it;
            return 1;
        }
        T back(){
            return it_l->data;
        }
        void push_front(T a){
            if (empty()){
                node<T>* x = new node<T>;
                x->data = a;
                it_l = x;
                it_f = x;
                x->next = NULL;
                x->prev = NULL;
                return;
            }
            node<T>* x = new node<T>;
            it_f->prev = x;
            x->data = a;
            x->next = it_f;
            x->prev = NULL;
            it_f = x;
            size++;
        }
        node<T>* begin(){
            return it_f;
        }
        node<T>* end(){
            return NULL;
        }
        T& operator [] (int a){
            for (auto it= begin(); it!=end(); it = it->next){
                if (a) a--;
                else return it->data;
            }
            return it_l->data;
        }
        ~listt(){
            while (pop_back()){}
        }

};
