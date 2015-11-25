#include <iostream>
#include <stdio.h>
#include <math.h>


using namespace std;


char med[4] = {'A', 'B', 'C', 'D'};
int x[4] = {3, 4, 5, 4}, y[4] = {7, 2, 3, 2};
float c[2][2] = {3, 7, 4, 2}, center_0_x = 0, center_0_y = 0, center_1_x = 0, center_1_y = 0;
int group1[2][4], group2[2][4];


void k_means_algorithm(double distance[2][4], int increment) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            distance[i][j] = sqrt(((x[j] - c[i][0]) * (x[j] - c[i][0])) + ((y[j] - c[i][1]) * (y[j] - c[i][1])));
        }
    }

    cout << "C1 : ";
    for (int i = 0; i < 2; i++) {
        cout << c[0][i] << " ";
    }
    cout << "\nC2 : ";
    for (int i = 0; i < 2; i++) {
        cout << c[1][i] << " ";
    }
    cout << endl;

    cout << "Distance : \n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%.2f ", distance[i][j]);
        }
        cout << endl;
    }

    if (increment % 2 != 0) {
        for (int i = 0; i < 4; i++) {
            if (distance[0][i] > distance[1][i]) {
                group1[0][i] = 0;
                group1[1][i] = 1;
            } else {
                group1[0][i] = 1;
                group1[1][i] = 0;
            }
        }
        cout << "Group : \n";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                printf("%d ", group1[i][j]);
            }
            cout << endl;
        }
    } else {
        for (int i = 0; i < 4; i++) {
            if (distance[0][i] > distance[1][i]) {
                group2[0][i] = 0;
                group2[1][i] = 1;
            } else {
                group2[0][i] = 1;
                group2[1][i] = 0;
            }
        }
        cout << "Group : \n";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                printf("%d ", group2[i][j]);
            }
            cout << endl;
        }
    }
}

int check_groups() {

    int count = 0;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < 4; i++) {
            if (group1[j][i] == group2[j][i]) {
                count++;
            } else {
                return 0;
            }
        }
    }
    if (count == 8) {
        return 1;
    }
    return 0;
}

void find_centroid(int group[], int zero, int one) {
    for (int i = 0; i < 4; i++) {
        if (group[i] == 0) {
            zero++;
            center_0_x += x[i];
            center_0_y += y[i];
        } else {
            one++;
            center_1_x += x[i];
            center_1_y += y[i];
        }
    }

    c[0][0] = center_0_x / zero;
    c[0][1] = center_0_y / zero;
    c[1][0] = center_1_x / one;
    c[1][1] = center_1_y / one;

}

int main() {
    double distance[2][4];
    int increment = 1;

    cout << "  x y\n";
    char group = 'A';
    for (int i = 0; i < 4; i++) {
        cout << group++ << " ";
        cin >> x[i] >> y[i];
    }
    c[0][0] = x[0];
    c[0][1] = y[0];
    c[1][0] = x[1];
    c[1][1] = y[1];

    while (increment) {
        int zero = 0, one = 0;
        center_0_x = 0, center_0_y = 0, center_1_x = 0, center_1_y = 0;

        if (increment != 1) {
            if (check_groups()) {
                char group = 'A';
                cout << "\n\nFinal groups :\n";
                for (int i = 0; i < 4; i++) {
                    cout << group++ << " = " << group1[1][i] << "\n";
                }
                break;
            }
        }

        if (increment % 2 != 0) {
            k_means_algorithm(distance, increment);
            find_centroid(group1[1], zero, one);
        } else {
            k_means_algorithm(distance, increment);
            find_centroid(group2[1], zero, one);
        }
        increment++;
    }
    return 0;
}
