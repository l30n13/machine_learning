#include <iostream>

using namespace std;

int main() {
    int x[4][3], y[4] = {-1, 1, 1, 1}, w_old[3] = {0, 0, 0}, step = 0;

    cout << "x1 x2 b\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> x[i][j];
        }
    }

    while (step != 4) {
        int xy[3];
        for (int i = 0; i < 3; i++) {
            xy[i] = (x[step][i] * y[step]);
        }
        for (int i = 0; i < 3; i++) {
            w_old[i] = w_old[i] + xy[i];
        }
        cout << "Step : " << step + 1 << "\tw_new = ";
        for (int i = 0; i < 3; i++) {
            cout << w_old[i] << " ";
        }
        cout << endl;
        step++;
    }
    cout << "w1 : " << w_old[0] << "\n";
    cout << "w2 : " << w_old[1] << "\n";
    cout << "b  : " << w_old[2] << "\n";

    return 0;
}