class Solution {
public:
bool possible(vector<int>& bloomDay, int day, int m, int k){ 
    int n = bloomDay.size(); 
    int count =0; 
    int noOfB=0; 

    // count the nuber of bouquets
    for(int i=0;i<n;i++){ 
        if(bloomDay[i]<=day){ 
            count++;
        }
        else{ 
            noOfB += (count/k);
            count=0;
        }
    }
    noOfB += (count/k);
    return noOfB>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m*1ll*k*1ll;
        int n = bloomDay.size();
        if(val>n) return -1; // impossible case
        // find minimum and maximum 

        int mini = INT_MAX, maxi = INT_MIN;
        for(int i=0;i<n;i++){ 
            mini = min(mini, bloomDay[i]);
            maxi= max(maxi, bloomDay[i]);
        }
        // apply binary search tree
        int low = mini, high = maxi;
        while(low<=high){ 
            int mid = (low+high)/2; 
            if(possible(bloomDay,mid,m,k)){ 
                high = mid-1;
            }
            else 
            low = mid+1; 
        }
        return low;
    }
};