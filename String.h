template <class T>

class stringg{
    private:
        int len = 0;
        char *ar = new char[30];
    public:
        friend istream &operator >>(istream &inp, stringg &a){
            int vi_tri = 0;
            do() {
                inp >> ar[vt];
                vi_tri++;
            } 
            while(ar[vi_tri] != " ")
            return inp;
        }
  
        friend ostream &operator <<(ostream &out, stringg &a){
            for (int i = 0; i < len; i++) {
                out << a.ar[i];
            }
            return out;
        }

        bool empty() {
            if (len == 0) {
                return 1;
            }
            return 0;
        }

        int size() {
            return this->len;
        }

        bool compare(stringg &s) {
            if (len != s.len) return 0;
            for (int i = 0; i < s.len; i++) {
                if (s.a != this->a) return 0; 
            }
            return 1;
        }

};  
