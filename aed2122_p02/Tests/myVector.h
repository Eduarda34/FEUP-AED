#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

template <class T>
class MyVector {
    vector<T> values;
public:
    MyVector();
    ~MyVector();
    void push_back(T v1);
    vector<T> getValues() const;
    T max() const;
    bool hasDuplicates() const;
    void removeDuplicates() ;
};


// exception EmptyVector
class EmptyVector
{ };

// methods
template <class T>
MyVector<T>::MyVector() {}

template <class T>
MyVector<T>::~MyVector() {}

template <class T>
void MyVector<T>::push_back(T v1) {
    values.push_back(v1);
}

template <class T>
vector<T> MyVector<T>::getValues() const {
    return values;
}

//---------------------------------

//1. (a)
template <class T>  //Temporal: O(n)   Espacial: S(1)
T MyVector<T>::max() const {
    if(values.empty() == false){
        T vmax;
        for (int i=1; values.empty() > i; i++) {
            if (values[i] > vmax)
                vmax = values[i];
        }
        return vmax; //Retorna valor máximo do vetor
    }
    else{
        EmptyVector e = EmptyVector();
        throw (e);  //Lança uma exceção quando um problema é detetado, permitindo criar um erro personalizado
    }
}

//1. (b)
template<class T>  //Temporal: O(n)   Espacial: S(n)
bool MyVector<T>::hasDuplicates() const {
    for(int i=0; values.size() > i; i++){
        for(int j=i+1; values.size() > j; j++){
            if(values[i] == values[j]) //Verificar se existem valores repetidos
                return true;
        }
    }
	return false;
}

//1. (c)
template<class T>  //Temporal: O(n)   Espacial: O(n)
void MyVector<T>::removeDuplicates() {
    unordered_set<T> elements;
    for(auto iter = values.begin(): iter != values.end(); iter++){ //Auto torna-se inteiro mesmo que uma referência inteira lhe seja atribuída
        if(elements.find(*iter) != elements.end()){
            values.erase(iter);
            iter--;
        }
        else{
            elements.insert(*iter);
        }
    }
}

