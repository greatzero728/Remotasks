#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> board(N, vector<int>(N));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    vector<int> called_numbers(N * N);
    
    for (int i = 0; i < N * N; i++) {
        cin >> called_numbers[i];
    }
    
    vector<vector<int>> rows(N);
    vector<vector<int>> cols(N);
    
    int answer = -1;
    bool flag = false;
    
    for (int num : called_numbers) {
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (board[row][col] == num) {
                    rows[row].push_back(num);
                    cols[col].push_back(num);
                    
                    if (rows[row].size() == N || cols[col].size() == N) {
                        answer = num;
                        flag = true;
                        break;
                    }
                }
            }
            
            if (flag) {
                break;
            }
        }
        
        if (flag) {
            break;
        }
    }
    
    if (answer != -1) {
        cout << answer << endl;
    } else {
        cout << "Santa lost" << endl;
    }
    
    return 0;
}
