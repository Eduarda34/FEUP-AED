#include "funSortProblem.h"
#include <algorithm>

FunSortProblem::FunSortProblem() {}


//-----------------------------------------------------------------

//1. (a)
void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {
    if(products.size() > k){ //Caso o número de produtos seja superior ao limite
        for(int i=0; i < products.size(); i++){
            int minimo = i;
            for(int j=i+1; j < products.size(); j++){
                if(products[j] < products[minimo])  //Compara os preços
                    minimo = j;
                swap(products[i], products[minimo]); //Aceita dois parâmetros obrigatórios que devem ser trocados
            }
        }
        products.erase(products.begin() + k, products.end());
    }
}

//1. (b)
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    if (nc > values.size()) //Se o número de crianças for superior ao número de pacotes de chocolate
        return -1;

    else{
        vector<unsigned> v = values;
        for(int i=0; i < v.size(); i++){
            int min = i;
            for(int j= i+1; j < v.size(); j++){
                if(v[j] < v[min]){
                    min = j;
                }
            }
            swap(v[i], v[min]);
        }

        int minDiff = INT_MAX, currentDiff;
        for(int i=0; i < v.size(); i++){
            currentDiff = v[i + nc-1] - v[i];
            if(currentDiff < minDiff)
                minDiff = currentDiff;
        }
        return minDiff;
    }
}

//1. (c)
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    vector<float>chegada(arrival);
    vector<float>partida(departure);

    sort(chegada.begin(), chegada.end());
    sort(partida.begin(), partida.end());

    auto cheg = arrival.begin();
    auto part = departure.begin();
    int maxPlat = 0;
    int plat = 0;

    while (cheg < arrival.end()){
        if(*cheg < *part){
            plat++; //Quando chega um comboio, o número de plataformas ocupadas aumenta
            cheg++;
        }
        else{
            part++;  //Quando sai um comboio, o número de plataformas ocupadas diminui
            plat--;
        }

        if(plat > maxPlat)
            maxPlat = plat;
    }
    return maxPlat;
}


//1. (d) *exercício extra*
int partition(vector<Piece> arr, int low, int high){
    int pivot = arr[high].getDiameter();
    int i = (low-1);

    for(int j=low; j <= high-1; j++){
        if(arr[j].getDiameter() < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i+1);
}

void quickSort(vector<Piece> arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
    quickSort(nuts, 0, nuts.size()-1);
    quickSort(bolts, 0 ,nuts.size()-1);
}


