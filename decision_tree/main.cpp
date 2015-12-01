#include <iostream>
#include <math.h>

using namespace std;

void find_entropy(string entropy[], int total, string columnName);

bool is_checked(int total, string searchString, string entropy[]);

bool is_checked(int total, string searchString, string entropy[], string temp_checked[], int temp_count_checked[]);

void differentEntropy(string checkingEntropy[], string checkingEntropyName, string baseEntropy[],
                      string baseEntropyName, int to0tal);

int count = 0, countEntropy = 0, count_checked[100];
string checked[100], entropyName[100], decision_table[100][100], column_names[100];
double entropyValue[100];

int main() {
    int row, column, baseEntropy;
    char endProgram = '\0';
    cout << "Enter your numbers of row and column for the table\nRow : ";
    cin >> row;
    cout << "Column : ";
    cin >> column;
    string entropy_name;

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
        cin >> entropy_name;
        count = 0;
        for (int i = 0; i < column; i++) {
            if (column_names[i] == entropy_name) {
                find_entropy(decision_table[i], row, entropy_name);
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

        for (int i = 0; i < countEntropy; i++) {
            cout << "Entropy for " << entropyName[i] << " is : " << entropyValue[i] << "\n";
        }

        double temp = 0;
        string temp_name;
        for (int i = 1; i < countEntropy - 1; i++) {
            if (entropyValue[i] > entropyValue[i + 1]) {
                temp = entropyValue[i];
                temp_name = entropyName[i];
            }
        }
        cout << "\n\nRoot of decission tree is : " << temp_name << "\nAnd value is : " << temp << "\n\n";

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

bool is_checked(int total, string searchString, string entropy[], string temp_checked[], int temp_count_checked[]) {
    for (int i = 0; i < total; i++) {
        if (temp_checked[i] == searchString) {
            return true;
        }
    }
    temp_checked[count] = searchString;
    temp_count_checked[count] = 0;
    for (int i = 0; i < total; i++) {
        if (entropy[i] == searchString) {
            temp_count_checked[count] += 1;
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
    int anotherCount = 0, c = 0, temp_count_checked[total];
    string newEntropy[total], temp_checked[total];
    double anotherEntropyValue = 0;
    for (int i = 0; i < total; i++) {
        is_checked(total, checkingEntropy[i], checkingEntropy);
    }
    c = count;
    for (int i = 0; i < c; i++) {
        anotherCount = 0;
        count = 0;
        for (int k = 0; k < total; ++k) {
            temp_checked[k] = '\0';
            temp_count_checked[k] = 0;
        }

        for (int j = 0; j < total; j++) {
            if (checked[i] == checkingEntropy[j]) {
                newEntropy[anotherCount++] = baseEntropy[j];
            }
        }
        for (int j = 0; j < anotherCount; j++) {
            is_checked(anotherCount, newEntropy[j], newEntropy, temp_checked, temp_count_checked);
        }

        double sumEntropy = 0;
        for (int j = 0; j < count; j++) {
            double b = 0;
            double div = 0;
            div = (double) temp_count_checked[j] / (double) anotherCount;
            b = log(div) / log(2);
            sumEntropy -= div * b;
        }
        anotherEntropyValue += sumEntropy * ((double) anotherCount / (double) total);
        //cout << "Entropy for " << checkingEntropyName << " is : " << sumEntropy << "\n";
    }
    entropyName[countEntropy] = checkingEntropyName;
    entropyValue[countEntropy++] = entropyValue[0] - anotherEntropyValue;
    count = 0;
}