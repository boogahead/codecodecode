/*
dp question
if first two people shake hands with each other ( say, 1 and k )
then they will be creating a barrier separating the left group of people with the right who cannot shake hands across each other due to rules

lets say dp[i] = number of handshakes that can be made between 2 * i people
if two people ( 1 and k ) shakes hands, 2i - 2 people remain.
If there are 2j people on left side, it means 2i - 2j - 2 people remain on the right side.
and total of dp[j] ( for 2j people) * dp[i - j - 1] (for (2i - 2j - 2 people) 
we multiply use for loop to get the sum of all these numbers from j = 0 to i - 1 .
*/
class Solution {
    const static int m = 1'000'000'007;

public:
    int numberOfWays(int numPeople) {
        vector<int> dp(numPeople / 2 + 1);
        dp[0] = 1;
        for (int i = 1; i <= numPeople / 2; i++) {
            for (int j = 0; j < i; j++) {
                (dp[i] += (long long)dp[j] * dp[i - j - 1] % m) %= m;
            }
        }
        return dp[numPeople / 2];
    }
};
