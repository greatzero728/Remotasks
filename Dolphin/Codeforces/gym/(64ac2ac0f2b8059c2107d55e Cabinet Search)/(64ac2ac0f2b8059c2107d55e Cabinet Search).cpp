#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

void reflectItems(vector<Point>& items) {
    for (auto& item : items) {
        item.x = -item.x;
        item.y = -item.y;
    }
}

void rotateItems(vector<Point>& items) {
    for (auto& item : items) {
        swap(item.x, item.y);
        item.y = -item.y;
    }
}

int main() {
    int N;
    cin >> N;

    vector<Point> items(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i].x >> items[i].y;
    }

    int Q;
    cin >> Q;

    stack<pair<Point, set<int>>> previousStates;
    set<int> collectedItems;

    Point protagonist = {0, 0};

    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int step;
            char axis;
            cin >> axis >> step;

            if (axis == 'X')
                protagonist.x += step;
            else
                protagonist.y += step;

            for (const auto& item : items) {
                if (axis == 'X' && item.y == protagonist.y && item.x <= protagonist.x)
                    collectedItems.insert(item.x);
                else if (axis == 'Y' && item.x == protagonist.x && item.y <= protagonist.y)
                    collectedItems.insert(item.y);
            }
        } else if (type == 2) {
            reflectItems(items);
        } else if (type == 3) {
            rotateItems(items);
        } else if (type == 4) {
            if (!previousStates.empty()) {
                auto prevState = previousStates.top();
                previousStates.pop();
                protagonist = prevState.first;
                collectedItems = prevState.second;
            }
        }

        previousStates.push({protagonist, collectedItems});
    }

    cout << collectedItems.size() << endl;

    return 0;
}
