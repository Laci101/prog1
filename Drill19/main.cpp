 #include "../std_lib_facilities.h"

template <typename T>
struct S
{
private:
    T val;
public:
    S(T val){this->val=val;}
    T& get();
    T& get() const;
    void set(const T&);
    void operator= (const T&);
   

};

template <typename T>
T& S<T> :: get()
{
    return this->val;
}

template <typename T>
T& S<T> :: get() const
{
    return this->val;
}



template<typename T>
void S<T> :: set(const T& a)
{
    val = a;
}

template<typename T>
void S<T> :: operator= (const T& a)
{
    val = a;
}

template<typename T>
void read_val(T& v)
{
    cin>>v;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v)
{
    os << "{ ";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i] << (i < v.size() - 1 ? ", " : " ");
    }
    os << "}";

    return os;
}


int main()
{
    S<int> i(1);
    S<char> c('a');
    S<double> d(1.23);
    S<string> s("abcde");
    S<vector<int>> v(vector<int>{1,2,3});

    cout<<"Kiiras"<<endl;
    cout<<i.get()<<endl;
    cout<<c.get()<<endl;
    cout<<d.get()<<endl;
    cout<<s.get()<<endl;
    for(int i : v.get())
        cout<< i <<" ";
    cout<<endl;
    
    cout<<"Adj meg egy integert: ";
    int ii;
    read_val(ii);
    i.set(ii);
    cout<< i.get()<<endl;

    cout<<"Adj meg egy karaktert: ";
    char cc;
    read_val(cc);
    c.set(cc);
    cout << c.get()<<endl;

    cout<<"Adj meg egy doublet: ";
    double dd;
    read_val(dd);
    d.set(dd);
    cout << d.get() << endl;

    cout << "Adj meg egy stringet: ";
    string ss;
    read_val(ss);
    s.set(ss);
    cout << s.get() << endl;

    cout << "Adj meg 3 integert a vektorba: ";
   
    vector<int> v2;
    int temp;
    for (int i = 0; i < 3; ++i)
    {
    	read_val(temp);
    	v2.push_back(temp);
    };
    v.set(v2);
    cout << "Vektor" << v.get() << endl;
 	
    return 0;
}