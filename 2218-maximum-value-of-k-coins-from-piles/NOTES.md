// consider piles[0]={1,100,3}
// if we are picking 1 coins then value is 1
// if we are picking 2 coins then value is 101
// if we are picking 3 coins then value is 104
// so we need to take prefix sum of each pile
​
// now secondly we can choose maxm of k coins since there is 0 based indexing
// so we if we are at index x then we are picking x+1 coins so x+1<=k
​
// recursive tree will be like we have k coins to choose and we have choosen x coins from piles[idx]
//       (k,idx)
//      /       \
// (k,idx+1)  piles[idx][x]+(k-1,idx+1)