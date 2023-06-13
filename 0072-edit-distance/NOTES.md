If word1[i-1] == word2[j-1], then dp[i][j] = dp[i-1][j-1]. That is, no operation is required because the characters at positions i-1 and j-1 are already the same.
Otherwise, dp[i][j] is the minimum of the following three values:
dp[i-1][j-1] + 1: replace the character at position i-1 in word1 with the character at position j-1 inword2.
dp[i-1][j] + 1: delete the character at position i-1 in word1.
dp[i][j-1] + 1: insert the character at position j-1 in word2 into word1 at position i
​
dp[i][0] = i: transforming word1[0...i-1] into an empty string requires i deletions.
dp[0][j] = j: transforming an empty string into word2[0...j-1]requires j insertions.
​
f(i,j) n-1,m-1 finding the minimum number of operation to convert s1 from 0 to n-1 to s2 0 to m-1
​
horse    ros
e and s are not matching if we insert s after e then i will remain at e itself and j will be reduced
​
e and s are not matching if we delete  e then j will remain at s itself and i will be reduced
​
e and s are not matching if we insert s after e then i will remain at e itself and j will be reduced
e and s are not matching if we replace e with s then i and j both will reduce  since character is matched