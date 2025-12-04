#include <iostream>
#include <iomanip>

using namespace std;

void inputData(float** p, int d, int h);
float dayAverage(float* row, int h);
float overallAverage(float** p, int d, int h);
void showHotDays(float** p, int d, int h);

int main() {
    int d, h;
    cout << "Введите количество дней: ";
    cin >> d;
    cout << "Введите количество измерений в дне: ";
    cin >> h;
    
    if (d <= 0 || h <= 0 || d > 30 || h > 24) {
        cout << "Ошибка!" << endl;
        return 1;
    }
    
    float** data = new float*[d];
    for (int i = 0; i < d; i++) {
        *(data + i) = new float[h];
    }
    
    inputData(data, d, h);
    
    float avg = overallAverage(data, d, h);
    
    cout << fixed << setprecision(1);
    cout << "\nОбщая средняя температура: " << avg << endl;
    
    showHotDays(data, d, h);
    
    for (int i = 0; i < d; i++) {
        delete[] *(data + i);
    }
    delete[] data;
    
    return 0;
}

void inputData(float** p, int d, int h) {
    for (int i = 0; i < d; i++) {
        cout << "День " << (i + 1) << ": ";
        for (int j = 0; j < h; j++) {
            cin >> *(*(p + i) + j);
        }
    }
}

float dayAverage(float* row, int h) {
    float sum = 0;
    for (int i = 0; i < h; i++) {
        sum += *(row + i);
    }
    return sum / h;
}

float overallAverage(float** p, int d, int h) {
    float totalSum = 0;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < h; j++) {
            totalSum += *(*(p + i) + j);
        }
    }
    return totalSum / (d * h);
}

void showHotDays(float** p, int d, int h) {
    float overallAvg = overallAverage(p, d, h);
    
    cout << "Теплые дни:" << endl;
    
    for (int i = 0; i < d; i++) {
        float dayAvg = dayAverage(*(p + i), h);
        if (dayAvg > overallAvg) {
            cout << "День " << (i + 1) << " (среднее = " << dayAvg << ")" << endl;
        }
    }
}