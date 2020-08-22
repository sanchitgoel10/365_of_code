class Solution {
public:
    vector<vector<int>> rects;
    
    Solution(vector<vector<int>> rects) : rects(rects) {
    }
    
    vector<int> pick() {
        int sum_area = 0;
        vector<int> selected;
        
        /* Step 1 - select a random rectangle considering the area of it. */
        for (auto r : rects) {
            /*
             * What we need to be aware of here is that the input may contain
             * lines that are not rectangles. For example, [1, 2, 1, 5], [3, 2, 3, -2].
             * 
             * So, we work around it by adding +1 here. It does not affect
             * the final result of reservoir sampling.
             */
            int area = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            sum_area += area;
            
            if (rand() % sum_area < area)
                selected = r;
        }
        
        /* Step 2 - select a random (x, y) coordinate within the selected rectangle. */
        int x = rand() % (selected[2] - selected[0] + 1) + selected[0];
        int y = rand() % (selected[3] - selected[1] + 1) + selected[1];
        
        return { x, y };
    }
};