class NumberContainers {
public:
    unordered_map<int,int>indexToNumber; //it will store at which index what number is store
    unordered_map<int,set<int>>numberToindices; //it will store for a given number what are position where the index is storing number in sorted order
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
       if(indexToNumber.find(index)!=indexToNumber.end()){
        int previousNumber = indexToNumber[index];
        numberToindices[previousNumber].erase(index);
        if(numberToindices[previousNumber].empty()) numberToindices.erase(previousNumber);
       }
       indexToNumber[index]=number;
       numberToindices[number].insert(index);
        
    }
    
    int find(int number) {

       if(numberToindices.find(number)!=numberToindices.end()) return *numberToindices[number].begin();

       return -1;
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */