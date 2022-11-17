class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a1=(ax2-ax1)*(ay2-ay1);
        int a2=(bx2-bx1)*(by2-by1);
        int common_area=0;
        int left=max(ax1,bx1);
        int right=min(ax2,bx2);
        int top=min(ay2,by2);
        int bottom=max(ay1,by1);
        if(left < right && top > bottom)
        common_area=(right-left)*(top-bottom);
        return a1+a2-common_area;
    }
};