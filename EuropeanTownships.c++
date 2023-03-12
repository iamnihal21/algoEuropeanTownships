#include<bits/stdc++.h>
    using namespace std;
    void IO(){
        #ifndef ONLINE_JUDGE
            freopen("input.txt", "r+", stdin);
            freopen("output.txt", "w+", stdout);
        #endif
    }
    void inp(int &num, vector<vector<int>>& data){
        cin  >> num;
        for(int i=0;i<num;++i){
            vector<int> tempVar;
            char tempStr[20];
            cin >> tempStr;
            char * brData = strtok(tempStr, ",");
            while (brData) {
                brData = strtok(NULL, ",");
                tempVar.push_back(atoi(brData));
            }
            data.push_back(tempVar);
        }
    }
    int main()
    {
        int t=0;
        double r = 1.00, s = (1/3.0) * 4.0, h = 2.00;
        double Col = 1.50, Hour = 2.50, Rcol = 2.25, hour = 3.25;
        cin >> t;
        while(t--){
            int N;
            vector<vector<int>> data;
            inp(N, data);
            double total_hour =0, totalAcc = 0, totalReg = 0;
            for(int i=0;i<N;++i){
                int roof = data[i][0], stdRoom = data[i][1], hall = data[i][2];
                total_hour += ((roof * r * Hour ) + (stdRoom * s * Hour ) + (hall * h * Hour)) ;
                total_hour += ((roof * r * 2 * hour ) + (stdRoom * s * 2 * hour) + (hall * h * 2 * hour)); 
                totalAcc += ((roof * r * Col * 100.0)/100.0 + (stdRoom * s * Col * 100.0) / 100.0 + (hall * h * Col * 100.0) / 100.0);
                totalReg += ((roof * r * 2 * Col * 100.0) / 100.0 + (stdRoom * s * 2 * Col * 100.0) / 100.0 + (hall * h * 2 * Col* 100.0) / 100.0);
            }
            cout << fixed << setprecision(2) << total_hour <<" " << totalAcc << " " << totalReg << endl;
        }
    return 0;
    }