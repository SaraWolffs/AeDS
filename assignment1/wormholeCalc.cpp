#include <cstdlib>
#include <vector>
#include <cassert>

using namespace std;

typedef vector< vector<unsigned int> > matrix;

template<T>
T &get_by_coords(vector<vector<T>> &m,vector<unsigned int> tuple){
	return m[tuple[0]][tuple[1]];
}

void deduce(matrix& deducted, matrix& input, vector<unsigned int> tuple, vector< vector<unsigned int> >& wormholes)
{
    assert(deducted.size() == input.size() && deducted[0].size() == input[0].size());
    
    if(deducted[tuple[0]][tuple[1]] != input[tuple[0]][tuple[1]]){
        deducted[tuple[0]][tuple[1]] = input[tuple[0]][tuple[1]];
        deducted[tuple[1]][tuple[0]] = input[tuple[0]][tuple[1]];
        for(int i = 0; i < deducted[tuple[0]].size(); i++){
            if(deducted[tuple[0]][i] > 0 && deducted[tuple[1]][i] == 0){
                deducted[tuple[1]][i] = deducted[tuple[0]][i] + deducted[tuple[0]][tuple[1]];
                deducted[i][tuple[1]] = deducted[tuple[1]][i];
            }
        }
        for(int i = 0; i < deducted[tuple[1]].size(); i++){
            if(deducted[tuple[1]][i] > 0 && deducted[tuple[0]][i] == 0){
                deducted[tuple[0]][i] = deducted[tuple[1]][i] + deducted[tuple[0]][tuple[1]];
                deducted[i][tuple[0]] = deducted[tuple[0]][i];
            }
        }
        vector<unsigned int> wormhole;
		wormhole.push_back(tuple[0]);
		wormhole.push_back(tuple[1]);
        wormhole.push_back(input[tuple[0]][tuple[1]]);
        wormholes.push_back(wormhole);
    }
}

vector< vector<unsigned int> > calcWormholes(matrix& input, vector< vector<unsigned int> >& tupleList)
{
    matrix deducted;
    for(int i = 0; i < input.size(); i++){
        vector<unsigned int> v;
        deducted.push_back(v);
        for(int j = 0; j < input[i].size(); j++){
            deducted[i].push_back(0);
        }
    }
    vector< vector<unsigned int> > wormholes;
    for(vector<unsigned int> tuple: tupleList){
        deduce(deducted, input, tuple, wormholes);
    }
    return wormholes;
}
