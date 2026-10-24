class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        vector<int> tdates = {0,31,59,90,120,151,181,212,243,273,304,334};
        int aam=(arriveAlice[0]-'0')*10+(arriveAlice[1]-'0');
        int aad=(arriveAlice[3]-'0')*10+(arriveAlice[4]-'0');
        int aem=(leaveAlice[0]-'0')*10+(leaveAlice[1]-'0');
        int aed=(leaveAlice[3]-'0')*10+(leaveAlice[4]-'0');
        int bam=(arriveBob[0]-'0')*10+(arriveBob[1]-'0');
        int bad=(arriveBob[3]-'0')*10+(arriveBob[4]-'0');
        int bem=(leaveBob[0]-'0')*10+(leaveBob[1]-'0');
        int bed=(leaveBob[3]-'0')*10+(leaveBob[4]-'0');

        int aliceStart=tdates[aam-1]+aad;
        int aliceEnd=tdates[aem-1]+aed;
        int bobStart=tdates[bam-1]+bad;
        int bobEnd=tdates[bem-1]+bed;
        int res=min(aliceEnd,bobEnd)-max(aliceStart,bobStart)+1;
        cout << aliceStart << " " << aliceEnd << "\n";
        cout << bobStart << " " << bobEnd << "\n";
        return max(res,0);
        

        
    }
};