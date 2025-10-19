class Bitset {
public:
   
   int length;
   vector<int>arr;
   int totFlip;
   int totOne=0;
    Bitset(int size) {
        length=size;
        arr.resize(length,0);
     totFlip=0;
        
    }
    
    void fix(int idx) {
        int currNumberofFlip=(arr[idx]+totFlip)%2;

        if(currNumberofFlip==0) {
            arr[idx]++;
            totOne++;
        }

        
    }
    
    void unfix(int idx) {
         int currNumberofFlip=(arr[idx]+totFlip)%2;
        //  cout<<arr[idx]<<" "<<totFlip<<endl;

        if(currNumberofFlip==1) {
            
            arr[idx]++;
            totOne--;
        }
        // cout<<"unfix"<<totOne<<endl;
        
    }
    
    void flip() {
        totFlip++;
        totOne=length-totOne;
        // cout<<"flip"<<totOne<<endl;
        
    }
    
    bool all() {
        // cout<<totOne<<endl;
        return totOne==length;
        
    }
    
    bool one() {

        return totOne>0;
        
    }
    
    int count() {
        return totOne;
        
    }
    
    string toString() {
        string s;
        for(auto it:arr){
            if((it+totFlip)%2) s.push_back('1');
            else s.push_back('0');
        }
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */