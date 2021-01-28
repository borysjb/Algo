#include <bits/stdc++.h>

using namespace std;

vector <int> table;

int minsize (int p,int q) {
  if(p>=q) {
    return p;
  }
  p*=2;
  minsize(p,q);
}

void initialize (int p) {
  while(p!=0) {
    for (size_t i = 0; i < p; i++) {
      table[i] = max(table[2*i],table[2*i+1]);
    }
    p/=2;
  }
  return;
}

void maximum (int p, int q, int wynik) {
  while(p<=q) {
    if(p%2==1) {

      wynik = max(wynik,table[p]);
      ++p;
    }

    if(q%2==0) {
      wynik = max(wynik,table[q]);
      --q;
    }

    p/=2; q/=2;
  }
  cout<<wynik<<endl;;
  return;
}

void update (int man) {
  while(man!=0) {
    man/=2;
    table[man]=max(table[2*man],table[2*man+1]);
  }
}

int main () {
  int Z;
  cin>>Z;
  while (Z--) {
    int ppl, questions;
    cin>>ppl>>questions;

    int size = minsize(1,ppl);
    table = vector <int> (size*2,-1000000001);
    for (int i = 0; i < ppl; i++) {
      cin >> table[size+i];
    }

    initialize (size);

    string token;
    int first,second;
    for (int i = 0; i < questions; i++) {
      cin>>token;
      cin>>first>>second;
      if (token=="MAX") {
        maximum(size+first-1, size+second-1, -1000000001);
      } else if (token=="UPDATE") {
        table[size+first-1]=second;
        update(size+first-1);
      } else {
        cout<<"you fucked up smth bruv"<<endl;
      }
    }
  }
  return 0;
}
