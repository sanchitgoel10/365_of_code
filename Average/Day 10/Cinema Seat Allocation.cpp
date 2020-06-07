class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats){
        int no=0;        //seats jaha family nhi baith sakti
        unordered_map<int,vector<int> > m;
        for(auto v:reservedSeats){
            m[v[0]].push_back(v[1]);
        }
        for(auto i:m){
            auto v=i.second;
            vector<int> row(11,1);    //simulated the row 
            for(auto j:v){
                row[j]=0;
            }
            int seat=0;
            if(row[2]&&row[3]&&row[4]&&row[5]){     //left 2 aur bich ki do hai kya
                seat++;
            }
            if(row[6]&&row[7]&&row[8]&&row[9]){    //right 2 and bich ki 2
                seat++; 
            }
            if(seat==0){                        //agar isse pehele ek koi family aa chuki hai to koi point nhi kyuki ek ya do hi ayengi ye hamara last resort hai bich me bithana
                if(row[4]&&row[5]&&row[6]&&row[7]){   //bich ke char hai kya
                    seat++;
                }
            }
            no+=(2-seat);  //max seat ek row me minus jaha family baith gayi
        }
        
        return 2*n-no;         //2*n max kitni family aa sakti hai
    }
};