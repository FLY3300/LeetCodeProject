class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int totalCandies = 0; 
        
        //initializing all the distribute candy to 1 
        vector<int> left (n,1);
        vector<int> right (n,1);

        //Left relative vector 
        for (int i=1; i<n; i++)
        {   
            //if the current index is larger then the previous index 
            //give one extra candy 
            if (ratings[i] > ratings[i-1])
            {
                left[i] = left[i-1] +1;
            }
        }

        //Right relative vector (start from the back)
        for (int i= n-2; i>=0; i--)
        {   //if the current index is larger then the right index 
            //give one extra candy 
            if (ratings[i] > ratings[i+1])
            {
                right[i] = right[i+1] +1;
            }
        }

        //Merge two vector 
        for (int i=0; i<n; i++)
        {
            totalCandies += max(left[i],right[i]);
        }
        
        return totalCandies;
    }

};
