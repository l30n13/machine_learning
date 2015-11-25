#include <iostream>
#include <math.h>

using namespace std;

void find_entropy(string entropy[], int total, string columnName);

bool is_checked(int total, string searchString, string entropy[]);

void differentEntropy(string checkingEntropy[], string checkingEntropyName, string baseEntropy[],
                      string baseEntropyName, int total);

int count = 0, countEntropy = 0, count_checked[100], baseEntropy;
string checked[100], entropyName[100], decision_table[100][100], column_names[100];
double entropyValue[100];

int main() {
    int row, column;
    char endProgram = '\0';
    cout << "Enter your numbers of row and column for the table\nRow : ";
    cin >> row;
    cout << "Column : ";
    cin >> column;
    string entropyName;

    cout << "Give the names of your columns:\n";
    for (int i = 0; i < column; i++) {
        cin >> column_names[i];
    }
    cout << "Give the values of your table respectively by column names :\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> decision_table[j][i];
        }
    }
    do {
        cout << "Give your classes coulmn name : ";
        cin >> entropyName;
        count = 0;
        for (int i = 0; i < column; i++) {
            if (column_names[i] == entropyName) {
                find_entropy(decision_table[i], row, entropyName);
                baseEntropy = i;
                break;
            }
        }
        for (int i = 0; i < column; i++) {
            if (i != baseEntropy) {
                differentEntropy(decision_table[i], column_names[i], decision_table[baseEntropy],
                                 column_names[baseEntropy], row);
            }
        }

        /*cout << endl;
        for (int i = 0; i < count; i++) {
            cout << checked[i] << "\t\t" << count_checked[i] << "\n";
        }*/
        cout << "Do you want to find entropy from this same table again?(y/n) : ";
        cin >> endProgram;
    } while (endProgram != 'n');
    return 0;
}

bool is_checked(int total, string searchString, string entropy[]) {
    for (int i = 0; i < total; i++) {
        if (checked[i] == searchString) {
            return true;
        }
    }
    checked[count] = searchString;
    count_checked[count] = 0;
    for (int i = 0; i < total; i++) {
        if (entropy[i] == searchString) {
            count_checked[count] += 1;
        }
    }
    count++;
    return false;
}

void find_entropy(string entropy[], int total, string columnName) {
    for (int i = 0; i < total; i++) {
        is_checked(total, entropy[i], entropy);
    }

    double sumEntropy = 0;
    for (int i = 0; i < count; i++) {
        double b = 0;
        double div = 0;
        div = (double) count_checked[i] / (double) total;
        b = log(div) / log(2);
        sumEntropy -= div * b;
    }
    entropyName[countEntropy] = columnName;
    entropyValue[countEntropy++] = sumEntropy;
    cout << "Entropy for " << columnName << " is : " << sumEntropy << "\n";
}

void differentEntropy(string checkingEntropy[], string checkingEntropyName, string baseEntropy[],
                      string baseEntropyName, int total) {
    count = 0;
    int anotherCount = 0, c = 0;
    string newEntropy[total];
    for (int i = 0; i < total; i++) {
        is_checked(total, checkingEntropy[i], checkingEntropy);
    }
    c = count;
    for (int i = 0; i < c; i++) {
        anotherCount = 0;
        for (int j = 0; j < total; j++) {
            if (checked[i] == checkingEntropy[j]) {
                newEntropy[anotherCount++] = baseEntropy[j];
            }
        }
        for (int j = 0; j < anotherCount; j++) {
            is_checked(anotherCount, newEntropy[j], newEntropy);
        }

        double sumEntropy = 0;
        for (int j = c; j < anotherCount; j++) {
            double b = 0;
            double div = 0;
            div = (double) count_checked[j] / (double) anotherCount;
            b = log(div) / log(2);
            sumEntropy -= div * b;
        }
        entropyName[countEntropy] = checkingEntropyName;
        entropyValue[countEntropy++] = sumEntropy;
        cout << "Entropy for " << checkingEntropyName << " is : " << sumEntropy << "\n";

        /*count = 0;
        for (int k = 0; k < total; ++k) {
            checked[k] = '\0';
            count_checked[k] = 0;
        }*/
    }

    count = 0;
}
