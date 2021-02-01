#include <bits/stdc++.h>

using namespace std;

vector<int> table;

int minsize (int p,int q) {
  if(p>=q) {
    return p;
  }
  p*=2;
  minsize(p,q);
}

void update (int p, int q, int val, int start, int end, int number) {
  if(p>end || q<start) {
    return;
  } else if (q<=end && p>=start) {
    table[number]+=val;
  } else if (q<=end || p>=start) {
    update((p+q)/2+1,q,val,start,end,number*2+1);
    update(p,(p+q)/2,val,start,end,number*2);
  }
}

void check (int p) {
  int wynik;
  while(p!=0){
    wynik+=table[p];
    p/=2;
  }
  cout<<wynik<<endl;
}

int main () {
  int Z;
  cin>>Z;
  while(Z--) {
    int ppl,questions;
    cin>>ppl>>questions;
    int size = minsize(1,ppl);
    table = vector<int>(size*2,0);

    for (size_t i = 0; i < questions; i++) {
      char token;
      cin>>token;
      if(token=='E') {
        int start,end,val;
        cin>>start>>end>>val;
        update(1,ppl,val,start,end,1);
      } else if (token=='P') {
        int man;
        cin>>man;
        check(man+size-1);
      } else {
        cout<<"bro you fucked up \n";
      }
    }
  }
}
