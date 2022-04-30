class Solution {
public:
    int hIndex(vector<int>& arr) {
	if (arr.size() == 0) {
		return 0;
	}
	int s = 0, size = arr.size(), e = size - 1;
	while(s <= e) {
		int mid = (s + e) >> 1;
		if (arr[mid] == size - mid) {
			return arr[mid];
		} else if(arr[mid] > size - mid) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	return size - s;
    }
};