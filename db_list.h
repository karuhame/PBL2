// double linked list

template <class T>
struct node{
    T data;
    node* next;
    node* prev;
    //--
};
template <class T>
class l_list{
    private:
        node<T>* it_f;
        node<T>* it_l;
        int size;
    public:
        l_list(){
            it_f =nullptr;
            it_l =nullptr;
            size=0;
        }
        bool empty(){
            if (it_f == nullptr) return 1;
            return 0;
        }
        void push_back(T a){
            if (empty()){
                node<T>* x = new node<T>;
                x->data = a;
                it_l = x;
                it_f = x;
                x->next = nullptr;
                x->prev = nullptr;
                size=1;
                return;
            }
            node<T>* x = new node<T>;
            x->data = a;
            x->prev = it_l;
            x->next = nullptr;
            it_l->next = x;
            it_l = x;
            size++;
        }
        bool pop_back(){
            if(empty()) return 0;
            auto it = it_l;
            if (it_l == it_f) {
                it_f = nullptr;
                it_l = nullptr;
            }
            else {
                it_l = it_l->prev;
                it_l->next=nullptr;
            }
            size--;
            delete it;
            return 1;
        }
        bool pop_front(){
            if(empty()) return 0;
            auto it = it_f;
            if (it_l == it_f) {
                it_f = nullptr;
                it_l = nullptr;
            }
            else {
                it_f = it_f->next;
                it_l->prev=nullptr;
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
                x->next = nullptr;
                x->prev = nullptr;
                return;
            }
            node<T>* x = new node<T>;
            it_f->prev = x;
            x->data = a;
            x->next = it_f;
            x->prev = nullptr;
            it_f = x;
            size++;
        }
        node<T>* begin(){
            return it_f;
        }
        node<T>* end(){
            return nullptr;
        }
        T operator [] (int a){
            for (auto it= begin(); it!=end(); it = it->next){
                if (a) a--;
                else return it->data;
            }
            return 0;
        }
        ~l_list(){
            while (pop_back()){}
        }

};