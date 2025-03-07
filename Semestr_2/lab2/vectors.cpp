#include<vector>
#include<iostream>
using namespace std;
namespace vectors{
    vector<int> reverse(vector<int>* old){
        vector<int>nowy;
        for(int i=old->size();i>-1;i--){
          nowy.push_back((*old)[i]);
        }
    }
    int maksimum(vector<int>* vec){
      int maks=-1;
      for(int i=0;i<vec->size();i++){
        maks=max((*vec)[i],maks);
      }
    }
}