class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int Moves=0;
        while(target >1 && maxDoubles>0){
            if(target %2==0){
                target =target/2;
                maxDoubles--;
            }
            else{
                target =target-1;
            }
                Moves++;
        }
            Moves +=(target -1);
            return Moves;            
        

    }
};