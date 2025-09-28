class StockPrice {
public:

multiset<int>st; //track all the prices from low value to high value;
map<int,int>mp; //track the price at particular timestamp
int latest_timestamp=-1;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {  //2*o(log(numberofuniquetimestamp))
        if(mp.find(timestamp)==mp.end()){
            mp[timestamp]=price;
            st.insert(price);
            latest_timestamp=max(timestamp,latest_timestamp);

        }
        else{
            st.erase(st.find(mp[timestamp]));
            st.insert(price);
            mp[timestamp]=price;

        }
        
        
    }
    
    int current() {

    return mp.rbegin()->second;
        
    }
    
    int maximum() {

        return *st.rbegin();
        
    }
    
    int minimum() {

        return *st.begin();
        
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */