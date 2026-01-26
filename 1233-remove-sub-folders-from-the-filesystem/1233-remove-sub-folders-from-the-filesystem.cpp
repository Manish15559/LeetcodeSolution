class Solution {
public:
    bool isPrefix(string &a,string &b){  //whether string  a is prefix of b
      int n=a.size();
      int m=b.size();
      int idx1=1;
      int idx2=1;
      bool f=true;
      while(idx1<n&&idx2<m){
        string str1;
        string str2;
        while(idx1<n&&a[idx1]!='/'){
            str1.push_back(a[idx1]);
            idx1++;
        }
        while(idx2<m&&b[idx2]!='/'){
            str2.push_back(b[idx2]);
            idx2++;
        }
        if(str1==str2){
            idx1++;
            idx2++;
        }
        else{
            f=false;
            break;
        }
      }

      if(!f) return false;

      return idx1>=n;
      

    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        int n=folder.size();
         vector<string>ans;
         for(auto it:folder){
            if(ans.empty()){
                ans.push_back(it);
            }
            else if(it.find(ans.back())==0&&it[ans.back().size()]=='/'){
                continue;
            }
            else{
                ans.push_back(it);

            }
         }

         return ans;
        

        
        
    }
};