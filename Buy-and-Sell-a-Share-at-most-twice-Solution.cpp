#############################################################################  Question  ###############################################################################################################################

In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, the second transaction can only start after the first one is complete (buy->sell->buy->sell). The stock prices throughout the day are represented in the form of an array of prices. 

Given an array price of size n, find out the maximum profit that a share trader could have made.

Example 1:

Input:
n = 6
prices[] = {10,22,5,75,65,80}
Output:
87
Explanation:
Trader earns 87 as sum of 12, 75 Buy at 10, sell at 22, Buy at 5 and sell at 80.
Example 2:

Input:
n = 7
prices[] = {2,30,15,10,8,25,80}
Output:
100
Explanation:
Trader earns 100 as sum of 28 and 72 Buy at price 2, sell at 30, Buy at 8 and sell at 80,
Your Task:

Complete the function maxProfit() which takes an integer array price as the only argument and returns an integer, representing the maximum profit, if only two transactions are allowed.

Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraints:

1 <= n <= 105
1 <= price[i] <= 105



#############################################################################  Solution  ###############################################################################################################################

//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
      
        
        int maxProfit(vector<int>&price){
        
            
                        vector<vector<int>>ahead(3,vector<int>(2,0)),curr(3,vector<int>(2,0));
            int n = price.size();
            for(int i=n-1;i>=0;i--){
                for(int txn=1;txn>=0;txn--){
                    for(int canBuy=1;canBuy>=0;canBuy--){
                        int buy = 0;
                        if(canBuy){
                            buy = ahead[txn][0] - price[i]; // buy
                        }
                        else{
                            buy = ahead[txn+1][1] + price[i]; //Sell
                        }
                        int notBuy = ahead[txn][canBuy];  //ignore and go to next
                        curr[txn][canBuy] = max(buy,notBuy);
                    }
                }
                ahead = curr;
            }
            return ahead[0][1];
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends
