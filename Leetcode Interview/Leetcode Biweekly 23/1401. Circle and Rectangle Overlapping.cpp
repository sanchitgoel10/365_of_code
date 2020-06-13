//Find the shortest distance from the center to the rect and compare it to the radius.
/*https://leetcode.com/problems/circle-and-rectangle-overlapping/discuss/563341/4-lines-C%2B%2B-O(1)%3A-Test-shortest-distance-from-center-to-rect-(with-pics)

link for pictures
*/
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int edgeX = (x_center < x1) ? x1 : (x_center > x2) ? x2 : x_center;       //ya to x1 close hai ya fir x2 hai ya fir x overlapp hi hai
        int edgeY = (y_center < y1) ? y1 : (y_center > y2) ? y2 : y_center;
        int distX = x_center - edgeX, distY = y_center - edgeY;                  //pythogoras lagaya hai bhai
        return distX * distX + distY * distY <= radius * radius;
    }
};