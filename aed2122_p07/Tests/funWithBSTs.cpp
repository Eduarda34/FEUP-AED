// AED 2021/2022 - Aula Pratica 07
// Pedro Ribeiro (DCC/FCUP) [06/12/2021]

#include <set>
#include <map>
#include "funWithBSTs.h"
#include "bst.h"

// ----------------------------------------------------------
// Exercicio 1: Colecao de Cromos
// ----------------------------------------------------------
int FunWithBSTs::newBag(const vector<int>& collection, const vector<int>& bag) {
    std::set<int> temp(collection.begin(), collection.end());
    std::set<int> temp1(bag.begin(), bag.end());
    int result = 0;

    for (auto x : temp1) {
        if(temp.find(x) == temp.end())
            result = result + 1;
    }
    return result;
}

// ----------------------------------------------------------
// Exercicio 2: Batalha de Pokemons
// ----------------------------------------------------------
int FunWithBSTs::battle(const vector<int>& alice, const vector<int>& bruno) {
  std::multiset<int> aliceSet(alice.begin(), alice.end());
  std::multiset<int> brunoSet(bruno.begin(), bruno.end());

  while (not(aliceSet.empty() || brunoSet.empty())){
      multiset<int>::iterator ali, bru;
      ali = -- aliceSet.end();
      bru = -- brunoSet.end();

      if(*ali > *bru){
          int x = *ali - *bru;
          brunoSet.erase(bru);
          aliceSet.erase(ali);
          aliceSet.insert(x);
      }

      else if(*ali < *bru){
          int x = *bru - *ali;
          brunoSet.erase(bru);
          aliceSet.erase(ali);
          brunoSet.insert(x);
      }

      else{
          brunoSet.erase(bru);
          aliceSet.erase(ali);
      }
  }
    return aliceSet.size() - brunoSet.size();
}

// ----------------------------------------------------------
// Exercicio 3: Reviews Cinematograficas
// ----------------------------------------------------------

// ..............................
// a) Contando Filmes
int FunWithBSTs::numberMovies(const vector<pair<string, int>>& reviews) {
  std::set<string> temp;

  for(auto x:reviews)
      temp.insert(x.first);

  return temp.size();
}

// ..............................
// b) O filme com mais reviews
void FunWithBSTs::moreReviews(const vector<pair<string, int>>& reviews, int& m, int& n) {
    map<string, int> temp;

    for(auto x:reviews){
        int y = not(temp.end() == temp.find(x.first) * temp.find(x.first)) -> second;
        temp.insert(pair<string, int>(x.first, y));
    }

    int a = 0, b = 0;
    auto it = temp.rbegin();
    auto range = temp.equal_range(it -> first);

    for(auto x:temp) {

    }
}

// ..............................
// c) Os melhores filmes
// TODO
vector<string> FunWithBSTs::topMovies(const vector<pair<string, int>>& reviews, double k) {
    vector<string> answer;
    return answer;
}
