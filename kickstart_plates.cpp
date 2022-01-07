#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
int main() {
    int a = 0;
    cin >> a;

    int stack, numberOfPlates, requiredPlates;
    for (int i = 0; i < a; i++)
    {
        cin >> stack >> numberOfPlates >> requiredPlates;
        vector<vector<int>> stacks;
        for (int j = 0; j < stack; j++)
        {
            vector<int> sts;
            for (int p = 0 ; p < numberOfPlates; p++) {
                int data = 0;
                cin >> data;
                sts.push_back(data);
            }
            
            stacks.push_back(sts);
        }


        vector<vector<pair<int,int>>> stackWithWeights; 

        //convert stack into pair form 
        for (int i = 0; i < stacks.size(); i++)
        {
            int sum =0; 
            vector<pair<int,int>> newStack;
            for (int j = stacks[i].size() - 1; j >= 0 ; j--)
            {

                newStack.push_back(make_pair(stacks[i][j],sum));
                sum += stacks[i][j];
            }
            // reverse(newStack.begin(), newStack.end());
            stackWithWeights.push_back(newStack);
        }

        std::cout << stackWithWeights[0][1].second << endl;
        int sum = 0;
        while(requiredPlates != 0) {
            int biggestToPop = 0;
            for (int i =0 ; i< stackWithWeights.size(); i++)
            {
                if(stackWithWeights[i].size() == 0) {
                    continue;
                }
                if(requiredPlates > 1) {
                    if(stackWithWeights[i][stackWithWeights[i].size() - 1].second > stackWithWeights[biggestToPop][stackWithWeights[biggestToPop].size() - 1].second) {
                        biggestToPop = i;
                    }
                }else if(requiredPlates == 1) {
                    if(stackWithWeights[i][stackWithWeights[i].size() - 1].first > stackWithWeights[biggestToPop][stackWithWeights[biggestToPop].size()-1].first) {
                        biggestToPop = i;
                    }
                }
            }
            sum+=stackWithWeights[biggestToPop][stackWithWeights[biggestToPop].size()-1].first;

            stackWithWeights[biggestToPop].pop_back();
            if(stackWithWeights[biggestToPop].size() == 0) {
                stackWithWeights[biggestToPop].push_back(make_pair(0,0));
            }
            requiredPlates -= 1;
        }

    }

    


    
}
