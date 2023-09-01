
class Solution {
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n) {
        // Your code here
        stack<long long> s;
        long long max_area = 0, cur_area = 0;
        

        for(int i = 0; i <= n; i++) {
            // i == n will count for elements with no nse: so take nse = n
            while(!s.empty() && (i == n || arr[i] <= arr[s.top()])) {
                // i is the nse
                // pse is the element below top of stack
                // arr[tp] is the height
                // width = nse - pse - 1
                long long tp = s.top();
                s.pop();
                cur_area = arr[tp] * (s.empty() ? i : i - s.top() - 1);
                if(cur_area > max_area)
                    max_area = cur_area;
            }
            // insert current index in the stack
            s.push(i);
        }
        return max_area;
    }
};
