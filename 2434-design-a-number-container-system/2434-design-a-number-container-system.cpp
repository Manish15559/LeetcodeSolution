class NumberContainers {
public:
    map<int,int>idxer; 
    map<int,priority_queue<int,vector<int>,greater<int>>>num;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        num[number].push(index);
        idxer[index]=number;
        
    }
    
    int find(int number) {

        while(!num[number].empty()){
            int idx=num[number].top();
            if(idxer[idx]!=number) num[number].pop();
            else return idx;
        }

        return -1;
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */