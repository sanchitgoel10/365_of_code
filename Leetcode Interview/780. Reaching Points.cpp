/*
If sx,sy occurs in the path of Euclidean method to get GCD (by subtracting lesser value from greater value) of tx,ty, then return true.

To see why this is true, consider how the tx, ty could have been formed if tx > ty. Let ax, ay be the pair in previous step. It cannot be ax, ax+ay because both ax and ay are greater than 0. So the only other possibility is ax+ay, ay. This means ay = ty and ax = tx-ty. Now we can optimize this subtraction a bit by doing ax = tx % ty since we will keep subtracting ty from tx until tx > ty.

One special case we need to handle during this optimization is when tx=9,ty=3,sx=6, sy=3 which can be covered using the condition if(sy == ty) return (tx - sx) % ty == 0;
Similar argument applies for tx <= ty.
*/
 bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx >= sx && ty >= sy){
            if(tx > ty){
                if(sy == ty) return (tx - sx) % ty == 0;
                tx %= ty;
            }else{
                if(sx == tx) return (ty - sy) % tx == 0;
                ty %= tx;
            }
        }   
        
        return false;
    }