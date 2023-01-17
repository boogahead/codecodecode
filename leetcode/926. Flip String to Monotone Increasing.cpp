/*????????
* onecount : 1의 갯수를 세는것. 1 flip 하는것은 아무 변화가 없음
* 만약 S[i] 가 0이면 세가지 케이스
*       1. 이전까지의 모든 1들을 0으로 바꿔버린다. 이걸 하려면 1의 갯수(onecount) 를 알아야 한다    
*       2. 지금있는 0을 1로 바꾸고 oneflip의 값을 increment 한다.
*       3. 지금까지의 1을 전부 다 0으로 바꿔버리는 onecount 랑 지금까지 0을 1로 바꿔본 oneflip의 값 중 최소값을 oneflip에 저장한다. (최소를 원하니까)
*/
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int size=s.size();
        int onecount=0;
        int oneflip=0;
        for(int i=0;i<size;i++)
        {
            if(s[i]=='1')onecount++;
            else{
                oneflip++;
                oneflip=min(oneflip,onecount);
            }
        }
        return oneflip;
    }
};
