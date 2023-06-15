there will be two cases either we re allowed to buy or sell the stock
if(buy==1){ // we can buy on that day
// if we buy on that day we will add -nums[i] to the ans
max(-price[i]+rec(i+1,,0),rec(i+1,1))
curr day pr kharid liye to aglle din pe sell kr skte hai ya phir agle din pr buy krein
}
else { // or we can sell
return max(price[i]+rec(i+1,1),rec(i+1,0))
curr day pr sell kr diye to agle din buy krna padega ya phir agle din sell kro
}
​