# include <iostream>
# include <stack>
using namespace std;

template <class T>
class StackExt {
	stack<T> values;
	stack<T> minimums;
public:
	StackExt() {};
	bool empty() const; 
	T& top();
	void pop();
	void push(const T& val);
	T& findMin();
};

//2. Verifica se a pilha está vazia
template <class T> 
bool StackExt<T>::empty() const {
	return values.empty();
}

//2. Retorna o elemento no topo da fila
template <class T> 
T& StackExt<T>::top() {
    return values.top();
}

//2. Remove elemento
template <class T> 
void StackExt<T>::pop() {
    values.pop();
}

//2. Insere elemento
template <class T> 
void StackExt<T>::push(const T& val) {
    values.push(val);
}

//2. Retorna valor do menor elemento
template <class T> 
T& StackExt<T>::findMin() {
    minimums.push(values.top());
    values.pop();

    while(!values.empty()){
        if(values.top() < minimums.top())
            minimums.push(values.top());
    }
    return minimums.top();
}

