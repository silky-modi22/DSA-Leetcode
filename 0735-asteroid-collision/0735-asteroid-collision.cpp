class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; 
        for(int i=0;i<asteroids.size();i++){ 
            if(asteroids[i]> 0) 
            // Positive asteroid, just push to the stack
            st.push_back(asteroids[i]);
            else{
                 // Handle collisions for negative asteroid
                while(!st.empty() && st.back()>0 && st.back()<abs(asteroids[i]))
                st.pop_back();
            // if value in vector is equal to the current value with positive sign are poped from vector
            if(!st.empty() && st.back() == abs(asteroids[i]))
            st.pop_back(); 
            // if vector is empty and negative numbers are left only, then push to the vector
            else if(st.empty() || st.back() < 0)
            st.push_back(asteroids[i]);
        }
        }
        return st;
        
    }
};